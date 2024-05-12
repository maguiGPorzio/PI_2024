#include <stdio.h>
#include "getnum.h"
#include <math.h>
#include <stdlib.h>
#define DenNoCero(denom) {\
    do{\
        denom=getint("");\
        if (denom==0){\
            printf("El denominador no puede ser 0. Ingrese otro: \n");\
        }\
    }\
    while (denom==0);\
}


int DivisorComunMaximo (int num1,int num2);
void Simplificar_fracciones (int numerador,int denominador);
void SumarFracciones (int num1, int den1, int num2, int den2);
int menu ();

int 
main (){
    int opcion,num,den,num2,den2;
    do{ 
        opcion= menu();
        switch (opcion){
            case 1:
                num=getint("Ingrese el numerador: \n");
                printf("Ingrese el denominador distinto de cero: \n");
                DenNoCero(den);
                Simplificar_fracciones(num,den);
                break;

            case 2:
                num=getint("Ingrese el numerador de la primer fraccion: \n");
                printf("Ingrese el denominador de la primera fraccion (distinto de cero): \n");
                DenNoCero(den);
                num2=getint("Ingrese el numerador de la segunda fraccion: \n");
                printf("Ingrese el denominador de la segunda fraccion (distinto de cero): \n");
                DenNoCero(den2);
                printf("La suma es ");
                SumarFracciones(num,den,num2,den2);
                break;

            case 3:
                break;

            default:
                printf("La opcion elegida es incorrecta\n");
                break;
        }
    } while (opcion!=3);

    return 0;

}


int 
menu (){
    int opcion;

    printf("\n1-Simplificar una fracción\n");
    printf("2-Sumar dos fracciones\n");
    printf("3-Terminar la ejecución\n");

    opcion=getint(" ");

    return opcion;
}

int 
DivisorComunMaximo (int a,int b){
    int num1,num2;

    num1=(a>b) ? a : b;
    num2=(a<b) ? a : b;

    num1=((num1<0) ? -num1 : num1);
    num2=((num2<0) ? -num2 : num2);

    int auxi=num1%num2;

	while (auxi>0)
	{	
		num1 = num2;
        num2 = auxi;
        auxi = num1 % num2 ;
    }
	return num2;
}

void
Simplificar_fracciones (int numerador,int denominador){
    int auxNum, auxDen,mcd;
    auxNum=numerador;
    auxDen=denominador;
    mcd=fabs(DivisorComunMaximo(numerador,denominador));
    if (fabs(mcd)!=1){
        auxDen/=mcd;
        auxNum/=mcd;
    }
    printf("\n%d/%d simplificada es %d",numerador,denominador,((numerador*denominador)>0) ? abs(auxNum) : auxNum);
    if (auxDen!=1){
        printf("/%d\n",((numerador*denominador)>0) ? abs(auxDen) : auxDen);
    }
    return;
}

void
SumarFracciones (int num1, int den1, int num2, int den2){
    int denComun,numComun;
    denComun=den1*den2;
    numComun=(num1*den2)+(num2*den1);
    Simplificar_fracciones(numComun,denComun);
    return;
}
