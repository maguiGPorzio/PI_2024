#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/mgonzalezporzio/PI/taller11_02.h"

/*
Crear un T.A.D. que maneje una cola de enteros. (queueADT)
Funcionalidades:
- Crear instancia: newQueue
- Liberar recursos: freeQueue
- Cargar elemento: queue
- Sacar elemento: dequeue
- ¿está vacía?: isEmpty
- …
*/

typedef struct node {
    elementType elem;
    struct node * tail;
} node;

typedef node * TList;

struct queueCDT {
    TList que;
    TList last;
    TList next;
};

queueADT newQueue(void){
    queueADT new=calloc(1,sizeof(struct queueCDT));
    return new;
}
 
// Agrega un elemento al final de la cola
void queue(queueADT q, elementType n){
    TList new=malloc(sizeof(node));
    new->elem=n;
    new->tail=NULL;
    if (q->last != NULL){
        q->last->tail=new;
    }
    else{
        q->que=new;
    }
    q->last=new;
}
 
// Remueve un elemento del principio de la cola y lo deja en out
void dequeue(queueADT q, elementType * out){
    if (q->que == NULL){
        return;
    }

    TList aux=q->que->tail;
    *out=q->que->elem;
    free(q->que);
    q->que=aux;

    if (q->que == NULL){
        q->last=NULL;
    }
}
 
int isEmpty(queueADT q){
    return q->que == NULL;
}

void
freeRec(TList que){
    if (que == NULL){
        return;
    }

    TList aux=que->tail;
    free(que);
    freeRec(aux);
}

void freeQueue(queueADT q){
    freeRec(q->que);
    free(q);
}

queueADT 
newQueue(void);

/* Funciones agregadas para poder iterar*/
void 
toBegin(queueADT q){
    q->next=q->que;
}

int 
hasNext(queueADT q){
    return q->next != NULL;
}

elementType 
next(queueADT q){
    if (!hasNext(q)){
        exit(1);
    }

    elementType aux=q->next->elem;
    q->next=q->next->tail;
    return aux;
}