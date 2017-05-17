cmake_minimum_required(VERSION 3.6)
project(lem_in)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(SOURCE_FILES main.c lem_in.h input_validation.c usage.c input_validation_2.c lem_realloc.c lem_init.c sub.c types_input.c write_input.c data_check.c depth_first_search.c)

add_executable(lem_in ${SOURCE_FILES})

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)