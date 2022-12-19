#ifndef ALGORITMOEVOLUTIVO_ALGORITMO_H
#define ALGORITMOEVOLUTIVO_ALGORITMO_H

#define MAX_OBJ 500		// Numero maximo de objectos

// EStrutura para armazenar parametros
struct info
{
    // Tamanho da população
    int     popsize;
    // Probabilidade de mutação
    float   pm;
    // Probabilidade de recombinaçãoo
    float   pr;
    // Tamanho do torneio para seleção do pai da próxima geração
    int     tsize;
    // Número de objetos que se podem colocar na mochila
    int     numMochila;
    // Número de gerações
    int     numGenerations;
};

// Individuo
typedef struct individual chrom, *pchrom;

struct individual
{
    // Soluçãoo (objetos que estão dentro da mochila)
    int     mochila[MAX_OBJ];
    // Valor da qualidade da solução
    float   fitness;
    // 1 se for uma solução válida e 0 se não for
    int     valido;
};


#endif //ALGORITMOEVOLUTIVO_ALGORITMO_H
