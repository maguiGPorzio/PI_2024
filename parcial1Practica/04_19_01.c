/*
esAscendente
-reciba una matriz de enteros y determine si los elementos estan en forma ascendente 
-los elementos estan en orden ascendente si conservan ese orden recorriendo de izquierda a derecha y 
de arriba hacia abajo

si esta en orden ascendente --> devolver en un vector todos los elem de la matriz ordenados sin repetir 
en caso de no estarlo retornar cero
*/
#include <stdio.h>
#define DIM 4


int 
esAscendente (int mat[][DIM], int vec[]);

int
main(void){
    int m[][DIM] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int ordenados[DIM*DIM];
    int resultado = esAscendente(m, ordenados);
    for(int i = 0; i < resultado; i++)
        printf("%d ", ordenados[i]);
    return 0;
}

int 
esAscendente (int mat[][DIM], int vec[]){
    int asc=1, dimVec=0, anterior=mat[0][0], actual;
    vec[dimVec++]=anterior;
    for (int i=0 ; i<DIM && asc; i++){
        for (int j=0 ; j<DIM && asc; j++){
            actual=mat[i][j];

            if (actual<anterior || (i>0 && actual<mat[i-1][j])){
                return 0;
            }

            if (vec[dimVec-1]!=actual){
                vec[dimVec++]=actual;
            }

            anterior=actual;
        }
    }
    return dimVec;
}