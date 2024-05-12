#include <stdio.h>

double
neg(double n){
    return -n;
}

int
main (){
    double i=5.42;
    i=neg(i);
    printf("%g\n",i);
    return 0;
}