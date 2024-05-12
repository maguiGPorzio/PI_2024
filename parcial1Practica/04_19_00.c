/*
funcion resta
recibe dos arreglos de numeros reales y deja en un tercer arreglo la resta entre los dos primeros 
todos los arrelgos tienen al entero -1 como marca de fin

CHECKED
*/



#include <stdio.h>

void 
resta(const int v1[], const int v2[], int v3[]);
int
presencia (int elem1, const int v2[]);

int
main(void){
    int v1[] = {1, 9, 2, 6, 3, 6, -1};
    int v2[] = {3, 2, 8, 2, -1};
    int dimV3 = sizeof(v2)/sizeof(v2[0]);
    int v3[dimV3];
    resta(v1, v1, v3);
    for(int i = 0; v3[i] != -1; i++)
        printf("%d ", v3[i]);
    putchar('\n');

    return 0;
}

void 
resta(const int v1[], const int v2[], int v3[]){
    int h=0;
    for (int i=0 ; v1[i]>-1 ; i++){
        if (!presencia(v1[i],v2)){
            v3[h++]=v1[i];
        }
    }
    v3[h]=-1;
}

int
presencia (int elem1, const int v2[]){
    for (int i=0 ; v2[i]>-1 ; i++){
        if (elem1==v2[i]){
            return 1;
        }
    }
    return 0;
}