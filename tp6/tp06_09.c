/*
Se desea calcular la desviación estándar de un arreglo de números enteros. 
Los números del arreglo toman valores entre 0 y 15 inclusive, por lo que para almacenar cada número se 
utilizarán solo 4 bits, pudiendo almacenar dos números en un solo byte. 
Para representar dicho arreglo se utilizará un vector de caracteres, 
donde cada elemento del vector contendrá dos números (uno en los cuatro bits superiores y 
el otro en los cuatro bits inferiores). Escribir una función que reciba un arreglo como el mencionado 
anteriormente y la cantidad de números que contiene y retorne en su nombre la desviación estándar de los 
números recibidos.
Ejemplo: Si se define el siguiente arreglo:

	unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
 
	Representa al arreglo de los elementos: 3, 7, 15, 2, 0, 3, 4, 10, 15, 15.

*/
#include <stdio.h>
#include "math.h"
#define MASK 0xF

double desv(const char vector[], int cantnum);

double desv(const char vector[], int cantnum){
    if (cantnum!=0){
        int nuevo[cantnum];
        int i=0,j=0,k=0,num;
        double promedio=0, desv=0;
        while (j<cantnum){
            num=((vector[i]>>4) & MASK); //numero 4 bits izquierda 
            nuevo[j++]=num;
            promedio+=num;
            if (j<cantnum){
                num=(vector[i] & MASK); //numero 4 bits derecha
                nuevo[j++]=num;
                promedio+=num;
            }
            i++;
        }
        promedio/=cantnum;
        while (k<cantnum){
            desv+=(nuevo[k++]-promedio)*(nuevo[k++]-promedio);
        }
        return sqrt(desv/cantnum);
    }
    else{
        return 0;
    }
}

