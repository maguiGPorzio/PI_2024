#include <stdio.h>
#include "getnum.h"

int main() {
    int lado=getint("Indique la longitud del lado del cuadrado: ");
    for(int a=1;a<=lado*lado;a+=1) {
        printf("*");
        if ((a%lado)==0){
            printf("\n");
        }
    }
    return 0;
} 