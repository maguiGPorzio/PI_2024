#include <stdio.h>
#include "getnum.h"
#include <math.h>

int lugar (int num, int pos);

int
main( void ) {
    int boleto, esCapicua=1;
	int  j,h=0,aux;
	boleto=getint("Ingrese un numero: ");
    aux=boleto;
    while (aux>0){
        h+=1;
        aux/=10;
    }
    for (j=1; j<=2; j++) {
        if ( lugar(boleto, j) != lugar(boleto,h-j+1)) {	
            esCapicua=0;
            break;
        }
    }
    printf("El boleto %ses capicúa \n",(esCapicua)? "":"no ");
    if (esCapicua){
        return 1;
    }
    else{
        return 0;
    }
}

int 
lugar(int num, int pos) {	
    return (num / (int)pow(10, pos-1)) % 10;
}
