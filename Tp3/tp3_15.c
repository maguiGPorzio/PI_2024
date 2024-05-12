#include <stdio.h>
#include "getnum.h"

int main() {
    int numBinario=getint("Ingrese un numero entero en base binaria \n"),numDecimal=0,multiplicando;
    multiplicando=1;  
    while (numBinario!=0){ 
        numDecimal+=(numBinario%10)*multiplicando; 
        multiplicando*=2;
        numBinario/=10;
    }
    printf("El numero en decimal es %d \n", numDecimal);
    return 0;
} 