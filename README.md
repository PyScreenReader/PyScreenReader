# PyScreenReader
PyScreenReader is a cross-platform Python library that encapsulates native accessibility APIs on Windows, macOS, and Linux, which allows Python programmers to collect widget tree information on the screen. 

## Table of Content

- [Quick Start](#quick-start)
- [Contributing](#contributing)
- [Feedback & Support](#feedback--support)
- [Licensing](#licensing)


## Quick Start
Install PyScreenReader latest release from pip registries.
```shell
pip install PyScreenReader
```

In your Python script, import PyScreenReader
```
import PyScreenReader as psr

# Create a screen reader instance
screen_reader = psr.ScreenReader()
# Read the virtual widget tree by program's PID
root = screen_reader.getVirtualWidgetTreeByPID("20880")
```

[//]: # (TODO #15, link our documentation once the doc system is up)
This is just a quick start. For more information, please refer to our official documentation.

[//]: # (TODO #19 Until integration test PR is merged, then we can link this to e2e test cases)
[//]: # (You can see more examples from our [integration test cases]&#40;tests&#41;)

## Contributing

[//]: # (TODO #35, link to our contributing guideline)
Yay! We are glad to hear that you are interested in contributing to PyScreenReader! Please see the contribution guideline
for more information. The guideline includes how to file a GitHub issue, open a GitHub Pull Request, etc.

## Feedback & Support
Feedback is a gift! We appreciate any kind of feedback/questions/concerns in the following forms:  
- Visit our Discussion Page - We will create a discussion for each version of PyScreenReader. In the discussion forum, feel
free to asking questions about this project. It is always great to see people sharing knowledge with and actively helping each other. :)
- [File an issue ticket](https://github.com/Lmh-java/PyScreenReader/issues). Issue board is another place where we track technical questions.
Once approved by the maintainers, new issues will be assigned and worked on, and hopefully will be released in the next version of PyScreenReader.
- Found Security concerns and vulnerabilities? Oh no, now we have troubles! But the good news is - you found it and alerted us, so nothing bad happened. Yah, please report them through the [Security Page](https://github.com/Lmh-java/PyScreenReader/security),
so it does not get exposed to the public.

## Licensing
PyScreenReader is licensed under [MIT License](LICENSE).
By using, distributing, or contributing to this project, you agree the terms and conditions of this license.  

PyScreenReader uses libraries:  
- [Google Test](https://github.com/google/googletest)  
- [PyBind11](https://github.com/pybind/pybind11)
- [PyTest](https://docs.pytest.org/en/stable/)
- [PySide2](https://pypi.org/project/PySide2/) (Only used for building integration test targets and is not distributed with the releases)
