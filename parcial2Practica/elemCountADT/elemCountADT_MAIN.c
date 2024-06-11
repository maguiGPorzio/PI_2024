#include "/home/mgonzalezporzio/PI/elemCountADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
 int cmpInts(int a, int b) {
    return a-b;
 }

 int
 main(void) {
    elemCountADT ecADT = newElemCount(cmpInts);
    assert(countElem(ecADT, 10) == 1);
    assert(countElem(ecADT, 5+5) == 2);
    assert(distinctElems(ecADT) == 1);
    assert(countElem(ecADT, 5) == 1);
    assert(countElem(ecADT, 10) == 3);
    assert(countElem(ecADT, 5) == 2);
    assert(countElem(ecADT, 30) == 1);
    assert(distinctElems(ecADT) == 3);
    // Se itera por todos los elementos
    size_t aux;
    toBegin(ecADT);
    assert(hasNext(ecADT) == 1);
    assert(next(ecADT, &aux) == 5 && aux == 2);
    assert(hasNext(ecADT) == 1);
    assert(next(ecADT, &aux) == 10 && aux == 3);
    assert(next(ecADT, &aux) == 30 && aux == 1);
    assert(hasNext(ecADT) == 0);
    freeElemCount(ecADT);
    puts("OK!");
    return 0;
}