#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

void geraVizinho(int a[], int b[], int n, int k) {
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

int trepaColinas(int sol[], int sol2[], int *mat, int point, int k, int numIter) {

    int *novaSol, custo1, custo2, custoViz, delta;
    int tmax = TMAX;

    novaSol = malloc(sizeof(int) * k);
    if (novaSol == NULL) //Por completar
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    // Avalia solucao inicial
    custo1 = calculaFit(sol, mat, point, k);
    custo2 = calculaFit(sol2, mat, point, k);


    for (int i = 0; i < numIter; i++) {
        // Gera vizinho
        geraVizinho(sol, novaSol, point, k);
        // Avalia vizinho
        custoViz = calculaFit(novaSol, mat, point, k);


        // Aceita vizinho se o custo aumentar (problema de maximização)
        if (custoViz > custo1)  // || randomMinMax(0, 100) < CHANCE)   //Aceita soluções com menor custo e custo igual e com chance
        {
            substitui(sol, novaSol, k);
            custo1 = custoViz;

            //Debbuging
            //escreveSol(sol, k);
            //printf("\t\nCusto -> %d\n", custoViz);
        }else if(custoViz > custo2)  // || randomMinMax(0, 100) < CHANCE)   //Aceita soluções com menor custo e custo igual e com chance
        {
            substitui(sol2, novaSol, k);
            custo2 = custoViz;

            //Debbuging
            //escreveSol(sol, k);
            //printf("\t\nCusto -> %d\n", custoViz);
        }
    }

    free(novaSol);

    return(custo1);
}

int geneticTrepaColinas(int pai[], int mae[], int *mat, int point, int k, int numIter, int pr, int pm) {

    int *novaSol, *novaSolB, *paiB, *maeB, custo1, custo2, custoViz, delta;
    int tmax = TMAX;

    novaSol = malloc(sizeof(int) * k);
    novaSolB = malloc(sizeof(int) * point);
    paiB = malloc(sizeof(int) * point);
    maeB = malloc(sizeof(int) * point);
    if (novaSol == NULL || novaSolB == NULL  || paiB == NULL || maeB == NULL) //Por completar
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    // Avalia solucao inicial
    custo1 = calculaFit(pai, mat, point, k);
    custo2 = calculaFit(mae, mat, point, k);


    for (int i = 0; i < numIter; i++) {
        // Gera vizinho
        geraVizinho(pai, novaSol, point, k);

        //GeneticOperators
        if (randomMinMax(1,100) <= pr){

            //transformar em "binário"
            binaryTransform(novaSol, novaSolB, point, k);
            binaryTransform(pai, paiB, point, k);
            binaryTransform(mae, maeB, point, k);

            //trocar em binário
            crossover(paiB, maeB, novaSolB, point);

            //Corrigir e gerar son em "indices"
            correction(novaSol, novaSolB, point, k);

        }
        if (randomMinMax(1,100) <= pm){

            //transformar em "binário"
            binaryTransform(novaSol, novaSolB, point, k);
            binaryTransform(pai, paiB, point, k);
            binaryTransform(mae, maeB, point, k);

            //trocar em binário
            mutation(paiB, novaSolB, point);

            //Corrigir e gerar son em "indices"
            correction(novaSol, novaSolB, point, k);

        }

        // Avalia vizinho
        custoViz = calculaFit(novaSol, mat, point, k);


        // Aceita vizinho se o custo aumentar (problema de maximização)
        if (custoViz > custo1)  // || randomMinMax(0, 100) < CHANCE)   //Aceita soluções com menor custo e custo igual e com chance
        {
            substitui(pai, novaSol, k);
            custo1 = custoViz;

            //Debbuging
            //escreveSol(sol, k);
            //printf("\t\nCusto -> %d\n", custoViz);
        }else if(custoViz > custo2)  // || randomMinMax(0, 100) < CHANCE)   //Aceita soluções com menor custo e custo igual e com chance
        {
            substitui(mae, novaSol, k);
            custo2 = custoViz;

            //Debbuging
            //escreveSol(sol, k);
            //printf("\t\nCusto -> %d\n", custoViz);
        }
    }

    free(novaSol);
    free(novaSolB);
    free(paiB);
    free(maeB);

    return custo1;
}

void crossover(int pai[], int mae[], int son[], int nPoints) {
    int point;

    point = randomMinMax(0, nPoints-1);
    for (int j=0; j<point; j++){
        son[j]=pai[j];
    }
    for (int j=point; j<nPoints; j++){
        son[j]=mae[j];
    }
}

void mutation(int pai[], int son[], int nPoints) {

    for (int i=0; i<nPoints; i++){
        son[i] = !(pai[i]);
    }
}