/*
Escribir una función recursiva deleteAll que reciba únicamente dos listas de enteros ordenados en forma ascendente (sin repetidos) y 
elimine de la primera lista los elementos que pertenezcan a la segunda lista.

l1:4,5,6,7
l2:1,2,3,4
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct node {
	int elem;
	struct node * tail;
} TNode;

typedef struct node * TList;

TList
deleteAll(TList list1, TList list2){
    if (list2 == NULL || list1 == NULL){
        return list1;
    }

    if (list1->elem < list2->elem){
        list1->tail=deleteAll(list1->tail, list2);
        return list1;
    }

    if (list1->elem == list2->elem){
        TList aux=deleteAll(list1->tail, list2->tail);
        free(list1);
        return aux;
    }

    list1->tail=deleteAll(list1, list2->tail);
    return list1;

}

