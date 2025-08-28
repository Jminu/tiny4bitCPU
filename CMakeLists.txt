cmake_minimum_required(VERSION 3.29)
project(4BitComptuer C)

include_directories(include)

set(CMAKE_C_STANDARD 11)

add_executable(4BitComptuer main.c
        src/register.c
        include/register.h
        include/memory.h
        src/memory.c
        include/isa.h
        include/cpu.h
        src/cpu.c
        include/decoder.h
        src/decoder.c
        src/fetcher.c
        include/fetcher.h
        src/executor.c
        include/executor.h
        src/asembler.c
        include/assembler.h
        src/display.c
        include/display.h
        src/filesystem.c
        include/filesystem.h
        src/util.c
        include/util.h)

target_link_libraries(4BitComptuer ncurses)
