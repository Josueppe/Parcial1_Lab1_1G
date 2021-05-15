#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "fecha.h"
#include "juego.h"
#include "cliente.h"
#include "categoria.h"
#include "getters.h"
#include <stdio.h>
#include <string.h>
#define OCUPADO 0
#define VACIO 1
typedef struct
{
  int idAlquiler;//AUTOINCREMENTAL
  int idJuego;
  int idCliente;
  eFecha fecha;
  int isEmpty;
} eAlquiler;

void InicializarAlquiler(eAlquiler listadoAlquiler[], int tamA);
int BuscarAlquilerLibre (eAlquiler listadoAlquiler[], int tamA);
eAlquiler PedirUnAlquiler(eJuego listadoJuego[],int tamJ,eCliente listadoCliente[],int tamCL,eCategoria listadoCategoria[]);
int CargarAlquiler(eAlquiler listadoAlquiler[], int tamA,int legajo,eJuego listadoJuego[],int tamJ,eCliente listadoCliente[],int tamCL,eCategoria listadoCategoria[]);

#endif // ALQUILERES_H_INCLUDED
