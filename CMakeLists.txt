cmake_minimum_required(VERSION 3.5)
project(liso)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
# generate databse for YouCompleteMe plugin
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SOURCE_FILES 
    main.c 
    logger.c 
    arg_parser.c 
    liso_server.c 
    http_mod.c 
    http_response.c 
    http_request_parser.lex.c)
add_executable(liso ${SOURCE_FILES})

target_compile_options(liso PRIVATE -Wall -Wextra -pedantic)
