#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "node.h"
#include "carrito.h"
#include "estante.h"

int verificar_compra = 0; 

//MENU EMPLEADO
void empleado(estante *e){
    int re, volver;
    bool b;
    printf("\n\n\n\t\t\t BIENVENIDO A EMPLEADO \n\n\n");
    do{
        system("clear");
        printf("\t ¿Qué desea hacer? \n \n\t1) Agregar un libro \n\t2) Dar de baja \n\t3) Agregar existencias \n\t4) Salir ");
        printf("\n\n\tOpcion: ");
        scanf("%d",&re);        
        switch(re){
            case 1:
                system("clear");
                pedir_libro(e);                            
                break;
            case 2:
                system("clear");
                do{
                    b = eliminar_libro(e);
                    if(b==false) printf("ERROR");                                        
                    printf("¿Desea seguir eliminando? (1 = si / 2 = no): ");
                    scanf("%d", &volver);                    
                    system("clear");
                }while(volver==1);
                printf("\n Usted salió correctamente\n");
            break;
            case 3:                
                system ("clear");
                b = existencias(e);                
                if(b==false) printf("ERROR");                
            break;
            case 4:
            break;
            default:
                printf("\nOpcion invalida\n");            
        }        
    } while(re !=4);
}

//MENU CLIENTE 
void cliente(estante *e, carrito c){
    int rc;   
    bool b;
    printf("\n\n\n\t\t\t BIENVENIDO A CLIENTE\n\n\n");
    do{
        system("clear");
        printf("\t ¿Qué desea hacer? \n\n\t1) Ver libros en venta \n\t2) Buscar libros\n\t3) Ver carrito \n\t4) Salir");
        printf("\n\n\tOpcion: ");
        scanf("%d",&rc);        
        switch(rc){
            case 1:
                system("clear");
                b = recorrer_estante(e);
                if(b==false) printf("ERROR");                          
            break;
            case 2:                
                system("clear");    
                b = buscar_carrito(c,e);
                if(b==false) printf("ERROR");                
            break;                
            case 3:                
                system ("clear");
                ver_carrito(c, &verificar_compra);
                if(verificar_compra == 1) return;
            break;
            case 4:
            break;
            default:
                printf("\nOpcion invalida\n");
        }                        
    } while(rc!=4);    
}

//MAIN
int main(){    
    int respuesta;
    estante *l = crear_estante();
    download(l);    
    carrito c = crear_estante();
    system("clear");
    printf("\n\n\tLa empresa bibliotEDA agradece su preferencia.\n\tEsperamos que nuestros servicios llenen sus expectativas.\n");
    printf("\n\n\tEn esta plataforma usted podra comprar los libros que guste \n\t\t Podra ver nuestro catalogo\n\t\t y MAS");
    printf("\n\n\tPresione enter para continuar... ");
    getchar();
    do{
        system("clear");
        printf("\n\n\n\t\t\t BIENVENIDO\n\n\n");
        printf("\t¿Cómo desea ingresar? \n \n\t1) Empleado \n\t2) Cliente \n\t3) Salir");
        printf("\n\nOpcion: ");
        scanf("%d",&respuesta);
        switch(respuesta){
            case 1:
                system("clear");
                empleado(l);
            break;
            case 2:
                system("clear");
                cliente(l,c);
                if (verificar_compra == 1){
                    upload(l);
                    eliminar_estante(l);
                    return 0;
                }
            break;
            case 3:
            break;
            default:
                printf("\nOpcion invalida\n");
        }    
    } while(respuesta != 3);
    printf("\n\n\n\t\tMuchas gracias, vuelva pronto\n\n\n\n\t\t\t BIBLIOTEDA \n\n\n\n\n");
    upload(l);    
    eliminar_estante(l);
    eliminar_estante(c);    
    return 0;
} 
//DANIELA NICOLAS 06-06-2020
//Daniel 07-06-2020
//Diego 13-06-2020
