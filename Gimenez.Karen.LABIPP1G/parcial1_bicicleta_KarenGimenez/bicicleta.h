#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct{
int id;
char marca[21];
int idTipo;
int idColor;
float rodado;

int isEmpty;
}eBicicleta;

/** \brief carga datos para testing
 *
 * \param lista[] eBicicleta
 * \param cant int cant a cargar
 * \return void
 *
 */
void hardcodearBicicletas(eBicicleta lista[],int cant);

/** \brief inicializa el array en 0
 *
 * \param lista[] eBicicleta
 * \param tam_list int tamanio array
 * \return void
 *
 */
void bicicletas_init(eBicicleta lista[], int tam_list);

/** \brief busca el primer espacio libre en el array
 *
 * \param lista[] eBicicleta array bicis
 * \param tam_list int tamanio array
 * \return int retorna -1 si hay error o el indice si es correcto
 *
 */
int buscar_EspacioLibre(eBicicleta lista[], int tam_list);

/*----------MOSTRAR-------------*/
/** \brief muestra los datos de una bici en fila
 *
 * \param bici eBicicleta una bici
 * \param tipos[] Tipo lista de topos
 * \param tamTipos int tamanio array tipos
 * \param colores[] Color , array colores
 * \param tamCol int, tamanio array color
 * \return void
 *
 */
void bicicleta_mostrarUno(eBicicleta bici, Tipo tipos[],int tamTipos,Color colores[],int tamCol);

/** \brief muestra los datos de una bici en fila con un cartel de sus campos
 *
 * \param bici eBicicleta
 * \param tipos[] Tipo
 * \param tamTipos int
 * \param colores[] Color
 * \param tamCol int
 * \return void
 *
 */
void bicicleta_mostrarUnoCampos(eBicicleta bici, Tipo tipos[],int tamTipos,Color colores[],int tamCol);

/** \brief muestra la lista de bicicletas con sus respectivos campos
 *
 * \param
 * \param
 * \return
 *
 */
void bicicleta_mostrarLista(eBicicleta lista[],int tam, Tipo tipos[],int tamTipos,Color colores[],int tamCol);


/** \brief reliza el alta de una bici
 *
 * \param lista[] eBicicleta
 * \param idAutoincremental int
 * \param tam int
 * \param tipos[] Tipo
 * \param tamTipos int
 * \param colores[] Color
 * \param tamCol int
 * \return int retorna -1 si hubo error o 0 si es correcto
 *
 */
int bicicletas_alta(eBicicleta lista[],int idAutoincremental,int tam, Tipo tipos[], int tamTipos,Color colores[],int tamCol);

/** \brief realiza la baja logica
 *
 * \param [] eBicicleta lista
 * \param tam int
 * \param tipos[] Tipo
 * \param tamTipo int
 * \param colores[] Color
 * \param tamCol int
 * \return int retorna -1 si no se pudo realizar o 0 si fue correcto
 *
 */
int bicicletas_baja(eBicicleta lista [],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol);

/** \brief modiica uno de los campos tipo o marca
 *
 * \param [] eBicicleta lista
 * \param tam int
 * \param tipos[] Tipo
 * \param tamTipo int
 * \param colores[] Color
 * \param tamCol int
 * \return void
 *
 */
void bicicletas_modify(eBicicleta lista [],int tam,Tipo tipos[],int tamTipo,Color colores[],int tamCol);

/*--------listar-----*/
int bicicletas_ordenar(eBicicleta lista[],int tamMascota,int criterio);
int listar_bicicletasMarca(eBicicleta lista [],int tamMascota,Tipo tipos[],int tamTipo,Color colores[],int tamCol);


#endif // BICICLETA_H_INCLUDED
