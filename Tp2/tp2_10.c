#include <stdio.h>
#include "getnum.h"

int 
main() {
    int num;
    do 
        puts("Escriba u intervalo de tiempo expresado en segundos:");
    while ((num=getint(""))<=0);
    
    printf("Los segundos ingresados equivalen a %d horas, %d minutos, %d segundos \n",num/3600,(num%3600)/60,(num%3600)%60);
    
    return 0;
}