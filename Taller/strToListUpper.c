#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#define BLOCK 10

typedef struct Node *tList;

typedef struct Node
{
    char elem;
    tList *tail;
} tNode;

tList strToListUpper(char *s);

char *listToString(tList l)
{
    tList aux = l;
    char *s = NULL;
    int i = 0;
    while (aux != NULL)
    {
        if (i % BLOCK == 0)
            s = realloc(s, i + BLOCK);
        s[i] = aux->elem;
        aux = aux->tail;
        i++;
    }
    s = realloc(s, i + 1);
    s[i] = 0;
    return s;
}

void freeList(tList l)
{
    if (l != NULL)
    {
        freeList(l->tail);
        free(l);
    }
}

int main()
{
    tList aux = strToListUpper("AbCdEfG");
    char *strList = listToString(aux);
    assert(!strcmp(strList, "ACEG"));
    freeList(aux);
    free(strList);

    aux = strToListUpper("");
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    freeList(aux);
    free(strList);

    aux = strToListUpper("Hoy vinimos a ver a Messi al Monumental");
    strList = listToString(aux);
    assert(!strcmp(strList, "HMM"));
    freeList(aux);
    free(strList);

    aux = strToListUpper("no va a quedar ninguna porque son todas minusculas");
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    freeList(aux);
    free(strList);

    aux = strToListUpper(NULL);
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    freeList(aux);
    free(strList);

    aux = strToListUpper("solo van a quedar las siguientes letras ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strList = listToString(aux);
    assert(!strcmp(strList, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    freeList(aux);
    free(strList);

    puts("OK!");
}
/*
Realizar una función recursiva strToListUpper que reciba una cadena terminada en ‘\0’ y
pase a una lista sólo las letras mayúsculas.
La función debe retornar el puntero al primer nodo de la lista resultante. No definir
funciones ni macros auxiliares.
Definir también una función showListStr para mostrar la lista resultante.
*/

