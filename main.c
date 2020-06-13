#include<stdio.h>

//MENU EMPLEADO
void empleado(){
    char re, rme, elim,volver;
    puts("\n\n\n\t\t\t BIENVENIDO A EMPLEADO \n\n\n");
    do{
    puts("\t ¿Qué desea hacer? \n \n\ta) Agregar un libro \n\tb) Dar de baja \n c) Agregar existencias \n\t ");
        scanf("%s",&re);
        re=tolower(re);
            switch(re){
                case 'a':
                    system("clear");
                    //ARGUMENTOS 
                    agregarLibro();
                    break;
                case 'b':
                    system("clear");
                        do{
                            buscarLibro(titulo, autor, ISBN);
                            puts("\n¿Cuál desea elegir?\n");
                            //IMPRIMIR LISTA
                            //elegir el libro 
                            puts("\n ¿Desea eliminar? (s/n)\n");
                            scanf("%s", &elim);
                            elim = tolower(elim);
                                if (elim =='s'){
                                    eliminarLibro();
                                    getchar();
                                    system("clear");
                                    puts("\n\tLibro eliminado correctamente\n\t");
                                    getchar();
                                    system("clear");
                                    puts("¿Desea seguir eliminando?(s/n)");
                                    scanf("%s", &volver);
                                    volver= tolower(volver);
                                        }
                                    } while(volver=='s');
                                    puts("\n usted salió correctamente\n");
                    break;
                case 'c':
                    int num;
                    system ("clear");
                    buscarLibro(titulo, autor, ISBN);
                    puts("\n¿Cuál desea elegir?\n");
                    //IMPRIMIR LISTA
                    //elegir el libro 
                    puts("¿Cuantos libros desea agregar?");
                    scanf("%i", &num);
                    agregarExistencias(num);
                    puts("Se agregaron %i existencia(s) correctamente", num);
                    break;
                default:
                    printf("Opcion invalida\n");
            }
        puts("Desea volver a leer el Menu (s/n)?\n");
        scanf("%s",&rme);
        rme = tolower(rme);
        system("clear");

    } while(rme=='s');

    printf("\n\n\n\n\n\t\t\tMuchas gracias, vuelva pronto\n\n\n\n\t\t\t\t\t BIBLIOTEDA \n\n\n\n\n");
    getchar();

}

//MENU CLIENTE 
void cliente(){
    char rc,rmc;
    puts("\n\n\n\t\t\t BIENVENIDO A CLIENTE\n\n\n");
        do{
    puts("\t ¿Qué desea hacer? \n \n\ta) Ver libros en venta \n\tb) Buscar libros\n c) Ver carrito \n\t ");
        scanf("%s",&rc);
        rc=tolower(rc);
            switch(rc){
                case 'a':
                    system("clear");
                    printLibros();
                    break;
                case 'b':
                    char libro, opc, volver;
                    system("clear");
                    do{
                        buscarLibro(titulo,autor,ISBN);
                        puts("¿Cuál desea elegir?");
                        printLibros();
                        //ELEGIR EL LIBRO
                        puts("¿Desea agregarlo al carrito?(s/n)");
                        scanf("%s", opc);
                        opc = tolower(opc);
                            if (opc == 's'){
                                agregar_al_carrito(libro);
                                getchar();
                                system("clear");
                                puts("Agregado al carrito correctamente");
                                puts("¿Desea seguir agregando?(s/n)");
                                scanf("%s", &volver);
                                volver = tolower(volver);
                            }
                    }  while(volver == 's');
                    puts("\n usted salió correctamente\n");
                    break;
                    
                case 'c':
                    char elim,respuesta,confirmar;
                    system ("clear");
                    printCarrito();
                    //Solo se va a imprimir el titulo
                    puts("\n Desea eliminar algún elemento del carrito(s/n) \n ");
                    scanf("%s",&elim);
                        if(elim == 's'){
                            eliminar_carrito();
                            print("Desea comprar o seguir navegando");
                            scanf("%s", &respuesta);
                                if(respuesta =='comprar'){
                                    imprimir_carrito();
                                    puts("¿Confirmar compra?(s/n)");
                                    scanf("%s",&confirmar);
                                        if(confirmar=='s'){
                                            confirmar_compra();
                                            generar_recibo();
                                            puts("GRACIAS POR SU PREFERENCIA");
                                            }
                                        }else{
                                            printf("Usted decidio salir");
                                        }
                                    }
                                break;

                                default:
                                    printf("Opcion invalida\n");
                            }

        puts("Desea volver a leer el Menu (s/n)?\n");
        scanf("%s",&rmc);
        rmc=tolower(rmc);
        system("clear");

    } while(rmc=='s');

printf("\n\n\n\n\n\t\t\tMuchas gracias, vuelva pronto\n\n\n\n\t\t\t\t\t NOMBRE DE LA EMPRESA \n\n\n\n\n");
getchar();


}


int main(){
    char respuesta, resp;
    puts("\n\n\n\n\tLa empresa biblioteda agradece su preferencia.\n\tEsperamos que nuestros servicios llenen sus expectativas.\n");
    getchar();
    system("clear");
    puts("\n\n\n\n\tEn esta plataforma usted podra comprar los libros que guste \n\t\t Podra ver nuestro catalogo\n\t\t etc");
    getchar();
    system("clear");

     do{
        puts("\n\n\n\t\t\t BIENVENIDO\n\n\n");
        puts("\t¿Cómo desea ingresar? \n \n\ta) Empleado \n\tb) Cliente \n ");
        scanf("%s",&respuesta);
        respuesta=tolower(respuesta);

            switch(respuesta){
                                case 'a':
                                    system("clear");
                                    empleado();
                                break;

                                case 'b':
                                    system("clear");
                                    cliente();
                                break;

                                default:
                                    printf("Opcion invalida\n");
                            }

        puts("Desea volver a leer el Menu (s/n)?\n");
        scanf("%s",&resp);
        resp=tolower(resp);
        system("clear");

    } while(resp=='s');

printf("\n\n\n\n\n\t\t\tMuchas gracias, vuelva pronto\n\n\n\n\t\t\t\t\t BIBLIOTEDA \n\n\n\n\n");
getchar();

} //main

//DANIELA NICOLAS 06-06-2020
//Daniel 07-06-2020

