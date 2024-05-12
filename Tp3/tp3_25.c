/*
Escriba un programa que lea de entrada estándar un número entero positivo y calcule la cantidad de bits en ‘1’ que contiene.

Por ejemplo:

Si el número es 1, imprime 1
Si el número es 64, imprime 1
Si el número es 229, imprime 5
*/

#include <stdio.h>
#include "getnum.h"


int main (){
    int num=getint("Ingrese un numero: "),aux,conotador=0;
    aux=num;
    while (num>0){
        if (num%2==1){
            conotador+=1;
        }
        num/=2;
    }
    printf("La cantidad de bits %c en %d es %d\n",'1',aux,conotador);
    return 0;
}