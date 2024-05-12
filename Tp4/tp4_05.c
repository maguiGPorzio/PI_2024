#include <stdio.h>
#define MAXIMO2(a,b,c) (c=(((a)>(b))?(a):(b)))
	

int
main(void)
{
    int x=3,y=6,z;
    MAXIMO2(x,y,z);
    printf("%d\n",z);
    
}