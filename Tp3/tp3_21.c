#include <stdio.h>
#include "getnum.h"

int main() {
    int num=getint("Escribir un numero entero: "),aux=num,numDadoVuelta=0;
    while (num>=1){
        numDadoVuelta=(numDadoVuelta*10)+(num%10);
        num/=10;
    }
    printf("El numero %d %s capicua \n", aux, (numDadoVuelta==aux) ? "es":"no es");
    return 0;
    }