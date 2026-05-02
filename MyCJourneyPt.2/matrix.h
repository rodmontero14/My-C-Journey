#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>


typedef struct Intmatrix{
    int *m;
    int NumRow, NumCol;
}Intmatrix;

typedef struct Coordinates{
    int i;
    int j;
}Coordinates;

void ReadMatrix(Intmatrix *matrix);

int  *CreateMatrix(Intmatrix *matrix);

Intmatrix  CreateSubMatrix(int order);

void FillMatrix(int *matrix, int dimMat);

void CoordinateError(Coordinates *coordinate, Intmatrix *matrix, int *error);

void ReadCoordinates(Coordinates *coordinate, Intmatrix *matrix, int *error);

int *FindSymmetricSubmatrix(Intmatrix *matrix, Coordinates *coordinate, int * MatMem, int dimMat);

#endif