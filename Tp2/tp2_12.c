#include <stdio.h>
#include "getnum.h"

int 
main(void) {
    {
        int a =0;
    }

    {
        float a = 2;
    }

    int b =2;
    printf("Ingrese un caracter:");
    int caracter=getchar();
    printf("El caracter %s \n",((caracter>='a' && caracter<='z') || (caracter>='A' && caracter<='Z')) ? "es una letra":"no es una letra");
    return 0;
}