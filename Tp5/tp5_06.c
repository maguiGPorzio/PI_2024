/*
Escribir un programa que ofrezca las siguientes opciones para accionar sobre un caracter leído desde la entrada estándar. 
Utilizar distintas funciones (con no más de 4 líneas) para cada una de las opciones y una función para el menú de opciones:

Convertir de mayúscula a minúscula. 
Convertir de minúscula a mayúscula. 
Imprimir el carácter siguiente. 
Imprimir la siguiente letra en forma circular (si la letra es 'z', debe imprimir 'a')
*/

#include <stdio.h>
#include <ctype.h>
#include "getnum.h"

int menu();
int toUpp(int caracter);
int toLow(int caracter);
int carSiguiente(int caracter);
int letraSiguiente(int caracter);

int
main (){
    int c;
    do { 
        printf("Ingrese un caracter (EOF para terminar):\n");
        c=getchar();
        
        if (c!=EOF){ 
            int opcion=menu();
            if (opcion==1){
                printf("%c\n",toLow(c));      
            }
            else if (opcion==2){
                printf("%c\n",toUpp(c));
            }
            else if (opcion==3){
                printf("%c\n",carSiguiente(c));
            }
            else{
                printf("%c\n",letraSiguiente(c));
            }
        }
    }
    while (c!=EOF);
    return 0;
}

int 
menu (){
    int opcion;
    do {
        printf("Ingrese 1 si desea convertir de mayuscula a minuscula\n");
        printf("Ingrese 2 si desea convertir de minuscula a mayuscula\n");
        printf("Ingrese 3 si desea imprimir el siguiente caracter\n");
        printf("Ingrese 4 si desea imprimir la siguiente letra\n");
    }
    while (((opcion=getint(" "))<1) || (opcion>4));
    return opcion;
}

int
toUpp(int caracter){
    if (caracter<='z' && caracter>='a'){
        caracter=caracter-'a'+'A';
    }
    return caracter;
}

int
toLow(int caracter){
    if (caracter<='Z' && caracter>='A'){
        caracter=caracter-'A'+'a';
    }
    return caracter;
}

int 
carSiguiente(int caracter){
    return caracter+=1;
}

int
letraSiguiente(int caracter){
    if ((caracter<='Z' && caracter>='A') || (caracter<='z' && caracter>='a')){
        if (caracter=='z' || caracter=='Z'){
            caracter-= ('Z'-'A');
        }
        else {
            caracter+=1;
        }
    }
    return caracter;
}
