#include <stdio.h>

int main() {
    printf("%-2s %-4s %-5s %-6s \n","N", "10*N", "100*N", "1000*N");
    int N=1;
    while(N<=20) {
        printf("%-2d %-4d %-5d %-6d \n",N,N*10,N*100,N*1000);
        N+=1;
    }
    return 0;
} 