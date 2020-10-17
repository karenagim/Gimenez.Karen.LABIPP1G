#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"


void tipo_mostrar(Tipo unTipo)
{
    printf("   [%d]               %6s   \n", unTipo.id, unTipo.descripcion);
}

int tipo_listar(Tipo lista[], int tam)
{
    printf(" -----------------------\n");
    printf(" ---   Tipos de Bicicletas  ----\n");
    printf(" -   Id          Descripcion   -\n");

    if(lista != NULL)
    {
        for (int i = 0; i<tam; i++)
        {
            tipo_mostrar(lista[i]);
        }
    }

    return 0;
}

int tipo_PrintName(char descripcion[], int idTipo, Tipo listaTipos[], int tamTipos)
{
    int todoOk = -1;
    for(int i=0; i<tamTipos; i++)
    {
        if(listaTipos[i].id == idTipo)
        {
            strcpy(descripcion, listaTipos[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}




int tipo_buscarPorId(int id, Tipo tipos[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(tipos[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


