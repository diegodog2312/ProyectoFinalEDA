#ifndef NODO_H
#define NODO_H

#include <stdbool.h>

typedef struct _libro libro;
struct _libro{
    char titulo[50];
    char autor[50];
    char editorial[50];  
    int ISBN;
    bool formato;  //tapa blanda = false / tapa dura = true
    int existencia;
    int precio;
};

//Funcion para crear un libro
libro crear_libro(char titulo[], char autor[], char editorial[], int ISBN, bool formato, int existencia, int precio);

typedef struct _dnodo dnodo;
struct _dnodo{
    libro libro;
    dnodo *sig;
    dnodo *prev;
};

dnodo *crear_dnodo(libro l);
bool borrar_dnodo(dnodo *n);

#endif
//Daniel 02/06/2020
//Mara 04/06/2020 
//Diego 06/06/2020
