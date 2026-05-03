#include "magicSquare.h"

void readNumber(int *number){
    int error;
    do{
        printf("\nWrite an odd number lower/equal to 15: ");
        scanf("%d", number);
    }while(*number%2==0||*number<=1||*number>15);

}

matInt* createSquare(int n){
    matInt *matrix = (matInt*) malloc(sizeof(matInt));
    if (matrix == NULL) return NULL; 

    matrix->n=n;

    int **v;
    v=(int **)malloc(n*sizeof(int *));
    matrix->m=v;

    for(int i = 0; i < n; i++){
        matrix->m[i] = (int *) malloc(n * sizeof(int));
          for(int j = 0; j < n; j++){
            matrix->m[i][j] = -1;
        }
    }
    return matrix;
 }

void fillSquare(matInt *matrix){
    int **m=matrix->m;
    int n=matrix->n;
    int number=1;
    int j=n/2;
    for(int i=0; i>=0; i--){
        if((number)%n-1==0 && number!=1){
            i=i+2;
            if(i>=n) i=i-n;
            m[i][j]=number;
            number++;
            j++;
        }
        else{
        m[i][j]=number;
        if(number%n!=0) j++;
        number++;
        }
        
        if(j==n) j=0;
        if(i<1) i=n;
        if(number==n*n+1) break;
    }

    printf("\nThe magic square for number %d is:\n", n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%6d", m[i][j]);
        }
        printf("\n");
    }
}
void destroySquare(matInt *matrix, int order){
    for(int i=order-1; i>=0; i--){
        free(matrix->m[i]);
    }
    free(matrix->m);
    free(matrix);
}

 int main(){
    matInt *matrix;
    int order;
    readNumber(&order);
    matrix=createSquare(order);
    fillSquare(matrix);
    destroySquare(matrix, order);
}