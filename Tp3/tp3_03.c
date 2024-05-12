#include <stdio.h>
#include "getnum.h"
#define VALOR_FIJO 300

int main() {
    double sum_vendida;
    do{
        sum_vendida=getint("La suma vendida en una semana es: ");
    }
    while (sum_vendida<0);
    
    if (sum_vendida <=1000) {
        printf("La suma vendida en una semana es $%.2f y el monto total a cobrar es $%d \n",sum_vendida,VALOR_FIJO);
    }
    else if (sum_vendida <=2000) {
        printf("La suma vendida en una semana es $%.2f y el monto total a cobrar es $%.2f \n",sum_vendida,VALOR_FIJO+(sum_vendida*0.05));
    }
    else if (sum_vendida <=4000) {
        printf("La suma vendida en una semana es $%.2f y el monto total a cobrar es $%.2f \n",sum_vendida,VALOR_FIJO+(sum_vendida*0.07));
    }
    else {
        printf("La suma vendida en una semana es $%.2f y el monto total a cobrar es $%.2f \n",sum_vendida,VALOR_FIJO+(sum_vendida*0.09));
    }
    return 0;
} 