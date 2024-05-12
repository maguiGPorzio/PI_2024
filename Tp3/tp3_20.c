#include <stdio.h>
#define EPS 0.0000001

int main() {
    double e=1,prev=0;
    int factorial=1;
    printf("%-10s %-20s\n","N","e");
    for (int n=1;(e-prev)>EPS;n++){
        prev=e;
        printf("%-10d %11.8f \n",n,e);
        factorial*=n;
        e+=1.0/factorial;
    }
    return 0;
    }