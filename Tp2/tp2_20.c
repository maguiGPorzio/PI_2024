#include <stdio.h>
#include "getnum.h"

int 
main() {
    int c;
    printf("%d\n",(c=getchar())!=EOF);
    printf("%d\n",EOF);
    return 0;
} 