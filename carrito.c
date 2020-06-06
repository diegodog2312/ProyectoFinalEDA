#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estante.h"
#include "carrito.h"
/*
 *Esta funcion crea un carrito vacio
 */
carrito *crear_carrito(){
	carrito *c = (carrito*)malloc(sizeof(carrito));
	c->head = NULL;
	c->tail = NULL;
	c->num = 0;
}
//Mara 05/06/2020
/*
 *Esta funcion elimina un carrito vacio
 */
void eliminar_carrito(carrito *c){
	if(!carrito_vacio(c)){
		borrar_carrito(c);
	}
	free(c);
}
//Mara 05/06/2020
/*
 *Esta funcion agrega un nodo con un libro al carrito REDUCE las unidades del estante
 *Comportamiento de pila agrega al inicio
 */
bool agregar_al_carrito(estante *e, carrito *c, libro *l){
	if (c == NULL) return false;
	nodo *n = crear_nodo(l);
	existencias(e, l, false);
	if (carrito_vacio(c)){
		c->head = c->tail = n;
		c->num = 1;
	}else{
		n->sig = c->head;
		c->head = n;
		c->num ++;
	}
	return true;
}
//Mara 05/06/2020
/*
 *Esta funcion elimina un nodo del carrito AUMENTA las unidades del estante
 *Comportamiento de cola elimina al inicio
 */
 bool quitar_del_carrito(estante *e, carrito *c){
	if ((c == NULL) || (carrito_vacio(c))) return false;
	nodo *n = c->head->sig;
	existencias (e, n->libro, true);
	borrar_nodo(c->head);
	c->head = n;
	c->num --;
	return true;
}
//Mara 05/06/2020
/*
 *Esta funcion Borra un nodo del carrito SIN ALTERAR las unidades del estante
 *Debe ser utilizada cuando la COMPRA YA HA SIDO CONFIRMADA
 *Comportamiento de cola elimina al inicio
 */
 void borrar_carrito(carrito *c){
	if (c == NULL) return;
	if (carrito_vacio(c)){
		free(c);
		return;
	} 
	nodo *n = c->head->sig;
	borrar_nodo(c->head);
	c->head = n;
	c->num --;
	return;
}
//Mara 05/06/2020
/*
 *Esta funcion vacia completamente un carrito como si fuera una cola
 */
bool vaciar_carrito(estante *e, carrito *c){
	if(carrito_vacio(c))return true;
	while(!carrito_vacio(c)){
		quitar_del_carrito(e, c);
	}
	return true;
}
//Mara 05/06/2020

/*
 *Esta funcioion confima la compra(TRUE) e imprime el recibo de compra con el total
 */
bool confirmar_compra(carrito *c){
	char op;
	printf("\n Desea confirmar su compra (s/n) ");
	scanf(" %c",&op);
	switch (op){
		case 's':
			estante *r;
			r = generar_recibo(c);
			int total = 0;
			int i = 1;
			dnodo *aux = r->head;
			while(i <= r->num){
				total = aux->libro.precio;
				aux->sig = aux;
				i++;
			}
			imprimir_estante(r);
			printf("\t\n Total (mxn): &d \n",total);
			return true;
		case 'n':
			return false;
		default:
			printf("\n Entrada no valida\n");
			return false;
	}
}
//Mara 05/06/2020
/*
 *Esta funcion genera un apundador a un estante llamado recibo de compra
 *Extrayendo la información del carrito como si lo DESENCOLARA
 *Y al terminar elimina al carrito
 */
estante *generar_recibo(carrito *c){
	if ((c == NULL) || (carrito_vacio(c))) return NULL;//ADVERTENCIA puede crear un apuntador a NULO
	estante *nuevo = crear_estante();
	nodo *n = c->head;
	while(n!=NULL){
		insertar_ini(nuevo, n->libro);
		n = n->sig;
	}
	eliminar_carrito(c);
}
//Mara 05/06/2020
/*
 *Esta funcion valida si un carrito esta vacio (TRUE)
 */
bool carrito_vacio(carrito *c){
	if (c->head && c->tail == NULL) return true;
	return false;
}
//Mara 05/06/2020
/*
 *Esta funcion imprime un carrito
 */
void imprimir_carrito(carrito *c){
	if(c == NULL) return;
	if(carrito_vacio(c)) return;
	nodo *t = c->head;
    printf("\n\tArticulos en el carrito\n");
    for(int i=0; i < c->num-1; i++){
        printf("Titulo: %s, ", t->libro.titulo);
        printf("Autorr: %s, ", t->libro.autor);
        printf("Editorial: %s, ", t->libro.editorial);
        if(t->libro.formato) printf("Formato: Tapa Dura");
        else printf("Foramto: Tapa Blanda");
        printf("ISBN: %d, ", t->libro.ISBN);
        printf("Existencias: %d, ", t->libro.existencia);
        printf("Precio(mxn): %d, ", t->libro.precio);
        t = t->sig;
    }
    printf("\n\tFin carrito\n");
}
//MAra 05/06/2020
