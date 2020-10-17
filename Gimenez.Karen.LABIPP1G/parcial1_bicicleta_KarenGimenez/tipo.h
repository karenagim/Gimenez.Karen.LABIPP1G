#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
#include <string.h>
typedef struct{

int id; //Comienza en 1000
char descripcion[21];
}Tipo;

/** \brief carga el nombvre a traves de su id
 *
 * \param descripcion[] char donde carga el nombre
 * \param idTipo int el id a buscar
 * \param listaTipos[] Tipo array tipos
 * \param tamTipos int tam del array
 * \return int
 *
 */
int tipo_PrintName(char descripcion[], int idTipo, Tipo listaTipos[], int tamTipos);


/** \brief muestra el i tipo y su descripcion
 *
 * \param unTipo Tipo
 * \return void
 *
 */
void tipo_mostrar(Tipo unTipo);


/** \brief muestra el array por pntalla
 *
 * \param lista[] Tipo
 * \param tam int
 * \return int 0 todo ok
 *
 */
int tipo_listar(Tipo lista[], int tam);

/** \brief carga el nombvre a traves de su id
 *
 * \param descripcion[] char donde carga el nombre
 * \param idTipo int el id a buscar
 * \param listaTipos[] Tipo array tipos
 * \param tamTipos int tam del array
 * \return 0
 *
 */
int tipo_PrintName(char descripcion[], int idTipo, Tipo listaTipos[], int tamTipos);



/** \brief busca el id en el array
 *
 * \param id int id a buscar
 * \param tipos[] Tipo array tipos
 * \param tam int tamanio array
 * \return int retorna -1 si no lo encontro o el indice si lo encontro
 *
 */
int tipo_buscarPorId(int id, Tipo tipos[], int tam);






#endif // TIPO_H_INCLUDED
