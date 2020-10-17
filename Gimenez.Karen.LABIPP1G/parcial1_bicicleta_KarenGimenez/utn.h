#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#include "utn.h"

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);


/** \brief
 *
 * \param requestMessage Es el mensaje a ser mostrado
  * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit float indica el minimo valor +1 que se puede ingresar
 * \return float retorna el valor ingresado por el usuario
 *
 */
float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \param cantMaxCaracter indica la cantidad de caracteres maximo del array
 * \return 1 si el texto contiene solo letras
 */
int getStringLetrasLimitada(char mensaje[],char input[],int cantMaxCaracter);

/**
 * \brief Solicita una cadena de caracteres al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
  * \param errorMensaje Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \param cantMaxCaracter indica la cantidad de caracteres maximo del array
 * \return 1 si el texto contiene solo letras*/
void getValidStringLimitada(char requestMessage[],char errorMessage[], char input[],int maxCaracter);

void cleanStdin(void);

#endif // UTN_H_INCLUDED
