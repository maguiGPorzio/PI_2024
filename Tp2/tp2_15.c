#include <stdio.h>
#include "getnum.h"

int 
main() {
    printf("Escribir un caracter ");
    char car1=getchar();
    printf("El caracter '%c' en mayuscula es '%c' \n", car1, (car1<='z' && car1>='a')? (car1-'a'+'A'):car1);
    return 0;
} 