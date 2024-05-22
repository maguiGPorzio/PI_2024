#include <stdio.h>
#include "stackADT.h"
#include <assert.h>
#include <string.h>
#include <strings.h>

int cmpString(char *s1, char *s2) {
    return strcasecmp(s1,s2)==0;
}

// Si el stack fuera de enteros
int cmpInts(int n1, int n2) {
    return n1==n2;
}

int main(void) {
    stackADT s1;
    s1 = newStack(cmpString);
    assert(isEmpty(s1));
    push(s1, "hola");

    assert(!isEmpty(s1));
    assert(strcmp(pop(s1),"hola")==0);

    assert(isEmpty(s1));

    char vec[] = "HOLA";
    assert(belongs(s1, vec));

    freeStack(s1);
    return 0;
}
