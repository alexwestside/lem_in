cmake_minimum_required(VERSION 3.6)

project(lem_in)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(SOURCE_FILES main.c lem_in.h input_validation.c usage.c lem_realloc.c lem_init.c sub.c types_input.c pack_routes.c write_input.c data_check.c depth_first_search.c choice.c choice.c print_lemin.c free_lemin.c lem_init_2.c print_lemin_2.c DELETE_IT.c sub_2.c sub_data_check.c print_lemin_3.c)

add_executable(lem_in ${SOURCE_FILES})

target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)