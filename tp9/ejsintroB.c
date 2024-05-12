/*
Escribir una versión recursiva para la función strlen
*/
#include <stdio.h>

int 
strlen(char *s){
    if (!(*s)){
        return 0;
    }
    return 1 + strlen(s+1);
}

int 
main (){
    char s[]="HOLA";
    printf("%d\n",strlen(s));
    return 0; 
}