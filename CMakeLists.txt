cmake_minimum_required(VERSION 3.12)
project(routine)

set(CMAKE_C_STANDARD 11)

enable_language(ASM)

add_executable(routine main_t.c ./src/routine_base.c ./src/stack_collect.c ./src/reuse.c ./src/routine_helper.c ./src/routine_user_api.c ./src/routine_dfa.c ./src/routine_freebsd.s ./src/routine_common.c ./src/routine_kernel_api.c ./src/routine_event.c ./src/bitmap.c)
