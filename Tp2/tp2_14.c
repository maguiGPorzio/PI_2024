#include <stdio.h>
#include "getnum.h"

int 
main() {
    int num1=getint("Escribir un numero entero : "), num2=getint("Escribir otro numero entero: ");
    printf("El promedio es %.2f \nLa suma es %d \nEl menor es %d \nEl mayor es %d \n%s son iguales \n",((float)num1 + num2)/2,num1+num2,(num1<num2) ? num1:num2,(num1>num2) ? num1:num2, (num1==num2) ? "Si":"No" );
    return 0;
}   