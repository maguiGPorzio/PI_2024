/*
Escribir una versión recursiva de la función strchr
*/
#include <stdio.h>

char *
strchr (char *s, char car){
    if (!(*s)){
        return NULL;
    }
    if ((*s)==car){
        return s;
    }
    return strchr(s+1,car);
}

int 
main (){
    char *p="HOLA";
    char *s=strchr(p,'R');
    printf("%s\n",s);
    return 0;
}

