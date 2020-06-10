#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estante.h"
#include "carrito.h"

float total=0; //Monto total de compra

/*
* Esta funcion permite buscar en el catalogo
* y agrega al carrito si se desea.
*/
bool buscar_carrito(carrito c, estante *e){
	int op;
	dnodo *n = buscar(e);
	if(n == NULL) return false;
	printf("\n¿Desea agregarlo al carrito? (1 = si, 2= no): ");
	scanf("%d", &op);
	if(op==1){
		n->libro.existencia--;
		bool b = agregar_al_carrito(c, n->libro);
		if(b==false) return false;
		printf("\nAgregado correctamente\n");
	}
	return true;
}
//Diego 07/06/2020

/*
* Esta funcion agrega un libro al carrito 
* Comportamiento de pila agrega al inicio
*/
bool agregar_al_carrito(carrito c, libro l){
	bool b = insertar_ini(c,l);	
	if(b==false) return false;
	int precio = l.precio;
	total += precio;	
	return true;
}
//Mara 05/06/2020
//Diego 07/06/2020

/*
* Esta funcion elimina un libro del carrito 
* Comportamiento de pila elimina al final
*/
bool borrar_del_carrito(carrito c){
	int precio = c->tail->libro.precio;
	bool b = remover_fin(c);
	if(b==false) return false;
	total = total -precio;
	return true;
}
//Mara 05/06/2020
//Diego 07/06/2020


/*
* Esta funcion confirma la compra e imprime el recibo de compra junto con el total
*/
bool confirmar_compra(carrito c){
	int op;	
	carrito r = crear_estante();
	printf("\n¿Desea confirmar su compra? (1 = si /2 = no): ");
	scanf("%d",&op);
	switch (op){
		case 1:						
			r = generar_recibo(c);				
			printf("\nCOMPRA REALIZADA EXITOSAMENTE\n");
			printf("\nRecibo de compra: \n");									
			bool b = imprimir_carrito(r);
			if(b==false) return false;
			return true;
		case 2:
			return false;
		default:
			printf("\n Entrada no valida\n");
			return false;
	}
}
//Mara 05/06/2020
//Diego 07/06/2020

/*
* Esta funcion genera un apundador a una lista que es el recibo de compra
* Extrayendo la información del carrito como si lo DESENCOLARA
*/
carrito generar_recibo(carrito c){	
	carrito nuevo = crear_estante();
	dnodo *n = c->head;
	for(int i=0; i<c->num; i++){
		insertar_ini(nuevo, n->libro);
		n = n->sig;
	}	
	return nuevo;
}
//Mara 05/06/2020
//Diego 07/06/2020

/*
* Esta funcion imprime la compra final
*/
bool imprimir_carrito(carrito e){
	if(e == NULL) return false;
	if(estante_vacio(e)) return false;
	dnodo *t = e->head;
    printf("\n\tCARRITO:\n");
    printf("\nHay %d libro(s).\n", e->num);
    for(int i=0; i <= e->num-1; i++){
		printf("\t---Libro %d---\n", i+1);
        printf("Titulo: %s \n", t->libro.titulo);
        printf("Autor: %s \n", t->libro.autor);
        printf("Editorial: %s \n", t->libro.editorial);
        if(t->libro.formato) printf("Formato: Tapa Dura\n");
        else printf("Foramto: Tapa Blanda\n");
        printf("ISBN: %d \n", t->libro.ISBN);        
        printf("Precio(mxn): %d \n", t->libro.precio);
        t = t->sig;
    }
    printf("\n\tFIN CARRITO\n");
	printf("\nSubtotal(mxn): %.2f\n", total);
	printf("TOTAL(IVA) (mxn): %.2f\n", total+total*0.16);
	return true;
}
//Diego 07/06/2020

/*
* Esta funcion imprime el carrito
*/
bool ver_carrito(carrito e){
	if(e == NULL) return false;
	if(estante_vacio(e)) return false;
	dnodo *t = e->head;
	int op;
    printf("\n\tCARRITO:\n");
    printf("\nHay %d libro(s).\n", e->num);
    for(int i=0; i <= e->num-1; i++){
		printf("\t---Libro %d---\n", i+1);
        printf("Titulo: %s \n", t->libro.titulo);        
        printf("Precio(mxn): %d \n", t->libro.precio);
        t = t->sig;
    }
	printf("Subtotal(mxn): %.2f\n", total);
	printf("¿Qué desa hacer?\n");
	printf("1) Seguir comprando\n");
	printf("2) Concluir compra\n");

	scanf("%d", &op);
	if(op==2){
		bool b = confirmar_compra(e);
		if(b==false) return false;
	}
	return true;
}
//Diego 07/06/2020
