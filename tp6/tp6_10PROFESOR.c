#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

#define FILAS 20
#define COLUMNAS 60

/* Generar una matriz con valores al azar */
void generaMatriz(int cielo[][COLUMNAS], int filas, int columnas);

/* Dada una matriz que representa una zona estelar, 
** grafica las estrellas en salida estandar */
void graficar (const int cielo[][COLUMNAS], int filas, int columnas);

int
main (void) {
	int cielo[FILAS][COLUMNAS];

	/* Setear la semilla de números aleatorios */
	randomize();

	generaMatriz(cielo, FILAS, COLUMNAS);
	graficar(cielo, FILAS, COLUMNAS);
	return 0;
}


void 
generaMatriz(int cielo[][COLUMNAS], int filas, int columnas) {
	int i, j;

	/* Generar una matriz en forma aleatoria */
	for (i = 0; i< filas; i++)
		for (j = 0; j < columnas; j++)
			cielo[i][j] = randInt(0, 20);
}


void
graficar (const int cielo[][COLUMNAS], int filas, int columnas) {
        int  suma;

        for (int i = 1; i < filas-1; i++) {
                printf("\n ");
                for (int j = 1; j < columnas-1; j++)
                {
                        suma = 0;
                        for (int k = -1; k <= 1; k++)
                                for (int m = -1; m <= 1; m++)
                                        suma += cielo[i+k][j+m];
                        if (suma / 9 > 10 )
                                putchar('*');
                        else
                                putchar(' ');
                }
        }
        putchar('\n');
}