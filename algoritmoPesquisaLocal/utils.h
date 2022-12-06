#ifndef ALGORITMOPESQUISALOCAL_UTILS_H
#define ALGORITMOPESQUISALOCAL_UTILS_H

int* init_dados(char *nome, int *point, int *line, int *k);

void init_rand();

int randomMinMax(int min, int max);

void geraSolIni(int *sol, int point);

void display_grid(int *matriz, int point);

void escreveSol(int *sol, int point);

#endif //ALGORITMOPESQUISALOCAL_UTILS_H
