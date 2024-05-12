/*
Ejercicio 3:
a) Escribir una función que reciba como parámetros
• matriz: una matriz de enteros
• filas: la cantidad de filas reales de la matriz
• cols: la cantidad de columnas reales de la matriz
• fila: un número entero que indica la fila a tratar

La función debe completar con el valor 0 la fila indicada por el parámetro fila si la misma resulta de
sumar otro par de filas cualquiera.
La cantidad de columnas con la que se define la matriz está dada por la constante simbólica COLS
*/
#include <stdio.h>
#define COLS 4
#define NO_X(M,X) (((M)==(X)) ? ((++M)):(M))

void 
sum (int fil, int col, int mat[][col], int x);
int 
checkFils (const int fil1[], const int fil2[], const int fil3[], int col);

int
main (){
    int mat[][COLS]={{1,2,3,4},{5,6,7,8},{9,8,7,5},{6,8,10,12}};
    sum(4,4,mat,1);
    for (int i=0 ; i<4 ; i++){
        for (int j=0 ; j<4 ; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void 
sum (int fil, int col, int mat[][col], int x){
    int ok=0;
    for (int i=0 ; NO_X(i,x)<fil && !ok; i++){
        for (int j=i+1 ; NO_X(j,x)<fil && !ok; j++){
            ok=checkFils(mat[i],mat[j],mat[x],col);
        }
    }
    if (ok){
        for (int h=0 ; h<col ; h++){
            mat[x][h]=0;
        }
    }
}

int 
checkFils (const int fil1[], const int fil2[], const int fil3[], int col){
    for (int i=0 ; i<col ;i++){
        if ((fil1[i]+fil2[i])!=fil3[i]){
            return 0;
        }
    }
    return 1;
}



