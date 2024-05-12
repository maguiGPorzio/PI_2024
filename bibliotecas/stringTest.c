//
// Implementacion de algunas funciones de string.h
//
#include <assert.h>
#include <stdio.h>

int 
strlen (const char *s) {
    int i=0;
    for (; s[i] ; i++);
    return i;
}


char * strcpy(char * t, const char * s) {
    char *aux=t;
    while (*t++=*s++);
    return aux;
}


char * strncpy(char * t, const char * s, unsigned int n) {
    for (int i=0 ; i<n ; i++){
        if (*s){
            t[i]=*s++;
        }
        else{
            t[i]=0;
        }
    }
    return t;
}


char * strcat(char * t, const char * s){
    strcpy(t+strlen(t), s);
    return t;
}

int strcmp(const char *t, const char *s){
    for ( ; *t==*s && *t ; t++,s++);
    return *t-*s;
}


char * strncat(char * t, const char * s, int n) {
    int i=strlen(t);
    for (int h=0 ; s[h] && h<n; h++){
        t[i++]=s[h];
    }
    t[i]=0;
    return t;
}


int strncmp(const char * t, const char * s, unsigned int n) {
    while(n && *t==*s && *t) {
        t++;
        s++;
        n--;
    }
    if ( n==0 ) {
        return 0;
    }
    return *t - *s;
}

char * strchr(const char * s, char c){
    for ( ; *s ; s++){
        if (*s==c){
            return s;
        }
    }
    return NULL;
}
char * strrchr(const char * s, char c){
    char *p=NULL;
    for ( ; *s ; s++){
        if (*s==c){
           p=s;
        }
    }
    return p;
}


int main(void) {
    char s[20] = {0};
    char * aux;
    aux = strcpy(s, "Prueba");
    assert(aux == s);
    assert(s[0]=='P');
    assert(s[1]=='r');
    assert(s[2]=='u');
    assert(s[3]=='e');
    assert(s[4]=='b');
    assert(s[6]==0);


    aux = strcpy(s, "");
    assert(aux[0]==0);


    aux = strncpy(s, "123", 10);
    assert(aux==s);
    assert(aux[0]=='1' && aux[1]=='2' && aux[2]=='3' && aux[3]==0 && aux[4]==0 && aux[5]==0);

    aux = strncpy(s, "xyz", 2);
    assert(aux==s);
    assert(aux[0]=='x' && aux[1]=='y' && aux[2]=='3' && aux[3]==0 && aux[4]==0 && aux[5]==0);


    aux = strcat(s, "bien");
    assert(aux==s);
    assert(aux[0]=='x' && aux[1]=='y' && aux[2]=='3' && aux[3]=='b' && aux[4]=='i' && aux[5]=='e');

    strcpy(s, "abcd");
    aux = strncat(s, "xyz", 2);
    assert(aux==s);
    assert(strlen(s)==6);
    assert(s[0]=='a');
    assert(s[3]=='d');
    assert(s[4]=='x');

    s[0]=0;
    strncat(s, "", 2);
    assert(strlen(s)==0);

    strncat(s, "abc", 0);
    assert(strlen(s)==0);

    /* Ejemplo que pisa memoria
    char s2[1];
    strncpy(s2, "1234567888888888888888746784657we65", 12);
    puts(s2);
    puts(s);
     */


    assert(strcmp("","")==0);
    assert(strcmp("ab", "ba")<0);
    assert(strcmp("abc", "abc")==0);
    assert(strcmp("abc", "abcd")<0);
    assert(strcmp("abcd", "abc")>0);
    assert(strcmp("abc", "Abc")>0);
    assert(strcmp("123", "1234")<0);


    assert(strncmp("abc", "abcd", 3) == 0);
    assert(strncmp("abc", "abc", 5) == 0);
    assert(strncmp("abc", "abcd", 5) < 0);
    assert(strncmp("Xbc", "abcd", 0) == 0);

    strcpy(s, "012345601");
    assert(strchr(s, 'x')==NULL);
    assert(strchr(s, '0')==s);
    assert(strchr(s, '1')==s+1);
    assert(strchr(s, '5')==s+5);

    assert(strrchr(s, 'x')==NULL);
    assert(strrchr(s, '0')==s+7);
    assert(strrchr(s, '1')==s+8);
    assert(strrchr(s, '5')==s+5);

    puts("OK!");
    return 0;
}