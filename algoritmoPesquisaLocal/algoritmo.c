#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

void geraVizinho(int a[], int b[], int n, int k){
    int p1, p2;

    for(int i=0; i<k; i++){
        b[i]=a[i];
    }

    //Encontra indice a trocar
    p1=randomMinMax(0, k-1);

    //Encontra valor a colocar
    do{
        p2= randomMinMax(0, n-1);
    }while(verify(b, k, p2)==1);

    // Troca
    b[p1] = p2;
}

int trepaColinas(int sol[], int *mat, int point, int k, int numIter) {

    int *novaSol, custo, custoViz, delta;
    int tmax = TMAX;

    novaSol = malloc(sizeof(int) * k);
    if (novaSol == NULL) //Por completar
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    // Avalia solucao inicial
    custo = calculaFit(sol, mat, point, k);


    for (int i = 0; i < numIter; i++) {
        // Gera vizinho
        geraVizinho(sol, novaSol, point, k);
        // Avalia vizinho
        custoViz = calculaFit(novaSol, mat, point, k);


    /*
        delta = custoViz - custo;
        if(delta >= 0){
        substitui(sol, novaSol, k);
        custo = custoViz;
        }else {
            int expression = exp(-delta / tmax);
            if (randomMinMax(0, 100) < (100 * expression)) {
                substitui(sol, novaSol, k);
                custo = custoViz;
            }
        }
        //tmax = tmax - ALPHA;
        //tmax = tmax * ALPHA;
        tmax = tmax / (1 + ALPHA * tmax);
        */


        // Aceita vizinho se o custo aumentar (problema de maximização)
        if (custoViz > custo || randomMinMax(0, 100) < CHANCE)   //Aceita soluções com menor custo e custo igual e com chance
        {
            substitui(sol, novaSol, k);
            custo = custoViz;

            //Debbuging
            //escreveSol(sol, k);
            //printf("\t\nCusto -> %d\n", custoViz);
        }
    }

    free(novaSol);
    return custo;
}