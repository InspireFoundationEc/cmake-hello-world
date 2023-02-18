# cmake-hello-world
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
Inside the `build` directory we created above, we can find the executable file `SquareRootCalc` (or `SquareRootCalc.exe` on Windows) in the `Debug` folder. We can run it as follows:

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

### Resources
- [CMake Tutorial steps](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [CMake Tutorial source code](https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial)