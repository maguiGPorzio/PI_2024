#include <stdio.h>

int main() {
    int espacio=0,c;
    puts("Ingrese una cadena de texto");
    while ((c=getchar())!='\n' && c!=EOF){
        if (c!=' '){
            printf("%c",c);
            espacio=0;
        }
        else if (c==' ' && espacio==0){
            espacio=1;
            printf("%c",c); 
        }
    }
    printf("\n");
    return 0;
    }