cmake_minimum_required(VERSION 3.21)
project(algoritmoEvolutivo C)

set(CMAKE_C_STANDARD 23)

add_executable(algoritmoEvolutivo main.c algoritmo.c funcao.c utils.c algoritmo.h funcao.h utils.h)
