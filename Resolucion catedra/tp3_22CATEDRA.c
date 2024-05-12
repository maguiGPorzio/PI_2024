#include <stdio.h>
#define BLANCO 1
#define CARACTER 0

int main(void)
{
    int c;
    int estado = CARACTER; /* estado indica si el ultimo caracter leido
							** es un blanco u otro caracter  */

    while ((c = getchar()) != EOF)
    {
        switch (estado)
        {
        case CARACTER:
            if (c == ' ')
                estado = BLANCO;
            putchar(c);
            break;
        case BLANCO:
            if (c != ' ')
            {
                putchar(c);
                estado = CARACTER;
            }
            break;
        }
    }
    return 0;
}