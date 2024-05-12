/*Escribir una función verifica que recibe como único parámetro una "matriz"
de enteros de NxN, donde N es una constante previamente definida, de tipo entero y
múltiplo de 3, por ejemplo 3, 6, 9, etc.
La función debe retornar 1 si se cumplen todas las siguientes condiciones:
● Todos los elementos de la matriz están entre 1 y 3*N inclusive
● Cada submatriz de 3x3 debe tener elementos sin repetir
● Al sumar los elementos de cada submatriz de 3x3 se obtiene el mismo
resultado
Las submatrices son similares a las del juego de Sudoku, comienzan en las
posiciones (0,0), (0,3), (3,0), (3,3), (0,6), etc
CHECKED
*/
#include <stdio.h>
#define N 3
#define DIM_SUB 3
int
verifica (int mat[][N]);
int 
verSub (int mat[][N], int filSub, int colSub);

int
main (){
    int mat[3][3]={{1,2,3},
                {4,5,6},
                {7,8,9}};
    printf("%d\n", verifica(mat));
    return 0;
}


int
verifica (int mat[][N]){
    if (N%3!=0){
        return 0;
    }
    int start=0, aux;
    for (int i=0 ; (i<N) ; i+=3){
        for (int j=0 ; (j<N) ;j+=3){
            if (!start){
                start=verSub(mat,i,j);
                if (!start){
                    return 0;
                }
                aux=start;
            }
            else if (verSub(mat,i,j)!=aux){
                    return 0;
            }
        }
    }
    return 1;
}

int 
verSub (int mat[][N], int filSub, int colSub){
    int vec[DIM_SUB*N]={0},suma=0;
    for (int i=filSub ; i<(filSub+DIM_SUB) ; i++){
        for (int j=colSub ; j<(colSub+DIM_SUB) ; j++){
            if (mat[i][j]<1 || mat[i][j]>DIM_SUB*N){
                return 0;
            }
            
            if (vec[mat[i][j]-1]==1){
                return 0;
            }
            vec[mat[i][j]-1]=1;
            suma+=mat[i][j];
        }
    }
    return suma;
}