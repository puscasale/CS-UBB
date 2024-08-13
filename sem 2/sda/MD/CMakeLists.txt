cmake_minimum_required(VERSION 3.27)
project(MD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MD
        App.cpp
        IteratorMD.cpp
        IteratorMD.h
        MD.cpp
        MD.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
