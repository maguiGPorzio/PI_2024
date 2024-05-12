#include <stdio.h>
#include "getnum.h"

int 
numerosAmigos(int num1,int num2) {
    int suma1=0,suma2=0,aux=1;
    while (aux<num1 && aux<num2) {
        if (num1%aux==0) {
            suma1+=aux;
        }
        if (num2%aux==0) {
            suma2+=aux;
        }
        aux+=1;
    }
    if (suma1==num2 && suma2==num1) {
        return 1;
    }
    return 0;
}


int 
main(){
    int num1=220;
    int num2=284;
    printf("%s \n",(numerosAmigos(num1, num2)) ? "FUNCA" : "NO FUNCA");
    return 0;
}