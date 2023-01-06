#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "algoritmo.h"

#define DEFAULT_RUNS 10;
#define DEFAULT_INTERACTIONS 2500;

int main(int argc, char *argv[]) {
    char path[] = "../../TestFiles/";
    char nome_fich[100];
    int nPoints, nLines, kValue, runs, numIter, cost, bestCost, i;
    int *grid, *sol, *sol2, *bestSol;
    float mbf = 0.0;

    float probRec = 30;
    float probMut = 1;

    //Obtem nome ficheiro
    if (argc == 3) {
        runs = atoi(argv[2]);
        numIter = DEFAULT_INTERACTIONS
        strcpy(nome_fich, argv[1]);
        strcat(path, nome_fich);
    } else if (argc == 2) {
        runs = DEFAULT_RUNS
        numIter = DEFAULT_INTERACTIONS
        strcpy(nome_fich, argv[1]);
        strcat(path, nome_fich);
    } else {
        runs = DEFAULT_RUNS
        numIter = DEFAULT_INTERACTIONS
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

    sol = malloc(sizeof(int)*kValue);  //kvalue de tamanho
    sol2= malloc(sizeof(int)*kValue);  //kValue de tamanho
    bestSol = malloc(sizeof(int)*kValue);   //kValue de tamanho
    if(sol == NULL || sol2 == NULL|| bestSol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    for (int j = 0; j < 4; ++j) {
        if (j == 0) {
            runs = 100;
        } else if (j == 1) {
            runs = 1000;
        } else if (j == 2) {
            runs = 5000;
        }else if (j == 3) {
            runs = 10000;
        }

        for (i = 1; i <= runs; ++i) {

            //escreveSol(sol, kValue);   //Reavaliada e pronta para o trabalho

            // gerar e mostrar Solução Inicial
            geraSolIni(sol, nPoints, kValue);
            geraSolIni(sol2, nPoints, kValue);

            //Calcular Custo
            trepaColinas(sol, sol2, grid, nPoints, kValue ,numIter);

            cost = geneticTrepaColinas(sol, sol2, grid, nPoints, kValue, numIter, probRec, probMut);

            // Escreve resultados da repeticao k
            //printf("\nRepeticao %d:", i);
            //escreveSol(sol, kValue);
            //printf("Custo final: %2d\n", cost);
            mbf += cost;
            if(i==1 || bestCost < cost)
            {
                bestCost = cost;
                substitui(bestSol, sol, kValue);
            }

        }
        // Escreve eresultados globais
        printf("\n\nMBF: %f\n", mbf/i);
        printf("\nMelhor solucao encontrada");
        escreveSol(bestSol, kValue);
        printf("Custo final: %2d\n", bestCost);

        mbf = 0;

    }


    free(grid);
    free(sol);
    free(sol2);
    free(bestSol);
    return 0;
}