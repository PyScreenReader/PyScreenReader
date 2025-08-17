# Adapted from NumPy's (https://numpy.org/) `download-wheels.py` for use in PyScreenReader
# Copyright (c) 2005-2025, NumPy Developers.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following
# disclaimer in the documentation and/or other materials provided
# with the distribution.
#
# * Neither the name of the NumPy Developers nor the names of any
# contributors may be used to endorse or promote products derived
# from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

"""
Script to download PyScreenReader wheels from the Anaconda staging area.

Usage::

    $ ./tools/download-wheels.py <version> -w <optional-wheelhouse>

Dependencies
------------

- beautifulsoup4
- urllib3

Examples
--------

While in the repository root::

    $ python tools/download-wheels.py 0.1.0
    $ python tools/download-wheels.py 0.1.0 -w ~/wheelhouse

"""
import argparse
import os
import re
import shutil

import urllib3
from bs4 import BeautifulSoup

__version__ = "0.1"

# Base URLs for PyScreenReader on Anaconda staging
NAMES_URL = "https://pypi.anaconda.org/Lmh-java/simple/pyscreenreader/"
FILES_URL = "https://anaconda.org/Lmh-java/pyscreenreader"

# Name prefix of the files to download.
PREFIX = "pyscreenreader"

# Name endings of the files to download.
SUFFIX = r"-.*\.whl$"


def get_wheel_names(version):
    """Get wheel names from Anaconda HTML directory."""
    http = urllib3.PoolManager(cert_reqs="CERT_REQUIRED")
    tmpl = re.compile(rf"^.*{PREFIX}-{version}{SUFFIX}")
    index_html = http.request("GET", NAMES_URL)
    soup = BeautifulSoup(index_html.data, "html.parser")
    return sorted(soup.find_all(string=tmpl))


def download_wheels(version, wheelhouse, test=False):
    """Download release wheels for PyScreenReader."""
    http = urllib3.PoolManager(cert_reqs="CERT_REQUIRED")
    wheel_names = get_wheel_names(version)

    for i, wheel_name in enumerate(wheel_names):
        wheel_url = f"{FILES_URL}/{version}/download/{wheel_name}"
        wheel_path = os.path.join(wheelhouse, wheel_name)
        with open(wheel_path, "wb") as f:
            with http.request("GET", wheel_url, preload_content=False) as r:
                info = r.info()
                length = int(info.get("Content-Length", "0"))
                if length == 0:
                    length_str = "unknown size"
                else:
                    length_str = f"{(length / 1024 / 1024):.2f}MB"
                print(f"{i + 1:<4}{wheel_name} {length_str}")
                if not test:
                    shutil.copyfileobj(r, f)
    print(f"\nTotal files downloaded: {len(wheel_names)}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "version",
        help="PyScreenReader version to download from stalling."
    )
    parser.add_argument(
        "-w", "--wheelhouse",
        default=os.path.join(os.getcwd(), "release"),
        help="Directory in which to store downloaded wheels\n"
             "[defaults to <cwd>/release/]"
    )
    parser.add_argument(
        "-t", "--test",
        action="store_true",
        help="Only list available wheels, do not download"
    )

    args = parser.parse_args()

    wheelhouse = os.path.expanduser(args.wheelhouse)
    if not os.path.isdir(wheelhouse):
        raise RuntimeError(
            f"{wheelhouse} wheelhouse directory is not present."
            " Perhaps you need to use the '-w' flag to specify one."
        )

    download_wheels(args.version, wheelhouse, test=args.test)
