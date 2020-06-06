#ifndef CARRITO_H
#define CARRITO_H
#include "nodo.h"
#include "estante.h"
#include <stdbool.h>

typedef struct _carrito carrito;

typedef struct _carrito{
	nodo *head;
	nodo *tail;
	int num;//Contador de nodos
};

//Básicas
carrito *crear_carrito();
void eliminar_carrito(carrito *c);
void borrar_carrito(carrito *c);

//Comportamiento de pila
bool agregar_al_carrito(estante *e, carrito *c, libro *l);

//Comportamiento de cola
bool quitar_del_carrito(estante *e, carrito *c); //TRUE salida exitosa
bool vaciar_carrito(estante *e, carrito *c);	//TRUE carrito_vacio(c)

//para el cliente
bool confirmar_compra(carrito *c); //TRUE compra confirmada

//De apoyo
bool carrito_vacio(carrito *c);
estante *generar_recibo(carrito *c);
void imprimir_carrito(carrito *c);
#endif

//Mara 05/06/2020
