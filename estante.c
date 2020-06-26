#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estante.h"

/*
* Esta funcion crea un estante vacio
*/
estante *crear_estante(){
    estante *e = (estante*)malloc(sizeof(estante));
    e->head = NULL;
    e->tail = NULL;
    e->num = 0;
    return e;
}
//Mara 4/06/2020
//Diego 07/06/2020

/*
* Esta funcion elimina un estante si está vacio
*/
bool eliminar_estante(estante *e){
    if(!estante_vacio(e)) vaciar_estante(e);
    free(e);
    return true;
}
//Mara 4/06/2020
//Diego 07/06/2020

/*
 *Esta funcion vacia un estante
 */
void vaciar_estante(estante *e){
	if(estante_vacio(e)) return;
    dnodo *t = e->head;
    while(remover_ini(e));
}
//Mara 4/06/2020
//Diego 07/06/2020

/*
* Esta funcion pide los datos para crear un libro
*/
void pedir_libro(estante *e){
    char titulo[50];
    char autor[50];
    char editorial[50];
    int ISBN;
    int formato_num;
    bool formato;
    int existencia;
    float precio;    
    printf("\n\n\n\t\t\t AGREGAR UN LIBRO \n\n\n");
    printf("\n\tTitulo: ");
    getchar();
    gets(titulo);
    printf("\n\tAutor: ");    
    gets(autor);
    printf("\n\tEditorial: ");
    gets(editorial);
    printf("\n\tISBN: ");
    scanf("%d", &ISBN);
    printf("\n\tFormato (1 = Tapa blanda, 2  = Tapa dura): ");
    scanf("%d", &formato_num);
    printf("\n\tExistencias: ");
    scanf("%d", &existencia);
    printf("\n\tPrecio: ");
    scanf("%f", &precio);

    if (formato_num-1){
        formato = true;
    } else {
        formato = false;
    }
    libro b = crear_libro(titulo, autor, editorial, ISBN, formato, existencia, precio);    
    insertar_fin(e, b);
    printf("\n\n\n\t\t\t %s fue agregado correctamente\n", e->tail->libro.titulo);    
    getchar();
}
//Diego 07/06/2020

/*
* Esta funcion inserta al inicio del estante
*/
bool insertar_ini(estante *e, libro l){
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
//Diego 07/06/2020

/*
* Esta funcion inserta al final del estante
*/
bool insertar_fin(estante *e, libro l){
	if(e == NULL) return false;
 	dnodo *nuevo = crear_dnodo(l);
	if(estante_vacio(e)){
		e->head = nuevo;
        e->tail = nuevo;
        e->head->sig=e->head->prev=e->tail;
        e->tail->sig=e->tail->prev=e->head;
        e->num = 1;
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
//Diego 07/06/2020

/*
* Esta funcion elimina un libro al inicio del estante
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
//Diego 07/06/2020

/*
* Esta funcion elimina un libro al final del estante
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
//Diego 07/06/2020

/*
* Esta funcion elimina un libro del estante
*/
bool eliminar_libro(estante *e){	
	int op;
	dnodo *t = buscar(e);	
	if(t==NULL) return false;
	printf("\n\n\t¿Esta seguro de eliminar este libro? (1 = si /2 = no): ");
	scanf("%d", &op);
	if(op==1){
        if(t==e->head){
            remover_ini(e);
            return true;
        }
        if (t==e->tail){
            remover_fin(e);
            return true;
        }
        
		dnodo *prev = t->prev;    
		dnodo *next = t->sig;        
		prev->sig = next;        
		next->prev = prev;
		t->sig = NULL;
		t->prev = NULL;
		borrar_dnodo(t);
		e->num--;
		printf("\n\n\tEliminado correctamente");
	} else {
		printf("\n\n\tCancelando...");
	}	
	return true;
    getchar();
}
//Diego 06/06/2020

/*
* Esta funcion aumenta o disminuye las existencias de un libro
*/
bool existencias(estante *e){	
	int op;
	int existencias;
	printf("\t\t\t\nControl de existencias\n");	
	printf("\t1) Agregar existencias\n");
	printf("\t2) Quitar existencias\n");
	printf("\t¿Que desea hacer?\n");
    scanf("%d", &op);
    setbuf(stdin, NULL);
	if (op!=2 && op!=1) return false;	
	
	dnodo *l = buscar(e);
	if (l==NULL) return false;	
	
	if(!estante_vacio(e)){	    		
		if (op==1){						
			printf("\n\t¿Cuantas existencias desea agregar? ");
			scanf("%d",&existencias);
            setbuf(stdin, NULL);            
			l->libro.existencia = l->libro.existencia + existencias;
			printf("\n\tSe agregaron %d existencias", existencias);		
			return true;
		} else{			
			printf("\n\t¿Cuantas existencias desea eliminar? ");
			scanf("%d",&existencias);
			if(existencias>l->libro.existencia){
				printf("\n\tError, fuera de rango");
				return false;
			} else {
				l->libro.existencia = l->libro.existencia - existencias;
				printf("\n\tSe quitaron %d existencias", existencias);						
                return true;
			}
		}
	}
    return false;
	printf("\n\t\tEstante Vacio\n");	
}
//Mara 5/06/2020
//Diego 06/06/2020

/*
* Esta funcion se encarga de recorrer el estante
* tanto hacia adelante como hacia atras
*/
bool recorrer_estante(estante *e){
	if(e == NULL) return false;
	if(estante_vacio(e)) return false;
	dnodo *t = e->head;
    int op=1;
    int i=1;    
    while (op==1 || op==2){
        system("clear");
        printf("\n\t\tESTANTE\n");
        printf("\tHay %d libros.\n\n", e->num);
        printf("\t\t---Libro---");
        printf("\n\tTitulo: %s ", t->libro.titulo);
        printf("\n\tAutor: %s ", t->libro.autor);
        printf("\n\tEditorial: %s ", t->libro.editorial);
        if(t->libro.formato) printf("\n\tFormato: Tapa Dura");
        else printf("\n\tFormato: Tapa Blanda");
        printf("\n\tISBN: %d ", t->libro.ISBN);
        printf("\n\tExistencias: %d ", t->libro.existencia);
        printf("\n\tPrecio(mxn): %.2f ", t->libro.precio);
        printf("\n\n\t1 = Libro siguiente");
        printf("\n\t2 = Libro anterior");
        printf("\n\t3 = Salir");
        printf("\n\tOpcion: ");
        scanf("%d",&op);
        if(op==1){
            t = t->sig;        
        }
        if(op==2){
            t = t->prev;            
        }
    }    
    printf("\n\t\tFin estante\n");
    return true;
}
//Mara 05/06/2020
//Diego 06/06/2020

/*
* Esta funcion nos dice si un estante esta vacío(TRUE)
*/
bool estante_vacio(estante *e){
	if((e->head == NULL) && (e->tail == NULL)) return true;
    return false;
}
//Mara 5/06/2020

/*
* Esta funcion imprime todo un estante en la consola
*/
void imprimir_estante(estante *e){	
	if(e == NULL) return;
	if(estante_vacio(e)) return;
	dnodo *t = e->head;
    printf("\n\tESTANTE\n");
    printf("\nHay %d libros.\n", e->num);
    for(int i=0; i <= e->num-1; i++){
		printf("\t---Libro %d---", i+1);
        printf("\n\n\tTitulo: %s ", t->libro.titulo);
        printf("\n\n\tAutor: %s ", t->libro.autor);
        printf("\n\n\tEditorial: %s ", t->libro.editorial);
        if(t->libro.formato) printf("\n\n\tFormato: Tapa Dura");
        else printf("\n\n\tForamto: Tapa Blanda");
        printf("\n\n\tISBN: %d ", t->libro.ISBN);
        printf("\n\n\tExistencias: %d ", t->libro.existencia);
        printf("\n\n\tPrecio(mxn): %.2f ", t->libro.precio);
        t = t->sig;
    }
    printf("\n\tFin estante\n");
}
//Mara 5/06/2020
//Diego 07/06/2020

/*
* Esta funcion busca en el catalogo de libros
*/
dnodo* buscar(estante *l){		
    bool op=true;
    int opcion;
    int no_coincidencias=0; 
    int coincidencias[l->num];
    int ISBN;
    char c[50];
    dnodo *t;
    do{
        printf("\n\n\t¿Como desea buscar? ");
        printf("\n\t1. Titulo");
        printf("\n\t2. Autor");
        printf("\n\t3. ISBN");
        printf("\n\n\tOpcion: ");

        scanf("%d",&opcion);
        switch (opcion){
        case 1:
            t = l->head;
            printf("\n\n\tInserte el titulo del libro: ");
            getchar();        
            gets(c);
            printf("\n\n\n\tBuscando %s ....",c);          
            for(int i= 0; i<l->num; i++){
                if(strncmp(c,t->libro.titulo,50)==0){
                    coincidencias[no_coincidencias]=i;
                    no_coincidencias++;
                }
                t = t->sig;
            }               
            op=true; 
		break;
        case 2:
            t = l->head;
            printf("\n\n\tInserte el autor del libro: ");
            getchar();        
            gets(c);
            printf("\n\n\n\tBuscando %s ....",c);
            for(int i= 0; i<l->num; i++){
                if(strncmp(c,t->libro.autor,4)==0){
                    coincidencias[no_coincidencias]=i;
                    no_coincidencias++;
                }
                t = t->sig;
            }  
            op = true;
        break;            
        case 3:
            t = l->head;
            printf("\n\n\tInserte el ISBN del libro: ");
            scanf("%d", &ISBN);
            for(int i= 0; i <l->num; i++){
                if(ISBN==t->libro.ISBN){                    
                    coincidencias[no_coincidencias]=i;
                    no_coincidencias++;
                }
                t = t->sig;
            }
            op = true;
        break;    
        default:
		printf("\n\t ERROR \n Vuelva a ingresar\n");
		op = false;
        break;
        }
    }while (op==false);    
        //Cuando hay más de una coincidencia
        if(no_coincidencias>1){
            printf("\n\n\tSe ha encontrado mas de una coincidencia: ");
            int k;
            for(k=0; k<no_coincidencias;k++){
				t = search_dnodo_estante(l, coincidencias[k]);
                printf("\t %i. Titulo: %s\n Autor: %s", k+1, t->libro.titulo, t->libro.autor);
			}
            printf("\n\n\t¿Cual es el que buscaba? : ");
			scanf("%i", &k);  
            t = search_dnodo_estante(l, coincidencias[k-1]);            
            printf("\n\n\tTitulo: %s", t->libro.titulo);
            printf("\n\n\tAutor: %s", t->libro.autor);
            printf("\n\n\tISBN: %d ", t->libro.ISBN);
            printf("\n\n\tExistencias: %d ", t->libro.existencia);
            return t;
        //Cuando no se encontro ninguna coincidencia    
        }else if(no_coincidencias==0){
            printf("\n\n\t No se encontraron coincidencias");
            return NULL;
        } else {
        //Cuando se encuentra una sola coincidencia
            t = search_dnodo_estante(l, coincidencias[0]);
            printf("\n\n\tTitulo: %s", t->libro.titulo);
            printf("\n\n\tAutor: %s", t->libro.autor);
            printf("\n\n\tISBN: %d ", t->libro.ISBN);
            printf("\n\n\tExistencias: %d ", t->libro.existencia);
            return t;
        }            
}
//Diego 07/06/2020

/*
* Esta funcion busca un nodo
*/
dnodo* search_dnodo_estante(estante *l, int pos){
    if(pos == 0) return l->head;
    else if(pos == l->num-1) return l->tail;
    else if(pos >0 && pos < l->num-1){
        dnodo *t = l->head->sig;
        for(int i=1; i<l->num-1; i++){
            if(i==pos) return t;
            t = t->sig;
        }
    }
    return NULL;
}
//Diego 07/06/2020

//UPLOAD
//Escribe los cambios que se hacen en el archivo de texto
void upload(estante *l){ 
    libro arreglo[l->num];
    dnodo *t = l->head;
    for(int i=0; i<l->num; i++){
        strcpy(arreglo[i].titulo,t->libro.titulo);
        strcpy(arreglo[i].autor,t->libro.autor);
        strcpy(arreglo[i].editorial,t->libro.editorial);
        arreglo[i].existencia = t->libro.existencia;
        arreglo[i].ISBN = t->libro.ISBN;
        arreglo[i].precio = t->libro.precio;
        arreglo[i].formato = t->libro.formato;
        t = t->sig;
    }
    FILE *F;
    F = fopen("libreria.txt", "wb");
    fwrite(&arreglo, sizeof(libro), l->num, F);
    fclose(F);

    FILE *I;
    I = fopen("noLibros.txt", "w"); //Es necesario el uso de otro archivo de texto para guardar el # de libros
    fprintf(F, "%d\n", l->num);
    fclose(I);
}
//Diego 02/06/2020

//DOWNLOAD
//Descarga los libros del archivo y los pone en la lista
void download(estante *l){    
    vaciar_estante(l);    
    
    FILE *H;
    int noLibros;
    H = fopen("noLibros.txt", "r"); //Es necesario el uso de otro archivo de texto para guardar el # de libros    
    fscanf(H,"%d",&noLibros);
    fclose(H);
    
    libro arreglo[noLibros];
    libro b;

    FILE *G;
    G = fopen("libreria.txt", "rb");
    fread(&arreglo,sizeof(libro), noLibros, G); 
    fclose(G);

    for(int i=0; i<noLibros; i++){
        b = crear_libro(arreglo[i].titulo, arreglo[i].autor, arreglo[i].editorial, arreglo[i].ISBN, arreglo[i].formato, arreglo[i].existencia, arreglo[i].precio);
        insertar_fin(l,b);
    }

}
//Diego 02/06/2020
