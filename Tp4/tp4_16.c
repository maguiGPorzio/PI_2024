#include <stdio.h>
#define DIVISOR(a,b) ((b) != 0 && (((a)<0)?(-(a)):(a)) % (((b)<0)?(-(b)):(b)) == 0)

int 
main (){
    int a, b = 10, c = 3;
    a = DIVISOR(b,c); 	/* a = 0 */
    printf("%d \n",a);
    a = DIVISOR(b,c-1);	/* a = 1 */
    printf("%d \n",a);
    return 0;
}