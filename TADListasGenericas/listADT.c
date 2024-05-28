//
// Created on 22/05/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "/home/mgonzalezporzio/PI/TADListasGenericas/listADT.h"

typedef struct node {
    elemType head;
    struct node * tail;
} node;

typedef struct node * List;

struct listCDT {
    List first;
    size_t size;
    compare cmp;
    List next;
};

listADT newList(compare cmp) {
    listADT aux = malloc(sizeof (struct listCDT));
    aux->first = NULL;
    aux->size = 0;
    aux->cmp = cmp;
    return aux;
}

void freeRec(List l) {
    if ( l==NULL) {
        return;
    }
    freeRec(l->tail);
    free(l);
}

void freeList(listADT list) {
    freeRec(list->first);
    free(list);
}

int isEmptyList(const listADT list) {
    return list->first == NULL;
}

int belongsList(const listADT list, elemType elem) {
    List aux = list->first;
    int c;
    while(aux != NULL && (c=list->cmp(aux->head, elem)) <= 0) {
        if (c==0) {
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}

static int belongsRec(List list, elemType elem, compare cmp) {
    if (list==NULL) {
        return 0;
    }
    int c = cmp(list->head, elem);
    // c puede ser cero, negativo o positivo
    if (c==0) {
        return 1;
    }
    if ( c > 0) {
        return 0;
    }
    // Sabemos que list->head es "menor" que elem
    return belongsRec(list->tail, elem, cmp);
}

// Version recursiva de belongs
int belongsListRec(const listADT list, elemType elem) {
    return belongsRec(list->first, elem, list->cmp);
}

static List insertRec(List list, elemType elem, compare cmp, int *flag) {
    int c;
    if (list==NULL || (c=cmp(list->head, elem)) > 0) {
        List aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = list;
        *flag=1;
        return aux;
    }
    if ( c < 0) {
        // elem es "mayor" que el primero
        list->tail = insertRec(list->tail, elem, cmp, flag);
    }
    return list;
}

int insertList(listADT list, elemType elem) {
    int flag=0;
    list->first = insertRec(list->first, elem, list->cmp, &flag);
    list->size += flag;
    return flag;
}

static List
deleteRec(List list, elemType elem, compare cmp, int *flag){
    int c;
    if (list==NULL || (c=cmp(list->head, elem))>0){
        return list;
    }

    if (c==0){
        List aux=list->tail;
        *flag=1;
        free(list);
        return aux;
    }

    list->tail=deleteRec(list->tail,elem,cmp,flag);
    return list;
}

int deleteList(listADT list, elemType elem) {
    int flag=0;
    list->first=deleteRec(list->first, elem, list->cmp, &flag);
    list->size -= flag;
    return flag;
}

int sizeList(const listADT list) {
    return list->size;
}

//función map, que reciba un puntero a función que permita modificar cada elemento de la misma.
void map(const listADT list, elemType (*funcion) (elemType)){
    List aux=list->first;
    while (aux!=NULL){
        aux->head=funcion(aux->head);
        aux=aux->tail;
    }
}

void toBegin(listADT list) {
    list->next = list->first;
}

/* Le devuelve al usuario el siguiente.
 * La primer llamada posterior a toBegin retorna el primer elemento
 */
elemType next(listADT list) {
    if (!hasNext(list)) {
        exit(1);
    }
    elemType ans = list->next->head;
    list->next = list->next->tail;
    return ans;
}

/* retorna 1 si hay un elemento siguiente (nse puede llamar a next)
 * 0 si no hay elemento siguiente (si el usuario llama a next, aborta
 */
int hasNext(listADT list) {
    return list->next != NULL;
}


//función que reciba un número entero i y devuelve el i-ésimo elemento, donde el primer elemento tiene el índice cero.
elemType 
buscar (const listADT list, int indice){
    List aux=list->first;
    int i;

    for (i=0 ; aux!=NULL && i<indice ; i++, aux=aux->tail);

    if (aux==NULL){
        exit(1);
    }

    return aux->head;
}