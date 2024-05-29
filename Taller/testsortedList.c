#include <stdio.h>
#include "/home/mgonzalezporzio/PI/utillist.h"
#include <assert.h>
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

/*
Escribir una función recursiva sortedList que reciba como único parámetro una lista y
elimine de la misma aquellos elementos que hagan que la lista no esté ordenada en
forma ascendente (cada elemento debe ser menor al siguiente) teniendo en cuenta
que el último elemento está correctamente ubicado (no se lo debe borrar).
La función no debe crear una nueva lista, sino eliminar elementos de la lista recibida.
● Ejemplos:
• Si recibe la lista vacía, retorna la lista vacía
• Si recibe la lista 1 → 2 → 3 → 4 → 5 no cambia nada
• Si recibe la lista 2 → 3 → 4 → 1 la lista queda únicamente con el elemento 1
• Si recibe la lista 2 → 1 → 4 → 3 la lista queda 1 → 3
• Si recibe la lista 1 → 3 → 3 → 4 → 2 la lista queda 1 → 2
• Si recibe la lista 3 → 3 → 3 la lista queda únicamente con el elemento 3
• Si recibe la lista 3 → 5 → 2 → 4 → 3 → 6 la lista queda 2 → 3 → 6
*/

TList
sortedList(TList list){
    if (list==NULL || list->tail ==NULL){
        return list;
    }

    list->tail=sortedList(list->tail);

    TList aux=(list->tail);

    if (list->elem >= aux->elem){
        free(list);
        return aux;
    }
    return list;
}
