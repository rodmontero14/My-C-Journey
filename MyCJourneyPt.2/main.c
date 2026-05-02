#include "matrix.h"

void ReadMatrix(Intmatrix *matrix){
    do{
    printf("\nEnter the matrix number of rows:  ");
    scanf("%d", &(*matrix).NumRow);
    }while((*matrix).NumRow<=0);
    do{
    printf("\nEnter the matrix number of columns:  ");
    scanf("%d", &(*matrix).NumCol);
    }while((*matrix).NumCol<=0);
    

}

int  *CreateMatrix(Intmatrix *matrix){
    matrix->m= malloc((sizeof (int))*matrix->NumRow*matrix->NumCol);
    if(matrix->m==NULL) return NULL;
    return matrix->m;

}

Intmatrix  CreateSubMatrix(int order){
    Intmatrix Submatrix;
    Submatrix.NumRow=order;
    Submatrix.NumCol=order;
    Submatrix.m= malloc((sizeof (int))*order*order);
    if(Submatrix.m==NULL){
        printf("Error in memory allocation");
        exit(-1); 
      }
    return Submatrix;

}

void FillMatrix(int *matrix, int dimMat){
    printf("\nTime to fill the matrix with numbers.");
    for(int *i=matrix; i<matrix+dimMat; i++){
    printf("\nIntroduce a number: ");
    scanf("%d", i);
    }
    
}

void CoordinateError(Coordinates *coordinate, Intmatrix *matrix, int *error){
    *error=0;
    if(coordinate->i>=matrix->NumRow){
        *error=1;
    }
    else if(coordinate->j>=matrix->NumCol){
        *error=2;
    }
    else if(coordinate->i<0){
        *error=3;
    }
    else if(coordinate->j<0){
        *error=4;
    }
}

void ReadCoordinates(Coordinates *coordinate, Intmatrix *matrix, int *error){
    do{
        printf("\nEnter the coordinate row number:  ");
        scanf("%d", &coordinate->i);
        printf("\nEnter the coordinate column number:  ");
        scanf("%d", &coordinate->j);    
        CoordinateError(coordinate, matrix, error);

        if(*error==1){
            printf("\nRow coordinates are out of the matrix. Introduce new coordinates: ");
        } 
        else if(*error==2){
            printf("\nColumn coordinates are out of the matrix. Introduce new coordinates: ");
        }
        else if(*error==3){
            printf("\nRow coordinates are smaller or equal to 0, introduce them again: ");
        } 
        else if(*error==4){
            printf("\nColumn coordinates are smaller or equal to 0, introduce them again: ");
        }
    }while(*error!=0);
    

}

int *FindSymmetricSubmatrix(Intmatrix *matrix, Coordinates *coordinate, int * MatMem, int dimMat){
    int *m=MatMem;
    int NumRow=matrix->NumRow;
    int NumCol=matrix->NumCol;
    int order;
    if(NumRow-coordinate->i<=NumCol-coordinate->j) order=NumRow-coordinate->i;
    else order=NumCol-coordinate->j;

    Intmatrix MiSubmatriz = CreateSubMatrix(order);
    int *SubMatMem = MiSubmatriz.m;
    int *SubMatMemInitial=SubMatMem;

    printf("\nThe square submatrix starting from the provided coordinates is: ");
    for(int i=coordinate->i; i<coordinate->i+order; i++){
        printf("\n");
        for(int j=coordinate->j; j<coordinate->j+order; j++){
            int linealPosition = (i * NumCol) + j;
            int dynamicPosition = m[linealPosition];
            *SubMatMem=m[linealPosition];
            printf("%d   ", *SubMatMem);
            SubMatMem++;
        }
    }
    return SubMatMemInitial;
}

int main(){
    int error;
    int *MatMem;
    Intmatrix matrix;
    Coordinates coordinate;

    ReadMatrix(&matrix);
    ReadCoordinates(&coordinate, &matrix, &error);

    int dimMat=(matrix.NumRow*matrix.NumCol);
    MatMem=CreateMatrix(&matrix);
    if(MatMem==NULL){
        printf("Error in dynamic memory alloc");
        return -1;
    }

    FillMatrix(MatMem, dimMat);

    int *SubMatrixDirection=FindSymmetricSubmatrix(&matrix, &coordinate, MatMem, dimMat);

    free(MatMem);
    free(SubMatrixDirection);
    return 0;
}