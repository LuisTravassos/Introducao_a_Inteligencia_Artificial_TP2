#define _CRT_SECURE_NO_WARNINGS 1
#include "algoritmo.h"
#include "funcao.h"

void evaluate(pchrom pop, struct info d, int *mat){
    int i;

    for (i=0; i<d.popsize; i++)
        pop[i].fitness = evalIndividual(pop[i].mochila, d, mat, &pop[i].valido);

}

float evalIndividual(int sol[], struct info d, int *mat, int *v){
    int total = 0;
    int i, j;
    int zeros=0;

    for (i = 0; i < d.numMochila; i++){
        if (sol[i] == 0){
            for (j = 0; j < d.numMochila; j++){
                if (sol[j] == 0 && *(mat + i*d.numMochila + j) == 1){
                    total++; //total Ã© o numero de ligaÃ§oes entre os membros dos grupos de 0's
                }
            }
        }
    }
    if(total == 0){

        for(i=0;i<d.numMochila;i++){
            if(sol[i] == 0){
                zeros++;
            }
        }
        *v = 1;
        return zeros;//numero de zeros;
    }
    else{
        *v = 0;
        return -total;
    }

}