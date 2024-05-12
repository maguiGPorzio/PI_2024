/*
Reescribir el ejercicio 10 de la práctica 5 de forma tal que quede separado correctamente el front-end del back-end.

Para la opción de simplificar una fracción, la obtención del numerador y denominador pertenece al front-end. 
Luego se invoca a una función de back-end que recibe esos parámetros y los modifica. 
¿Cómo se puede hacer para que la función de back-end reciba ambos y los pueda modificar? 

*/

// tengo problemas con el 0 

#include <stdio.h>
#include "getnum.h"
#include <math.h>
#include <stdlib.h>
#define NUM(f) f[0]
#define DEN(f) f[1]
#define INCORRECTO 0
#define CORRECTO 1
#define DIM_FRACC 2

int menu ();
int validarMenu (int opcion);
int numerador();
int denominador();
int valDen(int den);
int DivComMax(int num1,int num2);
void Simp_fracc (int fraccion[DIM_FRACC]);
void SumarFracciones (const int fraccion1[DIM_FRACC], const int fraccion2[DIM_FRACC],int sumFracc[DIM_FRACC]);

int 
main (){
    int frac1[DIM_FRACC],frac2[DIM_FRACC],frac3[DIM_FRACC],opcion;
    do {
        opcion=menu();

        switch (opcion){
            case 1:
                NUM(frac1)=numerador();
                DEN(frac1)=denominador();
                printf("\n%d/%d simplificada es ",NUM(frac1),DEN(frac1));
                Simp_fracc(frac1);
                printf("%d",((DEN(frac1)*NUM(frac1))>0) ? abs(NUM(frac1)) : NUM(frac1));
                if (DEN(frac1)!=1){
                    printf("/%d",((DEN(frac1)*NUM(frac1))>0) ? abs(DEN(frac1)) : DEN(frac1));
                }
                break;

            case 2:
                printf("Para la primer fraccion: \n");
                NUM(frac1)=numerador();
                DEN(frac1)=denominador();
                printf("Para la segunda fraccion: \n");
                NUM(frac2)=numerador();
                DEN(frac2)=denominador();
                SumarFracciones(frac1,frac2,frac3);
                printf("La suma de las fracciones es %d",((DEN(frac3)*NUM(frac3))>0) ? abs(NUM(frac3)) : NUM(frac3));
                if (DEN(frac3)!=0){
                    printf("/%d",((DEN(frac3)*NUM(frac3))>0) ? abs(DEN(frac3)) : DEN(frac3));
                }
                break;
            
            case 3:
                break;
        }
    }
    while (opcion!=3);
}

int menu (){ //front end 
    int opcion;
    do {
        printf("\n1-Simplificar una fracción\n");
        printf("2-Sumar dos fracciones\n");
        printf("3-Terminar la ejecución\n");
        opcion=getint(" ");
    }
    while (!(validarMenu(opcion)));
    return opcion;
}

int validarMenu (int opcion){ //back end 
    if (opcion<1 || opcion>3){
        return INCORRECTO;
    }
        return CORRECTO;
}

int 
numerador(){ //front end 
    int num;
    return num=getint("Ingrese el numerador: \n");
}

int 
denominador(){ //front end 
    int den;
    do{
        printf("Ingrese el denominador distinto de cero: \n");
        den=getint("");
    }
    while (!(valDen(den)));

    return den;
}

int 
valDen(int den){ //back end 
    if (den){
        return CORRECTO;
    }
    else{
        return INCORRECTO;
    }
}

int 
DivComMax(int num1,int num2){ //back end 
    int mayor,menor;

    mayor=(num1>num2) ? num1 : num2;
    menor=(num1<num2) ? num1 : num2;

    if (menor){
        mayor=((mayor<0) ? -mayor : mayor);
        menor=((menor<0) ? -menor : menor);

        int auxi=mayor%menor;

        while (auxi>0)
        {	
            mayor = menor;
            menor = auxi;
            auxi = mayor % menor ;
        }
        return menor;
    }
    else {
        return mayor;
    }
}

void Simp_fracc (int frac1[DIM_FRACC]){ //back end 
    int mcm;
    mcm=abs(DivComMax(NUM(frac1),DEN(frac1)));
    NUM(frac1)/=mcm;
    DEN(frac1)/=mcm;
    return;
}

void
SumarFracciones (const int frac1[DIM_FRACC], const int frac2[DIM_FRACC], int frac3[DIM_FRACC]){ //back end
    DEN(frac3)=DEN(frac1)*DEN(frac2);
    NUM(frac3)=(DEN(frac1)*NUM(frac2))+(DEN(frac2)*NUM(frac1));
    Simp_fracc(frac3);
    return;
}