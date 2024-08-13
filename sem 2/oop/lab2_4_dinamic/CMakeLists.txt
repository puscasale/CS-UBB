cmake_minimum_required(VERSION 3.27)
project(lab2_4_dinamic C)

set(CMAKE_C_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(lab2_4_dinamic main.c
        list.c
        list.h
        med.c
        med.h
        functions.c
        functions.h
        tests.c
        tests.h
        customSort.c
        customSort.h)
