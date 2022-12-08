cmake_minimum_required(VERSION 3.21)
project(algoritmoPesquisaLocal C)

set(CMAKE_C_STANDARD 23)

add_executable(algoritmoPesquisaLocal main.c utils.h utils.c funcao.c funcao.h algoritmo.c algoritmo.h)
