# Documentation

If you find an error in the PyScreenReader documentation (this site), notice missing or outdated information, or have suggestions to improve clarity or completeness, we warmly welcome your feedback.

You have two options to contribute:
- **Open an issue** on our GitHub repository describing the problem or suggestion.
- **Submit a pull request** directly if you'd like to propose a fix or improvement.

## Generate Documentation Locally

If you want to directly contribute your changes to *PyScreenReader*, please follow these steps to generate and preview the documentation locally.

*PyScreenReader* uses [Sphinx](https://github.com/sphinx-doc/sphinx), a powerful documentation generator.
Most documentation is written in _GitHub-styled Markdown_, with some files in _reStructuredText_.

The source files for documentation are located in `/doc/source`.

### Install Sphinx

First, ensure your development virtual environment (often named `.venv`) is active. Then, install the development dependencies from the project root
(if you haven't done so):

```shell
pip install -r requirements-dev.txt
```

Navigate to the documentation directory:

```shell
cd doc
```

Make your changes in the `.md` or `.rst` files as needed.

To generate the HTML documentation, run:

```shell
make html
```

If the above command fails, please review the logs to debug any issues.

To preview the generated documentation locally, start a Python web server:

```shell
cd build/html
python -m http.server 8000
```

Then open `localhost:8000` in your web browser to view the documentation.

Once you are satisfied with your changes, feel free to open a Pull Request. After your PR is merged, a GitHub workflow running on the `main` branch will automatically publish the updated documentation.
