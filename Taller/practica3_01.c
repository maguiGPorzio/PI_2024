#include <stdio.h>
#include <math.h>
#include "getnum.h"

int
esPrimo (int num){
    int aux=2, primo=0;
    if (num!=0){
        if (num<0){
            num*=-1;
        }   
        printf("estoy aca\n");
        double root = sqrt(num);
        while (aux<(root) && primo==0){
            printf("%g\n", sqrt(num));
            if (num%aux==0){  // si aux es 0 aca trata de dividir por 0 por eso da ese erorr
                primo=1;
            }
            aux+=1;
        }
    }
    return primo;
}

int 
main(){
    int num=getint("Ingrese un numero: \n");
    printf("%s \n",(esPrimo(num)) ? "ES PRIMO" : "NO ES PRIMO");
    return 0;
}