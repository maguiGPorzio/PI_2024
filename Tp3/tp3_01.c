#include <stdio.h>
int main (void) {
    puts("Ingrese un caracter: ");
    int car=getchar();
    if ('a'<=car && car<='z'){
        puts("Es una letra minuscula");
        }
    else if ('A'<=car && car<='Z') {
        puts("Es una letra mayuscula");
    }
    else {
        puts("No es una letra");
    }
    return 0;
}