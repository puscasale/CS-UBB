cmake_minimum_required(VERSION 3.27)
project(Multime)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Multime
        App.cpp
        IteratorMultime.cpp
        IteratorMultime.h
        Multime.cpp
        Multime.h
        TestScurt.cpp
        TestExtins.cpp)
