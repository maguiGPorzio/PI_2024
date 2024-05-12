#include <stdio.h>
#include <ctype.h>

int 
main (void){
    int c;
    while ((c=getchar())!="\n" || c!=EOF) {
        if !(isspace(c)){
            c=toupper(c);
            putchar(c);
        }
    }
    return 0;
}