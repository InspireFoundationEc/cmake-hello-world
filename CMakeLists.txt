cmake_minimum_required(VERSION 3.10)

project(SquareRootCalc VERSION 1.0)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)

add_executable(SquareRootCalc SquareRootCalc.cpp)

configure_file(SquareRootCalcConfig.h.in SquareRootCalcConfig.h)

target_include_directories(SquareRootCalc PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/DummyMathFunctions"
                           )

add_subdirectory(DummyMathFunctions)

target_link_libraries(SquareRootCalc PUBLIC DummyMathFunctions compiler_flags)