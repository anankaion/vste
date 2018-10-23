cmake_minimum_required(VERSION 3.8)
project(vste)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c file.c file.h mode.c mode.h)
add_executable(vste ${SOURCE_FILES})