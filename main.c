#include <stdio.h>
#include "list.h"
#include <assert.h>
#include <stdlib.h>

int main() {
    TList myList = NULL;  // lista vacia

    assert(isEmpty(myList));

    assert(belongs(myList, 10)==0);

    size_t dim2;
    int * vec2 = toArray(myList, &dim2);
    for(int i=0; i < dim2; i++) {
        printf("%d\n", vec2[i]);
    }
    free(vec2);
    assert(size(myList)==0);
    // Agregamos el numero 10
    myList = insert(myList, 10);
    assert(! isEmpty(myList));
    assert(size(myList)==1);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 15)==0);
    printf("%p \n", myList);

    // Volvemos a agregar, no tiene  que agregarlo
    myList = insert(myList, 10);
    assert(! isEmpty(myList));
    assert(size(myList)==1);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 15)==0);
    printf("%p \n", myList);

    myList = insert(myList, 15);
    assert(! isEmpty(myList));
    assert(size(myList)==2);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 15)==1);
    printf("%p \n", myList);

    myList = insert(myList, 5);
    assert(! isEmpty(myList));
    assert(size(myList)==3);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 15)==1);
    printf("%p \n", myList);

    // Borrar uno que no existe
    myList = delete(myList, 50);
    assert(! isEmpty(myList));
    assert(size(myList)==3);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 15)==1);
    assert(belongs(myList, 5)==1);
    assert(belongs(myList, 50)==0);
    printf("%p \n", myList);

    myList = delete(myList, 5);
    assert(! isEmpty(myList));
    assert(size(myList)==2);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 15)==1);
    assert(belongs(myList, 5)==0);
    printf("%p \n", myList);

    myList = delete(myList, 15);
    assert(! isEmpty(myList));
    assert(size(myList)==1);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 15)==0);
    assert(belongs(myList, 5)==0);
    printf("%p \n", myList);

    myList = delete(myList, 10);
    assert(isEmpty(myList));
    assert(size(myList)==0);
    printf("%p \n", myList);

    // Agregamos uno mas para probar el free
    myList = insert(myList, 10);
    myList = insert(myList, 5);
    myList = insert(myList, 15);

    TList aux = myList;
    while ( !isEmpty(aux)) {
        printf("%d \t", head(aux));
        aux = tail(aux);
    }
    putchar('\n');

    aux = myList;
    int suma = 0;
    while ( !isEmpty(aux)) {
        suma += head(aux);
        aux = tail(aux);
    }
    assert(suma==30);

    myList = insert(myList, 5);
    assert(! isEmpty(myList));
    assert(size(myList)==3);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 15)==1);
    printf("%p \n", myList);

    int dim;
    int * vec = toArray(myList,&dim);
    suma=0;
    for(int i=0; i < dim; i++) {
        suma += vec[i];
    }
    assert(suma==30);
    free(vec);


    freeList(myList);

    puts("OK!");
    return 0;
}
