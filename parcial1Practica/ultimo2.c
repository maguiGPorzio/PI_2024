/*
Escribir una función que, dada una matriz de enteros de N filas y M columnas, arme los números que se
forman con cada fila y retorne cuál es el máximo. Para poder armar un número con los elementos de una fila,
todos sus elementos deben contener un número entero entre 0 y 9 inclusive.
Si hubiera números negativos o de más de una cifra, no se completa el armado del número.
Si no se pudo armar ningún número, retorna -1.
*/

#include <stdio.h>
#define N 4
#define M 4

int
maxNum (int mat[][M]);
int
armaNum(int vec[]);

int main() {
    int matriz[N][M] = {
        {10, 71, 31, 41},
        {5, 6, 7, 8},
        {9, 0, 1, 21},
        {3, 4, 9, 6}
    };

    int resultado = maxNum(matriz);

    if (resultado == -1) {
        printf("No se pudo armar ningún número.\n");
    } else {
        printf("El número máximo armado es: %d\n", resultado);
    }

    return 0;
}

int
maxNum (int mat[][M]){
    int aux=armaNum(mat[0]), num;
    for (int i=1 ; i<N ; i++){
        num=armaNum(mat[i]);
        if (num>aux){
            aux=num;
        }
    }
    return aux;
}

int
armaNum(int vec[]){
    int num=0;
    for (int i=0 ; i<M ; i++){
        if (vec[i]<0 || vec[i]>9){
            return -1;
        }
        num*=10;
        num+=vec[i];
    }
    return num;
}
