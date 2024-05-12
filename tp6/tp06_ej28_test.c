#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5
//LISTO

int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n);
int esVocal(char c);

int main(void) {
  int m[6][CANT_VOCAL];
  char s[] = "las buenas ideas escasean, si";

  assert(elimVocales(s, m, 6)==EXITO);
  assert(strcmp(s, "ls bns ds scsn, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == 23);
  assert(m[5][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  strcpy(s, "las buenas ideas escasean, si");
  assert(elimVocales(s, m, 1)==ERROR);
  assert(strcmp(s, "las buenas ideas escasean, si")==0);
  assert(m[0][0]==-1);
  assert(m[0][1]==-1);
  assert(m[0][2]==-1);
  assert(m[0][3]==-1);
  assert(m[0][4]==-1);

  assert(elimVocales(s, m, 5)==ERROR);
  assert(strcmp(s, "ls bns ds scsan, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  printf("OK!\n");
  return 0;
}

/*
Escribir la función elimVocales que reciba un string s y una matriz de 5 columnas y n filas, 
donde cada columna representa una vocal y n es un parámetro de la función.
La función deberá devolver el string s sin las vocales (ya sean mayúsculas o minúsculas), 
y la matriz con las ubicaciones de las vocales eliminadas. Cada columna de la matriz debe “cerrarse” 
con un -1.
La función tiene que controlar el espacio disponible en la matriz para seguir guardando ubicaciones. 
Si no hay espacio suficiente, devuelve ERROR, aunque haya quedado modificado el string.
*/

int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n){

  // usamos un vector donde en cada posicion se guarda el indice de la columna
  // correspondiente a la vocal. La otra posibilidad era usar cinco variables
  unsigned int pos[CANT_VOCAL] = {0};
  int ans = EXITO;
  
  int i, j;

  // Para eliminar las vocacles es el mismo algoritmo que para eliminar ceros
  // Solo que ademas de verificar si es vocal, tenemos que guardar la posicion original
  for(i=j=0; s[i]; i++) {
     int vocal = esVocal(s[i]);
     if (vocal && pos[vocal-1] < n-1) { // es vocal pero ademas tenemos que ver si hay lugar en la columna
      m[pos[vocal-1]++][vocal-1] = i;
     } 
     else {
       if ( vocal )
          ans = ERROR;  // era vocal pero no habia mas lugar
       s[j++] = s[i];
     }
  }
  s[j] = 0;
  // Completamos con -1 al final de cada columna
  for(i=0; i < CANT_VOCAL; i++) {
    m[pos[i]][i] = -1;
  }
  return ans;
}

int esVocal(char c){
  static char * vocales="AEIOU";
  char * p = strchr(vocales, toupper(c));
  if ( p == NULL)
     return 0;
  return p - vocales + 1;
}



/* 
int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n){

  for (int i=0 ; i<n ;i++){
    for (int j=0 ; j<CANT_VOCAL ; j++){
      m[i][j]=-1;
    }
  }

  char act, h=0, ok, exito=EXITO;

  for (int i=0 ; s[i]; i++){

    act=toupper(s[i]);

    if (act=='A' || act=='E' || act=='I' || act=='O' || act=='U'){
      ok=contVoc(m,n,act,i);
      if (!ok){
        s[h++]=s[i];
        exito=ERROR;
      }
    }
    else{
      s[h++]=s[i];
    }

  }
  s[h]=0;

  return exito;
}

int
contVoc (int m[][CANT_VOCAL], unsigned int n, char voc, int pos){

  int col;

  switch (voc){
    case 'A':
      col=0;
      break;
    case 'E':
      col=1;
      break;
    case 'I':
      col=2;
      break;
    case 'O':
      col=3;
      break;
    case 'U':
      col=4;
      break;
  }

  int entry=ERROR;
  for (int i=0 ; i<n-1 && !entry; i++){
    if (m[i][col]==-1 && m[i+1][col]==-1){
      m[i][col]=pos;
      entry=EXITO;
    }
  }
  return entry;
}
*/