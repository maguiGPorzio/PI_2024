#include <stdio.h>
#include "getnum.h"

int 
main() {
    int num1=getint("Ingrese el primer numero: "), num2=getint("Ingrese el segundo numero: ");
    printf("El segundo numero %s multiplo del primer numero \n",((num1 !=0) && ((num2%num1)==0))? "es":"no es");
    return 0;
}