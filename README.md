<p align="center">
  <img src=".github/assets/right_side_text.svg" alt="PyScreenReader" width="100%">
</p>

# PyScreenReader

PyScreenReader is a library for developers to parse **on-screen** information using the simplicity of **Python**.

It's a cross-platform abstraction of native accessibility APIs for Windows, macOS, and Linux, based around
representing UI elements in a common tree-like interface in Python.

Key features:

- **Parse UI properties:** Such as location, size, text content, focus state, and more...
- **Cross-platform support:** Write once, works (mostly) everywhere! Compatible with Windows, macOS, and Linux.
- **Unified UI model:** Abstracts diverse native UI controls into a single consistent tree-like data structure.
- **Abstracted System APIs:**  Avoid delving in to the complexity of native per-platform system APIs to interact with
  the screen.  
- **Lightweight and Pythonic:**  No need for compilers or special toolchain setup, just use Python.  

> [!WARNING]
> PyScreenReader is not yet released and is still in testing. Stay tuned for its public release on PyPi in the near
> future.

## Table of Content

- [Quick Start](#quick-start)
- [Feedback & Support](#feedback--support)
- [Licensing](#licensing)

[//]: # (- [Contributing]&#40;#contributing&#41;)

## Quick Start

Install PyScreenReader latest release from pip registries.

```bash
pip install PyScreenReader
```

[//]: # (<details>)

[//]: # (<summary>For Linux Users</summary>)

[//]: # (```bash)

[//]: # (sudo apt-get install libatk-bridge2.0-0 at-spi2-core libatspi2.0-dev libglib2.0-dev libsystemd-dev)

[//]: # (```)

[//]: # (</details>)

In your Python script, import PyScreenReader -

```py
# Import the reader itself
from PyScreenReader.screen_reader import ScreenReader
# Import the widgets the reader will return
from PyScreenReader.virtual_widgets import VirtualWidget

# Create a screen reader instance
screen_reader = ScreenReader()
# Read the virtual widget tree by your program's PID
root = screen_reader.get_virtual_widget_tree_by_pid(20880)
# Print the location of the root widget extracted
print(f"Position of Root Widget (X: {root.get_x()}, Y: {root.get_y()})")

# Optional: Get all children of the root as a list of VirtualWidgets to traverse the tree!
children = root.get_children()
```

[//]: # (TODO #15, link our documentation once the doc system is up)
This is just a quick start. For more information, please refer to our official documentation.

[//]: # (TODO #19 Until integration test PR is merged, then we can link this to e2e test cases)

[//]: # (You can see more examples from our [integration test cases]&#40;tests&#41;)


[//]: # (## Contributing)

[//]: # ()

[//]: # ([//]: # &#40;TODO #35, link to our contributing guideline&#41;)

[//]: # (Yay! We are glad to hear that you are interested in contributing to PyScreenReader! Please see the contribution)

[//]: # (guideline)

[//]: # (for more information. The guideline includes how to file a GitHub issue, open a GitHub Pull Request, etc.)

## Feedback & Support

Feedback is a gift! We appreciate any kind of feedback/questions/concerns in the following forms:

[//]: # (- Visit our Discussion Page - We will create a discussion for each version of PyScreenReader. In the discussion forum,)

[//]: # (  feel)

[//]: # (  free to asking questions about this project. It is always great to see people sharing knowledge with and actively)

[//]: # (  helping each other. :&#41;)

- [File an issue ticket](https://github.com/Lmh-java/PyScreenReader/issues). Issue board is another place where we track
  technical questions.
  Once approved by the maintainers, new issues will be assigned and worked on, and hopefully will be released in the
  next version of PyScreenReader.
- Found Security concerns and vulnerabilities? Oh no, now we have trouble! But the good news is you found it and
  alerted us, so nothing bad will happen. Please refer to our [SECURITY](SECURITY.md) page and report them through
  the [GitHub Security Portal](https://github.com/Lmh-java/PyScreenReader/security).

## Licensing

PyScreenReader is licensed under [MIT License](LICENSE).
By using, distributing, or contributing to this project, you agree the terms and conditions of this license.

PyScreenReader uses libraries:

- [Google Test](https://github.com/google/googletest)
- [PyBind11](https://github.com/pybind/pybind11)
- [PyTest](https://docs.pytest.org/en/stable/)

Special thanks to:

- [NumPy](https://github.com/numpy/numpy) for inspiration for our release workflow
- [Typer](https://github.com/fastapi/typer) for reference for our `README`
