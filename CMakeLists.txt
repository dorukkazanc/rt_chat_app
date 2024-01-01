cmake_minimum_required(VERSION 3.27)
project(rt_chat_app C)

set(CMAKE_C_STANDARD 11)

add_executable(rt_chat_app main.c
        tcp.c
        winsock.h
)

target_link_libraries(rt_chat_app Ws2_32.lib)

