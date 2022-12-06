#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define DEFAULT_RUNS 10;

int main(int argc, char *argv[]) {
    char path[] = "../../TestFiles/";
    char nome_fich[100];
    int nPoints, nLines, kValue, runs;
    int *grid, *sol, *best_sol;

    //Obtem nome ficheiro
    if (argc == 3) {
        runs = atoi(argv[2]);
        strcpy(nome_fich, argv[1]);
        strcat(path, nome_fich);
    } else if (argc == 2) {
        runs = DEFAULT_RUNS
        strcpy(nome_fich, argv[1]);
        strcat(path, nome_fich);
    } else {
        runs = DEFAULT_RUNS
        printf("Nome do Ficheiro: ");
        gets(nome_fich);
        strcat(path, nome_fich);
    }
    if(runs <= 0){
        return 0;
    }
    init_rand();    //Inicializa random

    //Cria matrizes de dados
    grid=init_dados(path, &nPoints, &nLines, &kValue);
    //display_grid(grid, nPoints);
    sol = malloc(sizeof(int)*nPoints);
    best_sol = malloc(sizeof(int)*nPoints);
    if(sol == NULL || best_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    for (int i = 0; i <= runs; ++i) {
        //gerar e mostrar Solução Inicial
        geraSolIni(sol, nPoints);
        escreveSol(sol, nPoints);
    }
}