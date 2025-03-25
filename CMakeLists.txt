cmake_minimum_required(VERSION 3.30)
project(yr1_coursework C)

set(CMAKE_C_STANDARD 11)

add_executable(yr1_coursework main.c
        grid_generation.c
        grid_generation.h
        output_grid.c
        output_grid.h
        player_move.c
        player_move.h
        main.h)
