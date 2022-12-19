#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "algoritmo.h"
#include "utils.h"

// Inicialização do gerador de números aleatórios
void initRand()
{
    srand((unsigned)time(NULL));
}

// Leitura dos parâmetros e dos dados do problema
int initData(char *filename, int *mat, struct  info *x ){

    FILE    *f;
    int     lin, col;
    int     lines, k;

    // Leitura dos parametros do problema
    f=fopen(filename, "r");
    if(!f){
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }

    fscanf(f, "k %d", &k);

    fscanf(f, " p edge %d %d", &x->numMochila, &lines);   // Numero de vertices e ligações
    if (x->numMochila > MAX_OBJ)
    {
        printf("Number of itens is superior to MAX_OBJ\n");
        exit(1);
    }

    // Preenchimento da matriz
    for(int i=0; i<x->numMochila; i++){
        for(int j=0; j<x->numMochila; j++){
            *(mat + (x->numMochila)*i + j) = 0;
        }
    }

    for(int i=0; i<lines; i++)
    {
        fscanf(f, " e %d %d", &lin, &col);
        *(mat + x->numMochila*(lin-1) + col-1) = 1;
        *(mat + x->numMochila*(col-1) + lin-1) = 1;
    }
    fclose(f);

    return k;

}

pchrom initPop(struct info d, int k){
    pchrom  indiv;
    int g;

    indiv = malloc(sizeof(chrom)*d.popsize);
    if (indiv==NULL)
    {
        printf("Erro na alocacao de memoriaaa\n");
        exit(1);
    }
    for (int i=0; i<d.popsize; i++){
        for (int j=0; j<d.numMochila; j++){
            indiv[i].mochila[j] = 0;
        }

        for (int j = 0; j < k; j++) {
            do{
                g = randomMinMax(0, d.numMochila-1);
            }while(indiv[i].mochila[g] == 1);
            indiv[i].mochila[g] = 1;
        }
    }


    return indiv;
}

void displayGrid(int *grafo, int vert){
    for (int i = 0; i < vert; i++)
    {
        printf("\n");
        for (int j = 0; j < vert; j++)
        {
            printf("%d ", grafo[i*vert + j]);
        }
    }
}

int randomMinMax(int min, int max){
    return min + rand() % (max-min+1);
}

void writeBest(chrom x, struct info d){
    int i;

    //printf("\nBest individual: %4.1f\n", x.fitness);
    for (i=0; i<d.numMochila; i++)
        printf("%d", x.mochila[i]);
    putchar('\n');
}
