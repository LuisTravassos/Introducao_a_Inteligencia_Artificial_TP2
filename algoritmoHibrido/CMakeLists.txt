cmake_minimum_required(VERSION 3.21)
project(algoritmoHibrido C)

set(CMAKE_C_STANDARD 23)

add_executable(algoritmoHibrido main.c algoritmo.c utils.c funcao.c algoritmo.h funcao.h utils.h)
