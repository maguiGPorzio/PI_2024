#include <stdio.h>
#define MAXIMO2(a,b,c) (c=(((a)>(b))?(a):(b)))
#define MAXIMO3(x,y) (((x)>(y))?(x):(y))
	

int
main(void)
{
    int x=3,y=4,z,w=5;
    printf("%d\n",MAXIMO3(MAXIMO2(x,y,z),w));
    
}