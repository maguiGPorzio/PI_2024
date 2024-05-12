/*
Escribir un programa que convierta enteros de una base a otra. Los números entre y después de los
símbolos '<' y '>' indican la base de entrada y de salida respectivamente. Dichos números serán decimales
entre 2 y 10.

Ejemplo: la cadena de entrada < 5 > 2 indica que leerá números enteros en base 5 y los imprimirá
en su equivalente binario. Luego, si se ingresa 41 se lo deberá pasar a 10101.
*/
#include <stdio.h>
#include "getnum.h"

void
base_a_decimal (int * num, int base){
    int decimal=0, i=1;
    while ((*num)>0){
        decimal+=i*((*num)%10);
        i*=base;
        (*num)/=10;
    }
    *num=decimal;
}

void
decimal_a_base (int * num, int base){
    int numEnBase=0, i=1;
    while ((*num)>0){
        numEnBase+=((*num)%base)*i;
        i*=10;
        (*num)/=base;
    }

    *num=numEnBase;
}


int
main (){
    int base_in, base_out;

    do{ 
    printf("Ingrese la base de entrada y la base de salida entre 2 y 10: ");
    scanf("< %d > %d", &base_in, &base_out);
    }
    while (base_in < 2 || base_in > 10 || base_out < 2 || base_out > 10);

    int num;
    printf("Ingrese el número en base %d: ", base_in);
    scanf("%d", &num);

    base_a_decimal(&num,base_in);
    decimal_a_base(&num,base_out);

    printf("El número en base %d es: ", base_out);
    printf("%d\n",num);
    return 0;
}