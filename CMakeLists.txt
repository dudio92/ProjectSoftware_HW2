cmake_minimum_required(VERSION 3.15)
project(HW2 C)

set(CMAKE_C_STANDARD 90)

add_executable(HW2 main.c sp_nim.c main_aux.c main_aux.h sp_nim.h)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -Wextra -Werror -pedantic-errors")