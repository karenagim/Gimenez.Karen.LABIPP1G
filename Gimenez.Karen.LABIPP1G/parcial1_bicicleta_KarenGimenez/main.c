#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*----Libreria de validaciones y menues--*/
#include "utn.h"
#include "menu.h"
/*----libreria de estructuras y funciones---*/
#include "color.h"
#include "servicios.h"
#include "tipo.h"
#include "bicicleta.h"


#define TAM_BICI 6

#define TAM_COL 5
#define TAM_TIPO 5
#define TAM_SERV 4

#define CANT_DATOS 4




int main()
{
    int proximoId=99;
    char respuesta;
    int flagAlta =0;

    Color colores[TAM_COL]=
    {
        {5000,"NEGRO"},{5001,"BLANCO"},{5002,"GRIS"},{5003,"ROJO"},{5004,"AZUL"}
    };

    Tipo tipos[TAM_TIPO]=
    {
        {1000,"RUTERA"},
        {1001,"CARRERA"},
        {1002,"MOUNTAIN"},
        {1003,"BMX"}
    };
     Servicio servicios[TAM_SERV]=
    {
        {250,"LIMPIEZA",250},
        {300,"PARCHE",300},
        {400,"CENTRADO",400},
        {350,"CADENA",350}
    };
    eBicicleta bicicletas[TAM_BICI];
    bicicletas_init(bicicletas,TAM_BICI);


    proximoId+= CANT_DATOS;
    hardcodearBicicletas(bicicletas,CANT_DATOS);

    respuesta='s';




    do
    {
        switch(opcionMenuInicio())
        {
        case 1:
             // bicicletas_alta(bicicletas,proximoId,TAM_BICI,tipos,TAM_TIPO,colores,TAM_COL);
           if( bicicletas_alta(bicicletas,proximoId,TAM_BICI,tipos,TAM_TIPO,colores,TAM_COL)==0)
            {
                proximoId++;
            }
            if(proximoId >0)
            {
                flagAlta=1;
            }
            break;

        case 2:
            if(flagAlta != 1 && proximoId==99)
            {
                printf("\n\nError, debe existir al menos UNA mascota!!!\n\n");
            }
            else
            {
                bicicletas_modify(bicicletas,TAM_BICI,tipos,TAM_TIPO,colores,TAM_COL);

                 break;
            }
            break;

        case 3:
            if(flagAlta != 1&& proximoId==99)
            {
                printf("\n\nError, debe existir al menos 1 usuario!!!\n\n");
            }
            else
            {
                bicicletas_baja(bicicletas,TAM_BICI,tipos,TAM_TIPO,colores,TAM_COL);

            }
            break;

        case 4:
            if(flagAlta != 1 && proximoId==99)
            {
                printf("\n\n NO HAY bicicletas QUE MOSTRAR!!!\n\n");
            }
            else
            {
                listar_bicicletasMarca(bicicletas,TAM_BICI,tipos,TAM_TIPO,colores,TAM_COL);
            }
            break;
           case 5:
           tipo_listar(tipos,TAM_TIPO);
            break;

            case 6:
            color_listar(colores,TAM_COL);
            break;

             case 7:
            servicio_listar(servicios,TAM_SERV);
            break;

        case 10:

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


    return 0;
}


