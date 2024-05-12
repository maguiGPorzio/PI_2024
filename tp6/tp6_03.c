/*
Dado un arreglo lineal de números reales, cuyo indicador de fin de elementos es cero, 
escribir una función para obtener la mayor diferencia entre dos elementos consecutivos. (En no más de 5 líneas). 
Tener en cuenta que los números pueden ser negativos. 
En caso de que el vector tenga un solo elemento deberá retornar como diferencia el valor cero.
*/
#include <stdio.h>
#include "math.h"
#define EPSILON 0.00001

double
mayorDif (const double Arreglo[]){
    double maxDif=0, dif=0;
    int posicion=1;
    while (fabs(Arreglo[posicion])>EPSILON){
        dif=fabs(Arreglo[posicion-1]-Arreglo[posicion]);
        if (dif>maxDif){
            maxDif=dif;
        }
        posicion+=1;
    } 
    return maxDif;
}


