## cpp_app_template

[![Build Status](https://app.travis-ci.com/mmpaszkowski/cpp_app_template.svg?branch=master)](https://app.travis-ci.com/mmpaszkowski/cpp_app_template)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/bafce4de2a5549ecb62bd3617286728e)](https://www.codacy.com/gh/mmpaszkowski/cpp_app_template/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=mmpaszkowski/cpp_app_template&amp;utm_campaign=Badge_Grade)
[![codecov](https://codecov.io/gh/mmpaszkowski/cpp_static_lib_template/branch/master/graph/badge.svg?token=S2PIG8LUCW)](https://codecov.io/gh/mmpaszkowski/cpp_static_lib_template)

### Project structure
```shell
.
├── app
│   ├── CMakeLists.txt
│   └── main.cpp
├── cmake
│   ├── AddGitSubmodule.cmake
│   ├── CodeCoverage.cmake
│   ├── ConfigSafeGuards.cmake
│   ├── Docs.cmake
│   ├── LTO.cmake
│   ├── Tools.cmake
│   └── Warnings.cmake
├── CMakeLists.txt
├── configured
│   ├── CMakeLists.txt
│   └── config.h.in
├── include
│   └── mnist
│       └── library.h
├── README.md
├── src
│   ├── CMakeLists.txt
│   └── library.cpp
└── tests
    ├── CMakeLists.txt
    └── library.cpp
```