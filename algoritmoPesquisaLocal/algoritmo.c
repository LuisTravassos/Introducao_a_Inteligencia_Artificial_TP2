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

    int *novaSol1, *novaSol2, custo, custoViz1, custoViz2, delta;
    int tmax = TMAX;

    novaSol1 = malloc(sizeof(int) * k);
    novaSol2 = malloc(sizeof(int) * k);
    if (novaSol1 == NULL || novaSol2 == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    // Avalia solucao inicial
    custo = calculaFit(sol, mat, point, k);

    for (int i = 0; i < numIter; i++) {
        geraVizinho(sol, novaSol1, point, k);
        custoViz1 = calculaFit(novaSol1, mat, point, k);

        //2 Vizinhanças
        geraVizinho(sol, novaSol2, point, k);
        custoViz2 = calculaFit(novaSol2, mat, point, k);


        // Aceita vizinho se o custo aumentar (problema de maximização)
        if (custoViz1 >= custo)
        {
            substitui(sol, novaSol1, k);
            custo = custoViz1;
        }

        //2 Vizinhanças
        if (custoViz2 >= custo)
        {
            substitui(sol, novaSol2, k);
            custo = custoViz2;
        }
    }

    free(novaSol1);
    free(novaSol2);
    return custo;
}