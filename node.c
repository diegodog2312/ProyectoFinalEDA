#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


libro *crear_libro(char titulo[], char autor[], char editorial[], int ISBN, bool formato, int existencia, int precio){
    libro *b;
	b = (libro*)malloc(sizeof(libro));
    strcpy(b->titulo, titulo);
    strcpy(b->autor, autor);
    strcpy(b->editorial, editorial);
    b->ISBN = ISBN;
    b->formato = formato;
    b->existencia = existencia;
    b->precio = precio;
	return b;
}

nodo *crear_nodo(libro *l){
    nodo *e;
    e = (nodo*)malloc(sizeof(nodo));
    e->libro = l;
    e->sig = NULL;
    return e;
}

dnodo *crear_dnodo(libro *l){
    dnodo *e;
    e = (dnodo*)malloc(sizeof(dnodo));
    e->libro = l;
    e->sig = NULL;
    e->prev = NULL;
    return e;
}



bool borrar_dnodo(dnodo *e){
    if (e->sig ==  e->prev){
	    borrar_libro(e->libro);
		free(e);
        return true;
    }
    return false;
}

bool borrar_nodo(nodo *e){
    if (e->sig == NULL){
    	borrar_libro(e->libro);
	    free(e);
        return true;
    }
    return false;
}

bool borrar_libro(libro *l){
	free(l);
	return true;
}
//Daniel   02-06-2020
//Mara 04/06/2020
