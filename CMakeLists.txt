cmake_minimum_required(VERSION 3.6)
project(push_swap)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES main.c)
add_executable(push_swap ${SOURCE_FILES})