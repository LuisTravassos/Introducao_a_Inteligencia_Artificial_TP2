#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "utils.h"

void tournament(pchrom pop, struct info d, pchrom parents){
    int x1, x2;

    // Realiza popsize torneios
    for (int i=0; i<d.popsize;i++) {
        x1 = randomMinMax(0, d.popsize - 1);
        do {
            x2 = randomMinMax(0, d.popsize - 1);
        }while (x1==x2);

        if (pop[x1].fitness > pop[x2].fitness)		// Problema de maximizacao
            parents[i] = pop[x1];
        else
            parents[i] = pop[x2];
    }
}


void genetic_operators(pchrom parents, struct info d, pchrom offspring){
    // Recombina��o com um ponto de corte
    crossover(parents, d, offspring);
    // Recombina��o com dois pontos de corte
    // Exerc�cio 4.4(a)
    //recombinacao_dois_pontos_corte(parents, d, offspring);

    // Recombina��o uniforme
    // Exerc�cio 4.4(b)
    //recombinacao_uniforme(parents, d, offspring);


    // Muta��o bin�ria
    mutation(offspring, d);
    // Muta��o por troca
    // Exerc�cio 4.3
    //mutacao_por_troca(offspring, d);
}

void crossover(pchrom parents, struct info d, pchrom offspring){
    int point;

    for (int i=0; i<d.popsize; i+=2)
    {
        if (randomMinMax(1,100) < d.pr)
        {
            point = randomMinMax(0, d.numMochila);
            for (int j=0; j<point; j++)
            {
                offspring[i].mochila[j] = parents[i].mochila[j];
                offspring[i+1].mochila[j] = parents[i+1].mochila[j];
            }
            for (int j=point; j<d.numMochila; j++)
            {
                offspring[i].mochila[j]= parents[i+1].mochila[j];
                offspring[i+1].mochila[j] = parents[i].mochila[j];
            }
        }
        else
        {
            offspring[i] = parents[i];
            offspring[i+1] = parents[i+1];
        }
    }
}

void mutation(pchrom offspring, struct info d){

    for (int i=0; i<d.popsize; i++){
        for (int j=0; j<d.numMochila; j++){
            if (randomMinMax(1,100) < d.pm){
                offspring[i].mochila[j] = !(offspring[i].mochila[j]);
            }
        }
    }
}

//COrrigir valores alterarados incorretamente em genetic_operators
void correction(pchrom offspring, struct info d, int k){
    int g, counter=0;
    for (int i=0; i<d.popsize; i++){
        counter=0;
        for (int j=0; j<d.numMochila; j++){
            if(offspring[i].mochila[j] == 1){
                counter++;
            }
        }
        while(counter != k){
            if(counter > k){
                do{
                    g = randomMinMax(0, d.numMochila-1);
                }while(offspring[i].mochila[g] == 0);
                offspring[i].mochila[g] = 0;
                counter--;
            }
            if(counter < k){
                do{
                    g = randomMinMax(0, d.numMochila-1);
                }while(offspring[i].mochila[g] == 1);
                offspring[i].mochila[g] = 1;
                counter++;
            }
        }
    }
}

