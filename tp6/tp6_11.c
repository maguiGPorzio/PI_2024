/*
Escribir una función que ordene las filas de una matriz de cualquier tamaño, según el valor de una determinada
columna. La función recibirá como parámetros la matriz, la cantidad de filas, la cantidad de columnas y el número de
columna a tomar como clave de ordenación, teniendo en cuenta que la primera columna es la columna 1 (uno).
Para ordenar se puede usar el bubble sort o selection sort 

{3,5,7,2,1}
selection sort

0- {3,5,7,2,1} --> min: indice 4 --> swapeo la posicion 0 con la 4 --> {1,5,7,2,3}
1-{1,5,7,2,3} --> min: indice 3 --> swapeo la posicion 1 con la 3 --> {1,2,7,5,3}
....
*/


#define MAXCOL 10
void 
ordenaMatriz (int matriz[][MAXCOL], int fil, int col, int colOrd){
    for (int i=0 ; i<fil-1 ; i++){
        int menor=i;
        for (int j=i+1 ; j<fil ; j++){ //encontrar el indice minimo
            if (matriz[j][colOrd-1]<matriz[menor][colOrd-1]){
                menor=j;
            }
        }
        if (i!=menor){
            swap(matriz[i],matriz[menor],col);
        }
    }
    return;
}

void swap(int v1[], int v2[], int dim){
    for (int i=0 ; i<dim ; i++){
        int aux=v1[i];
        v1[i]=v2[i];
        v2[i]=aux;
    }
    return;
}
