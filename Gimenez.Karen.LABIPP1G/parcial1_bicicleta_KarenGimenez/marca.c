#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"

void marca_mostrar(Marca marca)
{
    printf("   [%d]               %6s   \n", marca.id, marca.descripcion);
}

int marca_listar(Marca lista[], int tam)
{
    printf(" -----------------------\n");
    printf(" ---   Lista de Marcas   ----\n");
    printf(" -   Id          Descripcion   -\n");

    if(lista != NULL)
    {
        for (int i = 0; i<tam; i++)
        {
            marca_mostrar(lista[i]);
        }
    }

    return 0;
}

int marca_cargarDescripcion(char descripcion[], int idMarca, Marca list[], int tamMarca)
{
    int error = -1;
    for (int i=0; i<tamMarca; i++)
    {
        if(list[i].id == idMarca)
        {
            strcpy(descripcion, list[i].descripcion);
            error=0;
        }
    }
    return error;
}

int marca_buscarPorId(int id, Marca marca[], int tamMarca)
{
    int indice = -1;

    for(int i = 0; i < tamMarca; i++)
    {
        if(marca[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
