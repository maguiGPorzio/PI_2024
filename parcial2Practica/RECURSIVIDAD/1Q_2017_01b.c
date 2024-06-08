/*
RECUSRIVA
Escribir una funcion que reciba una lista de enteros ordenada de menor a mayor pero que puede contener elementos repetidos. 
La funcion debe retornar una NUEVA lista de enteros ordenada y sin repetidos. 
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
lista(TList l){
    if (l==NULL){
        return NULL;
    }

    TList last=lista(l->tail);

    if (l->tail  == NULL || l->head != l->tail->head){
        TList aux=malloc(TNode);
        aux->head=l->head;
        aux->tail=last;
        return aux;
    }

    return last;
}