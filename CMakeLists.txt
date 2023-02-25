# Basic configurations
cmake_minimum_required(VERSION 3.15)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

project(cmake_hello_world VERSION 1.0)


add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)
target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-W3>"
)


# Add libraries
add_subdirectory(DummyMathFunctions)

# Build tests
add_executable(tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_factorial.cpp ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_sqrt.cpp)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/DummyMathFunctions ${CMAKE_CURRENT_SOURCE_DIR}/external)

target_link_libraries(tests PRIVATE DummyMathFunctions compiler_flags)

# Build SquareRootCalc CLI app
add_executable(SquareRootCalc SquareRootCalc.cpp)
target_include_directories(SquareRootCalc PRIVATE
                           "${PROJECT_BINARY_DIR}"
                           "${CMAKE_CURRENT_SOURCE_DIR}/DummyMathFunctions"
                           )
target_link_libraries(SquareRootCalc PRIVATE DummyMathFunctions compiler_flags)

# Build FactorialCalc CLI app
add_executable(FactorialCalc FactorialCalc.cpp)
target_include_directories(FactorialCalc PRIVATE
                           "${PROJECT_BINARY_DIR}"
                           "${CMAKE_CURRENT_SOURCE_DIR}/DummyMathFunctions"
                           )
target_link_libraries(FactorialCalc PRIVATE DummyMathFunctions compiler_flags)