#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int aleatorio(int left, int right);

int main(void){

    int rand=aleatorio(1, 10);
    assert(rand<=10 && rand>=1);
    rand=aleatorio(-10, -2);
    assert(rand<=-2 && rand >=-10);
    assert(aleatorio(0,0)==0);
    assert(aleatorio(10,10)==10);
    
    // Solo estamos testeando que caiga dentro del rango, habria que realizar un test
    // mas sofisticado que analizara la desviacion estandar
    for(int i=0; i < 1000; i++) {
        rand = aleatorio(-10, 10);
        assert(rand<=10 && rand >=-10);    
    }

    puts("OK!");
    return 0;
}

int aleatorio(int left, int right){
    return ((int)((rand () / ((double) RAND_MAX+1))*(right-left+1)) + left);
}