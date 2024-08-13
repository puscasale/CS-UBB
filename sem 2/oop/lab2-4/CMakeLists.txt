cmake_minimum_required(VERSION 3.27)
project(lab2_4 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab2_4 main.c
        functions.c
        functions.h
        functions_test.c
        functions_test.h)
