#include <stdio.h>
#include "getnum.h"

int main() {
    int numDecimal=getint("Ingrese un numero entero positivo en base decimal \n"),numBinarioAlReves=1,numBinario=1,length=1;
    while (numDecimal>=1){
        if ((numDecimal%2)==0){
            numBinarioAlReves*=10;
        }
        else {
            numBinarioAlReves=(numBinarioAlReves*10)+1;
        }
        numDecimal/=2;
    }
    while (numBinarioAlReves>=1) {
        length*=10;
        if ((numBinarioAlReves%10)==1){
            numBinario=(numBinario*10)+1;
        }
        else {
            numBinario*=10;
        }
        numBinarioAlReves/=10;
    }
    printf("El numero en binario es %d \n", (((numBinario-length)-1)/10)); 
    return 0;
    }

    
