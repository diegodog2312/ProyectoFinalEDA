#ifndef ESTANTE_H
#define ESTANTE_H

#include "nodo.h"
#include <stdbool.h>

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
bool insertar_ini(estante *e, libro *l);
bool insertar_fin(estante *e, libro *l);
//bool insertar_pos(estante *e, libro libro, int pos);

//Remover
bool remover_ini(estante *e);
bool remover_fin(estante *e);
//bool remover_pos(estante *e, int pos);

//Búsqueda
//int locate_dlist(dlist *l, DATA data);//ESTE
estante *buscar_autor(estante *e, char autor[]);
dnodo *buscar_ISBN(estante *e, int ISBN);
estante *buscar_titulo(estante *e, char titulo[]);

//Para el empleado
bool existencias(estante *e, libro *l, bool num);//TRUE agregar FALSE quitar

//Para el cliente
dnodo *recorrer_estante(estante *e, bool direccion, int pos);//TRUE adelante FALSE atras

//Apoyo
void imprimir_estante(estante *e);
bool estante_vacio(estante *e);

#endif
// Mara 04/06/2020
