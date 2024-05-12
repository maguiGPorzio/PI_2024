/*
Escribir una función recursiva que reciba un string  y devuelva la cantidad de vocales que contiene. 
*/
#include <stdio.h>
#include <ctype.h>
#define ES_VOCAL(LETRA) ((LETRA)=='A' || (LETRA)=='E' || (LETRA)=='I' || (LETRA)=='O' || (LETRA)=='U')

int
cantVoc(char * s);

int 
main (){
    char vec[]="HOoAaama";
    printf("%d\n",cantVoc(vec));
}


int
cantVoc(char * s){

    if ((*s)==0){
        return 0;
    }

    return ES_VOCAL(toupper(*s)) + cantVoc(s+1);
}

