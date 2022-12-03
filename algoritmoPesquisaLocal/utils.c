#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

//inicializa gerador random numbers
void init_rand()
{
    srand((unsigned)time(NULL));
}

int* init_dados(char *nome)
{
    FILE *file;
    int num;
    char oi;
    file=fopen(nome, "r");
    if(!file)
    {
        printf("Erro no acesso ao ficheiro dos dados\n");
        exit(1);
    }else{
        printf("Está a funcionar!\n");
        // teste
        fscanf(file, " %c %d", &oi, &num);
        printf("%c %d", oi, num);
    }
}