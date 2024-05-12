/*
Escribir una función que reciba un vector desordenado de números enteros y su dimensión, y construya 
otro vector eliminando los valores repetidos. La función deberá retornar en su nombre la dimensión del 
nuevo vector (La función solicitada  no debe superar las 10 líneas).
*/

#include <stdio.h>
#define NO 0
#define SI 1

/* 
int
estaRepetido(const int arr[], int elem, int dim){
    for (int i=elem+1 ; i<dim ; i++){
        if (arr[elem]==arr[i])
        return SI;
    }
    return NO;
}

int
eliminaRepetidos(const int original[], int dimOrig, int resultado[]){
    int dimNuevo=0;
    for (int i=0 ; i<dimOrig ; i++){
        if (!estaRepetido(original,i,dimOrig)){
            resultado[dimNuevo++]=original[i];
        }
    }
    return dimNuevo;
}

int
main (){
    int v[] = { 3, 5, 1, 3, -3, 3, 5, 1};
    int res[20];
    int dimRes;
    dimRes = eliminaRepetidos(v, 4, res);
    printf("%d\n",dimRes==3);
    printf("%d\n",res[0]);
    printf("%d\n",res[1]);
    printf("%d\n",res[2]);
    return 0;
}
*/

int
presenciaElemento (int ele, int resultado[], int dimNuevo){
    for (int posNuevo=0 ; posNuevo<dimNuevo ; posNuevo++){
        if (ele==resultado[posNuevo]){
            return 1;
        }
    }
    return 0;
}

int
eliminaRepetidos( const int original[], int dimOrig, int resultado[]){
    int posOriginal;
    int dimNuevo=0;
    for (posOriginal=0 ; posOriginal<dimOrig ; posOriginal++){
        if (!presenciaElemento(original[posOriginal], resultado, dimNuevo)){
            resultado[dimNuevo++]=original[posOriginal];
        }
    }
    return dimNuevo;
}

