#include "juego.h"

void MostrarListadoJuego(eJuego listadoJuego[], int tamJ, eCategoria listadoCategoria[],int tamC)
{
  int i;
  int j;
  if (listadoJuego != NULL&&listadoCategoria!=NULL)
    {

      GetChar ("ID DEL JUEGO:          NOMBRE:         CATEGORIA:         PRECIO:    \n");

      for (i = 0; i < tamJ; i++)
	 {
	  for (j = 0; j < tamC; j++)
	    {
	      if (listadoJuego[i].idJuego == listadoCategoria[j].idCategoria)
		    {

			      MostrarUnJuego(listadoJuego[i], listadoCategoria[j]);
		     }
	    }
	 }
    }
}


void MostrarUnJuego(eJuego miJuego, eCategoria miCategoria)
{

  printf ("%d %30s %15s %15.2f\n",miJuego.idJuego,miJuego.descripcion,miCategoria.descripcion,miJuego.importe);

}

