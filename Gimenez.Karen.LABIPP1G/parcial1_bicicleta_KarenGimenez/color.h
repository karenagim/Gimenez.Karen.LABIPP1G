
typedef struct
{
    int id; //Comienza en 1000
    char nombreColor[21];
}Color;

/** \brief muestra un mensaje con el id color y su descripcion
 *
 * \param col Color corresponde a un color
 * \return void
 *
 */
void color_mostrar(Color col);

/** \brief muestra la lista de colores
 *
 * \param array de colores
 * \param el tamaño del array
 * \return retorna la lista de colores
 *
 */
int color_listar(Color lista[], int tam);


/** \brief busca la descripcion del color por su id
 *
 * \param id int
 * \param lista[] Color
 * \param tamc int
 * \return int retorna el indice de ese color o -1 si hy error
 *
 */
int color_buscarPorId(int id, Color lista[], int tamc);


/** \brief carga el nombre a traves del id pasado por parametro
 *
 * \param descripcion[] char donde se carga el nombre
 * \param idColor int , el id a cargar el nombre
 * \param listaColor[] Color
 * \param tamCol int
 * \return int
 *
 */
int color_PrintName(char descripcion[], int idColor, Color listaColor[], int tamCol);

