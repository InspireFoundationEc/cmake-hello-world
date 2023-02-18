# cmake-hello-world

[![Build & Test](https://github.com/InspireFoundationEc/cmake-hello-world/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/InspireFoundationEc/cmake-hello-world/actions/workflows/build_and_test.yml)

This is a simple project to demonstrate how to use [CMake](https://cmake.org/) for building a cross-platform C++ project.

It contains a couple of functions (sqrt and factorial) and their respective unit tests (using [Catch2](https://github.com/catchorg/Catch2)).

## Prerequisites

- [CMake](https://cmake.org/install/) (version 3.15 or higher)
- A C++ compiler (e.g. [GCC](https://gcc.gnu.org/), [Clang](https://clang.llvm.org/), [MSVC](https://visualstudio.microsoft.com/))

## Build

CMake documentation advices the following:
> “Out-of-source build” is a good practice of keeping separate the generated files of the binary tree from the source files of the source tree. 

Following this approach, we create a `build` directory and run CMake from there. The CMakeLists.txt file is located in the root directory of the project. 

**Warning**: Always make sure that build directories are added to the `.gitignore` file.

```bash
mkdir build
cd build

# Windows
cmake ../
cmake --build . --config Debug

# Linux
cmake -DCMAKE_BUILD_TYPE=Debug ../
cmake --build .
```

_Note: for building under `Release` mode, replace `Debug` with `Release` in the above commands._

## Run
Inside the `build` directory we created above, we can find the executable file `SquareRootCalc`. (When compiling on Windows with MSVC it will have the `.exe` extension and it'll be placed in a folder called `Debug`). 

We can run it as follows:

```bash
# Windows
./Debug/SquareRootCalc.exe 2

# Linux
./SquareRootCalc 2
```

## Test
This project is configured for testing with the [Catch2](https://github.com/catchorg/Catch2) library. Inside the `build` directory, run:
```bash
ctest
```

<!--
```bash
rm -rf * && cmake .. && cmake --build . && ./Debug/SquareRootCalc 2
```
-->

## Resources
- [CMake Tutorial steps](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [CMake Tutorial source code](https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial)
- [CMake + Catch2 Integration](https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md)