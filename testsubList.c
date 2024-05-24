#include <stdio.h>
#include "/home/mgonzalezporzio/PI/utillist.h"
#include <assert.h>
#include <stdlib.h>

TList
subList(TList list, int from, int to);

int main(void) {
    int v[] = { -10, -5, 0, 5, 10, 15, 20, 25};
    // Test para subList
    TList l1 = fromArray(v, 0);
    assert(subList(l1, 0, 10)==NULL);
    assert(subList(l1, 1, 2)==NULL);
    assert(subList(l1, 0, 0)==NULL);

    // Un solo elemento
    l1 = fromArray(v, 1);
    TList l2 = subList(l1, 0, 10);
    assert(checkElems(l2, v, 1));
    freeList(l2);
    l2 = subList(l1, 1, 3);
    assert(l2==NULL);
    l2 = subList(l1, -1, 0);
    assert(l2==NULL);

    freeList(l1);
    l1 = fromArray(v, 8);
    l2 = subList(l1, 0, 10);
    assert(checkElems(l2, v, 8));
    freeList(l2);
    l2 = subList(l1, 1, 3);
    assert(checkElems(l2, v+1, 3));
    freeList(l2);
    l2 = subList(l1, 7, 10);
    assert(checkElems(l2, v+7, 1));
    freeList(l2);

    freeList(l1);
    puts("OK subList");
}

/*
Realizar una función recursiva subList que reciba una lista y dos valores enteros from y to
y retorne una nueva sublista que contenga los elementos ubicados entre from y to
inclusive, considerando que el primer elemento es el elemento 0 (cero).
La función debe retornar el puntero al primer nodo de la lista resultante.
No usar funciones ni macros auxiliares.
Se asegura que la función se invoca con valores correctos de from y to.
Asumir que hay memoria suficiente para la nueva lista (no hace falta validar el malloc)
Ejemplo: Para la siguiente lista:
- Si from = 0 y to = 2, retorna la lista con los valores 4,3,7.
- Si from = 5 y to = N, retorna la lista vacía (sea cual sea N > 5)
- Si from = 3 y to = 10, retorna la lista con los valores 2 y 6.
*/

TList
subList(TList list, int from, int to){
    if ( list == NULL ){
        return NULL;
    }

    if (from==0 && to>=0){
        TList aux=malloc(sizeof(list[0]));
        aux->elem=list->elem;
        aux->tail=subList(list->tail,from,to-1);
        return aux;
    }

    TList aux=subList(list->tail,from-1,to-1);
    return aux;
}