#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estante.h"
#include "carrito.h"

float total=0; //Monto total de compra
dnodo *ultimo; //Ultimo libro comprado

/*
* Esta funcion permite buscar en el catalogo
* y agrega al carrito si se desea.
*/
bool buscar_carrito(carrito c, estante *e){
	int op;
	dnodo *n = buscar(e);
	ultimo = n;
	if(n == NULL) return false;
	printf("\n\n\t¿Desea agregarlo al carrito? (1 = si, 2= no): ");
	scanf("%d", &op);
	if(op==1){
		n->libro.existencia--;
		bool b = agregar_al_carrito(c, n->libro);
		if(b==false) return false;
		printf("\n\tAgregado correctamente\n");
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
	float precio = l.precio;
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
	float precio = c->tail->libro.precio;
	bool b = remover_ini(c);
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
	printf("\n\t¿Desea confirmar su compra? (1 = si /2 = no): ");
	scanf("%d",&op);
	switch (op){
		case 1:
			system("clear");						
			r = generar_recibo(c);				
			printf("\t\tCOMPRA REALIZADA EXITOSAMENTE\n");
			printf("\t\tRecibo de compra: \n");									
			bool b = imprimir_carrito(r);
			if(b==false) return false;
			return true;
		case 2:
			return false;
		default:
			printf("\n\t Entrada no valida\n");
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
	getchar();
	system("clear");
	if(e == NULL) return false;
	if(estante_vacio(e)) return false;
	dnodo *t = e->head;
    printf("\n\n\n\t\t\t CARRITO:\n");
    printf("\n\t\tHay %d libro(s).\n", e->num);
    for(int i=0; i <= e->num-1; i++){
		printf("\t---Libro %d---\n", i+1);
        printf("\n\tTitulo: %s ", t->libro.titulo);
        printf("\n\tAutor: %s ", t->libro.autor);
        printf("\n\tEditorial: %s ", t->libro.editorial);
        if(t->libro.formato) printf("\tFormato: Tapa Dura\n");
        else printf("\tFormato: Tapa Blanda\n");
        printf("\tISBN: %d \n", t->libro.ISBN);        
        printf("\tPrecio(mxn): %f \n", t->libro.precio);
        t = t->sig;
    }
    printf("\n\tFIN CARRITO\n");
	printf("\n\n\n\t\t\tSubtotal(mxn): %.2f\n", total);
	printf("\n\n\n\t\t\tTOTAL(IVA) (mxn): %.2f\n", total+total*0.16);
	return true;
}
//Diego 07/06/2020

/*
* Esta funcion imprime el carrito
*/
bool ver_carrito(carrito e, int *c){
	getchar();
	system("clear");
	if(e == NULL || estante_vacio(e)){
		printf("\n\n\n\t\tCARRITO VACIO");
		printf("\n\tPresione enter para continuar");
		return false;
	}
	dnodo *t = e->head;
	int op;
    printf("\n\n\n\t\t\tCARRITO:\n\n");
    printf("\tHay %d libro(s).\n", e->num);
    for(int i=0; i <= e->num-1; i++){
		printf("\n\t\t---Libro %d---", i+1);
        printf("\t\tTitulo: %s \n", t->libro.titulo);        
        printf("\t\tPrecio(mxn): %f \n", t->libro.precio);
        t = t->sig;
    }
	printf("\n\tSubtotal(mxn): %.2f\n", total);
	printf("\n\t¿Qué desa hacer?");
	printf("\n\t1) Seguir comprando");
	printf("\n\t2) Concluir compra");
	printf("\n\t3) Eliminar último libro comprado del carrito");	
	printf("\n\n\tOpcion: ");
	scanf("%d", &op);
	if(op==2){
		bool b = confirmar_compra(e);
		*c = 1;
		if(b==false) return false;
	}
	if(op==3){
		bool b = borrar_del_carrito(e);
		ultimo->libro.existencia++;
		if(b==false) return false;
	}
	return true;
}
//Diego 07/06/2020
