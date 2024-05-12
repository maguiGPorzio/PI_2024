/*
Implementar un programa que lea de la entrada estándar hasta EOF y genere elsupervector que 
todo lo puede guardar. 
Luego imprimir el contenido del vector ensalida estándar.
*/
#include <stdio.h>
#include <stdlib.h>
#define BLOCK 10

char *
superVector(int *dim){
    int car;
    *dim=0;
    char *v=NULL;
    while ((car=getchar())!='\n' && car!=EOF){
        if (((*dim) % BLOCK)==0){
            v=realloc(v,(*dim)+BLOCK);
        }
        v[(*dim)++]=car;
    }
    v=realloc(v,(*dim)+1);
    v[*dim]='\0';
    return v;
}

int 
main (){
    int dim=0;
    char *v=superVector(&dim);
    for (int i=0 ; i<dim ; i++){
        printf("%c",v[i]);
    }
    printf("\n");
    return 0;
}