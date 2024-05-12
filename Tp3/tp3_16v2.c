#include <stdio.h>
#include "getnum.h"

int main() {
    int binario,posicion=1,decimal;
    do {
        decimal=getint("Ingrese un numero entero positivo \n");
    }
    while (decimal<0);

    while (decimal>0){
        binario+=(decimal%2)*posicion;
        decimal/=2;
        posicion*=10;
    }
    printf("\nEquivalente binario: %d\n", binario);
    return 0;
    }