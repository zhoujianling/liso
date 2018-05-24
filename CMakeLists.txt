cmake_minimum_required(VERSION 3.5)
project(liso)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
set(SOURCE_FILES main.c arg_parser.c liso_server.c liso_core.c http_mod.c http_response.c)
add_executable(liso ${SOURCE_FILES})