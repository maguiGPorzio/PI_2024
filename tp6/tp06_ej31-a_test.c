#include <stdio.h>
#include <assert.h>
#include <string.h>
//LISTO
int
strend (char * s,char * t);

int main(void) {
  assert(strend("","")==1);
  assert(strend("something","")==1);
  assert(strend("something","thing")==1);
  assert(strend("something","something")==1);
  assert(strend("something","plus something")==0);
  assert(strend("not at the eeeeeend"," end")==0);
  assert(strend("not at the eeeeeennnnnd","end")==0);
  assert(strend("","s")==0);
  assert(strend("ssss","sss")==1);
  assert(strend("ssss","sssss")==0);
  puts("OK!");
  return 0;
}

int
strend (char * s,char * t){
  int dim1=strlen(s), dim2=strlen(t), i=dim1-dim2;
  if (i<0){
    return 0; 
  }
  for (int h=0 ; s[i] ; h++, i++){
    if (s[i]!=t[h]){
      return 0;
    }
  }
  return 1;
}

/* 
int strend(const char *s, const char *t)
{
    int ls, lt;

    //Se calcula la longitud de las cadenas 
    ls = strlen(s);
    lt = strlen(t);

    if (lt > ls) //Si la cadena t es mas larga, es falso 
        return 0;

    for (ls--, lt--; lt >= 0 && s[ls] == t[lt]; ls--, lt--);

    return (lt == -1);
}

// Version mas simple 
int strend(const char *s, const char *t) {
    int ls, lt;

    // Se calcula la longitud de las cadenas 
    ls = strlen(s);
    lt = strlen(t);

    if (lt > ls) // Si la cadena t es mas larga, es falso
        return 0;
    return  strcmp(s + ls - lt, t) == 0;
    // La funcion tambien podria ser unicamente la siguiente linea
    // return strcmp(s + strlen(s) - strlen(t), t) == 0;
    // pero podria dar error de acceso a memoria invalida si lt > ls 
}
*/