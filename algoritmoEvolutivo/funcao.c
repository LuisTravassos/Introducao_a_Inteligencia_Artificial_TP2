#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "algoritmo.h"
#include "funcao.h"

float eval_individual(int sol[], struct info d, int *mat, int *v, int k){
    int total = 0;
    int counter = 0;

    for (int j=0; j<d.numMochila; j++){
        if(sol[j] == 1){
            counter++;
        }
    }

    for (int i = 0; i < d.numMochila; i++){
        if (sol[i] == 1)
        {
            for (int j = i; j < d.numMochila; j++)
                if (sol[j] == 1 && *(mat + i*d.numMochila + j) == 1)
                    total++; //total Ã© o numero de ligaÃ§oes entre os membros dos grupos de 0's
        }
    }

    if(total == 0){
        *v = 0;
        return -1;//numero de zeros;
    }
    if(counter != k){
        *v = 0;
        return -2;
    }
    *v = 1;
    //printf("->%d\n", total);
    return total;

}


void evaluate(pchrom pop, struct info d, int *mat, int k){
    int i;

    for (i=0; i<d.popsize; i++){
        pop[i].fitness = eval_individual(pop[i].mochila, d, mat, &pop[i].valido, k);
        //printf("%f\n", pop[i].fitness);
    }

}

