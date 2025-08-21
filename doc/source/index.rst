.. PyScreenReader documentation master file, created by
   sphinx-quickstart on Mon Jul 21 23:53:29 2025.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

PyScreenReader Official Documentation
=====================================

.. important::

   *PyScreenReader* is still under active development. APIs are subjects to change.

Welcome to the official documentation for **PyScreenReader**, a cross-platform Python library for retrieving UI widget tree information.

*PyScreenReader* achieves platform compatibilities while maintaining the ability to interact with native system APIs by
providing a unified abstraction layer that maps platform-specific accessibility data into a consistent virtual widget
tree model.

Key Features
------------

- **Cross-platform support:** Compatible with Windows, macOS, and Linux.
- **Unified virtual widget model:** Abstracts diverse native UI controls into a consistent data structure.
- **Easy access to widget properties:** Such as bounding rectangles, text content, focus state, and more.
- **Highly Simplified API designs:** Clean APIs, each focused on a single responsibility.
- **Lightweight and Pythonic:** Designed to integrate seamlessly into Python applications.

Potential Use Cases:

- Implementing screen readers to assist users with accessibility needs
- Developing MCP servers that interact directly with user desktops
- Gathering visual UI data for research and analysis

Supported Platforms
-------------------

The following table summarizes the platforms currently supported by *PyScreenReader*:

+--------------------+--------------------------+-----------------------------+
| Operating System   | Architecture             | Supported Python Versions   |
+====================+==========================+=============================+
| Windows 10/11      | x86_64                   | 3.11 – 3.13                 |
+--------------------+--------------------------+-----------------------------+
| macOS 11+          | x86_64, arm64 (M1/M2)    | 3.11 – 3.13                 |
+--------------------+--------------------------+-----------------------------+
| Linux              | x86_64, aarch64          | 3.11 – 3.13                 |
+--------------------+--------------------------+-----------------------------+

.. WARNING::
  - Windows builds: Tested on Windows 10. Windows 11 expected to behave similarly.
  - macOS builds: Tested on macOS 14 and macOS 15. macOS 11+ are expected to behave similarly.
  - Linux builds: Tested on Ubuntu 24 and Ubuntu 22. Expect all the distros to have the same behavior based on at-spi framework.

Other combinations of OS, architecture, and Python version might be compatible but have not been tested.
Use them at your own discretion.

*PyScreenReader* builds may be sensitive to the Python interpreter version due to various factors.
If you would like us to support a specific OS, architecture, or Python version, please don’t hesitate to reach out (see the `Useful Links`_ section below).
Your feedback is highly appreciated.

Installation
------------

*PyScreenReader* is a Python library.
Currently, only PyPi installation via `pip` is supported.

.. code-block:: shell

  pip install PyScreenReader


.. _useful-links:

Useful Links
------------

* `GitHub Repository <https://github.com/Lmh-java/PyScreenReader>`_
* `Issue Tracker <https://github.com/Lmh-java/PyScreenReader/issues>`_
* `PyPI Project <https://pypi.org/project/PyScreenReader/>`_

.. toctree::
   :maxdepth: 1
   :caption: Content Table:

   quickstart
   reference/index
   contributing/index
