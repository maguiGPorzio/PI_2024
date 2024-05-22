//
// Created  on 20/05/2024.
//

#include "stackADT.h"
#include <stdlib.h>
#define BLOCK 10

typedef struct stackCDT {
    elemType *vec;
    size_t dim;   // elementos en la pila
    size_t size;  // elementos reservados
    fnEquals equals;
}stackCDT;

// stackADT newStack(int (*equals) (elemType, elemType))
stackADT newStack(fnEquals equals) {
    stackADT aux = calloc(1, sizeof( stackCDT));
    aux->equals = equals;
    return aux;
}

void freeStack(stackADT stack) {
    free(stack->vec);
    free(stack);
}

int isEmpty(const stackADT stack){
    return stack->dim ==0;
}

void push(stackADT stack, elemType elem){
    if ( stack->dim == stack->size) {
        stack->size+=BLOCK;
        stack->vec = realloc(stack->vec, stack->size * sizeof(stack->vec[0]));
    }
    stack->vec[stack->dim++] = elem;
}

elemType pop(stackADT stack){
    if(isEmpty(stack)) {
        exit(1);
    }
    return stack->vec[--stack->dim];
}

int sizeStack(const stackADT stack) {
    return stack->dim;
}

int belongs(const stackADT stack, elemType elem) {
    for(int i=0; i<stack->dim; i++) {
        if(stack->equals(stack->vec[i],elem)) {
            return 1;
        }
    }
    return 0;
}