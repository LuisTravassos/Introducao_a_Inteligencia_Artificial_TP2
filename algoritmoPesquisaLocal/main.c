#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define DEFAULT_RUNS 10;

int main(int argc, char *argv[]) {
    char path[] = "../../TestFiles/";
    char nome_fich[100];
    int runs;

    if (argc == 3) {
        runs = atoi(argv[2]);
        strcpy(nome_fich, argv[1]);
        strcat(path, nome_fich);
    } else if (argc == 2) {
        runs = DEFAULT_RUNS
        strcpy(nome_fich, argv[1]);
        strcat(path, nome_fich);
    } else {
        runs = DEFAULT_RUNS
        printf("Nome do Ficheiro: ");
        gets(nome_fich);
        strcat(path, nome_fich);
    }
    if(runs <= 0){
        return 0;
    }
    init_rand();
    init_dados(path);
}