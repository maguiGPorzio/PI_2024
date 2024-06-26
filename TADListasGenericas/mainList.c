#include <stdio.h>
#include "/home/mgonzalezporzio/PI/TADListasGenericas/listADT.h"
#include <strings.h>
#include <assert.h>

// Si mi lista fuera de enteros ordenados en forma descendente
int cmpInts(int n1, int n2) {
    return n2 - n1;
}

int main(void) {
    listADT myList = newList((int (*) (char *, char*)) strcasecmp);
    assert(sizeList(myList)==0);
    assert(isEmptyList(myList));
    assert(insertList(myList, "hola")==1);
    assert(insertList(myList, "HOLA")==0);
    assert(insertList(myList, "hola y adios")==1);
    assert(sizeList(myList)==2);

    //assert(deleteList(myList,"hola"));
    //assert(sizeList(myList)==1);
    //assert(deleteList(myList, "no estoy")==0);

    //assert(strcasecmp(buscar(myList,0),"hola")==0);

    // Otra forma de imprimir todos, pero mas eficiente
    toBegin(myList);
    while (hasNext(myList)) {
        printf("%s\n", next(myList));
    }
    // Si hago next(myList) aborta

    insertList(myList, "ZZZZZ");
    toBegin(myList);
    int i=1;
    // Imprimo solo los tres primeros
    while (hasNext(myList) && i++<=3) {
        printf("%s\n", next(myList));
    }

    freeList(myList);

    puts("OK");
    return 0;
}
