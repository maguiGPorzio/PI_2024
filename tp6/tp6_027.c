/*
Escribir la función analize que reciba un string de nombre text (se espera que sea muy extenso) y 
un vector de chars de nombre chars que tiene al menos 256 posiciones reservadas pero no inicializadas 
(contienen basura). La función debe dejar en chars los distintos caracteres que aparecen en text, 
ordenados ascendentemente por valor ASCII y sin repetir. El vector chars debe quedar null terminated.
*/

#define CHARS_DIM 256
#include <stdio.h>

void
analize (const char *text, char chars[]);
void 
delCero (char chars[]);

int main(void) {
 char chars[CHARS_DIM];
 analize("El zorro mete la cola, Pero no la pata!", chars);
 printf("%s\n", chars);
 return 0;
}

void
analize (const char *text, char chars[]){
    for(int i=0; i < CHARS_DIM ; i++){
        chars[i]=0;
    }

    for (int i=0 ; text[i] ; i++){
        chars[text[i]]=text[i];
    }
    delCero(chars);
}

void 
delCero (char chars[]){
    int h=0;
    for (int i=0 ; i<CHARS_DIM ; i++){
        if (chars[i] && h!=i){
            chars[h++]=chars[i];
        }
        else if (chars[i]){
            h++;
        }
    }
    chars[h]=0;
}


