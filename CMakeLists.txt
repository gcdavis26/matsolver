cmake_minimum_required(VERSION 3.28) # Specify CMake version.
project(matsolver) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR}/include) # header file folder.
add_executable(Solver main.cpp Shape.cpp stress-theory.cpp)
