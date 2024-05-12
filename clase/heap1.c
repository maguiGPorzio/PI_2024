/*
Escribir una función que retorne un conjunto de números reales 
ingresados por el usuario en un arreglo. La cantidad de números no es 
constante sino que también debe ser solicitada al usuario. 
*/
#include <stdio.h>
#include <getnum.h>

float * 
readarray(int *dim){
    do{
        *dim=getint("Ingrese un numero entero: ");
    }
    while (*dim<0);
    float *v=malloc(*dim * sizeof(float));
    for (int i=0 ; i<*dim ; i++){
        *(v+i)=getfloat("Ingrese un numero punto flotante: ");
    }
    return v;
}