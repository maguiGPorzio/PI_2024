#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#define IGUAL 1
#define MAYOR 2
#define MENOR 3


void deleteChars( char str1[], char str2[] );

int main(void) {
    
  char s3[] = "abc";
  char s4[] = "axc123456789012345678901234567890";
  deleteChars(s3,s4);
  assert(strcmp(s3, "b")==0);
  assert(strcmp(s4, "x123456789012345678901234567890")==0);

  char s1[] = "Hola, soy un string";
  char s2[] = "Yo soy otro string";

  deleteChars(s1, s2);
  assert(strcmp(s1, "Hla, sy un string")==0);
  assert(strcmp(s2, "Y soy tro string")==0);

  char empty[] = "";
  deleteChars(s1, empty);
  assert(strcmp(s1, "Hla, sy un string")==0);
  assert(strcmp(empty, "")==0);

  strcpy(s1, "ABCDE");
  strcpy(s2, "abcde");
  deleteChars(s1, s2);
  assert(strcmp(s1, "ABCDE")==0);
  assert(strcmp(s2, "abcde")==0);

  deleteChars(s1,s1);
  assert(strcmp(s1, "")==0);
  
  char s5[] = "abc";
  char s6[] = "axc123456789012345678901234567890";
  deleteChars(s5,s6);
  assert(strcmp(s5, "b")==0);
  assert(strcmp(s6, "x123456789012345678901234567890")==0);


  puts("OK!");
  return 0;
}

/*
Escribir la función deleteChars que recibe dos strings y 
elimine en ambos los caracteres que sean iguales y estén en la misma posición. 
Ambos strings pueden tener longitudes diferentes.

Ejemplo:

Si recibe "Hola, soy un string"  y "Yo soy otro string" deben quedar como "Hla, sy un string" y 
"Y soy tro string" respectivamente
Si recibe "Tengo algunos chars" y "", no deben cambiar
Si recibe "ABCDE"  y "abcde", no deben cambiar
Si recibe dos string iguales, ambos deben quedar vacíos
*/
/* 
void
deleteChars (char * s1, char * s2){
  int i=0, j=0,h=0,k=0;
  char car1, car2;
  while (s1[i] || s2[j]){
    car1=s1[i];
    car2=s2[j];
    if (car1==car2){
      i++;
      j++;
    }
    else if (car1==0){
      s2[k++]=s2[j++];
    }
    else if (car2==0){
      s1[h++]=s1[i++];
    }
    else{
      s2[k++]=s2[j++];
      s1[h++]=s1[i++];
    }
  }
  s2[k]=0;
  s1[h]=0;
}
*/

// En esta version hacemos un solo ciclo, con cuidado de no
// seguir copiando sobre el string que haya finalizado
void deleteChars( char str1[], char str2[] ){
  int i = 0, j = 0, count1 = 0, count2 = 0;
  while( str1[i] || str2[j] ){
    if( str1[i] == str2[j] ){
      i++; j++;
    }
    else{
      if( str1[i] )
        str1[count1++] = str1[i++];
      if( str2[j] )
        str2[count2++] = str2[j++];
    }
  }
  str1[count1] = 0; str2[count2] = 0;
}
/* 
// Esta es similar a la anterior, pero usando punteros 
void deleteChars2(char v1[], char v2[]) {
    char i=0, j=0, *p1=v1, *p2=v2;
    while ( *p1 != 0 || *p2 != 0) {
        if (*p1==*p2){
            p1++;
            p2++;
        } else {
            if (*p1 != 0)
                v1[i++]=*p1++;
            if (*p2 != 0)
                v2[j++]=*p2++;  
        }
    }
    v1[i]=0;
    v2[j]=0;
}

// En esta version salimos del ciclo cuando se termina alguno de los dos
// Luego del ciclo copiamos los caracteres que restan
void deleteChars3( char str1[], char str2[] ){
  int i = 0, j = 0, count1 = 0, count2 = 0;
  while( str1[i] && str2[j] ){
    if( str1[i] == str2[j] ){
      i++; j++;
    }
    else{
        str1[count1++] = str1[i++];
        str2[count2++] = str2[j++];
    }
  }
  while(str1[count1++] = str1[i++]) // copiamos hasta el cero inclusive
     ;
  while(str2[count2++] = str2[j++])
     ;
  
}
*/