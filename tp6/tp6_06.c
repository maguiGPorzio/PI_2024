/*
Dado un arreglo ordenado ascendentemente se pide escribir una función que reciba como parámetro de 
entrada/salida el arreglo y como parámetro de entrada su dimensión y que lo devuelva desordenado, 
simulando la mezcla de un mazo de cartas o de un bolillero (en no más de 10 líneas).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randNormalize();
int randInt(int left, int right);
void desordenarVector(int vecDes[],int dim);

int 
main (){
    double vec[7]={1,4,2.3,5,7.8,4,5.6};
    int dim=7;
    desordenarVector(vec,dim);
    printf("%g\n",vec[0]);
    printf("%g\n",vec[1]);
    printf("%g\n",vec[2]);
    printf("%g\n",vec[3]);
    printf("%g\n",vec[4]);
    printf("%g\n",vec[5]);
    printf("%g\n",vec[6]);
    return 0; 
}

void 
desordenarVector(int vecDes[],int dim){
    srand ((int)time(NULL));
    int valorActual;
    int posicion;
    for (int i=0 ; i<dim ; i++){
        valorActual=vecDes[i];
        posicion=randInt(0,dim-1);
        vecDes[i]=vecDes[posicion];
        vecDes[posicion]=valorActual;
    } 
}

// Función para generar un número aleatorio normalizado en [0,1) 
double randNormalize(){
    return rand () / ((double) RAND_MAX+1);
}

// Función para generar un número entero aleatorio en el rango [left, right]
int randInt(int left, int right){
    return ((int)(randNormalize()*(right-left+1)) + left);
}
