/*
Escribir la función elimina que recibe tres strings s1, s2 y s3 y elimina de s1
aquellos caracteres que están presentes en s2 o en s3 en la misma posición que
en s1
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>


void elimina(char *s1, char *s2, char *s3);

int main(void) {
    char s[] = "abc";
    elimina(s, "123", "cab");
    assert(strcmp(s, "abc") == 0); // No se eliminan caracteres
    elimina(s, "axc", "xbc");
    // Se elimina la a porque está en s2 en la misma posición
    // se elimina la b porque está en s3 en la misma posición
    // Se elimina la c porque está en s2 o en s3 en la misma posición
    assert(strcmp(s, "") == 0);
    char t[] = "abc 123";
    elimina(t, "b", "1");
    assert(strcmp(t, "abc 123") == 0); // No se eliminan caracteres
    elimina(t, "aaaaaaaaaaaaaaaaaaaaaa", "2222222222222222222");
    assert(strcmp(t, "bc 13") == 0);
    elimina(t, "", ""); // No se eliminan caracteres
    assert(strcmp(t, "bc 13") == 0);
    puts("OK!");
return 0;
}

void 
elimina(char *s1, char *s2, char *s3){
    int h=0, i;
    for (i=0 ; *s1 ; i++){
        if (!(*s2==*s1 || *s1==*s3)){
            *(s1-i+h)=*s1;
            h++;
        }
        if (*s2){
            s2++;
        }
        if (*s3){
            s3++;
        }
        s1++;
    }
    *(s1-i+h)='\0';
}