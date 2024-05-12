#include <stdio.h>
#include "getnum.h"

int main() {
    int numero=getint("Escriba un numero entero: "),sumaCifras=0;
    if (numero<0){
        numero*=-1;
    }
    while (numero>0){
        sumaCifras+=numero%10;
        numero/=10;
    }
    printf("%d \n",sumaCifras);
    return 0;
}