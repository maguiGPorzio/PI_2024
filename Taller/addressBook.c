#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include "/home/mgonzalezporzio/PI/addressBookADT.h"
#define BLOCK 10

typedef struct contacto {
    char * name;
    size_t dim;
    char * phoneNumber;
    size_t dimPhone;
    struct contacto * nextContact;
} contacto;

typedef struct groups{
    char * groupName; //lo guardo con marca de cero 
    contacto * firstContact;
    size_t longName;
    struct groups * nextGroup;
}groups;

struct addressBookCDT{
    groups * firstGroup;
    groups * groupIterator;
    contacto * persIterator;
};

/* Crea un nuevo TAD vacío */
addressBookADT newAddressBook(){
    addressBookADT new=calloc(1,sizeof(struct addressBookCDT));
    return new;
}

char * 
copyName(const char * name, size_t * longName){
    int i=0;
    char * copyOfName=NULL;
    for (; name[i] ; i++){
        if (i % BLOCK == 0){
            copyOfName=realloc(copyOfName, i+BLOCK);
        }
        copyOfName[i]=name[i];
    }
    copyOfName=realloc(copyOfName, i+1);
    copyOfName[i]=0;
    if (longName != NULL){
        *longName=i+1;
    }
    return copyOfName;
}

groups *
addGroupRec(groups * group , const char * groupName, int * added){
    if (group == NULL || strcasecmp(groupName,group->groupName) < 0){
        groups * new=calloc(1,sizeof(groups));
        new->nextGroup=group;
        size_t longName=0;
        new->groupName=copyName(groupName, &longName);
        new->longName=longName;
        *added=1;
        return new;
    }
    if (!strcasecmp(groupName,group->groupName)){
        return group;
    }
    group->nextGroup=addGroupRec(group->nextGroup,groupName,added);
    return group;
}

/* Almacena un nuevo grupo de contactos. Si el grupo existe, no hace nada.
** No diferencia entre minúsculas y mayúsculas, el grupo "abc" es el mismo que "ABC",
** "Abc", etc. pero distinto que " abc" o "abc "
** Almacena una copia del nombre, que no tiene un límite para su longitud
*/
int addGroup(addressBookADT addressBook, const char * groupName){
    int added=0;
    addressBook->firstGroup=addGroupRec(addressBook->firstGroup,groupName, &added);
    return added;
}

contacto *
addContactRec(contacto * cont, tContact contact , int * added){
    int c;
    if (cont == NULL || (c=strcasecmp(contact.name, cont->name)) < 0){
        contacto * new=calloc(1,sizeof(contacto));
        size_t longName=0;
        new->name=copyName(contact.name,&longName);
        new->dim=longName;
        new->nextContact=cont;
        size_t longPhone=0;
        new->phoneNumber=copyName(contact.phoneNumber,&longPhone);
        new->dimPhone=longPhone;
        *added=1;
        return new;
    }
    if (!c){
        return cont;
    }
    cont->nextContact=addContactRec(cont->nextContact,contact,added);
    return cont;
}

/* Si existe un grupo de nombre groupName, agrega el contacto contact a la agenda
** Si el grupo no existe, no hace nada
** Si el contact ya estaba relacionado al grupo (había uno con el mismo nombre),
** no lo agrega
*/
int 
addContact(addressBookADT addressBook, const char * groupName, tContact contact){
    groups * aux=addressBook->firstGroup;
    int added=0;
    while (aux!=NULL){
        int c;
        if (!(c=strcasecmp(groupName, aux->groupName))){
            aux->firstContact=addContactRec(aux->firstContact, contact, &added);
            return added;
        }

        if (c < 0){
            return added;
        }
        aux=aux->nextGroup;
    }
    return added;
}

/*
** Permite iterar por todos los contactos de la agenda
** QUE PERTENEZCAN AL GRUPO INDICADO por parámetro en toBegin
** El orden es alfabético por nombre del contacto.
*/
void toBeginForGroup(addressBookADT addressBook, const char * groupName){
    groups * aux=addressBook->firstGroup;
    while (aux != NULL){
        int c=strcasecmp(aux->groupName,groupName);
        if (!c){
            addressBook->persIterator=aux->firstContact;
        }
        if (c > 0){
            return;
        }
        aux=aux->nextGroup;
    }
}

int hasNextForGroup(addressBookADT addressBook){
    return addressBook->persIterator != NULL;
}

/* Retorna un contacto, aborta si no hay siguiente */
tContact nextForGroup(addressBookADT addressBook){
    if (!hasNextForGroup(addressBook)){
        exit(1);
    }
    tContact new;
    new.name=malloc(addressBook->persIterator->dim);
    strcpy(new.name,addressBook->persIterator->name);
    new.phoneNumber=malloc(addressBook->persIterator->dimPhone);
    strcpy(new.phoneNumber,addressBook->persIterator->phoneNumber);
    addressBook->persIterator=addressBook->persIterator->nextContact;
    return new;
}

/*
** Permite iterar por todos los grupos de la agenda
** El orden es alfabético por nombre del grupo.
*/
void toBegin(addressBookADT addressBook){
    addressBook->groupIterator=addressBook->firstGroup;
}

int hasNext(addressBookADT addressBook){
    return addressBook->groupIterator != NULL;
}

/* Retorna una copia del grupo, aborta si no hay siguiente */
char * next(addressBookADT addressBook){
    if (!hasNext(addressBook)){
        exit(1);
    }
    char * group=malloc(addressBook->groupIterator->longName);
    strcpy(group,addressBook->groupIterator->groupName);
    addressBook->groupIterator=addressBook->groupIterator->nextGroup;
    return group;

}