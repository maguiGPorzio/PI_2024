/*
Escribir la función recursiva countGroups que reciba como únicos parámetros una lista de tipo TList y un carácter. 
La función debe retornar la cantidad de grupos de caracteres consecutivos iguales al carácter pasado por parámetro. 
Un grupo está formado por uno o más caracteres iguales en nodos consecutivos. 

Las funciones contarGrupos y countGroups NO pueden invocar a otras funciones ni macros.
*/
#include <assert.h>
#include <stdio.h>
#include "/home/mgonzalezporzio/PI/bibliotecas/utillist.h"

int
countGroups(TList l, char c){
    if (l==NULL){
        return 0;
    }

    if (l->tail == NULL){
        return l->elem == c;
    }

    if (l->elem != l->tail->elem && l->elem == c){
        return 1 + countGroups(l->tail->tail,c);
    }

    return countGroups(l->tail,c);
}
