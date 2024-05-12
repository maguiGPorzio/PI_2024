#include <stdio.h>
#include "getnum.h"

int main() {
    int lado=getint("Indique la longitud del lado del cuadrado: "),a=1,b;
    while (a<=lado){
        b=1;
        while (b<=lado){
            printf("*");
            b+=1;
        }
        a+=1;
        printf("\n");
    }
    return 0;
} 