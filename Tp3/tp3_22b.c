#include <stdio.h>

int main() {
    int c;
    puts("Ingrese una cadena de texto");
    while ((c=getchar())!='\n' && c!=EOF){
        if (c=='\t'){
            printf("%s","\\t");
        }
        else if (c=='\\'){
            printf("%s","\\"); 
        }
        else if (c=='\b'){
            printf("%s","\\b");
        }
        else{
            printf("%c",c);
        }
    }
    printf("\n");
    return 0;
    }