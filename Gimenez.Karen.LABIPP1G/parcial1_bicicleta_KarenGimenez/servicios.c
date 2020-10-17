#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"

void servicio_mostrar(Servicio serv)
{
    printf("   %d      %6s   %.2f \n", serv.id, serv.descripcion,serv.precio);
}

int servicio_listar(Servicio lista[], int tam)
{
    printf(" -----------------------\n");
    printf(" ---   Lista de Marcas   ----\n");
    printf(" -   Id        Descripcion    precio   -\n");

    if(lista != NULL)
    {
        for (int i = 0; i<tam; i++)
        {
            servicio_mostrar(lista[i]);
        }
    }

    return 0;
}

int servicio_cargarDescripcion(char descripcion[], int idS, Servicio list[], int tamS)
{
    int error = -1;
    for (int i=0; i<tamS; i++)
    {
        if(list[i].id == idS)
        {
            strcpy(descripcion, list[i].descripcion);
            error=0;
        }
    }
    return error;
}

int servicio_buscarPorId(int id, Servicio lista[], int tamS)
{
    int indice = -1;

    for(int i = 0; i < tamS; i++)
    {
        if(lista[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
