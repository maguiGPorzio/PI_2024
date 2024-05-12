#include <stdio.h>

int 
main ()
{
    int x,y;
    x=(char)5;
    y=x++;
    printf("%d %d",x,y);
    return 0;
}