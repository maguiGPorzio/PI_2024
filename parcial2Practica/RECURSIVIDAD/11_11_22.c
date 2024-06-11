/*
 Escribir una función recursiva sortedList que reciba como único parámetro una lista y elimine
 de la misma aquellos elementos que hagan que la lista no esté ordenada en forma ascendente (cada
 elemento debe ser menor al siguiente) teniendo en cuenta que el último elemento está correctamente
 ubicado (no se lo debe borrar).
 La función no debe crear una nueva lista, sino eliminar elementos de la lista recibida.
 No definir funciones ni macros auxiliares
 No usar variables static
 No usar ciclos dentro de la función
 Ejemplos:
 ● Sirecibe la lista vacía, retorna la lista vacía
 ● Sirecibe la lista 1 → 2 → 3 →4→5nocambianada
 ● Sirecibe la lista 2 → 3 → 4 →1la lista queda únicamente con el elemento 1
 ● Sirecibe la lista 2 → 1 → 4 →3la lista queda 1 → 3
 ● Sirecibe la lista 1 → 3 → 3 →4→2 lalista queda 1 →2
 ● Sirecibe la lista 3 → 3 → 3 la lista queda únicamente con el elemento 3
 ● Sirecibe la lista 3 → 5 → 2 →4→3→6 lalistaqueda 2→3→6

*/

#include "/home/mgonzalezporzio/PI/bibliotecas/utillist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

TList
sortedList(TList list);

int main(void) {
    int v[] = { -10, -5, 0, 5, 10, 15, 20, 25};

    // Test para sortedList
    TList l1 = fromArray(v, 8);
    l1 = sortedList(l1);
    assert(checkElems(l1, v, 8));
    freeList(l1);

    int v2[] = { -10, -5, 0, 5, 10, 15, 20, 5};
    l1 = fromArray(v2, 8);
    l1 = sortedList(l1);
    int v3[] = { -10, -5, 0, 5};
    assert(checkElems(l1, v3, 4));
    l1 = sortedList(l1);
    assert(checkElems(l1, v3, 4));
    freeList(l1);

    int v4[] = { 10, 5, 8, 3, 10, 5, 2, 0};
    l1 = fromArray(v4, 8);
    l1 = sortedList(l1);
    assert(l1->elem==0 && l1->tail==NULL);
    freeList(l1);

    l1 = sortedList(NULL);
    assert(l1==NULL);

    puts("OK sortedList");
    return 0;
}
TList
sortedList(TList l){
    if (l==NULL || l->tail == NULL){
        return l;
    }

    l->tail=sortedList(l->tail);

    if (l->elem >= l->tail->elem){
        TList aux=l->tail;
        free(l);
        return aux;
    }

    return l;
}