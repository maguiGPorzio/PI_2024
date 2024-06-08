#include "/home/mgonzalezporzio/PI/multiSetADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int 
main (){
    multiSetADT m;
    m=newMultiSet();
    int n;
    assert(add(m,10)==1);
    assert(add(m,10)==2);
    assert(add(m,20)==1);
    assert(add(m,10)==3);
    assert(add(m,30)==1);
    assert(add(m,40)==1);
    assert(add(m,40)==2);
    assert(size(m) == 4); //=> retorna 4
    removeAll(m, 60); //=> no hace nada
    assert(removes(m, 10) == 2); //=> retorna 2
    assert(removes(m, 50) == 0); //=> retorna 0
    assert(removes(m, 40) == 1); //=> retorna 1
    elemType * vec=minElements(m, &n); //=> retorna un vector con los elementos 20,30,40 (no necesariamente en ese orden), y n = 3
    free(vec);
    free(m);
    puts("OK");
    return 0;
}