cmake_minimum_required(VERSION 3.17)
project(routine)

set(CMAKE_C_STANDARD 11)

add_executable(test main_t.c src/routine_helper.c src/routine_freebsd.s src/routine_common.c)