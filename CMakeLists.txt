cmake_minimum_required(VERSION 3.15)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

project(SquareRootCalc VERSION 1.0)

add_library(compiler_flags INTERFACE)
add_executable(SquareRootCalc SquareRootCalc.cpp)
add_subdirectory(DummyMathFunctions)

configure_file(SquareRootCalcConfig.h.in SquareRootCalcConfig.h)

target_include_directories(SquareRootCalc PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/DummyMathFunctions"
                           )

target_compile_features(compiler_flags INTERFACE cxx_std_20)
target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-W3>"
)

target_link_libraries(SquareRootCalc PUBLIC DummyMathFunctions compiler_flags)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)