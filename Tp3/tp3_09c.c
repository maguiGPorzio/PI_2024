#include <stdio.h>
#define IN_WORD 1
#define OUT_WORD 0
int main(void)
{
    int c, estado;
    estado = OUT_WORD;
    while ((c = getchar()) != EOF)
        switch (estado)
        {
        case IN_WORD:
            if (c == ' ' || c == '\n' || c == '\t')
            {
                putchar('\n');
                estado = OUT_WORD;
            }
            else
                putchar(c);
            break;
        case OUT_WORD:
            if (c != ' ' && c != '\n' && c != '\t')
            {
                estado = IN_WORD;
                putchar(c);
            }
            break;
        }
    return 0;
}