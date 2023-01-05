#ifndef ALGORITMOPESQUISALOCAL_UTILS_H
#define ALGORITMOPESQUISALOCAL_UTILS_H

int* init_dados(char *nome, int *point, int *line, int *k);

void init_rand();

int randomMinMax(int min, int max);

void geraSolIni(int *sol, int point, int k);

void display_grid(int *matriz, int point);

int verify(int b[], int k, int p);

void substitui(int a[], int b[], int k);

void escreveSol(int *sol, int k);

#endif //ALGORITMOPESQUISALOCAL_UTILS_H
