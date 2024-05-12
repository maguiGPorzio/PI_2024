#include <stdio.h>
#include <assert.h>
#include <string.h>
#define LETTERS ('Z'-'A'+1)

int palindromo(const char * s);

int main(void) {

  assert(palindromo("a")==1);
  assert(palindromo("")==1);
  assert(palindromo("neuquen")==1);
  assert(palindromo("abba")==1);
  assert(palindromo("12345654321")==1);

  assert(palindromo("abab")==0);
  assert(palindromo("123456")==0);
  
  int dim=100000;  // Qué pasa si probamos con un millón ?
  char s[dim+1];
  for(int i=0; i<dim/2; i++) {
	  s[i] = s[dim-i-1] = i%LETTERS + 'a';
  }
  s[dim]=0;
  assert(palindromo(s));
  assert(!palindromo(s+1));

  puts("OK!");
  return 0;
}

/*
Escribir una función que reciba como parámetro de entrada un string y retorne 1 si el mismo es palíndromo y 0 en caso contrario. 
Resolver el problema en forma recursiva
*/
int
auxEsCapicua(const char * s, int dim){ 
    if ((*s)==0){
        return 1;
    }
    if (*s!=s[dim-1]){
        return 0; 
    }
    return auxEsCapicua(s+1,dim-2);
}


int
palindromo(const char * s){ 

    return auxEsCapicua(s, strlen(s));
}