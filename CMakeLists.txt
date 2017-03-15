cmake_minimum_required(VERSION 3.6)
project(push_swap)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES main.c
        push_swap.c /
        libft/ft_atoi.c /
        swap_a_b_s.c /
        push_rotate.c /
        rev_a_b_rr.c /
        start_sort.c)
add_executable(push_swap ${SOURCE_FILES})