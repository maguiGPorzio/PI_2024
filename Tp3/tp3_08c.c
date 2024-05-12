#include <stdio.h>

int 
main(){
    int fahr,celsius;
    int lower, upper, step;

    lower=0;
    upper=300;
    step=20;

    printf("%-4s %-7s \n","fahr","celsius");

    fahr=upper;
    while (fahr>=lower){
        celsius=(5*(fahr-32))/9;
        printf("%-4d\t%-7d\n",fahr,celsius);
        fahr=fahr-step;
    }
    return 0;
}