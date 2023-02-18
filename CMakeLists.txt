cmake_minimum_required(VERSION 3.10)

project(SquareRootCalc VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SquareRootCalc SquareRootCalc.cpp)

configure_file(SquareRootCalcConfig.h.in SquareRootCalcConfig.h)

target_include_directories(SquareRootCalc PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )