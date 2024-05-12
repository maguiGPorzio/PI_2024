#include <stdio.h>


// [1,1,1,2,3,3,3,4,5,5,6]
int eliminaRepOrden(const int original[], int dimOrig, int resultado[]);

int 
main (){
    int v[]={0,1,2,3,4,5,6,};
    int dim=7;
    int res[20];
    printf("%d\n", eliminaRepetidosOrdenado(v,dim,res));
    printf("%d\n",res[0]);
    printf("%d\n",res[1]);
    printf("%d\n",res[2]);
    printf("%d\n",res[3]);
    printf("%d\n",res[4]);
    printf("%d\n",res[5]);
    printf("%d\n",res[6]);
    return 0;
}
/* 
int //hecha por mi
eliminaRepOrden(const int original[], int dimOrig, int resultado[]){
    int dimNuevo=0;
    if (dimOrig>0){
        int posicion=0;
        resultado[dimNuevo++]=original[posicion];
        for ( ; posicion<dimOrig-1 ; posicion++){
            if (original[posicion]!=original[posicion+1]){
                resultado[dimNuevo++]=original[posicion+1];
            }
        }
    }
    return dimNuevo;
}

int
eliminaRepOrden( const int original[], int dimOrig, int resultado[]) {
	int dimResult = 0;
	int i;
	
	if (dimOrig > 0) {
		resultado[0] = original[0];
		for (i = 1, dimResult = 1; i < dimOrig; i++)
			if (original[i] != original[i-1])
				resultado[dimResult++] = original[i];
	}
	return dimResult;
}
*/

/* Otra versión, también correcta: comparar contra el último elemento copiado. */

int
eliminaRepOrden( const int original[], int dimOrig, int resultado[]) {
	int dimResult = 0;
	int i;
	
	if (dimOrig > 0) {
		resultado[0] = original[0];
		for (i = 1, dimResult = 1; i < dimOrig; i++)
			if (original[i] != resultado[dimResult-1])
				resultado[dimResult++] = original[i];
	}
	return dimResult;
}

