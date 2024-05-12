/*
Escribir una función que detecte si una palabra es capicúa.
Resolverlo en forma recursiva.
*/
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int
esCapicua(char * s, int dim);

int 
main (){
    char vec[]="";
    printf("%d\n",esCapicua(vec,strlen(vec)));
}


int
esCapicua(char * s, int dim){ //sin wrapper
    if ((*s)==0){
        return 1;
    }
    if (*s!=s[dim-1]){
        return 0; 
    }
    return esCapicua(s+1,dim-2);
}