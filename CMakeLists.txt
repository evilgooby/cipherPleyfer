cmake_minimum_required(VERSION 3.28)
project(playferCipher)

set(CMAKE_CXX_STANDARD 17)

add_executable(playferCipher main.cpp
        class/class.cpp
        class/class.h
)
