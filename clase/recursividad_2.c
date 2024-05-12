/*
Escribir una función recursiva que reciba un arreglo de enteros y su dimensión, y devuelva 1 si el 
mismo es nulo y 0 en caso contrario. Es nulo si es vacío o todos son valores son cero.
*/

int
esNulo(int vec[], int dim){
    if (dim==0){
        return 1;
    }

    if (vec[dim-1]!=0){
        return 0;
    }

    return esNulo(vec,dim-1);
}



