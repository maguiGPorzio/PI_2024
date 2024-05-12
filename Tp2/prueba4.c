#include <stdio.h>

int 
main ()
{
    char a,b;
    unsigned char c;
    a=b=100;
    c=a+b;
    printf("%d %d %d",a,b,c);
    return 0;
}