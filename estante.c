#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estante.h"
/*
 *Esta fncion crea un estante vacio
 */
estante *crear_estante(){
    estante *e = (estante*)malloc(sizeof(estante));
    e->head = NULL;
    e->tail = NULL;
    e->num = 0;
    return e;
}
//Mara 4/06/2020

/*
 *Esta funcion elimina un estante Si está vacio
 */
bool eliminar_estante(estante *e){
    if(!estante_vacio(e))
        vaciar_estante(e);
    free(e);
    return true;
}
//Mara 4/06/2020

/*
 *Esta funcion vacia estante
 */
void vaciar_estante(estante *e){
	if(estante_vacio(e)) return;
    dnodo *t = e->head;
    while(remover_ini(e));
    e->num = 0;
}
//Mara 4/06/2020

/*
 *Esta funcion inserta al inicio del estante
 */
 bool insertar_ini(estante *e, libro *l){
    if(e == NULL) return false;
    dnodo *nuevo = crear_dnodo(l);
    if(estante_vacio(e)){        
        e->head = nuevo;
        e->tail = nuevo;
        e->head->sig=e->head->prev=e->tail;
        e->tail->sig=e->tail->prev=e->head;
        e->num =1;
        return true;
    }
    nuevo->sig = e->head;
    nuevo->prev = e->tail;
    e->head->prev = nuevo;
    e->tail->sig = nuevo;
    e->head = nuevo;
    e->num++;
    return true;
}
//Mara 4/06/2020

/*
 *Estafuncion insertar al final del estante
 */
 bool insertar_fin(estante *e, libro *l){
 	if(e == NULL) return false;
 	dnodo *nuevo = crear_dnodo(l);
 	if(estante_vacio(e)){
 		e->head = nuevo;
        e->tail = nuevo;
        e->head->sig=e->head->prev=e->tail;
        e->tail->sig=e->tail->prev=e->head;
        e->num =1;
        return true;
    }
    nuevo->prev = e->tail;
    nuevo->sig = e->head;
    e->head->prev = nuevo;
    e->tail->sig = nuevo;
    e->tail = nuevo;
    e->num++;
    return true;
 }
 //Mara 4/06/2020
 
/*
 *Esta funcion elimina el libro al inicio del estante
 */
bool remover_ini(estante *e){
    if(e == NULL || estante_vacio(e)) return false;
    if(e->head == e->tail){
        borrar_dnodo(e->head);
		e->head = e->tail = NULL;
        e->num = 0;
        return true;
    }
    dnodo *t = e->head->sig;
    e->head->sig= NULL;
    t->prev = e->tail;
	e->head->prev = NULL;
    borrar_dnodo(e->head);
    e->head = t;
    e->num--;
    return true;
}
//Mara 4/06/2020
/*
 *Esta funcion elimina el libro al final del estante
 */
bool remover_fin(estante *e){
	if(e == NULL || estante_vacio(e)) return false;
    if(e->head == e->tail){
        borrar_dnodo(e->head);
		e->head = e->tail = NULL;
        e->num = 0;
        return true;
    }
    dnodo *t = e->tail->prev;
	e->tail->sig= NULL;
    t->sig = e->head;
	e->tail->prev = NULL;
	e->head->prev = t;
    borrar_dnodo(e->tail);
    e->tail = t;
    e->num--;
    return true;
}
//Mara 4/06/2020

/*
 *Esta funcion encuentra todos los libros con un mismo autor
 *Almacena los resultados en un estante temporal declarado en main
 */
estante *buscar_autor(estante *e, char autor[]){
	estante *t = crear_estante();
	if(!estante_vacio(e)){
		dnodo *n = e->head;
		int aux = strlen(autor);
		while (n->sig != e->head->sig){
			if(strncmp(autor, n->libro.autor, aux)==0){//if (autor == n->dnodo->libro.autor){
				insertar_ini(t, n->libro);
			}else{
				n = n->sig;
			}
		}
		if(t->num == 0){
			printf("No hay libros de ese autor");
			free(t);
			return NULL;//crearía apuntador a nulo
		}else return t;
	}
	printf("No hay libros en el estante");
	free(t);
	return NULL;//crearía apuntador a nulo
}
//Mara 5/06/2020

/*
 *Esta funcion encuentra un libro por su ISBN
 *Devuelve un nodo con un libro dentro
 */
dnodo *buscar_ISBN(estante *e, int ISBN){
	if(!estante_vacio(e)){
		dnodo *n = e->head;
		while (n->sig != e->head->sig){
			if (ISBN == n->libro.ISBN){
				dnodo *t = crear_dnodo(n->libro);
				return t;
			}else{
				n = n->sig;
			}
		}
		printf("ISBN no valido");
		return NULL;//crearía apuntador a nulo
	}
	printf("No hay libros en el estante");
	return NULL;//crearía apuntador a nulo
}
//Mara 5/06/2020

/*
 *Esta funcion encuentra todos los libros con un mismo titulo
 *Almacena los resultados en un estante temporal declarado en main
 */
estante *buscar_titulo(estante *e, char titulo[]){
	estante *t = crear_estante();
	int aux = strlen(titulo);
	if(!estante_vacio(e)){
		dnodo *n = e->head;
		while (n->sig != e->head->sig){
			if(strncmp(titulo, n->libro.titulo, aux)==0){//if (titulo == n->dnodo->libro.titulo){
				insertar_ini(t, n->libro);
			}else{
				n = n->sig;
			}
		}
		if(t->num == 0){
			printf("No hay libros con ese titulo");
			free(t);
			return NULL;//crearía apuntador a nulo
		}else return t;
	}
	printf("No hay libros en el estante");
	free(t);
	return NULL;//crearía apuntador a nulo
}
//5/06/2020

/*
 *Esta funcion aumenta(TRUE) o disminuye(FALSE) las existencias de un libro
 */
 bool existencias(estante *e, libro *l, bool num){
 	if(!estante_vacio(e)){
	  dnodo *aux = e->head;
	  if (num){
	    while (aux->sig != e->head->sig){
			if (l == aux->libro){
				aux->libro.num = aux->libro.num + 1;
				return true;
			}else{
				aux = aux->sig;
			}
	  }
	  return false;
	  }	else{
	  	while (aux->sig != e->head->sig){
			if (l == aux->libro){
				aux->libro.num = aux->libro.num - 1;
				return true;
			}else{
				aux = aux->sig;
			}
	  }
	  return false;
	  }
	 }
	 printf("Estante Vacio");
	 return false;
 }
 //Mara 5/06/2020
/*
 *Esta funcion tiene un *dnodo auxiliar que recorre el estante una posicion
 *hacia adelante(TRUE) o atras(FALSE) desde cualquier posicion inicial dada
 *Si se quiere recorrer todo el estante se debe utilizar esta funcion en varias ocaciones
 *DEBE existir una variable que lleve la cuenta de las posiciones que avanza o retrocede en main
 */
dnodo *recorrer_estante(estante *e, bool direccion, int pos){
	if(estante_vacio(e)) return NULL; //Advertencia puede generar un apuntador a NULO
	dnodo *aux1 = e->head;
	int i = 1;
	while((pos > 0)&& (pos <= e->num) && (pos <= i)){
		aux1->sig = aux1;
		i++;
	}
	if(direccion){
		aux1 = aux1->sig;
		pos = i;
		return aux1;
	}else{
		aux1=aux1->prev;
		pos = i;
		return aux1;
	}
}
//Mara 05/06/2020
 /*
 *Esta funcion nos dice si un estante esta vacío(TRUE)
 */
bool estante_vacio(estante *e){
	if((e->head == NULL) && (e->tail == NULL)) return true;
    return false;
}
 //Mara 5/06/2020
 /*
 *Esta funcion imprime un estante en la consola
 */
 void imprimir_estante(estante *e){
 	if(e == NULL) return;
	if(estante_vacio(e)) return;
	dnodo *t = e->head;
    printf("\n\tEstante\n");
    for(int i=0; i < e->num-1; i++){
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
    printf("\n\tFin estante\n");
 }
 //Mara 5/06/2020
