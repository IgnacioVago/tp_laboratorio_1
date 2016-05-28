#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    FILE *emovie;
    EMovie movie;

     emovie = fopen("datos.dat","rb+");
        if(emovie==NULL)
        {
            emovie = fopen("datos.dat", "wb+");

            if(emovie==NULL)
            {
                printf("\nNo se pudo crear el registro");
                exit(1);
            }
        }

    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie,emovie);
                break;
            case 2:
                borrarPelicula(movie,emovie);
                break;
            case 3:
                modificar(movie,emovie);
                break;
            case 4:
                generarPagina(movie,emovie);
                break;
            case 5:
                seguir = 'n';
                break;

        }
    }
}
