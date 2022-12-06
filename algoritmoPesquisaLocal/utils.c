#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"


//inicializa gerador random numbers
void init_rand()
{
    srand((unsigned)time(NULL));
}

int* init_dados(char *nome, int *point, int *line, int *k)
{
    FILE    *f;
    int     *p;
    int     lin, col;

    f=fopen(nome, "r");
    if(!f){
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }
    fscanf(f, "k %d", k);

    fscanf(f, " p edge %d %d", point, line);

    p = malloc(sizeof(int)*(*point)*(*point));
    if(!p){
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }
    for(int i=0; i < *point; i++) {
        for (int j = 0; j < *point; j++) {
            *(p + (*point) * i + j) = 0;
        }
    }

    for(int i=0; i < *line; i++){
        fscanf(f, " e %d %d", &lin, &col);
        *(p+(*point)*(lin-1)+col-1)=1;
        *(p+(*point)*(col-1)+lin-1)=1;
    }

    fclose(f);
    return p;
}

void geraSolIni(int *sol, int point){
    int i, x;

    for(i=0; i<point; i++)
        sol[i]=0;

    for(i=0; i<point/2; i++)
    {
        do
            x = randomMinMax(0, point-1);
        while(sol[x] != 0);

        sol[x]=1;
    }
}

void escreveSol(int *sol, int point){
    int i;

    printf("\nConjunto A: ");
    for(i=0; i<point; i++)
        if(sol[i]==0)
            printf("%2d  ", i);
    printf("\nConjunto B: ");
    for(i=0; i<point; i++)
        if(sol[i]==1)
            printf("%2d  ", i);
    printf("\n");
}


int randomMinMax(int min, int max){
    return min + rand() % (max-min+1);
}

void display_grid(int *matriz, int point){
    for (int i = 0; i < point; ++i) {
        puts("\n");
        for (int j = 0; j < point; ++j) {
            printf("%d ", matriz[i*point + j]);
        }
    }
}