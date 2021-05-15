#include "cliente.h"

int menuCliente()
{
  int opcion;
  GetChar ("*****MENU CLIENTE*****\n");
  GetChar ("1. ALTA\n");
  GetChar ("2. BAJA\n");
  GetChar ("3. MODIFICACION\n");
  GetChar ("4. LISTAR\n");
  GetChar ("5. SALIR\n");
  GetChar ("**************\n");
  opcion = GetInt ("Elija una opcion:",5,1,"Error.Opcion incorrecta: ");

  return opcion;
}

void InicializarCliente(eCliente listadoCliente[], int tamCL);

void InicializarCliente(eCliente listadoCliente[], int tamCL)
{
  int i;
  if (listadoCliente != NULL)
    {
      for (i = 0; i < tamCL; i++)
	{
	  listadoCliente[i].isEmpty = VACIO;
	}
    }
}



int BuscarClienteLibre (eCliente listadoCliente[], int tamCL)
{
  int i;
  int index;
  index = -1;
  if (listadoCliente != NULL)
    {
      for (i = 0; i < tamCL; i++)
	{
	  if (listadoCliente[i].isEmpty == VACIO)
	    {
	      index = i;
	      break;
	    }
	}
    }
  return index;
}


int CargarCliente(eCliente listadoCliente[], int tamCL,int legajo)
{
  int index;
  index = BuscarClienteLibre (listadoCliente,tamCL);

  if (index == -1)
    {
      GetChar("No hay espacio para cargar otro CLIENTE!!!\n");
    }
  else
    {
      listadoCliente[index] = PedirUnCliente();
      listadoCliente[index].idCliente = legajo;
    }


  return index;
}



eCliente PedirUnCliente()
{
  eCliente miCliente;

  printf("Ingrese el telefono:");
  scanf("%d",&miCliente.telefono);

  printf ("Ingrese el nombre del cliente: ");
  fflush (stdin);
  scanf ("%s", miCliente.nombre);

  printf ("Ingrese el apellido del cliente: ");
  fflush (stdin);
  scanf ("%s", miCliente.apellido);

  printf ("Ingrese el sexo del cliente: ");
  fflush (stdin);
  scanf ("%c",&miCliente.sexo);

   while(miCliente.sexo!='f'&&miCliente.sexo!='m')
    {
  printf ("Error. Ingre el sexo del cliente de nuevo: ");
  fflush (stdin);
  scanf ("%c",&miCliente.sexo);
    }

  miCliente.isEmpty = OCUPADO;

  return miCliente;
}


int BajaCliente (eCliente listadoCliente[], int tamCL, int legajo)
{
  if (listadoCliente != NULL)
    {
      int i;
      for (i = 0; i < tamCL; i++)
	{
	  if (listadoCliente[i].idCliente == legajo)
	    {
	      listadoCliente[i].isEmpty = VACIO;
	      return 1;
	    }
	}

    }
  return 0;
}



int ModificarCliente(eCliente listadoCliente[], int tamCL, int legajo)
{
  if (listadoCliente != NULL)
    {
      int nuevoTelefono;
      int opcion;
      int i;

      for (i = 0; i < tamCL; i++)
	{
	  if (listadoCliente[i].idCliente == legajo)
	    {
	      opcion=GetInt("Que desea modificar?\n1-Nombre\n2-Apellido\n3-Telefono\nIngrese una opcion: ",4,0,"Error.Opcion incorrecta");
	      switch (opcion)
		{
		case 1:
          nuevoTelefono=GetInt("Ingrese un nuevo telefono:",21,9,"Error.Telefono invalido");
		  listadoCliente[i].telefono = nuevoTelefono;
		  break;

		case 2:
        printf ("Ingrese nombre el nombre: ");
        fflush (stdin);
        scanf ("%s", listadoCliente[i].apellido);break;
		  break;

		case 3:
        printf ("Ingrese nombre el apellido: ");
        fflush (stdin);
        scanf ("%s", listadoCliente[i].apellido);break;

		}
	      return 1;
	    }
	}

    }
  return 0;
}

void OrdenarClientePorNombre(eCliente listadoCliente[], int tamCL);

void OrdenarClientePorNombre(eCliente listadoCliente[], int tamCL)
{
  int i;
  int j;
  eCliente auxiliar;
  if (listadoCliente != NULL)
    {
      for (i = 0; i < tamCL - 1; i++)
	{
	  for (j = i + 1; j < tamCL; j++)
	    {

	      if (strcmp (listadoCliente[i].nombre, listadoCliente[j].nombre) > 0)
		{
		  auxiliar = listadoCliente[i];
		  listadoCliente[i] = listadoCliente[j];
		  listadoCliente[j] = auxiliar;
		}
	    }
	}
    }
}


void MostrarListadoCliente(eCliente listadoCliente[],int tamCL)
{
  int i;
  if (listadoCliente != NULL)
    {

      GetChar ("ID:    NOMBRE:   APELLIDO:    SEXO:     TELEFONO:\n");

      for (i = 0; i < tamCL; i++)
	 {
			  if (listadoCliente[i].isEmpty == OCUPADO)
			    {
			      MostrarUnCliente(listadoCliente[i]);
			    }
	 }
    }
}

void MostrarUnCliente (eCliente miCliente)
{

  printf ("%d %10s %10s %10c %10d\n", miCliente.idCliente,miCliente.nombre,miCliente.apellido,miCliente.sexo,miCliente.telefono);

}
