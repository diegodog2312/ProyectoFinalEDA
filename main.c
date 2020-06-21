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
    do{
        system("clear");
        printf("\n\n\n\t\t\t EMPLEADO \n\n\n");
        printf("\t ¿Qué desea hacer? \n \n\t1) Agregar un libro \n\t2) Dar de baja \n\t3) Agregar existencias \n\t4) Salir ");
        printf("\n\n\tOpcion: ");
        scanf("%d",&re);
        switch(re){
            case 1:
                system("clear");
                pedir_libro(e);
                getchar();
                break;
            case 2:
                do{
                    system("clear");
                    b = eliminar_libro(e);
                    printf("\n\t¿Desea seguir eliminando? (1 = si / 2 = no): ");
                    scanf("%d", &volver);
                }while(volver==1);
            break;
            case 3:
                system("clear");
                b = existencias(e);
                if(b==false) printf("\n\tERROR");
            break;
            case 4:
            break;
            default:
                system("clear");
                printf("\nOpcion invalida\n");
        }
    } while(re !=4);
}

//MENU CLIENTE
void cliente(estante *e, carrito c){
    int rc;
    bool b;
    do{
        getchar();
        system("clear");
        printf("\n\n\n\t\t\t CLIENTE \n\n\n");
        printf("\t ¿Qué desea hacer? \n\n\t1) Ver libros en venta \n\t2) Buscar libros\n\t3) Ver carrito \n\t4) Salir");
        printf("\n\n\tOpcion: ");
        scanf("%d",&rc);
        system("clear");
        switch(rc){
            case 1:
                system("clear");
                b = recorrer_estante(e);
            break;
            case 2:
                getchar();
                system("clear");
                b = buscar_carrito(c,e);                        
            break;
            case 3:
                system ("clear");
                ver_carrito(c, &verificar_compra);
                if(verificar_compra == 1) return;
            break;
            case 4:
            break;
            default:
                system ("clear");
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
    printf("\n\n\t\tLa empresa bibliotEDA agradece su preferencia.\n\t\tEsperamos que nuestros servicios llenen sus expectativas.\n");
    printf("\n\n\t\tEn esta plataforma usted podra comprar los libros que guste \n\t\tPodra ver nuestro catalogo y MAS");
    printf("\n\n\n\n\t\t\t Presione enter para continuar... ");
    getchar();
    do{
        system("clear");
        printf("\n\n\n\t\t\t BIENVENIDO\n\n\n");
        printf("\t¿Cómo desea ingresar? \n \n\t1) Empleado \n\t2) Cliente \n\t3) Salir");
        printf("\n\tOpcion: ");
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
    system("clear");
    printf("\n\n\n\n\t\t\t Muchas gracias, vuelva pronto\n\n\n\n\t\t\t BIBLIOTEDA \n\n\n\n\n");
    upload(l);
    eliminar_estante(l);
    eliminar_estante(c);
    return 0;
}
//DANIELA NICOLAS 06-06-2020
//Daniel 07-06-2020
//Diego 13-06-2020
//Daniela 20/06/2020
