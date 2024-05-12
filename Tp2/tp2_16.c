#include <stdio.h>
#include "getnum.h"

int 
main() {
    printf("Escribir dos caracteres ");
    char car1=getchar(),car2=getchar();
    printf("El caracter '%c' es %s al carcter '%c' \n", car1, (car1>car2) ? "mayor":"menor", car2);
    return 0;
} 