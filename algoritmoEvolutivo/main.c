#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#define DEFAULT_RUNS	5
#define DEFAULT_INTERACTIONS     100

int main(int argc, char *argv[]) {
    char path[] = "../../TestFiles/";
    char        nome_fich[100];
    struct info EA_param;
    int         mat[MAX_OBJ][MAX_OBJ], runs, i;
    pchrom      pop = NULL, parents = NULL;
    chrom       best_run, best_ever;
    int         gen_actual, inv, numIter, kValue;
    float       mbf = 0.0;


    EA_param.popsize = 10; //tamanho da população
    EA_param.pr = 50;     //probabilidade de recombinação
    EA_param.pm = 50;    //probabilidade de mutação
    EA_param.tsize = 2;    //tamanho do torneio
    EA_param.numGenerations = 30;  //numero de geracoes


    //Obtem nome ficheiro
    if (argc == 3) {
        runs = atoi(argv[2]);
        numIter = DEFAULT_INTERACTIONS;
        strcpy(nome_fich, argv[1]);
        strcat(path, nome_fich);
    } else if (argc == 2) {
        runs = DEFAULT_RUNS;
        numIter = DEFAULT_INTERACTIONS;
        strcpy(nome_fich, argv[1]);
        strcat(path, nome_fich);
    } else {
        runs = DEFAULT_RUNS;
        numIter = DEFAULT_INTERACTIONS;
        printf("Nome do Ficheiro: ");
        gets(nome_fich);
        strcat(path, nome_fich);
    }
    if (runs <= 0) {
        return 0;
    }
    initRand();    //Inicializa random

    // Preenche a matriz com dados dos objectos (peso e valor) e a estrutura EA_param que foram definidos no ficheiro de input
    kValue = initData(path, *mat, &EA_param);
    //displayGrid(*mat, EA_param.numMochila);
    //puts("\n");

    for (int r=0; r<runs; r++){
        printf("\nRepeticao %d:\n",r+1);

        pop = initPop(EA_param, kValue);

        evaluate(pop, EA_param, *mat, kValue);

        best_run = pop[0];
        best_run = get_best(pop, EA_param, best_run);

        parents = malloc(sizeof(chrom)*EA_param.popsize);
        if (parents==NULL){
            printf("Erro na alocacao de memoriaa\n");
            exit(1);
        }

        // Ciclo de optimização
        gen_actual = 1;

        while (gen_actual <= EA_param.numGenerations){
            tournament(pop, EA_param, parents);

            genetic_operators(parents, EA_param, pop);
            correction(pop, EA_param, kValue);  //Altera os dados, talvez seja a causa do falhanço

            // Avalia a nova popula��o (a dos filhos)
            evaluate(pop, EA_param, *mat, kValue);
            best_run = get_best(pop, EA_param, best_run);
            gen_actual++;
        }
        for (inv=0, i=0; i<EA_param.popsize; i++){
            if (pop[i].valido == 0){
                inv++;
            }
        }
        // Escreve resultados da repeti��o que terminou
        writeBest(best_run, EA_param);
        printf("\nPercentagem Invalidos: %f\n", 100*(float)inv/EA_param.popsize);
        mbf += best_run.fitness;
        if (runs==0 || best_run.fitness > best_ever.fitness)
            best_ever = best_run;
        // Liberta a mem�ria usada
        free(parents);
        free(pop);
    }

    // Escreve resultados globais
    printf("\n\nMBF: %f\n", mbf/runs);
    printf("\nMelhor solucao encontrada");
    writeBest(best_ever, EA_param);
    //logtofile(best_ever, EA_param,mbf/r);
    return 0;
}


