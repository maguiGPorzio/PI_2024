/*
Escribir una función que reciba una matriz cuadrada de dimensión N 
(N es una constante previamente definida) y retorne 1 si la misma cumple con 
las siguientes condiciones:
1) Contiene todos los números de 1 a N * N inclusive
2) En cada fila contiene números consecutivos, no necesariamente ordenados

CHECKED
*/
#include <stdio.h>
#define N 5

int correctMat (unsigned int mat[][N]);
int valFila(const unsigned int v[],int fila);

int 
main (){
    unsigned int mat1[][N]={{1,3,2,4,5},{7,6,9,8,1},{12,11,14,13,15},{18,17,16,20,19},{22,23,25,24,21}};
    printf("%d\n",correctMat(mat1));
    return 0;
}


int
correctMat (unsigned int mat[][N]){
    int ok=1;
    for (int i=0 ; (i<N) && ok ; i++){
        ok=valFila(mat[i],i);
    }
    return ok;
}

int 
valFila(const unsigned int v[],int fila){
    int aux[N]={0};
    for (int i=0 ; i<N ; i++){
        if (((v[i]-N*fila)>N) || (v[i]-N*fila)<1){
            return 0;
        }
        if (aux[(v[i]-N*fila)-1]==0){
            aux[(v[i]-N*fila)-1]=1;
        }
        else{
            return 0;
        }
    }
    return 1;
}