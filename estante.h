#ifndef ESTANTE_H
#define ESTANTE_H

#include "node.h"
#include <stdbool.h>

//Lista doblemente ligada circular
typedef struct _estante estante;
struct _estante{
	dnodo *head;
	dnodo *tail;
	int num;
};

//Básicas
estante *crear_estante();
bool eliminar_estante(estante *e);
void vaciar_estante(estante *e);

//Insertar
bool insertar_ini(estante *e, libro l);
bool insertar_fin(estante *e, libro l);


//Remover
bool remover_ini(estante *e);
bool remover_fin(estante *e);
bool eliminar_libro(estante *e);

//Búsqueda
dnodo* buscar(estante *e);
dnodo* search_dnodo_estante(estante *l, int pos);

//Para el empleado
bool existencias(estante *e);

//Para el cliente
bool recorrer_estante(estante *e);

//Apoyo
void imprimir_estante(estante *e);
bool estante_vacio(estante *e);
void pedir_libro(estante *e);

//Manejar archivos
void download(estante *l);
void upload(estante *l);

#endif
// Mara 04/06/2020
// Diego 06/06/2020
