#include <stdio.h>
#include "getnum.h"

int main() {
    int num=getint("Escribir un numero entero: "),aux=num,EsCapicua=0;
    while (num>=1){
        num/=10;
    }
    printf("El numero %d %s capicua \n", aux, (EsCapicua) ? "es":"no es");
    return 0;
    }