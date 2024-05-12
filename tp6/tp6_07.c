/*
Hacer una función que reciba dos parámetros de entrada representando arreglos de números enteros positivos, 
ordenados en forma ascendente y sin elementos repetidos. El último elemento de cada arreglo es -1. 
La función debe devolver en un tercer parámetro de salida un arreglo ordenado con la unión de los dos primeros,
también terminado en -1.

	Ejemplo: Dados v1 y v2 arreglos de enteros, se espera que la unión sea:
		v1 = {1,2,3,-1} y v2 = {2,3,4,-1}  →  unión = {1,2,3,4,-1}.
		v1 = {1,2,3,-1} y v2 = {1,2,3,-1}  →  unión = {1,2,3,-1}.

Recorrer una sola vez cada arreglo.
*/
#include <stdio.h>

/*void unirArreglos (const int v1[], const int v2[], int v3[]);

int
main (){

    int v1[] = { 1, 5, 15, 30, 35, 45, 55, -1};
    int v4[] = { 2, 3, 15, 16, 33, 35, 45, 65, -1};
    int v3[30];
    unirArreglos(v1,v4,v3);
    printf("%d\n",v3[0]);
    printf("%d\n",v3[1]);
    printf("%d\n",v3[2]);
    printf("%d\n",v3[3]);
    printf("%d\n",v3[4]);
    printf("%d\n",v3[5]);
    printf("%d\n",v3[6]);
    printf("%d\n",v3[7]);
    printf("%d\n",v3[8]);
    printf("%d\n",v3[9]);
    printf("%d\n",v3[10]);
    printf("%d\n",v3[11]);
    printf("%d\n",v3[12]);
    printf("%d\n",v3[13]);
    printf("%d\n",v3[14]);
    printf("%d\n",v3[15]);
    return 0;
}
*/

void 
unirArreglos (const int v1[], const int v2[], int v3[]){
    int i=0, j=0, k=0; //i dimension v1, j dimension v2, k dimension v3
    while (v1[i]!=-1 || v2[j]!=-1){
        if (v1[i]!=-1 && v2[j]!=-1){ 
            if (v1[i]==v2[j]){
                v3[k++]=v1[i++];
                j++;
            }
            else if (v1[i]<v2[j]){
                v3[k++]=v1[i++];
            }
            else {
                v3[k++]=v2[j++];
            }
        }
        else if (v1[i]==-1){
            v3[k++]=v2[j++];
        }
        else{
            v3[k++]=v1[i++];
        }
    }
    v3[k]=-1;
    return;
}
