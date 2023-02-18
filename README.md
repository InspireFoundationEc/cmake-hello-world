# cmake-hello-world

[![Build & Test](https://github.com/InspireFoundationEc/cmake-hello-world/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/InspireFoundationEc/cmake-hello-world/actions/workflows/build_and_test.yml)

This is a simple project to demonstrate how to use [CMake](https://cmake.org/) for building a cross-platform C++ project.

It contains a C++ program that calculates the square root of a number.

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

<!--
```bash
rm -rf * && cmake .. && cmake --build . && ./Debug/SquareRootCalc 2
```
-->

## Resources
- [CMake Tutorial steps](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [CMake Tutorial source code](https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial)