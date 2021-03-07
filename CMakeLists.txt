
cmake_minimum_required(VERSION 3.17)

project(test)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_C_FLAGS "-D DEBUG=1")
file(GLOB SRCS_PUSH_SWAP srcs/stack/*.c)
file(GLOB SRCS_LIBFT srcs/libft/*.c)
file(GLOB SRCS_CHECKER srcs/checker/*.c)

include_directories(
        includes/
        srcs/stack/
        srcs/stack/srcs/
        srcs/stack/includes/
        srcs/libft/
)

link_directories(
        includes/
        srcs/stack/
        srcs/stack/srcs/
        srcs/stack/includes/
        srcs/libft/
        )

add_executable(push_swap
        ${SRCS_PUSH_SWAP}
        ${SRCS_LIBFT}
        ${SRCS_CHECKER}
        srcs/checker/main.c
        )