#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/mgonzalezporzio/PI/moveToBackADT.h"

int main(void) {
    elemType aux1 = {10, "Diez"};
    elemType aux2 = {20, "Veinte"};
    elemType aux3 = {20, "Otro veinte"};
    elemType aux4 = {40, "Cuarenta"};

    moveToBackADT ml = newmoveToBack();

    size_t dim;
    elemType * p = getAll(ml, &dim);
    assert(p == NULL);

    assert(add(ml, aux2) == 1); // lo inserta al principio
    assert(add(ml, aux1) == 1); // lo inserta al principio
    assert(add(ml, aux3) == 0); // no lo inserta
    assert(add(ml, aux2) == 0); // no lo inserta
    assert(add(ml, aux4) == 1);

    assert(size(ml) == 3);

    aux4.code = 10; // Vamos a buscar el que tiene codigo 10
    p = getElement(ml, aux4);
    assert(p->code == 10);
    assert( strcmp(p->name, "Diez") == 0);
    free(p);

    p = getAll(ml, &dim);
    assert(dim == 3);
    assert(p[0].code==40);
    assert(p[1].code==20);
    assert(p[2].code==10);
    free(p);

    aux4.code = 40;
    p = getElement(ml, aux4);
    assert(p->code == 40);
    assert( strcmp(p->name, "Cuarenta") == 0);
    free(p);

    p = getAll(ml, &dim);
    assert(dim == 3);
    assert(p[0].code==20);
    assert(p[1].code==40);
    assert(p[2].code==10);
    free(p);

    freemoveToBack(ml);
    return 0;
}