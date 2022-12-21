#ifndef ALGORITMOEVOLUTIVO_FUNCAO_H
#define ALGORITMOEVOLUTIVO_FUNCAO_H

float eval_individual(int sol[], struct info d, int *mat, int *v, int k);

void evaluate(pchrom pop, struct info d, int *mat, int k);

#endif //ALGORITMOEVOLUTIVO_FUNCAO_H
