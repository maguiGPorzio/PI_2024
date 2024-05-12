/*
Escribir una función recursiva que reciba como parámetros dos números enteros y devuelva el máximo común 
divisor. Utilizar el algoritmo de mcd.
*/

/* 
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
*/


#include <stdio.h>

int 
mcd(int num1, int num2){
    if (num2==0){
        return num1;
    }
    
    return mcd(num2,num1%num2);
}

int 
main (){
    printf("%d\n",mcd(0,5));
    return 0;
}