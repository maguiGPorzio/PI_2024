#include <stdio.h>
#define N 4

int 
clasificarMat (int mat[][N]);
int 
simetrica (int mat[][N]);
int 
antisimetrica (int mat [][N]);

int
main(void){
    int m[][N] = {{0,-1,1,2}, {1,0,2,-3}, {-1,-2,0,-21}, {-2,3,21,0}};
    int resultado = clasificarMat(m);
    printf("%d ", resultado);
    return 0;
}

int 
clasificarMat (int mat[][N]){
    if (simetrica(mat)){
        return 1;
    }
    if (antisimetrica(mat)){
        return -1;
    }
    return 0;

}

int 
simetrica (int mat[][N]){
    for (int i=0 ; i<N ; i++){
        for (int j=i ; j<N ; j++){
            if (mat[i][j]!=mat[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

int 
antisimetrica (int mat [][N]){
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ; j++){
            if (mat[i][j]!=-mat[j][i]){
                return 0;
            }
        }
    }
    return 1;
}