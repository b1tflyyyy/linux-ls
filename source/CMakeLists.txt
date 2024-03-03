cmake_minimum_required(VERSION 3.14)

set(SOURCES main.c)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} LS_IMPL)
