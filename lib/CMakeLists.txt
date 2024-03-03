cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME LS_IMPL)

set(SOURCES
    parser/parser.c
    dir_reader/dir_reader.c
)

set(HEADERS
    parser/parser.h
    dir_reader/dir_reader.h
    parsing_flags/parsing_flags.h
)

add_library(${LIBRARY_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC ./)