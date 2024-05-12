/*
Escribir una función recursiva que reciba un entero que representa la altura central de una regla y muestre por 
pantalla los tamaños de las subdivisiones a cada lado, sabiendo que cada subdivisión es la mitad de la anterior. 
*/
#include <stdio.h>

void 
subdivision (int alturaCentral);

int
main (){
    int p=8;
    subdivision(p);
    return 0;
}

void 
subdivision (int h){
    if (h>0){
        subdivision(h/2);
        printf("%d",h);
        subdivision(h/2);
    }
}