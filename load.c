/*
*    En este programa están las funciones para descargar
*    y cargar la información del archivo de texto. También
*    incluyo la función para buscar. 
*    Sólo copien y peguen las funciones. Lo demás lo puse
*    nada más para probar que todo funcionara bien.
*    Para probar las funciones usé lo que hicimos de lista
*    doblemente ligada, por lo que en las funciones hay que
*    cambiar las líneas en donde llamo a sus funcines por las 
*    nuestras.
*/

//Cabeceras
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//Estructuras
typedef struct _libro LIBRO;
struct _libro{
    char titulo[4];
    char autor[4];
    int ISBN;
};
typedef struct _dnode dnode;
struct _dnode{
    LIBRO libro;
    dnode *next;
    dnode *prev;
};
typedef struct _dlist dlist;
struct _dlist{
    dnode *head;
    dnode *tail;
    int num;
};

//Prototipos
bool remove_init(dlist *l);
void empty_dlist(dlist *l);
bool is_empty_dlist(dlist *l);
dnode* search_dnode_dlist(dlist *l, int pos);

//Funciones para probar el funcionamiento
dnode *create_dnode(LIBRO libro){
    dnode * d = (dnode*)malloc(sizeof(dnode));
    d->next = NULL;
    d->prev = NULL;
    d->libro = libro;
    return d;
}

bool remove_dnode(dnode *n){
    if(n->prev == NULL && n->next == NULL){
        free(n);
        return true;
    }
    return false;
}

dlist *create_dlist(){
    dlist *l = (dlist*)malloc(sizeof(dlist));
    l->head = NULL;
    l->tail = NULL;
    l->num = 0;
    return l;
}

bool remove_dlist(dlist *l){
    if(!is_empty_dlist(l))
        empty_dlist(l);
    free(l);
    return true;
}

bool insert_end(dlist* l, LIBRO libro){
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(libro);
    if(is_empty_dlist(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        l->num =1;
        return true;
    }
    l->tail->next = nuevo;
    nuevo->prev = l->tail;
    l->tail = nuevo;
    l->num++;
    return true;
}

void print_dlist(dlist *l){
    dnode *t = l->head;    
    int i;
    for(i=0; i < l->num-1; i++){
        printf("\nLibro [%d]: \n",i+1);
        printf("Titulo: %s\n", t->libro.titulo);
        printf("Autor: %s\n", t->libro.autor);
        printf("ISBN: %d \n", t->libro.ISBN);
        t = t->next;
    }
    printf("\nLibro [%d]: \n", i+1);
    printf("Titulo: %s\n", t->libro.titulo);
    printf("Autor: %s\n", t->libro.autor);
    printf("ISBN: %d \n", t->libro.ISBN);
    printf("\n");
}

bool is_empty_dlist(dlist *l){
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}

void empty_dlist(dlist *l){
    if(is_empty_dlist(l)) return;
    dnode *t = l->head;
    while(remove_init(l));
}

bool remove_init(dlist *l){
    if(l == NULL || is_empty_dlist(l)) return false;
    if(l->head ==l->tail){
        remove_dnode(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    dnode *t = l->head->next;
    l->head->next= NULL;
    t->prev = NULL;
    remove_dnode(l->head);
    l->head = t;
    l->num--;
    return true;
}

dnode* search_dnode_dlist(dlist *l, int pos){
    if(pos == 0) return l->head;
    else if(pos == l->num-1) return l->tail;
    else if(pos >0 && pos < l->num-1){
        dnode *t = l->head->next;
        for(int i=1; i<l->num-1; i++){
            if(i==pos) return t;
            t = t->next;
        }
    }
    return NULL;
}

//FUNCIONES IMPORTANTES

//UPLOAD
//Escribe los cambios que se hacen en el archivo de texto
// Hecho por Diego Nuñez
void upload(dlist *l){ 
    FILE *F;
    F = fopen("libreria.txt", "wb");
    fwrite(l, sizeof(dlist), l->num, F);
    fclose(F);

    FILE *I;
    I = fopen("noLibros.txt", "wb"); //Es necesario el uso de otro archivo de texto para guardar el # de libros
    fwrite(&l->num, sizeof(int), 1, I);
    fclose(I);
}

//DOWNLOAD
//Descarga los libros del archivo y los pone en la lista
// Hecho por Diego Nuñez
void download(dlist *l){
    empty_dlist(l);
    FILE *H;
    int noLibros;
    H = fopen("noLibros.txt", "rb");
    fread(&noLibros, sizeof(int), 1, H); //Es necesario el uso de otro archivo de texto para guardar el # de libros
    fclose(H);
    
    FILE *G;
    G = fopen("libreria.txt", "rb");
    fread(l,sizeof(dlist), noLibros, G); 
    fclose(G);
}

//Buscar
//Hecho por Diego Nuñez
dnode* buscar(dlist *l){
	system("cls");
    bool op=true;
    int opcion;
    int no_coincidencias=0; 
    int coincidencias[l->num];
    int ISBN;
    char c[4]; //Aquí hay que cambiar el número por el número de caracteres que tendrán el título y autor
    dnode *t;
    do{
        printf("\nBUSCAR\n");
        printf("1. Titulo\n");
        printf("2. Autor\n");
        printf("3. ISBN\n");
        printf("¿Como desea buscar? ");
        scanf("%d",&opcion);
        switch (opcion){
        case 1:
            t = l->head;
            printf("\nInserte el titulo del libro: ");
            scanf("%s", &c);
            for(int i= 0; i<l->num; i++){
                if(strncmp(c,t->libro.titulo,4)==0){  //Aquí hay que cambiar el número por el número de caracteres que tendrán el título y autor                  
                    coincidencias[no_coincidencias]=i;
                    no_coincidencias++;
                }
                t = t->next;
            }               
            op=true; 
        break;
        case 2:
            t = l->head;
            printf("\nInserte el autor del libro: ");
            scanf("%s", &c);
            for(int i= 0; i<l->num; i++){
                if(strncmp(c,t->libro.autor,4)==0){ //Aquí hay que cambiar el número por el número de caracteres que tendrán el título y autor                     
                    coincidencias[no_coincidencias]=i;
                    no_coincidencias++;
                }
                t = t->next;
            }
            op = true;
        break;            
        case 3:
            t = l->head;
            printf("\nInserte el ISBN del libro: ");
            scanf("%d", &ISBN);
            for(int i= 0; i <l->num; i++){
                if(ISBN==t->libro.ISBN){                    
                    coincidencias[no_coincidencias]=i;
                    no_coincidencias++;
                }
                t = t->next;
            }
            op = true;
        break;    
        default:
            printf("\nERROR, Vuelva a ingresar\n");
            op = false;
        break;
        }
    }while (op==false);    
        //Aquí hay que agregar la informacion completa de los libros
        //Cuando hay más de una coincidencia
        if(no_coincidencias>1){
            printf("Se ha encontrado mas de una coincidencia: \n");
            int k;
            for(k=0; k<no_coincidencias;k++){
				t = search_dnode_dlist(l, coincidencias[k]);
                printf("%i. Titulo: %s\n Autor: %s\n", k+1, t->libro.titulo, t->libro.autor);
			}
            printf("\n¿Cual es el que buscaba? : ");
			scanf("%i", &k);  
            t = search_dnode_dlist(l, coincidencias[k-1]);            
            printf("\nTitulo: %s\n", t->libro.titulo);
            printf("Autor: %s\n", t->libro.autor);
            printf("ISBN: %d \n", t->libro.ISBN);
            return t;
        //Cuando no se encontro ninguna coincidencia    
        }else if(no_coincidencias==0){
            printf("\nNo se encontraron coincidencias\n");
            return NULL;
        } else {
        //Cuando se encuentra una sola coincidencia
            t = search_dnode_dlist(l, coincidencias[0]);
            printf("\nTitulo: %s\n", t->libro.titulo);
            printf("Autor: %s\n", t->libro.autor);
            printf("ISBN: %d \n", t->libro.ISBN);
            return t;
        }            
}

//MAIN
int main(){    
    //Upload
    dlist *libreria = create_dlist();
    LIBRO libro1;
    strcpy(libro1.titulo, "AAA");
    strcpy(libro1.autor, "A1");
    libro1.ISBN = 10;
    insert_end(libreria, libro1);
    LIBRO libro2;
    strcpy(libro2.titulo, "BBB");
    strcpy(libro2.autor, "A1");
    libro2.ISBN = 20;
    insert_end(libreria, libro2);
    print_dlist(libreria);
    upload(libreria); //Se suben los cambios al archivo
    
    //Download
    dlist *libreria2 = create_dlist();
    download(libreria2); //Se cargan los datos del archivo a la nueva lista
    print_dlist(libreria2); 
    
    //Buscar
    LIBRO libro3;
    strcpy(libro3.titulo, "BBB");
    strcpy(libro3.autor, "A2");
    libro3.ISBN = 30;    
    insert_end(libreria2, libro3);
    print_dlist(libreria2);
    buscar(libreria2);

    return 0;
}