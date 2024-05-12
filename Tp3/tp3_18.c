#include <stdio.h>
#include "getnum.h"

int main() {
    int num,aux=1,factorial=1;
    do {
        num=getint("Ingrese un numero entero no negativo, cero o mayor ");
    }
    while (num<=0);

    while (aux<=num){
        factorial*=aux;
        aux+=1;
    }
    printf("%d \n",factorial);
    return 0;
    }