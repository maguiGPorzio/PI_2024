#include <stdio.h>
#include <assert.h>
#include <string.h>

//LISTO

void insertaDesde(char * s1, const char * s2, char c);

int main(void) {
    char str1[60] = "manuel";
    char str2[] = "javi";
    insertaDesde(str1, str2,'n');
    assert(strcmp(str1,"majavi")==0);

    char str3[20];
    strcpy(str3, "manuel");
    insertaDesde(str3, "javi" ,'l');
    assert(strcmp(str3,"manuejavi")==0); // muestra manuejavi

    char str4[60];
    strcpy(str4, "lalala");
    insertaDesde(str4, "javi",'j');
    assert(strcmp("lalala",str4)==0);

    insertaDesde(str4, "javier ibaniez de toledo",'l');
    assert(strcmp("javier ibaniez de toledo",str4)==0);

    strcpy(str4,"12345");
    insertaDesde(str4, "6789abcdefgh",'5');
    assert(strcmp("12346789abcdefgh",str4)==0);


    puts("OK!");
    return 0;
}

/*
Escribir la función insertaDesde, que recibe dos strings (null terminated) y un carácter. 
Al primer string se le inserta el segundo a partir de la primera aparición del carácter indicado. 
Si el carácter no aparece en el primer string, el mismo no debe ser alterado.
*/

void 
insertaDesde(char * s1, const char * s2, char c){
    int pos=-1, i=0;
    for ( ; s1[i] && pos==-1; i++){
        if (s1[i]==c){
            pos=i;
        }
    }

    if (pos==-1){
        return ;
    }

    i--;

    for (int h=0 ; s2[h] ; h++, i++){
        s1[i]=s2[h];
    }
    s1[i]=0;
}