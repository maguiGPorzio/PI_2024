#include <stdio.h>
#include <ctype.h>

int 
main (){
    int a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();

    if (isupper(a) && a!='A' && a!='E' && a!='I' && a!='O' && a!='U'){
        printf("El caracter %c es una consonante mayúscula \n", a);
    }
    else if (islower(a) && a!='a' && a!='e' && a!='i' && a!='o' && a!='u'){
        printf("El caracter %c es una consonante minúscula \n", a);
    }
    else if (isalpha(a)){
        printf("El caracter %c es una vocal \n", a);
    }
    else{
        printf("El caracter %c no es una letra \n", a);
    }
    if ((b%2)==0){
        printf("El valor ASCII de %c es par \n", b);
    }
    if (isdigit(b) && (((b-'0')%2)==0)){
        printf("El caracter %c representa un dígito par \n", b);
    }
    if (isupper(c) || (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')){
        printf("El caracter %c es una vocal o es mayúscula \n", c);
    }
    if (isalpha(c) && ((toupper(c))!='A' && (toupper(c))!='E' && (toupper(c))!='I' && (toupper(c))!='O' && (toupper(c))!='U')){
        printf("El caracter %c no es una vocal pero es letra \n", c);
    }
    return 0;
}