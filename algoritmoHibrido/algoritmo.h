#ifndef ALGORITMOPESQUISALOCAL_ALGORITMO_H
#define ALGORITMOPESQUISALOCAL_ALGORITMO_H

#define CHANCE -1   //desligado
#define TMAX 40
#define ALPHA 0

int trepaColinas(int sol[], int sol2[], int *mat, int point, int k, int numIter);

int geneticTrepaColinas(int pai[], int mae[], int *mat, int point, int k, int numIter, int pr, int pm);

void crossover(int pai[], int mae[], int son[], int nPoints);

void mutation(int pai[], int son[], int nPoints);

void geraVizinho(int a[], int b[], int n, int k);

#endif //ALGORITMOPESQUISALOCAL_ALGORITMO_H
