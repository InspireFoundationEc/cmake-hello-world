# cmake-hello-world
### Build
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

### Run
Inside the `build` directory:
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
- [CMake Tutorial steps](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html)
- [CMake Tutorial source code](https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial)