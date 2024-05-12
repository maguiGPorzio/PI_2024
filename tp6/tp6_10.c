/*
matriz bidimensional de hasta 80 columnas por 20 filas

Cada elemento de la misma representa la cantidad de luz que hay en una zona del cielo con un rango de intensidad entre 0 y 20

En el lugar de coordenadas (i,j) del cielo se considera que hay una estrella si el elemento Aij 
correspondiente  cumple con la siguiente relación:
( A[i,j] + suma de las ocho intensidades circundantes ) / 9 > 10    (hacer las cuentas como int)

Escribir una función (en no más de 15 líneas) que reciba tres parámetros de entrada representando a una matriz de
dichas características y sus dimensiones. Dicha función debe localizar gráficamente las estrellas en la pantalla
dichas características y sus dimensiones. Dicha función debe localizar gráficamente las estrellas en la pantalla
*/
#include <stdio.h>
#include "random.h"
#include <time.h>
#include <stdlib.h>
#define COLUMNAS 30
#define FILAS 10
#define MAX(m,n) (((m) > (n)) ? (m) : (n))
#define MIN(m,n) (((m) < (n)) ? (m) : (n))

void matAleat (int mat[][COLUMNAS],unsigned fil, unsigned col);
int sumCirc ( int cielo[][COLUMNAS], int filas, int columnas, int filActual, int colActual);
void graficar ( int cielo[][COLUMNAS], int filas, int columnas);

int
main (){
    int cielo[FILAS][COLUMNAS];
    matAleat(cielo,FILAS,COLUMNAS);
    for (int i=0 ; i<FILAS ; i++){
        for (int j=0 ;  j<COLUMNAS ; j++){
            printf("%4d",cielo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    graficar(cielo,FILAS,COLUMNAS);
}

void
matAleat (int mat[][COLUMNAS],unsigned fil, unsigned col){
    srand ((int)time(NULL));
    for (int i=0 ; i<fil ; i++){
        for (int j=0 ; j<col ; j++){
            mat[i][j]=randInt(0,20);
        }
    }
}

/*
{{a,b,c,d}
{e,f,g,h}
{i,j,k,l}
{m,n,o,p}}
*/

int 
sumCirc(int cielo[][COLUMNAS], int filas, int columnas, int filActual, int colActual){
    int sumCirc=0;
    for (int i=MAX(filActual-1,0) ; i<=MIN(filActual+1,filas-1) ; i++){
        for (int j=MAX(colActual-1,0) ; j<=MIN(colActual+1,columnas-1) ; j++){
            sumCirc+=cielo[i][j];
        }
    }
    return sumCirc;
}

void 
graficar (int cielo[][COLUMNAS], int filas, int columnas){
    for (int i=0 ; i<filas ; i++){
        for (int j=0 ; j<columnas ; j++){
            int esEstrella=sumCirc(cielo,filas,columnas,i,j)/9;
            if (esEstrella>10){
                printf("%c",'*');
            }
            else{
                printf("%c",' ');
            }  
        }
        printf("\n");
    }
}