#include <stdio.h>

int 
main ()
{
    int x,y;
    x=300.0;
    y=x++;
    printf("%d %d",x,y);
    return 0;
}