

typedef struct bibleCDT * bibleADT;
typedef long unsigned int size_t;

bibleADT newBible();
/*
** Agrega un vers�culo a la Biblia. Si ya estaba ese n�mero de vers�culo en ese
** n�mero de libro, no lo agrega ni modifica y retorna 0. Si lo agreg� retorna 1
** bookNbr: n�mero de libro
** verseNbr: n�mero de vers�culo
*/
int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse);
/*
** Retorna una copia de un vers�culo o NULL si no existe.
** bookNbr: n�mero de libro
** verseNbr: n�mero de vers�culo
*/
char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr);
/* Libera todos los recursos reservados por el TAD */
void freeBible(bibleADT bible);
