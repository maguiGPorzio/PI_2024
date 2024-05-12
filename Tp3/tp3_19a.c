#include <stdio.h>
#include "getnum.h"

int main() {
    int num=getint("Ingrese un numero entero: \n"),contador=0, aux;
    aux=num;
    if (num<0){
        num*=-1;
    }
    while (num>=1){
        if ((num%10)==5){
            contador+=1;
        }
        num/=10;
    }
    printf("La cantidad de digitos de %d iguales a '5' son %d \n",aux,contador);
    return 0;
    }