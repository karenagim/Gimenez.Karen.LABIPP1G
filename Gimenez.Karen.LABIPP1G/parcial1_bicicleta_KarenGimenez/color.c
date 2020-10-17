#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include <string.h>

void color_mostrar(Color col)
{
    printf("   [%d]               %6s   \n", col.id, col.nombreColor);
}

int color_listar(Color lista[], int tam)
{
    printf(" -----------------------\n");
    printf(" ---   Lista de Colores   ----\n");
    printf(" -   Id          Descripcion   -\n");

    if(lista != NULL)
    {
        for (int i = 0; i<tam; i++)
        {
            color_mostrar(lista[i]);
        }
    }

    return 0;
}

int color_PrintName(char descripcion[], int idColor, Color listaColor[], int tamCol)
{
    int todoOk = -1;
    for(int i=0; i<tamCol; i++)
    {
        if(listaColor[i].id == idColor)
        {
            strcpy(descripcion, listaColor[i].nombreColor);
            todoOk = 1;
        }
    }
    return todoOk;
}


int color_buscarPorId(int id, Color lista[], int tamc)
{
    int indice = -1;

    for(int i = 0; i < tamc; i++)
    {
        if(lista[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
