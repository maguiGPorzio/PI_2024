/*
Escribir una función que reciba un arreglo de números enteros positivos y mezclesus elementos. 
La cantidad de elementos del arreglo se pasa mediante unsegundo parámetro entero.

¿Cómo cambiaría el programa si no se pasara el segundo parámetro y 
se indicarala finalización del arreglo mediante un elemento con el valor -1?

*/
#include <stdio.h>
#include "random.h"
#include <time.h>

int
main (){
    mezclar({3,5,7,9,15},5);
    return 0;
}

void 
mezclar(int arr[], int dim){
    srand ((int)time(NULL));
    int i=0, aux1, h;
    while (i<dim){
        aux1=arr[i];
        h=randInt(0,dim-1);
        arr[i]=arr[h];
        arr[h]=aux1;
        i+=1
    }
    return;
}

void 
mezclarConFin (int arr[]){ \\con marca de fin
    srand ((int)time(NULL));
    for (int i=0 ;  v[i]!=EOF ; i++){
        int h=randInt(0,i);
        int aux1=arr[i];
        arr[i]=arr[h];
        arr[h]=aux1;
    }
    return;
}