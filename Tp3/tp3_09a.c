#include <stdio.h>
int main(void)
{
    int c, blancos, tabs, nuevasLineas;
    blancos = 0;
    tabs = 0;
    nuevasLineas = 0;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case ' ':
            blancos++;
            break;
        case '\t':
            tabs++;
            break;
        case '\n':
            nuevasLineas++;
            break;
        }
    }
    printf("\nBlancos: %d\nTabuladores: %d\nNuevas Lineas: %d\n",
           blancos, tabs, nuevasLineas);
    return 0;
}