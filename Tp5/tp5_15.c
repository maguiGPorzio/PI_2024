#include <stdio.h>
#include <stdlib.h>
#define ELAPSED abs(((m1)+((h1)*60))-((m2)+((h2)*60)))

int 
main (){
    int minutos, h1, h2, m1, m2;
    h1 = 2; m1 = 10; h2 = 3; m2 = 15;
    minutos = ELAPSED(h1, m1, h2, m2);		/* minutos = 65 */
    minutos = ELAPSED(3, 15, 2, 10);		/* minutos = 65 */
    minutos = ELAPSED(h1, m1, h1 + 1, m1);	/* minutos = 60 */

    return 0; 
}