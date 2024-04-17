cmake_minimum_required(VERSION 3.10)
project(polynomial_methods)

set(CMAKE_CXX_STANDARD 17)

add_executable(polynomial_methods polynomial.cpp unit-test.cpp)
