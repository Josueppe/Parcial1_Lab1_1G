#include "alquileres.h"
void InicializarAlquiler(eAlquiler listadoAlquiler[], int tamA)
{
  int i;
  if (listadoAlquiler != NULL)
    {
      for (i = 0; i < tamA; i++)
	{
	  listadoAlquiler[i].isEmpty = VACIO;
	}
    }
}


int BuscarAlquilerLibre (eAlquiler listadoAlquiler[], int tamA)
{
  int i;
  int index;
  index = -1;
  if (listadoAlquiler != NULL)
    {
      for (i = 0; i < tamA; i++)
	{
	  if (listadoAlquiler[i].isEmpty == VACIO)
	    {
	      index = i;
	      break;
	    }
	}
    }
  return index;
}


int CargarAlquiler(eAlquiler listadoAlquiler[], int tamA,int legajo,eJuego listadoJuego[],int tamJ,eCliente listadoCliente[],int tamCL,eCategoria listadoCategoria[])
{
  int index;
  index = BuscarAlquilerLibre (listadoAlquiler,tamCL);

  if (index == -1)
    {
      GetChar("No hay espacio para cargar otro Alquiler!!!\n");
    }
  else
    {
      listadoAlquiler[index] = PedirUnAlquiler(listadoJuego,tamJ,listadoCliente,tamCL,listadoCategoria);
      listadoAlquiler[index].idAlquiler = legajo;
    }


  return index;
}



eAlquiler PedirUnAlquiler(eJuego listadoJuego[],int tamJ,eCliente listadoCliente[],int tamCL,eCategoria listadoCategoria[])
{
  eAlquiler miAlquiler;

  MostrarListadoJuego(listadoJuego,tamJ,listadoCategoria,tamCL);

  printf("Ingrese el ID del juego:");
  scanf("%d",&miAlquiler.idJuego);

 MostrarListadoCliente(listadoCliente,tamCL);
  printf ("Ingrese el id del cliente: ");
  fflush (stdin);
  scanf ("%d",&miAlquiler.idCliente);

  printf ("Ingrese el dia: ");
  fflush (stdin);
  scanf ("%d",&miAlquiler.fecha.dia);

  printf ("Ingrese el mes: ");
  fflush (stdin);
  scanf ("%d",&miAlquiler.fecha.mes);

  printf ("Ingrese el anio: ");
  fflush (stdin);
  scanf ("%d",&miAlquiler.fecha.anio);



  miAlquiler.isEmpty = OCUPADO;

  return miAlquiler;
}
