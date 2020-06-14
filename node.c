#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Crea un libro y lo retorna
libro crear_libro(char titulo[], char autor[], char editorial[], int ISBN, bool formato, int existencia, int precio){
    libro b;
    strcpy(b.titulo, titulo);
    strcpy(b.autor, autor);
    strcpy(b.editorial, editorial);
    b.ISBN = ISBN;
    b.formato = formato;
    b.existencia = existencia;
    b.precio = precio;
	return b;
}

dnodo *crear_dnodo(libro l){
    dnodo *e;
    e = (dnodo*)malloc(sizeof(dnodo));
    e->libro = l;
    e->sig = NULL;
    e->prev = NULL;
    return e;
}

bool borrar_dnodo(dnodo *e){
    if (e->sig ==  e->prev){	    
		free(e);
        return true;
    }
    return false;
}
//Daniel   02-06-2020
//Mara 04/06/2020
//Diego 06/06/2020
