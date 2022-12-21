#ifndef ALGORITMOEVOLUTIVO_UTILS_H
#define ALGORITMOEVOLUTIVO_UTILS_H

void initRand();

int initData(char *filename, int *mat, struct info *x);

void displayGrid(int *grafo, int vert);

pchrom initPop(struct info d, int k);

int randomMinMax(int min, int max);

chrom get_best(pchrom pop, struct info d, chrom best);

void writeBest(chrom x, struct info d);

#endif //ALGORITMOEVOLUTIVO_UTILS_H
