#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EPSILON 0.01


double 
raizNR(double valorAnterior , int iter , double x);

int main(void){

    assert(fabs(raizNR(4, 3, 8)-2.833) <= EPSILON);
    assert(raizNR(0, 0, 0) <= EPSILON);
    assert(raizNR(0, 0, 4) <= EPSILON);
    
    printf("OK!\n");
}

double 
raizNR(double valorAnterior , int iter , double x){

    double valorAprox=(valorAnterior+(x/valorAnterior))/2;

    if (iter==1){
        return valorAprox;
    }
    
    if (fabs(valorAnterior)<EPSILON){
        return 0;
    }

    return raizNR(valorAprox,iter-1,x);
}
