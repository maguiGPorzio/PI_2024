#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Si bien es mejor usar punteros, por ahora usaremos un vector v donde v[0] sea el numerador y v[1] el denominador
typedef int Fraccion[2];
#define NUM(f) f[0]
#define DEN(f) f[1]

/* Simplificaciรณn de la fraccion  */
void simplFrac(Fraccion frac);

/* Calcula la suma de dos fracciones representadas por frac1, frac2 
 * Deja el resultado en frac3 
 */
void sumarFrac(const Fraccion frac1, const Fraccion frac2, Fraccion frac3);

int DivComMax(int num1,int num2);


int main(void) {
    
    Fraccion f1, f2, fSum;

    printf("SIMPLIFICAR\n");
    NUM(f1) = 10; DEN(f1) = 15;
    simplFrac(f1);
    assert(NUM(f1)==2 && DEN(f1)==3);
    simplFrac(f1);
    assert(NUM(f1)==2 && DEN(f1)==3);

    NUM(f1) = 150; DEN(f1) = 15;
    simplFrac(f1);
    assert(NUM(f1)==10 && DEN(f1)==1);
    simplFrac(f1);
    assert(NUM(f1)==10 && DEN(f1)==1);
    
    NUM(f1) = 1; DEN(f1) = 10;
    simplFrac(f1);
    assert(NUM(f1)==1 && DEN(f1)==10);
    
    NUM(f1) = 12*5; DEN(f1) = 36*7;
    simplFrac(f1);
    assert(NUM(f1)==5 && DEN(f1)==21);
    NUM(f1) = 0; DEN(f1) = 36;
    simplFrac(f1);
    assert(NUM(f1)==0 && DEN(f1)==1);

    printf("SUMAR\n");
  
    NUM(f1) = 150; DEN(f1) = 15;
    NUM(f2) = 15;  DEN(f2) = 5;
    sumarFrac(f1, f2, fSum);
    assert(NUM(fSum)==13 && DEN(fSum)==1);
    assert(NUM(f1)==150 && DEN(f1)==15);

    NUM(f2) = 7;  DEN(f2) = 4;
    sumarFrac(f1, f2, fSum);
    assert(NUM(fSum)==47 && DEN(fSum)==4);

    return 0;
}

int 
DivComMax(int num1,int num2){ //back end 
    int mayor,menor;

    mayor=(num1>num2) ? num1 : num2;
    menor=(num1<num2) ? num1 : num2;

    if (menor){
        mayor=((mayor<0) ? -mayor : mayor);
        menor=((menor<0) ? -menor : menor);

        int auxi=mayor%menor;

        while (auxi>0)
        {	
            mayor = menor;
            menor = auxi;
            auxi = mayor % menor ;
        }
        return menor;
    }
    else {
        return mayor;
    }
}

void simplFrac (Fraccion frac1){ //back end 
    int mcm;
    mcm=abs(DivComMax(NUM(frac1),DEN(frac1)));
    NUM(frac1)/=mcm;
    DEN(frac1)/=mcm;
    return;
}

void
sumarFrac (const Fraccion frac1, const Fraccion frac2, Fraccion frac3){ //back end
    DEN(frac3)=DEN(frac1)*DEN(frac2);
    NUM(frac3)=(DEN(frac1)*NUM(frac2))+(DEN(frac2)*NUM(frac1));
    simplFrac(frac3);
    return;
}