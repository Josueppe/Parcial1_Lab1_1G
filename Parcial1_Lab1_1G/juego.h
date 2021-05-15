#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include "categoria.h"
#include "getters.h"
#define OCUPADO 0
#define VACIO 1
typedef struct
{
  int idJuego;
  char descripcion[51];
  float importe;
  int idCategoria;
} eJuego;

void MostrarUnJuego(eJuego  miJuego, eCategoria miCategoria);
void MostrarListadoJuego(eJuego listadoJuego[], int tamJ, eCategoria listadoCategoria[],int tamC);

#endif // JUEGO_H_INCLUDED
