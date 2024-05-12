#include <stdio.h>
#include <ctype.h>
#include "getnum.h"

int 
main (){
    int n,c;
    /* al salir del ciclo n debe ser un número par mayor que cero */
    do
	    n = getint("Ingrese un numero mayor a 0 y par \n");
    while (n<0 || (n%2)!=0);

    /* este ciclo debe incluir la lectura de caracteres y debe ejecutarse  
    * mientras no sea fin de archivo y los caracteres sean  dígitos o minúsculas
    */

    while ((c=getchar())!=EOF && (isdigit(c) || islower(c))){ 
        putchar(c);
    }

    return 0;
}