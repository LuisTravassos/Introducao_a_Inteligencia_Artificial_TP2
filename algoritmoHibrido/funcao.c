#include "funcao.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int calculaFit(int a[], int *mat, int point, int k) {
    int total=0;
    int x, y;

    for(int i=0; i < k-1; i++){     //kValue vezes
        for(int j = k-1; j > i; j--){  //kvalue vezes
            x=a[i];
            y=a[j];
            if( *(mat + x*point + y)==1 ){
                total++;
            }
        }
    }
    return total;
}

//COrrigir valores alterarados incorretamente em genetic_operators
void correction(int son[], int sonB[], int point, int k) {
    int g, counter=0;

    for (int i=0; i<point; i++){
        counter=0;
        for (int j=0; j<point; j++){
            if(sonB[j] == 1){
                counter++;
            }
        }

        while(counter != k){
            if(counter > k){
                do{
                    g = randomMinMax(0, point-1);
                }while(sonB[g] == 0);
                sonB[g] = 0;
                counter--;
            }
            if(counter < k){
                do{
                    g = randomMinMax(0, point-1);
                }while(sonB[g] == 1);
                sonB[g] = 1;
                counter++;
            }
        }
    }

    for(int i=0, count = 0; i < point; i++){
        if(sonB[i]==1){
            son[count]=i;
            count++;
        }
    }
}

void binaryTransform(int sol[], int solB[], int point, int k) {

    for(int i=0; i<point; i++){
        solB[i]=0;
    }
    for(int i=0; i < k; i++)
    {
        solB[sol[i]]=1;
    }

}