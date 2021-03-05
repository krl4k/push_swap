
cmake_minimum_required(VERSION 3.17)

project(test)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "-D DEBUG=1")
file(GLOB SRCS_PUSH_SWAP stack/srcs/*.c)
file(GLOB SRCS_LIBFT libft/*.c)
file(GLOB SRCS_CHECKER checker/srcs/*.c)

include_directories(
        checker/
        checker/includes
        checker/srcs
        includes/
        stack/
        stack/srcs/
        stack/includes/
        libft/
)

link_directories(
        checker/
        checker/includes/
        checker/srcs
        includes/
        stack/
        stack/srcs/
        stack/includes/
        libft/
        )

add_executable(push_swap
        ${SRCS_PUSH_SWAP}
        ${SRCS_LIBFT}
        ${SRCS_CHECKER}
        checker/main.c
        )