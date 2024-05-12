/*
Escribir la función recursiva igualesRet que recibe dos vectores que tienen
valores positivos y un -1 para indicar el final del vector y determina si ambos
son iguales (elemento a elemento, en igual posición)
Luego hacer una función recursiva igualesVoid que recibe los dos vectores
y guarda en un parámetro de entrada salida si son iguales o no. Esta función
será void.

● A=[1,2,3,4,5,-1]
● B=[2,3,-1]
● No son iguales
● A=[1,2,3,4,5,-1]
● B=[1,2,3,4,5,-1]
● Son iguales

*/

#include <stdio.h>

#include <stdio.h>
#include <assert.h>
 
int igualesRet(const int v1[], const int v2[]);
void igualesVoid(const int v1[], const int v2[], int * rta);
 
int
main(void) {
    int resultado;
    int a[] = {9, 4, 3, 2, 3, 7,-1};
    int b[] = {9, 4, 3, 2, 3, 7,-1};
    int c[] = {7, 3, 2, 3, 4, 9,-1};
    int d[] = {9, 4, 3, -1};
    int e[] = {-1};
 
    assert(igualesRet(a, b) == 1);
    assert(igualesRet(b, c) == 0);
    assert(igualesRet(c, d) == 0);
    assert(igualesRet(d, e) == 0);
 
    igualesVoid(a, b, &resultado);
    assert(resultado == 1);
    igualesVoid(b, c, &resultado);
    assert(resultado == 0);
    igualesVoid(c, d, &resultado);
    assert(resultado == 0);
    igualesVoid(d, e, &resultado);
    assert(resultado == 0);
 
    printf("OK!\n");
    return 0;
}

int 
igualesRet(const int v1[], const int v2[]){
    if ((*v1)==-1 || (*v2)==-1){
        return (*v1)==(*v2);
    }

    return *v1==*v2 && igualesRet(v1+1,v2+1);
}

void 
igualesVoid(const int v1[], const int v2[], int * rta){

    if ((*v1)==-1 || (*v2)==-1){
        *rta=(*v1)==(*v2);
        return;
    }

    if ((*v1)!=(*v2)){
        *rta=0;
        return;
    }

    igualesVoid(v1+1,v2+1,rta);
}