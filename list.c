//
//
// Lista de enteros ordenada y sin repetidos
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

#define BLOCK 10

int isEmpty(TList l) {
    return l == NULL;
}
// 1 si n está en la lista
int belongs(const TList l, int n) {
    if(l==NULL || l->elem > n) {    // isEmpty(l)
        return 0;
    }
    // La lista no es vacía
    return l->elem == n || belongs(l->tail, n);
}

// Retorna la cantidad de elementos
int size(const TList l) {
    if (isEmpty(l)) {
        return 0;
    }
    return 1 + size(l->tail);
}

void freeList(TList l) {
    if (isEmpty(l)) {
        return;
    }
    // Recursion de cola
    TList aux = l->tail;
    free(l);  // libero el primer nodo
    freeList(aux);
    // Recursion de pila
    // freeList(l->tail);
    // free(l);
}

TList insert(TList l, int n) {
    if ( l==NULL || l->elem > n) {
        TList aux = malloc(sizeof(node));
        aux->elem = n;
        aux->tail = l;
        return aux;
    }
    // Ya sabemos que la lista no está vacía
    if (l->elem == n) {
        return l;
    }
    // n es mayor que el primero
    l->tail = insert(l->tail, n);
    return l;
}

// Borrar un elemento de la lista
TList delete(TList l, int n) {
    if ( isEmpty(l) || l->elem > n) {
        return l;
    }
    if (l->elem == n) {
        TList ans = l->tail;
        free(l);
        return ans;
    }
    l->tail = delete(l->tail, n);
    return l;
}

// Devuelve el elemento del primero de la lista
int head(const TList l) {
    // assert(l != NULL)
    if (isEmpty(l)) {
        fprintf(stderr, "Mal invocado head");
        exit(1);
    }
    return l->elem;
}

// Devuelve la sublista (el puntero al siguiente del primero)
TList tail(const TList l) {
    if (isEmpty(l)) {
        fprintf(stderr, "Mal invocado tail");
        exit(1);
    }
    return l->tail;
}

// El elemento en la posición idx, el primero está en la posición cero
int elementAtIndex(const TList l, size_t idx) {
    if (isEmpty(l)) {
        fprintf(stderr, "Index out of limits");
        exit(1);
    }
    if ( idx==0 ) {
        return head(l);
    }
    return elementAtIndex(tail(l), idx-1);
}

// Retorna un vector con todos los elementos
// En *dim dejará el size de la lista
int * toArray (TList l, size_t * dim) {
    if ( l==NULL) {
        *dim=0;
        return NULL;
    }
    int * ans = NULL;
    int i;
    for(i=0; !isEmpty(l); i++, l = tail(l)) {
        if ( i % BLOCK == 0) {
            ans = realloc(ans, (i + BLOCK) * sizeof(*ans));
        }
        ans[i] = head(l);
    }
    ans = realloc(ans, i * sizeof(*ans));
    *dim = i;
    return ans;
}

// Version menos eficiente pero mas clara y simple
int * toArray2 (TList l, size_t * dim) {
    *dim = size(l);
    if ( l==NULL) {
        return NULL;
    }
    int * ans = malloc(*dim * sizeof(*ans));
    for(int i=0; !isEmpty(l); i++, l = tail(l)) {
        ans[i] = head(l);
    }
    return ans;
}


