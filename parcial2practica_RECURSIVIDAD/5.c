/*
Similar al ejercicio 12 pero el string contiene únicamente paréntesis y debe retornar cero sólo si los paréntesis están apareados. 
Consideramos que los paréntesis de una expresión están apareados si para cada paréntesis de apertura hay uno de cierre en una posición 
posterior. No definir macros ni funciones auxiliares. 
*/

#include <stdio.h>
#include <assert.h>

int apareados(const char *texto);

int main(void) {

  assert(apareados("")==0);
  assert(apareados("()")==0);
  assert(apareados("(())()(()())")==0);
  assert(apareados("((((()))))")==0);

  assert(apareados("(")!=0);
  assert(apareados(")")!=0);
  assert(apareados("(")!=0);
  assert(apareados("())")!=0);
  assert(apareados("()(")!=0);
  assert(apareados("((()))())(")!=0);
  
  int dim=100000;
  char s[dim+1];
  for(int i=0; i<dim/2; i++) {
	  s[i] = '(';
	  s[dim-1-i] = ')';
  }
  s[dim]=0;
  assert(apareados(s)==0);
  for(int i=1; i < dim/100; i++) {
	assert(apareados(s+i)!=0);
  }
  
  puts("OK!");
  return 0;
}


int 
apareados(const char *texto){
    if (!texto[0]){
        return 0;
    }

    int aux=apareados(texto+1);

    if (aux<0){
        return aux;
    }

    if (texto[0] == ')'){
        return 1 + aux;
    }
    
    return -1 + aux;
}