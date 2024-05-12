/*
Escribir una función dondeEsta que, dado un arreglo ordenado de números enteros,
su dimensión, y un número determinado, determine si el número está y en qué
posiciones. El arreglo está ordenado en forma creciente y puede tener elementos
repetidos.
*/
#include <stdio.h>

int dondeEsta(int const arr1[], unsigned int dim, int elemento, int arr2[]);

int 
main (){
    int vec[]={3,5,5,5,5,6,7,7,8,9,12,15}, vec2[7];
    int dimNueva=dondeEsta(vec,12,5,vec2);
    printf("%d\n",vec2[0]);
    printf("%d\n",vec2[1]);
    printf("%d\n",vec2[2]);
    printf("%d\n",vec2[3]);
    printf("%d\n",vec2[4]);
    printf("%d\n",vec2[5]);
    printf("%d\n",vec2[6]);
    printf("%d\n",dimNueva);
    return 0;
}

int
dondeEsta(int const arr1[], unsigned int dim, int elemento, int arr2[]){
    int j=0;
    for (int i=0 ; (i<dim) && (arr1[i]<=elemento) ; i++){
        if (arr1[i]==elemento){
            arr2[j++]=i;
        }
    }
    return j;
}

//resolucion de la catedra muy buena 