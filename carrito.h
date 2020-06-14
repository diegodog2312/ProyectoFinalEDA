#ifndef CARRITO_H
#define CARRITO_H
#include "node.h"
#include "estante.h"
#include <stdbool.h>

typedef estante* carrito;

//Comportamiento de pila
bool agregar_al_carrito(carrito c, libro l); //push
bool borrar_del_carrito(carrito c); //pop

//Para el cliente
bool confirmar_compra(carrito c); //TRUE compra confirmada
bool buscar_carrito(carrito c, estante *e);
estante *generar_recibo(carrito c);

//De apoyo
bool imprimir_carrito(carrito e);
bool ver_carrito(carrito e, int *c);
#endif

//Mara 05/06/2020
//Diego 07/06/2020
