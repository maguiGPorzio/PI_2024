#include <stdio.h>

int
main (){
    printf("%d",brunches(5));
    return 0;
}

int 
brunches(int altura, int min){
    if (altura<min){
        return 0;
    }
    return 1 + 2 * brunches(altura/2,min);
}
