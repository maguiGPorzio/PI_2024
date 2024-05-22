#ifndef __list_h
#define __list_h

#include <stdio.h>

typedef struct node {
    int elem;       // el dato que almacena el nodo
    struct node * tail;   // la sublista
} node;

typedef struct node * TList;

int isEmpty(TList l);

// 1 si n está en la lista
int belongs(const TList l, int n);

// Retorna la cantidad de elementos
int size(const TList l);

void freeList(TList l);

TList insert(TList l, int n);

// Borrar un elemento de la lista
TList delete(TList l, int n);

// Devuelve el elemento del primero de la lista
int head(const TList l);

// Devuelve la sublista (el puntero al siguiente del primero)
TList tail(const TList l);

// El elemento en la posición idx, el primero está en la posición cero
int elementAtIndex(const TList l, size_t idx);

// Retorna un vector con todos los elementos
// En *dim dejará el size de la lista
int * toArray (TList l, size_t * dim);

// Version menos eficiente pero mas clara y simple
int * toArray2 (TList l, size_t * dim);

#endif