#include <stdio.h>
#include "/home/mgonzalezporzio/PI/TADListasGenericas/listADT.h"
#include <strings.h>
#include <assert.h>


int doble(int n) {
    return 2*n;
}

int cmpInts(int n1, int n2) {
    return n2 - n1;
}



int main(void) {
    listADT myList = newList(cmpInts);  // Depende de la implementación
    // habrá que pasarle la función
    insertList(myList, 3);
    insertList(myList, 4);
    insertList(myList, 2);
    map(myList, doble);
    assert(belongsList(myList,6));
    assert(belongsList(myList,4));
    assert(belongsList(myList,8));
    puts("OK!");
    return 0;
   }
