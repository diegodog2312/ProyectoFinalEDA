#include "Almacenlibro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Daniel   02-06-2020

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


estante *crear_lugar(libro *l){
    estante *e;
    e = (estante*)malloc(sizeof(estante));
    e->libro = l;
    e->sig = NULL;
    e->prev = NULL;
    return e;
}


bool borrar_lugar(estante *e){
    if (e->sig == NULL && e->prev == NULL)
    {
        free(e)
        e = NULL;
        return true;
    }
    return false;
}
