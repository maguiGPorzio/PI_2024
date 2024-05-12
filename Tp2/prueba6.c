#include <stdio.h>

int 
main ()
{
    int x,y,z;
    z=(x=2)+(y=x);
    printf("%d %d %d",x,y,z);
    return 0;
}