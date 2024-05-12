#include <stdio.h>

int
neg(int n){
    return -n;
}

int
main (){
    int c=2;
    c=neg(c);
    printf("%d\n",c);
    return 0;
}