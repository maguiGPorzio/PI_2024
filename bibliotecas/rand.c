#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar un número aleatorio normalizado en [0,1) 
double randNormalize(){
    return rand () / ((double) RAND_MAX+1);
}

// Función para generar un número entero aleatorio en el rango [left, right]
int randInt(int left, int right){
    return ((int)(randNormalize()*(right-left+1)) + left);
}

// Función para generar un número real aleatorio en el rango [left, right)
double randReal(double left, double right){
    return (randNormalize() * (right-left)+ left);
}

// Función para inicializar la semilla del generador de números aleatorios
void randomize(){
    srand ((int)time(NULL));
}