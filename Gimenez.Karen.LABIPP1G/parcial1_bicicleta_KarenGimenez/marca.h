#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[30];
}Marca;

void marca_mostrar(Marca marca);

int marca_listar(Marca lista[], int tam);

int marca_cargarDescripcion(char descripcion[], int idMarca, Marca lista[], int tamMarca);


int marca_buscarPorId(int id, Marca marca[], int tamMarca);


#endif // MARCA_H_INCLUDED
