#include "getters.h"
int GetInt(char mensaje[],int param1,int param2,char mensajeError[])
{
    int num;
    printf ("%s", mensaje);
    scanf ("%d", &num);
    while(num>param1||num<param2)
    {
    printf ("%s", mensajeError);
    scanf ("%d", &num);
    }
    return num;
}


void GetChar (char mensaje[])
{
    fflush (stdin);
    printf ("%s", mensaje);
}
