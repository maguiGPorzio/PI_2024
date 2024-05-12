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
sumFil(const int matVec[],int vec[]);
int 
sumCol (int mat[][N], int col);

int main(int argc, char const *argv[])
{
    int m[N][N]={{16,3,2,13},{5,10,11,8},{9,6,7,12},{4,15,14,1}};
    printf ( "%d\n", CuadradoMagico(m));
    return 0;
}

int
CuadradoMagico (int mat[][N]){
    int vec[N*N]={0}; //vector de apariciones
    int aux1=sumFil(mat[0],vec), aux2=sumCol(mat,0);
    if (aux1!=aux2 || aux1==0){
        return 0;
    }
    for (int i=1 ; i<N ; i++){
        if (sumFil(mat[i],vec)!=aux1 || sumCol(mat,i)!=aux1){
            return 0;
        }

    }
    return 1;

}

int 
sumFil(const int matVec[],int vec[]){
    int sum=0;
    for (int i=0 ; i<N ; i++){
        if (matVec[i]<1 || matVec[i]>N*N || vec[matVec[i]-1]==1){
            return 0;
        }
        vec[matVec[i]-1]=1;
        sum+=matVec[i];
    }
    return sum;
}

int 
sumCol (int mat[][N], int col){
    int sum=0;
    for (int i=0 ; i<N ; i++){
        sum+=mat[i][col];
    }
    return sum;
}

