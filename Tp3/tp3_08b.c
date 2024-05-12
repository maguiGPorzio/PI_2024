#include <stdio.h>

int 
main(){
    int fahr,celsius;
    int lower, upper, step;

    lower=0;
    upper=300;
    step=20;

    printf("%-7s %-4s \n","celsius","fahr");

    celsius=lower;
    while (celsius<=upper){
        fahr=((celsius*9)/5)+32;
        printf("%-7d\t%-4d\n",celsius,fahr);
        celsius=celsius+step;
    }
    return 0;
}