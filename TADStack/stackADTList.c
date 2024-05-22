//
// Created on 21/05/2024.
//
#include "stackADT.h"
#include <stdlib.h>

struct node {
    elemType head;
    struct node * tail;
};

struct stackCDT {
    struct node * list;
    size_t dim;
    fnEquals equals;
};

stackADT newStack(fnEquals equals) {
    //return calloc(1, sizeof(struct stackCDT));
    stackADT ans = malloc(sizeof(struct stackCDT));
    ans->equals = equals;
    ans->list = NULL;
    ans->dim = 0;
    return ans;
}

static void freeList(struct node * l) {
    if(l==NULL) {
        return;
    }
    freeList(l->tail);
    free(l);
}

void freeStack(stackADT stack) {
    freeList(stack->list);
    free(stack);
}

int isEmpty(const stackADT stack) {
    return stack->list == NULL;
}

void push(stackADT stack, elemType elem) {
    struct node * newNode = malloc(sizeof(struct node));
    newNode->head = elem;
    newNode->tail= stack->list;
    stack->list = newNode;
    stack->dim++;
}

elemType pop(stackADT stack) {
    if (isEmpty(stack)) {
        exit(1);
    }
    elemType ans = stack->list->head;
    struct node * aux = stack->list; // el que tengo que liberar
    stack->list = aux->tail; // Ahora el primero es la cola
    free(aux);
    stack->dim--;
    return ans;
}

int sizeStack(const stackADT stack) {
    return stack->dim;
}


int belongsIter(const stackADT stack, elemType elem) {
    struct node * aux = stack->list;
    while (aux != NULL) {
        if (stack->equals(aux->head, elem)) {
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}

static int belongsRec(struct node * list, elemType elem, fnEquals equals) {
    if ( list == NULL) {
        return 0;
    }
    return equals(list->head, elem) || belongsRec(list->tail, elem, equals);
}

int belongs(const stackADT stack, elemType elem) {
    return belongsRec(stack->list, elem, stack->equals);
}