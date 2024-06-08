/*
RECURSIVA
Escribir una funcion que reciba un vector de enteros positivos, donde la marca de final es el valor -1. 
El vector esta ordenado de menor a mayor y no contiene elementos repetidos. La funcion debe retornar una 
lista de enteros (de tipo Tlist) ordenada en forma ascendente y sin repeticiones
*/
#include <string.h>
#include <strings.h>
#include <stdlib.h>

typedef struct node{
    int head;
    struct node * tail;
} TNode;

typedef TNode * TList;

TList
lista(int * vec){
    if (*vec == -1){
        return NULL;
    }

    TList new=malloc(sizeof(TNode));
    new->head=*vec;
    new->tail=lista(vec+1);
    return new;
}