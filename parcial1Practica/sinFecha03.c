/*
Escribir la función checkBoard que recibe como único parámetro una matriz cuadrada de dimensión DIM 
(es una constante simbólica previamente definida) y retorne 1 cuando la matriz representa un tablero 
válido de un juego al estilo ajedrez o dama. 
Un tablero es válido cuando cumple ambas condiciones mencionadas a continuación:
No existen dos posiciones adyacentes (tanto en forma horizontal o vertical) del mismo color
Sólo se utilizaron dos colores en todo el tablero

Los posibles colores están dados por el enum colors. 
Se garantiza que en la matriz estarán únicamente los valores del enum colors, no es necesario validarlo.


CHECKED
*/
#include <assert.h>
#include <stdio.h>
#define DIM 4
#define MAX(n,m)  ((m)>(n)) ? (m) : (n)
#define MIN(n,m)  ((m)<(n)) ? (m) : (n)

int checkBoard(unsigned char mat[][DIM]);

typedef enum colors {black=0, white, blue, red, purple, orange};

int 
main(void) {
   unsigned char t[DIM][DIM] = { 
           {black, white, black, white},
           {white, black, white, black},
           {black, white, black, white},
           {white, black, white, black}};
   // Es un tablero válido
   assert(checkBoard(t) == 1);

   unsigned char t2[DIM][DIM] = { 
           {black, white, black, white},
           {white, black, white, black},
           {black, white, black, white},
           {white, black, white, blue}};
   // No es válido pues se usaron más de dos colores
   assert(checkBoard(t2) == 0); 
   
   unsigned char t3[DIM][DIM] = { 
           {black, white, black, white},
           {white, black, white, black},
           {white, black, white, black},
           {black, white, black, white}};
   // No es válido pues hay dos posiciones adyacentes del mismo color
   assert(checkBoard(t3) == 0);

    printf("OK\n");
   return 0;
}

int checkBoard(unsigned char mat[][DIM]){
    int i=0;
    int aux1=mat[i][0], aux2=mat[i][1];
    if (aux1==aux2)
        return 0;
    for (; i<DIM ; i++){
        for (int j=0; j<DIM ; j++){
            if (((j+i)%2==0 && mat[i][j]!=aux1) || ((j+i)%2!=0 && mat[i][j]!=aux2))
                return 0;
        }
    }
    return 1;
}