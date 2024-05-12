/*
Escribir una función que detecte si una palabra es capicúa.
Resolverlo en forma recursiva.
*/
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int
auxEsCapicua(const char * s, int dim);

int
esCapicua(const char * s);

int 
main (){
    char vec[]="HOOHOOH";
    printf("%d\n",esCapicua(vec));
}

int
auxEsCapicua(const char * s, int dim){ 
    if ((*s)==0){
        return 1;
    }
    if (*s!=s[dim-1]){
        return 0; 
    }
    return auxEsCapicua(s+1,dim-2);
}


int
esCapicua(const char * s){ 

    return auxEsCapicua(s, strlen(s));
}