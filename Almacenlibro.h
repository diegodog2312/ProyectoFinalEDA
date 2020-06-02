#ifndef LIBRO_H
#define LIBRO_H
#include <stdbool.h>

typedef struct _libro libro;

struct _libro{
    char titulo[50];
    char autor[50];
    char editorial[50];  
    int ISBN;
    bool formato;  //tapa blanda = false     tapa dura = true
    int existencia;
    int precio;
};

libro *crear_libro(char titulo[], char autor[], char editorial[], int ISBN, bool formato, int existencia, int precio);
void borrar_libro(libro *l); 


typedef struct _estante estante;

struct _estante{
    libro *libro;
    estante *sig;
    estante *prev;
};

estante *crear_lugar(libro *l);
bool borrar_lugar(estante *e);







#endif

//Daniel 30-05-2020
//Daniel 02-06-2020 