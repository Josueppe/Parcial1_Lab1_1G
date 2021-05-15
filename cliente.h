#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#define OCUPADO 0
#define VACIO 1
#include "getters.h"
#include <stdio.h>
#include <string.h>
typedef struct
{
  int idCliente;//AUTOINCREMENTAL
  char nombre[51];
   char apellido[51];
    char sexo;
    int telefono;
    int isEmpty;
} eCliente;

int menuCliente();
void InicializarCliente(eCliente listadoCliente[], int tamCL);
int BuscarClienteLibre (eCliente listadoCliente[], int tamCL);
int CargarCliente(eCliente listadoCliente[], int tamCL,int legajo);
eCliente PedirUnCliente();
int BajaCliente (eCliente listadoCliente[], int tamCL, int legajo);
int ModificarCliente(eCliente listadoCliente[], int tamCL, int legajo);
void MostrarListadoCliente(eCliente listadoCliente[],int tamCL);
void MostrarUnCliente (eCliente miCliente);

#endif // CLIENTE_H_INCLUDED
