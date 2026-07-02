cmake_minimum_required(VERSION 3.17)
project(Sudokuish C)

set(CMAKE_C_STANDARD 99)

add_executable(Sudokuish main.c menu.c sudoku.c)