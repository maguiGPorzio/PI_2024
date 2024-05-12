#include <stdio.h>
#include "getnum.h"

int 
main() {
    printf("Escribir dos caracteres ");
    char car1=getchar(),car2=getchar();
    printf("El caracter '%c' es el de mayor valor ASCII \n", (car1>car2) ? car1:car2);
    return 0;
} 