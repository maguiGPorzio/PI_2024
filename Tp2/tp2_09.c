#include <stdio.h>
#include "getnum.h"

int 
main() {
    int num;
    do 
        puts("Escriba un numero entero positivo");
    while ((num=getint(""))<=0);
    
    printf("el numero ingresado dividido 2 es: %d \n",num>>1);
    
    return 0;
}