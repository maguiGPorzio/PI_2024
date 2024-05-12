#include <stdio.h>
#define DELTA ('a'-'A')
#define TRUE 1
#define FALSE 0

int main() {
    int c, countUp=0, countLow=0, lowest='z', isLowestUp,isCurrentUp;
    while (((c=getchar())>='a' && c<='z') || (c>='A' && c<='Z') || c==' ') {
        if (c!=' ') {
            if (c>='A' && c<='Z') {
                countUp++;
                isCurrentUp=TRUE;
                c+=DELTA;
            }
            else {
                countLow++;
                isCurrentUp=FALSE;
            }
            if (c<lowest){
                lowest=c;
                isLowestUp=isCurrentUp;
            }
        }
    }
    printf("#Mayusculas: %d, #minusculas: %d \n", countUp, countLow);
    printf("La menor alfabeticamente es %c \n", isLowestUp ? lowest-DELTA:lowest);
    return 0;
} 