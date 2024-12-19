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
        command/command.c
        command/command.h
        parser/parser.h
        parser/parser.c)
