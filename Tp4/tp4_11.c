#include <stdio.h>
#include "getnum.h"

int 
mayor (int a, int b,int c) {
    if (a>b && a>c) {
        return a;
    }
    else if (b>c){
        return b;
    }
    else {
        return c;
    }
    
}

int 
main () {
    int a=getint("Ingrese a: "), b=getint("Ingrese b: "),c=getint("Ingrese c: ");
    printf("El mayor entre %d, %d y %d es %d \n",a,b,c,mayor(a,b,c));
}
