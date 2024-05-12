#include <stdio.h>
#include <math.h>
#define EPS 0.00001

int main() {
    int num, sumaDecimal=0,punto=0;
    while ((num=getchar())!='\n' && num!=EOF){
        if (num=='.'){
            punto=1;
        }
        else if (punto==1){
            sumaDecimal+=num-'0';
        }
    }
    printf("%d \n",sumaDecimal);
    return 0;
}