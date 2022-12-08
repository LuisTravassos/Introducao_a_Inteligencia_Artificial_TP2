#include "funcao.h"
#include <stdio.h>

int calculaFit(int a[], int *mat, int point, int k)
{
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