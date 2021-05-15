#include <stdio.h>
#include <stdlib.h>
#define OCUPADO 0
#define VACIO 1
#include "alquileres.h"
#define TCL 50
#define TJ 3
#define TC 3
#define TA 50

int main()
{
  //eEstructura listado[T] = {{},{},{}};

  //eEstructura2 listado2[T2]={{},{},{}};

  int legajo;
  int opcion;

  eCliente listadoCliente[TCL];
  eAlquiler listadoAlquiler[TA];

  eJuego listadoJuego[TJ]={{1,"Doom",300,1},{2,"YuGiOh",250,2},{3,"CounterStrike",420,3}};
  eCategoria listadoCategoria[TC]={{1,"FPS"},{2,"Juego de Cartas"},{3,"FPS"}};

  InicializarCliente(listadoCliente, TCL);
  InicializarAlquiler(listadoAlquiler,TA);
  do

    {
      opcion = menuCliente();

      //InicializarEstructura2(listado2, T2);

      switch (opcion)
	{
	case 1:
        legajo++;
	  CargarCliente(listadoCliente, TCL,legajo);
	  break;

	case 2:
	  legajo = GetInt ("Ingrese el legajo del cliente: ",50,0,"Error.Legajo invalido: ");
	  BajaCliente(listadoCliente, TCL, legajo);
	  break;

	case 3:
	  legajo = GetInt ("Ingrese el legajo del cliente: ",50,0,"Error.Legajo invalido: ");
	  ModificarCliente(listadoCliente, TCL, legajo);
	  break;

	  case 4:
	  MostrarListadoCliente(listadoCliente, TCL);break;

	default:
	  GetChar ("Opcion Invalida.\n");
	}

    }
  while (opcion != 5);
    return 0;
}
