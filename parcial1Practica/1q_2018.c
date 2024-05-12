/*
Ejercicio 1
Escribir una función que, dada una matriz de N filas y N columnas determine si es un “cuadrado
mágico”.
Una matriz es cuadrado mágico cuando:
● es cuadrada (NxN) (donde N es una constante simbólica)
● tiene todos los números del 1 al N^2
● la suma de los elementos de cualquier fila es igual a la suma de los elementos de cualquier
columna

CHECKED
*/
#include <stdio.h>
#define N 4

int
CuadradoMagico (int mat[][N]);
int
sumEleFil (const int vec[],int vec1[]);
int 
sumEleCol (int mat[][N],int j);

int main(int argc, char const *argv[])
{
    int m[N][N]={{16,3,2,13},{5,10,11,8},{9,6,7,12},{4,15,14,1}};
    printf ( "%d\n", CuadradoMagico(m));
    return 0;
}

int
CuadradoMagico (int mat[][N]){
    int vec[N*N]={0}, i=0, sumFil, sumCol;
    int aux1=sumEleFil(mat[i],vec),aux2=sumEleCol(mat,i);
    if (aux1!=aux2 && aux1==0){
        return 0;
    }
    for (i=1 ; i<N ; i++){
        sumFil=sumEleFil(mat[i],vec);
        sumCol=sumEleCol(mat,i);
        if (aux1!=sumFil || aux1!=sumCol){
            return 0;
        }
    }
    return 1;
}

int
sumEleFil (const int vec[],int vec1[]){
    int sum=0;
    for (int i=0 ; i<N ; i++){
        if (vec[i]<1 || vec[i]>N*N || vec1[vec[i]-1]==1){
            return 0;
        }
        vec1[vec[i]-1]=1;
        sum+=vec[i];
    }
    return sum;
}

int 
sumEleCol (int mat[][N],int j){
    int sum=0;
    for (int i=0 ; i<N ; i++){
        sum+=mat[i][j];
    }
    return sum;
}