#include <stdio.h>

// Para la prueba, como armamos matrices de prueba, acotamos a 10 filas por 30 columnas
#define FILAS 10
#define COLUMNAS 30
#define MAX(m,n) (((m) > (n)) ? (m) : (n))
#define MIN(m,n) (((m) < (n)) ? (m) : (n))


/* Dada una matriz que representa una zona estelar, 
** grafica las estrellas en salida estandar */
void graficar ( int cielo[][COLUMNAS], int filas, int columnas);
int sumCirc (int cielo[][COLUMNAS], int filas, int columnas, int filActual, int colActual);

int
main (void) {
	int cielo1[FILAS][COLUMNAS] = {{0}};

	puts("A continuación debe mostrar 8 filas en blanco");

	graficar(cielo1, FILAS, COLUMNAS);
	puts("-----------------------------");

	
	int cielo2[FILAS][COLUMNAS] = {
		{10, 17, 6, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 11, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 13, 11, 3, 9, 20},
		{18, 17, 6, 5, 6, 7, 8, 9, 11, 12, 13, 5, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 13, 11, 3, 9, 20},
		{10, 15, 16, 15, 6, 17, 8, 19, 11, 12, 13, 1, 8, 10, 11, 1, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{12, 2, 6, 5, 16, 7, 8, 9, 1, 12, 13, 15, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{8, 5, 4, 15, 6, 7, 8, 9, 12, 12, 13, 5, 8, 10, 11, 13, 14, 15, 18, 20, 11, 8, 12, 3, 12, 23, 11, 3, 9, 20},
		{20, 19, 18, 15, 16, 7, 8, 9, 11, 12, 13, 15, 18, 10, 11, 13, 14, 15, 18, 20, 11, 8, 12, 3, 12, 23, 11, 3, 9, 20},
		{10, 9, 9, 15, 16, 7, 8, 9, 12, 12, 13, 11, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 13, 12, 23, 11, 3, 9, 20},
		{10, 12, 9, 6, 16, 7, 8, 9, 15, 12, 13, 15, 18, 10, 11, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{10, 7, 9, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 1, 10, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{10, 17, 16, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 11, 3, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
	};

	puts("A continuación su función debe mostrar esto:");
	puts(" **     **      *****    *");
 	puts(" *              *****   ***");
	puts("         *      *****   ***");
	puts("   *     ****  ******   ***");
	puts(" ****    ***   ******   ***");
	puts(" ****   *****  ******   ***");
	puts("   *    *****   *****   ***");
	puts(" **     *****   *****   ***");

	puts("-----------------------------");
	puts("Y muestra esto:");
	graficar(cielo2, FILAS, COLUMNAS);
	puts("-----------------------------");

	return 0;
}

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