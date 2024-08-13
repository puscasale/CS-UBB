cmake_minimum_required(VERSION 3.27)
project(lab6_7)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab6_7 main.cpp
        Activity.cpp
        Activity.h
        Repo.cpp
        Repo.h
        Service.cpp
        Service.h
        ui.cpp
        ui.h
        tests.cpp
        tests.h
        DinamicVector.h
        Validator.h
        Cart.cpp
        Cart.h
        Undo.cpp
        Undo.h
)
