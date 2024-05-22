//
// Stack de enteros, sin capacidad maxima
// Created  on 20/05/2024.
//

#ifndef UNTITLED5_STACKADT_H
#define UNTITLED5_STACKADT_H

#include <string.h>
typedef struct stackCDT * stackADT;

typedef char * elemType;

typedef int (*fnEquals) (elemType, elemType);

/*
 * Recibo una funcion que determine si dos elemType
 * son iguales
 */
stackADT newStack(fnEquals equals);

void freeStack(stackADT stack);

int isEmpty(const stackADT stack);

void push(stackADT stack, elemType elem);

elemType pop(stackADT stack);

int sizeStack(const stackADT stack);

// Solo con fines académicos
int belongs(const stackADT stack, elemType elem);

#endif //UNTITLED5_STACKADT_H
