

#include "/home/mgonzalezporzio/PI/bibleADT.h"
#include <stdlib.h>
#include <string.h>
#define BLOCK 10
#define AMOUNT_BOOKS 76
#define BOOK_NBR_IN_RANGE(M) ((M)>0 && (M)<77)

typedef struct {
    char * verse;
    size_t lenVerse;
} TVersicle;

typedef struct{
    TVersicle * allVerses;
    size_t amountVerses;
} TBooks;

struct bibleCDT{
    TBooks books[AMOUNT_BOOKS];
};

bibleADT newBible(){
    bibleADT newBib=calloc(1,sizeof(struct bibleCDT));
    return newBib;
}

char *
copyVerse(const char * verse, size_t * j){
    char * newVerse=NULL;
    int i=0;
    for (; verse[i] ; i++){
        if (i % BLOCK == 0){
            newVerse=realloc(newVerse, i + BLOCK);
        }
        newVerse[i]=verse[i];
    }
    newVerse=realloc(newVerse, i + 1);
    newVerse[i]=0;
    *j=i+1;
    return newVerse;
}
/*
** Agrega un vers�culo a la Biblia. Si ya estaba ese n�mero de vers�culo en ese
** n�mero de libro, no lo agrega ni modifica y retorna 0. Si lo agreg� retorna 1
** bookNbr: n�mero de libro
** verseNbr: n�mero de vers�culo
*/
int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse){
    if (!BOOK_NBR_IN_RANGE(bookNbr)){
        return 0;
    }

    if (bible->books[bookNbr-1].amountVerses < verseNbr){
        bible->books[bookNbr-1].allVerses=realloc(bible->books[bookNbr-1].allVerses,verseNbr * sizeof(TVersicle));
        int i=bible->books[bookNbr-1].amountVerses;
        for (; i<verseNbr ; i++){
            bible->books[bookNbr-1].allVerses[i].lenVerse=0;
            bible->books[bookNbr-1].allVerses[i].verse=NULL;
        }
        bible->books[bookNbr-1].amountVerses=verseNbr;
    }

    if (bible->books[bookNbr - 1].allVerses[verseNbr - 1].lenVerse != 0 ){
        return 0;
    }

    size_t len=0;
    bible->books[bookNbr - 1].allVerses[verseNbr - 1].verse=copyVerse(verse, &len);
    bible->books[bookNbr - 1].allVerses[verseNbr - 1].lenVerse=len;
    return 1;
}

/*
** Retorna una copia de un versiculo o NULL si no existe.
** bookNbr: numero de libro
** verseNbr: numero de versiculo
*/
char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr){
    if (!BOOK_NBR_IN_RANGE(bookNbr) || bible->books[bookNbr-1].amountVerses < verseNbr || bible->books[bookNbr-1].allVerses[verseNbr-1].lenVerse == 0){
        return NULL;
    }
    char * copyOfVerse=malloc(bible->books[bookNbr-1].allVerses[verseNbr-1].lenVerse);
    strcpy(copyOfVerse,bible->books[bookNbr-1].allVerses[verseNbr-1].verse);
    return copyOfVerse;
}

/* Libera todos los recursos reservados por el TAD */
void freeBible(bibleADT bible){
   for (int i=0 ; i < AMOUNT_BOOKS ; i++){
    for (int j=0 ; j<bible->books[i].amountVerses ; j++){
        // if (bible->books[i].allVerses[j].lenVerse != 0){
        //     free(bible->books[i].allVerses[j].verse);
        // }

        //como los inicialice en NULL
        //si no los hubiese inicializado en NULL si o si tengo que preguntar si la len es distinta de cero para liberar
        free(bible->books[i].allVerses[j].verse);

    }
    free(bible->books[i].allVerses);
   }
   free(bible);
}
