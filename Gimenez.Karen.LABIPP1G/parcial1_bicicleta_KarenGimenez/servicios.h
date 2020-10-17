
typedef struct{
int id;//comienza enn 2000
char descripcion[26];
float precio;
}Servicio;


/** \brief muestra un servicio
 *
 * \param serv Servicio un Servicio
 * \return void
 *
 */
void servicio_mostrar(Servicio serv);

/** \brief muestra una lista de servicios con sus nombres y precios
 *
 * \param lista[] Servicio
 * \param tam int
 * \return int retorna 0, muestra una lista por pantalla
 *
 */
int servicio_listar(Servicio lista[], int tam);


/** \brief carga la descripcion a traves del id de la estructura
 *
 * \param descripcion[] char donde se carga el nombre
 * \param idS int el id que se requiere el nombre
  *\param list[] Servicio, array
 * \param tamS int tamanio lista
 * \return int retorna -1 si hubo error o 0 si es correcto
 *
 */
int servicio_cargarDescripcion(char descripcion[], int idS, Servicio lista[], int tamS);

/** \brief busca por id el servicio y devuelve el indice
 *
 * \param id int id a buscar
 * \param lista[] Servicio array
 * \param tamS int tamanio array servicio
 * \return int, retorna -1 si no pudo encontrarlo o el indice si lo encontro
 *
 */
int servicio_buscarPorId(int id, Servicio lista[], int tamS);
