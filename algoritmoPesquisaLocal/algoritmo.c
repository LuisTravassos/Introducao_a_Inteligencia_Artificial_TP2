#include <stdio.h>
#include <stdlib.h>
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

    int *novaSol, custo, custoViz, i;

    novaSol = malloc(sizeof(int) * k);
    if (novaSol == NULL) //Por completar
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    // Avalia solucao inicial
    custo = calculaFit(sol, mat, point, k);

    for (i = 0; i < numIter; i++) {
        // Gera vizinho
        geraVizinho(sol, novaSol, point, k);
        // Avalia vizinho
        custoViz = calculaFit(novaSol, mat, point, k);
        // Aceita vizinho se o custo aumentar (problema de maximização)
        if (custoViz > custo)   //Aceita soluções com menor custo
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