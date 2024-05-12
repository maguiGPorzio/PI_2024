//matriz escalable
#include <stdio.h>
#define N 4

int
esEscalable (int mat[][N]);
int 
sumaFila (int matFil[]);

int
main(void){
    int m[][N] = {{1,1,1,1}, {1,2,1,1}, {2,2,1,1}, {3,2,1,1}};
    int resultado = esEscalable(m);
    printf("%d ", resultado);
    return 0;
}

int
esEscalable (int mat[][N]){
    int anterior=sumaFila(mat[0]), sumFil;
    for (int i=1 ; i<N ; i++){
        sumFil=sumaFila(mat[i]);
        if ((anterior+1)!=sumFil){
            return 0;
        }
        anterior=sumFil;
    }
    return 1;

}

int 
sumaFila (int matFil[]){
    int sum=0;
    for (int i=0 ; i<N ; i++){
        sum+=matFil[i];
    }
    return sum;
}