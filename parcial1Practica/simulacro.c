/*
eliminar del vector1 los elementos que tenga en comun con v2 y devolver la nueva dimension de v1 (estan ordenadas)
CHECKED
*/
#include <stdio.h>
#define IGUAL 1
#define MAYOR 2
#define MENOR 3

int eliminar(int v1[], unsigned dim1, const int v2[], unsigned dim2);
int compara (int elem1, int elem2, int dim1, int dim2, int i, int j);

int
main (){
    int v1[]={20,45,67,90},v2[]={1,4,8,9};
    printf("%d\n",eliminar(v1,4,v2,4));
    return 0;
}

int
eliminar(int v1[], unsigned dim1, const int v2[], unsigned dim2){
    int i=0,j=0,m=0;
    while (i<dim1 || j<dim2){
        switch (compara(v1[i],v2[j],dim1,dim2,i,j)){
            case IGUAL:
                i++;
                j++;
                break;
            case MAYOR:
                j++;
                break;
            case MENOR:
                v1[m++]=v1[i++];
                break;
        }
    }
    return m;
}

int
compara (int elem1, int elem2, int dim1, int dim2, int i, int j){
    if (i==dim1){
        return MAYOR;
    }
    if (j==dim2){
        return MENOR;
    }
    if (elem1<elem2){
        return MENOR;
    }
    if (elem1==elem2){
        return IGUAL;
    }
    return MAYOR;
}


