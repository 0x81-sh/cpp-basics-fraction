cmake_minimum_required(VERSION 3.17)
project(fraction)

set(CMAKE_CXX_STANDARD 20)

add_executable(fraction main.cpp Fraction.cpp Fraction.h TEST.h)