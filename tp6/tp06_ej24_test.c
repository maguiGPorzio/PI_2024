#include <stdio.h>
#include <assert.h>
#include <string.h>

void
eliminaBlancos (char cadena[]);

int main(void) {
  char s[60] = "   "; // cant impar de blancos
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  strcpy(s,"  ");
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);
  
  strcpy(s," . . .  ");
  eliminaBlancos(s);
  assert(strcmp(s, " . . . ")==0);

  strcpy(s,"");
  eliminaBlancos(s);
  assert(strcmp(s, "")==0);

  strcpy(s,"sinblancos");
  eliminaBlancos(s);
  assert(strcmp(s, "sinblancos")==0);



  printf("OK!\n");
  return 0;
}

/*
Hacer una función que reciba como único parámetro de entrada/salida un string y 
elimine los espacios de más.  Por ejemplo, si recibe “Hola           mundo      ”, 
deberá transformarlo en “Hola mundo ”
*/

void
eliminaBlancos (char cadena[]){
  int h=0;
  for (int i=0 ; cadena[i] ; i++){
    if ((cadena[i]!=' ' || (cadena[i]==' ' && cadena[i-1]!=' ')) && i!=h){
      cadena[h++]=cadena[i];
    }
    else if (cadena[i]!=' ' || (cadena[i]==' ' && cadena[i-1]!=' ')){
      h++;
    }
  }
  cadena[h]='\0';
}