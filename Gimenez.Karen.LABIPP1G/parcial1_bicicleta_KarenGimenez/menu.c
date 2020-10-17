#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "utn.h"


int opcionMenuInicio()
{
    int opcion;
    printf("-------------------------\n\n");
    printf("    MENU DE OPCIONES    \n");
    printf("-------------------------\n\n");
    printf("[1]- ALTA BICICLETA\n");
    printf("[2]- MODIFICAR BICICLETA\n");
    printf("[3]- BAJA BICICLETA\n");
    printf("[4]- LISTAR BICICLETAS\n");
    printf("[5]- LISTAR TIPOS\n");
    printf("[6]- LISTAR COLORES\n");
    printf("[7]- LISTAR SERVICIOS\n");
    printf("[8]- ALTA TRABAJO\n");
    printf("[9]- LISTAR TRABAJOS\n");
    printf("[10]- SALIR\n\n");

    opcion=getValidInt("\n\nElija una opcion: ","ERROR,ingrese una opcion valida\n", 1, 10);

    return opcion;
}
void menuAlta()
{
    printf("------------------------------------\n");
    printf("--------ALTA DE BICICLETAS---------- \n");
    printf("------------------------------------\n\n");
}

 int menuModify()
{
    int opcion;
    system("cls");
    printf("---------------------------------------\n");
    printf("---------MODIFICAR BICICLETA----------\n");
    printf("---------------------------------------\n\n");

    opcion=getValidInt("\n\n1--MODIFICAR TIPO\n2 - MODIFICAR RODADO \n3 - MOSTRAR CAMBIOS \n\n4 - SALIR \n\nElija una opcion: ","ERROR,INGRESE UNA OPCION VALIDA\n", 1, 4);

    return opcion;
}


void menuBaja()
{
    printf("--------------------------------------------------------------\n");
    printf("---------------------BAJA DE BICICLETAS--------------------------\n");
    printf("---------------------------------------------------------------\n");
}
