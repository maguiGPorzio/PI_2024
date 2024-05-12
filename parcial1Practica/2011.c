/*
Escribir una función que reciba dos vectores de enteros y la dimensión de cada uno y retorne:
• 1 si todos los elementos del primer vector están en el segundo
• 2 si todos los elementos del segundo vector están en el primero
• 0 en caso contrario
*/
#include <stdio.h>

int
presenciaElementos (const int vec1[], unsigned dim1, const int vec2[], unsigned dim2);
int
vecEnVec (const int vec1[], unsigned dim1, const int vec2[], unsigned dim2);
int
presenciaElemento(int elemento, const int vec[], unsigned dim);


int
main (){
    int v1[]={6,5,8,9,7}, v2[]={5,6,7,9,8};
    printf("%d\n",presenciaElementos(v1,5,v2,5));
    return 0;
}

int
presenciaElementos (const int vec1[], unsigned dim1, const int vec2[], unsigned dim2){
    if (vecEnVec(vec1,dim1,vec2,dim2)){
        return 1;
    }

    if (vecEnVec(vec2,dim2,vec1,dim1)){
        return 2;
    }

    return 0;
}


int
vecEnVec (const int vec1[], unsigned dim1, const int vec2[], unsigned dim2){
    for (int i=0 ; i<dim1 ; i++){
        if (!presenciaElemento(vec1[i],vec2,dim2)){
            return 0;
        }
    }
    return 1;
}

int
presenciaElemento(int elemento, const int vec[], unsigned dim){
    for(int i=0 ; i<dim ; i++){
        if (elemento==vec[i]){
            return 1;
        }
    }
    return 0;
}