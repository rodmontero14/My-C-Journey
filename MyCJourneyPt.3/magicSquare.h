#ifndef MAGIC_SQUARE
#define MAGIC_SQUARE

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 15

typedef struct matInt {
    int **m;
    int n;
} matInt;

matInt* createSquare(int n);

void fillSquare(matInt *matrix);

void destroySquare(matInt *matrix, int order);

#endif