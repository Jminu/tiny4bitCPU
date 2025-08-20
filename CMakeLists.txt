cmake_minimum_required(VERSION 3.29)
project(4BitComptuer C)

set(CMAKE_C_STANDARD 11)

add_executable(4BitComptuer main.c
        register/register.c
        register/register.h
        memory/memory.h
        memory/memory.c
        isa/isa.h
        cpu/cpu.h
        cpu/cpu.c
        isa/isa.c
        decoder/decoder.h
        decoder/decoder.c
        fetcher/fetcher.c
        fetcher/fetcher.h
        executor/executor.c
        executor/executor.h
        assembler/asembler.c
        assembler/assembler.h
        display/display_memory_state.c
        display/display_memory_state.h
        filesystem/filesystem.c
        filesystem/filesystem.h
        util/util.c
        util/util.h)
