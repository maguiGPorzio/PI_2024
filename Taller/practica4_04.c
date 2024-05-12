/*
Escribir la función interseccion que recibe dos arreglos y sus dimensiones y
obtiene en un tercer arreglo la intersección de los dos primeros. Asumir que los
arreglos no están ordenados, y que no hay elementos repetidos dentro del mismo arreglo.
*/
#include <stdio.h>

void inters (int const vec1[], unsigned int dim1, int const vec2[], unsigned int dim2, int vec3[]);
int presenciaElem (int const vec[],unsigned int dim,int num);

int
main (){
    int v1[]={7,9,3,5,15}, v2[]={5,6,7,9,8}, v3[6], i=0;
    inters(v1,5,v2,5,v3);
    while (i<6){
        printf("%d\n",v3[i]); i++;
    }
    return 0;
}

int 
presenciaElem (int const vec[],unsigned int dim,int num){
    int esta=0;
    for (int i=0 ; i< dim && !esta ; i++){
        if (vec[i]==num){
            esta=!esta;
        }
    }
    return esta;
}

void 
inters(int const vec1[], unsigned int dim1, int const vec2[], unsigned int dim2, int vec3[]){
    int i=0,j=0;
    while (i<dim1){
        if (presenciaElem(vec2,dim2,vec1[i])){
                vec3[j++]=vec1[i];
        }
        i++;
    }
}