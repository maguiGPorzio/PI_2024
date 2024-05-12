/*Dada una matriz cuadrada de dimensión M -donde M es una constante simbólica par
mayor a cero previamente definida (por ejemplo 2, 4, 6, etc.)-, se desea calcular la suma de
cada uno de sus bordes. Se considera como un borde a un contorno de la matriz.
El primer borde estaría conformado por la primer y última fila junto a la primer y
última columna, el segundo borde por la segunda y anteúltima fila junto a la segunda y
anteúltima columna, y continuando así hasta llegar al centro de la matriz, formado por un
cuadrado de 2x2.

Escribir la función bordes que reciba:
● una matriz mat de enteros de dimensión M (no se debe validar que M sea par positivo,
asumir que cumple con esa condición)
● un vector sumas de enteros no inicializado con al menos M/2 posiciones reservadas

La función debe dejar en sumas[i] la suma del borde i, para todo i en [0, M/2).
En el ejemplo anterior el vector sumas debe quedar con los valores { 20, 24, 12 },
ya que el primer borde está formado por 20 celdas con el valor 1, el segundo borde por 12
celdas con el valor 2 y el tercer borde (el centro) por 4 celdas con el valor 3.
*/
#include <stdio.h>
#define M 6

void
bordes (int mat[][M], int sumas[]);
int
sumaBorde(int mat[][M], int borde);

int main(void)
{
  int mat[M][M] = {
      {1, 1, 1, 1, 1, 1},
      {1, 2, 2, 2, 2, 1},
      {1, 2, 3, 3, 2, 1},
      {1, 2, 3, 3, 2, 1},
      {1, 2, 2, 2, 2, 1},
      {1, 1, 1, 1, 1, 1}
  };
  int borders[M / 2];

  bordes(mat, borders);

  for (unsigned int i = 0; i < M / 2; i++)
  {
    printf("Border %d: %d\n", i, borders[i]);
  }

  return 0;
}

void
bordes (int mat[][M], int sumas[]){
    for (int i=0 ; i*2<M ; i++){
        sumas[i]=sumaBorde(mat,i);
    }
}

int
sumaBorde(int mat[][M], int borde){
    int k=M-borde-1, suma=0;
    for (int i=borde ; i<=k ; i++){
        suma+=mat[borde][i]+mat[k][i];
        if (i>borde && i<k){
            suma+=mat[i][borde]+mat[i][k];
        }
    }
    return suma;
}