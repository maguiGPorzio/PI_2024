#include <stdio.h>


void 
nPrimos(n){
    int aux=0, num=2,;
    while (aux<=n){
        if (esPrimo(num)){
            aux+=1;
            printf("%d",num);
        }
        num+=1;
    }
    printf("\n");
    return ();
}

int 
main(){
    int num=getint("Ingrese un numero: \n");
    printf("%s \n",nPrimos(num));
    return 0;
}
