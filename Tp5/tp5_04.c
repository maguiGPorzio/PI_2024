//Escribir una función que reciba dos parámetros de entrada de tipo entero y devuelva en su nombre un número aleatorio entre ambos números. (En una línea)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "getnum.h"

// Función para generar un número aleatorio normalizado en [0,1) 
double randNormalize(){
    return rand () / ((double) RAND_MAX+1);
}

// Función para generar un número entero aleatorio en el rango [left, right]
int randInt(int left, int right){
    return ((int)(randNormalize()*(right-left+1)) + left);
}

// Función para generar un número real aleatorio en el rango [left, right]
double randReal(double left, double right){
    return (randNormalize() * (right-left)+ left);
}

// Función para inicializar la semilla del generador de números aleatorios
void randomize(){
    srand ((int)time(NULL));
}


int 
main (){
    int a=getint("Ingrese un numero entero positivo: ");
    int b=getint("Ingrese un numero entero positivo: ");
    double c=getdouble("Ingrese un numero real: ");
    double d=getdouble("Ingrese un numero real: ");

    randomize();
    printf("%d\n",randInt(a,b));
    printf("%f\n",randReal(c,d));
    return 0;

}