#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
int id;//comienza enn 20000
int idBicicleta;
int idServicio;
eFecha fecha;
float precio;
int isEmpty;
}Trabajo;



#endif // TRABAJO_H_INCLUDED
