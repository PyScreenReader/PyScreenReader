# Copyright (c) 2016 The Pybind Development Team. All rights reserved.
# Original license: https://github.com/pybind/cmake_example/blob/master/LICENSE
# Modified by Minghao Li: modified project-specific information and commands
import glob
import logging
import os
import platform
import re
import shutil
import subprocess
import sys
from pathlib import Path

from setuptools import Extension, setup, Command
from setuptools.command.build_ext import build_ext

# Convert distutils Windows platform specifiers to CMake -A arguments
PLAT_TO_CMAKE = {
    "win32": "Win32",
    "win-amd64": "x64",
    "win-arm32": "ARM",
    "win-arm64": "ARM64",
}

PROJECT_NAME = "PyScreenReader"


class CMakeExtension(Extension):
    def __init__(self, name: str, sourcedir: str = "") -> None:
        super().__init__(name, sources=[])
        self.sourcedir = os.fspath(Path(sourcedir).resolve())


class CMakeBuild(build_ext):
    def build_extension(self, ext: CMakeExtension) -> None:
        # Must be in this form due to bug in .resolve() only fixed in Python 3.10+
        ext_fullpath = Path.cwd() / self.get_ext_fullpath(ext.name)
        extdir = ext_fullpath.parent.resolve()

        # Using this requires trailing slash for auto-detection & inclusion of
        # auxiliary "native" libs

        debug = int(os.environ.get("DEBUG", 0)) if self.debug is None else self.debug
        cfg = "Debug" if debug else "Release"

        # CMake lets you override the generator - we need to check this.
        # Can be set with Conda-Build, for example.
        cmake_generator = os.environ.get("CMAKE_GENERATOR", "")

        # Set Python_EXECUTABLE instead if you use PYBIND11_FINDPYTHON from Python.
        cmake_args = [
            f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={extdir}{os.sep}",
            f"-DPYTHON_EXECUTABLE={sys.executable}",
            f"-DCMAKE_BUILD_TYPE={cfg}",  # not used on MSVC, but no harm
        ]
        build_args = []
        # Adding CMake arguments set as environment variable
        # (needed e.g. to build for ARM OSx on conda-forge)
        if "CMAKE_ARGS" in os.environ:
            cmake_args += [item for item in os.environ["CMAKE_ARGS"].split(" ") if item]

        cmake_args += [f"-DVERSION_INFO={self.distribution.get_version()}"]

        if self.compiler.compiler_type != "msvc":
            # Using Ninja-build since it a) is available as a wheel and b)
            # multithreads automatically. MSVC would require all variables be
            # exported for Ninja to pick it up, which is a little tricky to do.
            # Users can override the generator with CMAKE_GENERATOR in CMake
            # 3.15+.
            if not cmake_generator or cmake_generator == "Ninja":
                try:
                    import ninja

                    ninja_executable_path = Path(ninja.BIN_DIR) / "ninja"
                    cmake_args += [
                        "-GNinja",
                        f"-DCMAKE_MAKE_PROGRAM:FILEPATH={ninja_executable_path}",
                    ]
                except ImportError:
                    pass

        else:
            # Single config generators are handled "normally"
            single_config = any(x in cmake_generator for x in {"NMake", "Ninja"})

            # CMake allows an arch-in-generator style for backward compatibility
            contains_arch = any(x in cmake_generator for x in {"ARM", "Win64"})

            # Specify the arch if using MSVC generator, but only if it doesn't
            # contain a backward-compatibility arch spec already in the
            # generator name.
            if not single_config and not contains_arch:
                cmake_args += ["-A", PLAT_TO_CMAKE[self.plat_name]]

            # Multi-config generators have a different way to specify configs
            if not single_config:
                cmake_args += [
                    f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{cfg.upper()}={extdir}"
                ]
                build_args += ["--config", cfg]

        if sys.platform.startswith("darwin"):
            # Cross-compile support for macOS - respect ARCHFLAGS if set
            archs = re.findall(r"-arch (\S+)", os.environ.get("ARCHFLAGS", ""))
            if archs:
                cmake_args += ["-DCMAKE_OSX_ARCHITECTURES={}".format(";".join(archs))]

        # Set CMAKE_BUILD_PARALLEL_LEVEL to control the parallel build level
        # across all generators.
        if "CMAKE_BUILD_PARALLEL_LEVEL" not in os.environ:
            # self.parallel is a Python 3 only way to set parallel jobs by hand
            # using -j in the build_ext call, not supported by pip or PyPA-build.
            if hasattr(self, "parallel") and self.parallel:
                # CMake 3.12+ only.
                build_args += [f"-j{self.parallel}"]

        build_temp = Path(self.build_temp) / ext.name
        if not build_temp.exists():
            build_temp.mkdir(parents=True)

        subprocess.run(
            ["cmake", ext.sourcedir, *cmake_args], cwd=build_temp, check=True
        )
        subprocess.run(
            ["cmake", "--build", ".", *build_args], cwd=build_temp, check=True
        )


class RunTestCommand(Command):
    description = "Run test cases"

    user_options = [
        ("cpp-only", None, "Only run C++ tests (not implemented yet)"),
        ("py-only", None, "Only run Python tests"),
    ]

    def finalize_options(self) -> None:
        if self.cpp_only and self.py_only:
            raise ValueError(
                "Cannot specify both --cpp-only and --py-only"
            )

    def initialize_options(self):
        self.cpp_only = False
        self.py_only = False

    @staticmethod
    def _get_platform_extension():
        system = platform.system()
        if system == "Darwin":
            return ".so"
        elif system == "Windows":
            return ".pyd"
        elif system == "Linux":
            return ".abi3.so"
        else:
            raise RuntimeError(f"Unsupported platform: {system}")

    def _run_cpp_tests(self):
        raise NotImplementedError("C++ tests are not implemented yet")

    def _run_py_tests(self):
        build_path = Path("build")
        platform_ext = RunTestCommand._get_platform_extension()
        pattern = str(build_path / "lib.*" / ("*" + platform_ext))
        ext_path_candidates = glob.glob(pattern)

        if ext_path_candidates:
            logging.warning(f"Assuming the compiled artifact at {ext_path_candidates[0]} is up-to-date. Otherwise, "
                            "please consider re-build.")
        else:
            logging.warning("Did not find compiled artifact. Trying to compile it now...")
            self.run_command('build_ext')
            ext_path_candidates = glob.glob(pattern)
            if not ext_path_candidates:
                raise RuntimeError("Compilation failed. No extension module found after build.")

        ext_path = Path(ext_path_candidates[0])
        env_path = str(ext_path.parent.resolve())
        os.environ["PYTHONPATH"] = f"{env_path}{os.pathsep}{os.environ.get('PYTHONPATH', '')}"
        pytest_cmd = [sys.executable, "-m", "pytest", "tests/py/"]
        subprocess.run(pytest_cmd)

    def run(self):
        if not self.cpp_only:
            self._run_py_tests()
        if not self.py_only:
            self._run_cpp_tests()


class RunClearCommand(Command):

    description = "Remove build artifacts"

    def initialize_options(self) -> None:
        pass

    def finalize_options(self) -> None:
        pass

    def run(self) -> None:
        shutil.rmtree('./PyScreenReader.egg-info/', ignore_errors=True)
        shutil.rmtree('./build/', ignore_errors=True)
        logging.info("Artifacts removed")


setup(
    ext_modules=[CMakeExtension(PROJECT_NAME)],
    cmdclass={
        "build_ext": CMakeBuild,
        "test": RunTestCommand,
        "clear": RunClearCommand,
    },
)
