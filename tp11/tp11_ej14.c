/*
Se desea implementar un TAD para listas de elementos no repetidos, que permita recorrerla con dos criterios: 
en forma ascendente o por el orden de inserción de los elementos.
*/

#define BLOCK 10
#include <stdio.h>
#include "/home/mgonzalezporzio/PI/tp11/tp11_ej14.h"
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    elemType head;
    struct node * tail;
} node;

typedef node * Tlist;

struct listCDT{
    Tlist listaAsc; //lista ordenada de forma ascendente
    Tlist listaIns; //lista ordenada por orden de insercion
    Tlist ultimoAgregado;
    compares cmp;
    Tlist nextAsc;
    Tlist nextIns;
};

/* Retorna una lista vacía.
*/
listADT newList(int (*compare) (elemType e1, elemType e2)){
    listADT aux=calloc(1,sizeof(struct listCDT));
    aux->cmp=compare;
    return aux;
}

static Tlist
addAux(elemType elem){
    Tlist newNode=malloc(sizeof(node));
    newNode->head=elem;
    newNode->tail=NULL;
    return newNode;
}

static Tlist
addRec(Tlist lista, listADT listas, elemType elem){

    if (lista == NULL || listas->cmp(lista->head,elem) > 0){
        Tlist auxIns=addAux(elem);
        auxIns->head=elem;
        listas->ultimoAgregado->tail=auxIns;
        listas->ultimoAgregado=auxIns;

        Tlist auxAsc=addAux(elem);
        auxAsc->head=elem;
        auxAsc->tail=lista;
        return auxAsc;
    }

    if (!listas->cmp(lista->head,elem)){
        return lista;
    }

    lista->tail=addRec(lista->tail,listas,elem);
    return lista;

}

/* Agrega un elemento. Si ya estaba no lo agrega */
void add(listADT list, elemType elem){

    if (list->listaAsc == NULL){
        list->listaAsc=addAux(elem);
        list->listaIns=addAux(elem);
        list->ultimoAgregado=list->listaIns;
        return;
    }

    list->listaAsc=addRec(list->listaAsc, list, elem);
}

/* Elimina un elemento. */
//void remove(listADT list, elemType elem);

/* Resetea el iterador que recorre la lista en el orden de inserción */
void toBegin(listADT list){
    list->nextIns=list->listaIns;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en el orden de inserción. Sino retorna 0 */
int hasNext(listADT list){
    return list->nextIns != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en el orden de inserción. 
** Si no hay un elemento siguiente o no se invocó a toBegin aborta la ejecución.
*/
elemType next(listADT list){
    if (!hasNext(list)){
        exit(1);
    }

    elemType aux=list->nextIns->head;
    list->nextIns=list->nextIns->tail;
    return aux;
}

/* Resetea el iterador que recorre la lista en forma ascendente */
void toBeginAsc(listADT list){
    list->nextAsc=list->listaAsc;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en forma ascendente. Sino retorna 0 */
int hasNextAsc(listADT list){
    return list->nextAsc != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en forma ascendente. 
** Si no hay un elemento siguiente o no se invocó a toBeginAsc aborta la ejecución.
*/
elemType nextAsc(listADT list){
    if (!hasNextAsc(list)){
        exit(1);
    }

    elemType aux=list->nextAsc->head;
    list->nextAsc=list->nextAsc->tail;
    return aux;
}

static void
freeListRec(Tlist list){
    if (list == NULL){
        return;
    }

    Tlist aux=list->tail;
    free(list);
    freeListRec(aux);
}

/* Libera la memoria reservada por la lista */
void freeList(listADT list){

    freeListRec(list->listaAsc);
    freeListRec(list->listaIns);

    free(list);
}