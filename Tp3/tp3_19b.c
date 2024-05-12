#include <stdio.h>
#include "getnum.h"

int main() {
    int num,punto=0,contadorEntero=0,ContadorDecimal=0;
    puts("Ingrese un numero real: ");
    while ((num=getchar())!='\n' && num!=EOF){
        if (num=='.'){
            punto=1;
        }
        else if (punto==1 && num=='5'){
            ContadorDecimal+=1;
        }
        else if (num=='5'){
            contadorEntero+=1;
        }
    }
    printf("La cantidad de digitos iguales a '5' de la parte entera son %d y de la parte decimal son %d\n",contadorEntero, ContadorDecimal);
    return 0;
    }