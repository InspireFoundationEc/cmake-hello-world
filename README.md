# cmake-hello-world

[![Build & Test](https://github.com/InspireFoundationEc/cmake-hello-world/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/InspireFoundationEc/cmake-hello-world/actions/workflows/build_and_test.yml)

This is a simple project to demonstrate how to use [CMake](https://cmake.org/) for building a cross-platform C++ project.

It contains a couple of functions (sqrt and factorial) and their respective unit tests (using [doctest](https://github.com/doctest/doctest)).

## Prerequisites

- [CMake](https://cmake.org/install/) (version 3.15 or higher)
- A C++ compiler (e.g. [GCC](https://gcc.gnu.org/), [Clang](https://clang.llvm.org/), [MSVC](https://visualstudio.microsoft.com/))

## Usage
### Build

We follow the “out-of-source build” approach recommended by the CMake documentation.

1. Create a `build` directory and move into it:
    ```bash
    mkdir build
    cd build
    ```

2. Generate the project files:
    ```bash
    # On Windows (will generate project files to compile with MSVC)
    cmake ../

    # On Linux (will generate Makefiles for compiling with GCC)
    cmake -DCMAKE_BUILD_TYPE=Debug ../
    ```

3. Build the project:
    ```bash
    # On Windows
    cmake --build . --config Debug

    # On Linux
    cmake --build .
    ```

_Note: for building under `Release` mode, replace `Debug` with `Release` in the above commands._

#### Re-building after changes

- If you make changes to CMakeLists.txt, you need to repeat steps 2 and 3. 

- But if you only make changes to the source files, just repeat step 3.

### Run the tests
This project is configured for testing with the [doctest](https://github.com/doctest/doctest) library. Inside the `build` directory, run:
```bash
# Windows
./Debug/tests.exe

# Linux
./tests
```

### Run the app
Inside the `build` directory we created above, we can find the executable files for `SquareRootCalc` and `FactorialCalc`. (When compiling on Windows with MSVC they will have the `.exe` extension and they'll be placed in a folder called `Debug` or `Release` depending on the configuration chosen at build-time). 

You can run them as follows:

```bash
# Windows
./Debug/SquareRootCalc.exe 2
./Debug/FactorialCalc.exe 4

# Linux
./SquareRootCalc 2
./FactorialCalc 4
```

### Shortcuts

- Clean everything, re-generate the project files, build the project, run the tests and run the SquareRootCalc & FactorialCalc CLI apps (assuming you're in the `build` directory):

    ```bash
    rm -rf * && cmake ../ && cmake --build . && ./Debug/tests.exe && ./Debug/SquareRootCalc.exe 2 && ./Debug/FactorialCalc.exe 4
    ```


## Resources
- [CMake Tutorial steps](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [CMake Tutorial source code](https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial)
- [Doctest tutorial](https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md)