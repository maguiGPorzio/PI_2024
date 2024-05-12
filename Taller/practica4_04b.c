/*
Escribir la función interseccion que recibe dos arreglos y sus dimensiones y obtiene en un tercer arreglo 
la intersección de los dos primeros. 
Asumir que los arreglos están ordenados, y que no hay elementos repetidos dentro del mismoarreglo.
*/

int
interseccion(const int v1[],int dim1,const int v2[],int dim2,int res[]){
    int i=0,j=0,k=0;
    while (i<dim1 || j<dim2){
        if (v1[i]>v2[j]){
            j++;
        }
        else if (v1[i]<v2[j]){
            i++;
        }
        else{
            res[k++]=v1[i++];
            j++;
        }
    }
    return k;
}

