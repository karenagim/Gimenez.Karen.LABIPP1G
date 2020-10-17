#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*----LIBRERIA DE DATOS HARDCODEADOS ---*/
#include "DATA.h"
/*----Libreria de validaciones y menues--*/
#include "utn.h"
#include "menu.h"
/*----libreria de estructuras y funciones---*/
#include "color.h"
#include "servicios.h"
#include "tipo.h"
#include "bicicleta.h"



void hardcodearBicicletas(eBicicleta lista[],int cant)
{
    for(int i=0;i<cant; i++)
    {
        lista[i].id= idsBicicletas[i];
        strcpy(lista[i].marca,marcas[i]);
        lista[i].idTipo= idtipos[i];
        lista[i].idColor= idcolores[i];
        lista[i].rodado= rodados[i];
        lista[i].isEmpty=0;

    }
}
void mostrar_marcas()
{
    printf("---MARCAS BICICLETAS---\n");
    for(int i=0;i<6;i++)
    {
        printf("----------\n");
        printf("|%-5s\n",marcas[i]);
    }
}
void bicicletas_init(eBicicleta lista[], int tam_list)
{
    if(lista != NULL && tam_list >0)
    {
        for(int i=0; i<tam_list; i++)
        {
            lista[i].isEmpty=1;
        }
    }
}

void bicicleta_mostrarUno(eBicicleta bicicleta, Tipo tipos[],int tamTipos,Color colores[],int tamCol)
{
    char descripcionTipo[21];
    char descripcionColor[21];

    tipo_PrintName(descripcionTipo,bicicleta.idTipo,tipos,tamTipos);
    color_PrintName(descripcionColor,bicicleta.idColor,colores,tamCol);
    printf("\n|%1d  | %-5s | %4d  |  %-8s| %4d  | %-5s | %.1f |\n",
           bicicleta.id,
           bicicleta.marca,
           bicicleta.idTipo,
           descripcionTipo,
           bicicleta.idColor,
           descripcionColor,
           bicicleta.rodado);

}

void bicicleta_mostrarUnoCampos(eBicicleta bicicleta, Tipo tipos[],int tamTipos,Color colores[],int tamCol)
{
    printf("-----------------------------------------------------------\n");
    printf(" ID  MARCA   ID_TIPO   TIPO    ID_COLOR  COLOR RODADO\n");
    printf("-----------------------------------------------------------\n");
    bicicleta_mostrarUno(bicicleta,tipos,tamTipos,colores,tamCol);
}

void bicicleta_mostrarLista(eBicicleta lista[],int tam, Tipo tipos[],int tamTipos,Color colores[],int tamCol)
{
    printf("-----------------------------------------------------------\n");
    printf(" ID  MARCA   ID_TIPO   TIPO    ID_COLOR  COLOR RODADO\n");
    printf("-----------------------------------------------------------\n");

    if(lista !=NULL && tam>0){
        for (int i=0; i<tam; i++)
        {
            if(!(lista[i].isEmpty))
            {
                bicicleta_mostrarUno(lista[i],tipos, tamTipos,colores,tamCol);
            }
        }
    }
    else
    {
        printf("\n No hay bicicletas que listar\n");
    }
}

int buscar_EspacioLibre(eBicicleta lista[], int tam_list)
{
    int espacioDisponible= -1;
    if(lista !=NULL && tam_list>0)
    {
        for(int i=0; i<tam_list; i++)
        {
            if(lista[i].isEmpty==1)
            {
                espacioDisponible=i;
            }
        }
    }
    return espacioDisponible;
}

int bicicletas_add( eBicicleta lista[],int tam, int idAux, char marcaAux[],int idTipoAux,int idColorAux,int rodadoAux)
{
    int isOk= -1;
    int lugarDisponible = buscar_EspacioLibre(lista,tam);

    if(lista != NULL && tam >0 && lugarDisponible!= -1)
    {
        lista[lugarDisponible].id = idAux;
        strcpy( lista[lugarDisponible].marca,marcaAux);
        lista[lugarDisponible].idTipo = idTipoAux;
        lista[lugarDisponible].idColor = idColorAux;
        lista[lugarDisponible].rodado = rodadoAux;
        lista[lugarDisponible].isEmpty = 0;
        isOk=0;
    }
    return isOk;
}



int bicicletas_alta(eBicicleta lista[],int idAutoincremental,int tam, Tipo tipos[], int tamTipos,Color colores[],int tamCol)
{
    eBicicleta auxbicicleta;
    int locacionDisponible= buscar_EspacioLibre(lista,tam);
    int altaExitosa=-1;
    if(locacionDisponible!= -1 && bicicletas_add(lista,tam,idAutoincremental,auxbicicleta.marca,auxbicicleta.idTipo,auxbicicleta.idColor,auxbicicleta.rodado)==0)
    {
        system("cls");
        menuAlta();
        auxbicicleta.id = idAutoincremental;

        mostrar_marcas();
        getValidStringLimitada("Ingrese marca de la bicicleta \n\n", "ERROR,EL marca SOLO DEBE CONTENER LETRAS\n",auxbicicleta.marca,21);
        system("cls");
        tipo_listar(tipos,tamTipos);
        auxbicicleta.idTipo= getValidInt("Ingrese TIPO de la bicicleta\n","ERROR, INGRESE UN TIPO VALIDO ENTRE 1000-1003",1000,1003);
        system("cls");
        color_listar(colores,tamCol);
        auxbicicleta.idColor= getValidInt("Ingrese COLOR de la bicicleta\n","ERROR, INGRESE UN COLOR VALIDO ENTRE 1000-1004",5000,5004);
        system("cls");
        printf("\nLos rodados pueden ser: 20, 26, 27.5 y 29\n\n");
        auxbicicleta.rodado=getValidFloat("ingrese RODADO de la bicicleta\n","ERROR, REINGRESE UN RODADO VALIDA\n",20);
        auxbicicleta.isEmpty=0;

        lista[locacionDisponible]=auxbicicleta;
        bicicleta_mostrarUnoCampos( lista[locacionDisponible],tipos,tamTipos,colores,tamCol);
        printf("\n\n LA bicicleta FUE DE DADA DE ALTA EXITOSAMENTE \n");

        altaExitosa=0;
    }
    else
    {
        printf("SISTEMA COMPLETO !!!\n\n");
    }
    return altaExitosa;
}

/*  MODIFICAR bicicleta-------------------------------*/

int buscar_bicicletaPorId(eBicicleta lista[], int tambicicleta,int idM)
{
    int locacionBici=-1;
    if(lista !=NULL && tambicicleta>0 && idM>0 && idM<=1000)
    {
        for(int i=0; i<tambicicleta ; i++)
        {
            if(lista[i].id == idM)
            {
                locacionBici=i;
                break;
            }
        }
    }
    return locacionBici;
}


void bicicletas_modify(eBicicleta lista [],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol)
{
    eBicicleta Auxbicicleta;

    int idbicicletaEditable= getValidInt("INGRESE ID bicicleta A MODIFICAR\n","ERROR, INGRESE UN ID VALIDO",100,999);
    int locacionbicicleta=  buscar_bicicletaPorId(lista,tam,idbicicletaEditable);
    char confirma='n';
    char respuesta='s';

    if(locacionbicicleta ==-1)
    {
        printf("NO EXISTE LA bicicleta CON ID %d\n", idbicicletaEditable);
    }
    else
    {
        do
        {
            system("cls");

            switch(menuModify())
            {

            case 1:
                system("cls");
                printf("**------MODIFICAR TIPO-------**\n\n");
                confirma=getChar("Desea cambiar el tipo de la bicicleta? s/n \n\n");
                if(tolower(confirma) =='s')
                {

                    Auxbicicleta.idTipo=getValidInt("Ingrese nuevo TIPO de bicicleta: ","ERROR, INGRESE UN TIPO VALIDO\n",1000,1006);
                    lista[locacionbicicleta].idTipo=Auxbicicleta.idTipo;
                    printf("Se ha cambiado el tipo con exito\n\n");
                    break;
                }
            case 2:
                system("cls");
                printf("MODIFICAR RODADO\n\n");
                confirma=getChar("Desea cambiar el rodado de la bicicleta? s/n \n\n");
                if(confirma =='s')
                {
                    Auxbicicleta.rodado=getValidFloat("Ingrese nuevo rodado: ","ERROR, INGRESE UN RODADO VALIDO\n",20);
                    lista[locacionbicicleta].rodado=Auxbicicleta.rodado;
                    printf("Se ha cambiado el rodado con exito\n\n");
                    break;
                }
            case 3:

                bicicleta_mostrarUnoCampos(lista[locacionbicicleta],tipos,tamTipo,colores,tamCol);
                break;

            case 4:
                respuesta = 'n';
                break;
            default:

                printf("\n\n Ingrese una opcion valida\n\n");
                break;
            }

            system("\n\n pause");
            system("cls");

        }
        while(respuesta=='s');
    }

}

/*--------BAJA bicicleta--------------*/


int bicicletas_baja(eBicicleta lista [],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol)
{
    system("cls");
    menuBaja();
    bicicleta_mostrarLista(lista,tam,tipos,tamTipo,colores,tamCol);
    int idbicicletaARemover= getValidInt("\n\nINGRESE ID bicicleta A REMOVER\n","ERROR, INGRESE UN ID VALIDO",100,999);
    int locacionbicicleta= buscar_bicicletaPorId(lista,tam,idbicicletaARemover);
    char confirma;
    int bajaExitosa=-1;
    if(idbicicletaARemover==-1)
    {
        printf("ERROR, la bicicleta con ID %d no existe!!!\n\n",idbicicletaARemover);
    }
    else
    {
        system("cls");
        menuBaja();

        bicicleta_mostrarUnoCampos(lista[locacionbicicleta],tipos,tamTipo,colores,tamCol);
       // mostrarEmpleadoConCampos(lista[locacionbicicleta],sectores,tamSec);
        confirma=getChar("Desea dar de baja a la bicicleta? s/n\n\n");

        if(confirma =='s')
        {
            lista[locacionbicicleta].isEmpty=1;
            printf(" El EMPLEADO/A FUE DE DADO DE BAJA EXITOSAMENTE \n");
            bajaExitosa=0;
        }
        else
        {
            printf(" LA OPERACION FUE CANCELADA POR EL USUARIO\n");
        }
    }

    return bajaExitosa;
}

/*-----------LISTAR-------------*/


int bicicleta_ordenar(eBicicleta lista[],int tambicicleta,int criterio)
{
    int error= -1;
    eBicicleta auxbicicleta;

    if( lista != NULL && tambicicleta >0 && criterio>=0 &&criterio <=1)
    {
        for(int i=0; i<tambicicleta-1; i++)
        {                                   //TIPO Y marca
            for(int j=i+1; j<tambicicleta; j++)
            {

                //ordenados por orden alfabetico                 //criterio==1
                if( (strcmp(lista[i].marca,lista[j].marca) >0 && criterio) ||
                    (strcmp(lista[i].marca,lista[j].marca)< 0 && !criterio) )
                {
                    auxbicicleta =lista[i];
                    lista[i]= lista[j];
                    lista[j]= auxbicicleta;
                }
                else if ((strcmp(lista[i].marca,lista[j].marca)==0) && lista[i].idTipo > lista[j].idTipo )
                {
                    auxbicicleta =lista[i];
                    lista[i]= lista[j];
                    lista[j]= auxbicicleta;
                }
                else if(  (strcmp(lista[i].marca,lista[j].marca)==0) && lista[i].idTipo < lista[j].idTipo )
                {
                    auxbicicleta =lista[i];
                    lista[i]= lista[j];
                    lista[j]= auxbicicleta;
                }
            }
            error=0;
        }
    }

    return error;
}

int  listar_bicicletasMarca(eBicicleta lista [],int tambicicleta,Tipo tipos[],int tamTipo,Color colores[],int tamCol)
{

    int error= -1;
    int criterio=getValidInt("Ingrese criterio de ordenamiento 1- marca, 2-TIPO\n","ERROR,INGRESE UNA OPCION VALIDA\n",1,2);
    if(lista !=NULL && tambicicleta>0)
    {
        system("cls");
        printf("\n-----LISTA DE bicicleta-----\n\n");
        if(bicicleta_ordenar(lista,tambicicleta,criterio)==0)
        {
            bicicleta_ordenar(lista,tambicicleta,criterio);
            bicicleta_mostrarLista(lista,tambicicleta,tipos,tamTipo,colores,tamCol);
        }
    }
    else{
        printf("No hay bicicleta que listar\n\n");
    }
    return error;
}
