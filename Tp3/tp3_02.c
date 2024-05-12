#include <stdio.h>
int main() {
    printf("Escribir dos caracteres ");
    int car1=getchar(),car2=getchar();
    if (car1>car2) {
        printf("El caracter '%c' es mayor al carcter '%c' \n",car1,car2);
    }
    else if (car1<car2) {
        printf("El caracter '%c' es menor al carcter '%c' \n",car1,car2);
    }
    else {
        printf("El caracter '%c' es igual al carcter '%c' \n",car1,car2);
    }
    return 0;
} 