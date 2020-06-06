#include<stdio.h>

//MENU EMPLEADO
void mempleado(){
    char re, rme;
    puts("\n\n\n\t\t\t BIENVENIDO A EMPLEADO \n\n\n");
    do{
    puts("\t ¿Qué desea hacer? \n \n\ta) Agregar un libro \n\tb) Dar de baja \n c) Agregar existencias \n\t ");
        scanf("%s",&re);
        re=tolower(re);
            switch(re){
                                case 'a':
                                    system("cls");
                                    //ARGUMENTOS 
                                    Agregar_libro();
                                break;

                                case 'b':
                                    system("cls");
                                    //ARGUMENTOS
                                    Baja_libro();
                                break;

                                case 'c':
                                    system ("cls");
                                    //ARGUMENTOS
                                    Agregar_existencias();
                                break;

                                default:
                                    printf("Opcion invalida\n");
                            }

        puts("Desea volver a leer el Menu (s/n)?\n");
        scanf("%s",&rme);
        rme=tolower(rme);
        system("cls");

    } while(rme=='s');

printf("\n\n\n\n\n\t\t\tMuchas gracias, vuelva pronto\n\n\n\n\t\t\t\t\t NOMBRE DE LA EMPRESA \n\n\n\n\n");
getchar();

}

//MENU CLIENTE 
void mcliente(){
    char rc,rmc;
    puts("\n\n\n\t\t\t BIENVENIDO A CLIENTE\n\n\n");
        do{
    puts("\t ¿Qué desea hacer? \n \n\ta) Ver libros en venta \n\tb) Buscar libros\n c) Ver carrito \n\t ");
        scanf("%s",&rc);
        rc=tolower(rc);
            switch(rc){
                                case 'a':
                                    system("cls");
                                    //ARGUMENTOS 
                                    //print list 
                                break;

                                case 'b':
                                    system("cls");
                                    //argumentos
                                    Buscar_libros();
                                break;

                                case 'c':
                                    system ("cls");
                                    //print carrito 
                                break;

                                default:
                                    printf("Opcion invalida\n");
                            }

        puts("Desea volver a leer el Menu (s/n)?\n");
        scanf("%s",&rmc);
        rmc=tolower(rmc);
        system("cls");

    } while(rmc=='s');

printf("\n\n\n\n\n\t\t\tMuchas gracias, vuelva pronto\n\n\n\n\t\t\t\t\t NOMBRE DE LA EMPRESA \n\n\n\n\n");
getchar();


}


//MENU PRINCIPAL
int main(){
    char respuesta, resp;
    puts("\n\n\n\n\tLa empresa --------- agradece su preferencia.\n\tEsperamos que nuestros servicios llenen sus expectativas.\n");
    getchar();
    system("cls");
    puts("\n\n\n\n\tEn esta plataforma usted podra comprar los libros que guste \n\t\t Podra ver nuestro catalogo\n\t\t etc");
    getchar();
    system("cls");

     do{
        puts("\n\n\n\t\t\t BIENVENIDO\n\n\n");
        puts("\t¿Cómo desea ingresar? \n \n\ta) Empleado \n\tb) Cliente \n ");
        scanf("%s",&respuesta);
        respuesta=tolower(respuesta);

            switch(respuesta){
                                case 'a':
                                    system("cls");
                                    mempleado();
                                break;

                                case 'b':
                                    system("cls");
                                    mcliente();
                                break;

                                default:
                                    printf("Opcion invalida\n");
                            }

        puts("Desea volver a leer el Menu (s/n)?\n");
        scanf("%s",&resp);
        resp=tolower(resp);
        system("cls");

    } while(resp=='s');

printf("\n\n\n\n\n\t\t\tMuchas gracias, vuelva pronto\n\n\n\n\t\t\t\t\t NOMBRE DE LA EMPRESA \n\n\n\n\n");
getchar();

} //main
