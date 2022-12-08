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

void geraSolIni(int *sol, int point, int k){
    int *temp = malloc(sizeof(int)*point);  //nPoints de tamanho
    int x;

    for(int i=0; i<point; i++)
        temp[i]=0;
    for(int i=0; i < k; i++)
    {
        do {
            x = randomMinMax(0, point - 1);
        }while(temp[x] == 1);
        temp[x]=1;
    }

    for(int i=0, count = 0; i < point; i++){
        if(temp[i]==1){
            sol[count]=i;
            count++;
        }
    }
    free(temp);
}

void escreveSol(int *sol, int k){
    printf("\nSolucao: ");  //Usa-se os primeiros 8 indices com 1 no array sol como solução
    for(int i=0; i < k; i++){
        printf("%2d  ", sol[i]);
    }
    printf("\n");
}


int randomMinMax(int min, int max){
    return min + rand() % (max-min+1);
}

//Verifica se existe um valor igual já no array
int verify(int b[], int k, int p){
    for(int i=0; i < k; i++){
        if(b[i] == p){
            return 1;   //invalido
        }
    }
    return 0;   //valido
}

// copia vector b para a (tamanho n)
void substitui(int a[], int b[], int k){
    int i;
    for(i=0; i<k; i++)
        a[i]=b[i];
}

void display_grid(int *matriz, int point){
    for (int i = 0; i < point; ++i) {
        puts("\n");
        for (int j = 0; j < point; ++j) {
            printf("%d ", matriz[i*point + j]);
        }
    }
    puts("\n");
}