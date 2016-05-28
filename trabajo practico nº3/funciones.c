#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"



void agregarPelicula(EMovie movie, FILE *emovie)
    {
        char auxtitulo[75];
        char auxgenero[75];
        char auxdescripcion[200];

        printf("\nIngrese el titulo de la pelicula: ");
        fflush(stdin);
        gets(auxtitulo);
        val_tam(auxtitulo,21);
        strcpy(movie.titulo,auxtitulo);
        printf("_____________________________________");
        printf("\nIngrese genero de la pelicula: ");
        fflush(stdin);
        gets(auxgenero);
        val_tam(auxgenero,21);
        strcpy(movie.genero,auxgenero);
        printf("_____________________________________");
        printf("\nIngrese la descripcion de la pelicula: ");
        fflush(stdin);
        gets(auxdescripcion);
        val_tam(auxdescripcion,151);
        strcpy(movie.descripcion,auxdescripcion);
        printf("______________________________________");
        printf("\nIngrese el puntaje de la pelicula: ");
        scanf("%f",&movie.puntaje);
        printf("______________________________________");
        printf("\nIngrese la duracion en minutos: ");
        scanf("%d",&movie.duracion);
        printf("______________________________________");
        printf("\nIngrese el link de la imagen de la pelicula: ");
        fflush(stdin);
        gets(movie.linkImagen);

        fseek(emovie,0L,SEEK_END);
        fwrite(&movie,sizeof(EMovie),1,emovie);

    }

void modificar(EMovie movie, FILE *emovie)
{
    char rta;
    char auxtitulo[75];
    char auxdescripcion[200];
    char auxgenero[75];

    printf("Ingrese titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(auxtitulo);

    rewind(emovie);
    while(!feof(emovie))
    {
        fread(&movie,sizeof(EMovie),1,emovie);
        if(strcmpi(auxtitulo,movie.titulo)==0)
        {
           printf("\nTITULO: %s  \nGENERO: %s  \nDURACION: %d  \nDESCRIPCION: %s  \nPUNTAJE: %.2f  \nLINK: %s",movie.titulo,movie.genero,movie.duracion,movie.descripcion,movie.puntaje,movie.linkImagen);

           printf("\nDesea modificar?");

           fflush(stdin);
           rta=tolower(getch());

           if(rta=='s')
           {
              printf("Ingrese titulo de la pelicula: ");
              fflush(stdin);
              gets(auxtitulo);
              val_tam(auxtitulo,21);
              strcpy(movie.titulo,auxtitulo);
              printf("Ingrese genero de la pelicula: ");
              fflush(stdin);
              gets(auxgenero);
              val_tam(auxgenero,21);
              strcpy(movie.titulo,auxgenero);
              printf("\nIngrese la descripcion de la pelicula: ");
              fflush(stdin);
              gets(auxdescripcion);
              val_tam(auxdescripcion,151);
              strcpy(movie.descripcion,auxdescripcion);
              printf("Ingrese puntaje de la pelicula: ");
              scanf("%f",&movie.puntaje);
              printf("Ingrese duracion de la pelicula: ");
              scanf("%d",&movie.duracion);
              printf("Ingrese link de la pelicula: ");
              fflush(stdin);
              gets(movie.linkImagen);

              break;
           }
           else
                {
                    printf("\nNo se modificaron los datos.");
                    break;
                }

        }
        else
        {
            printf("El titulo no existe");
            break;
        }
    }
}

void borrarPelicula(EMovie movie, FILE *emovie)
    {
        char auxtitulo[21];
        char rta;

        printf("\nIngrese el titulo de la pelicula a borrar: ");
        fflush(stdin);
        gets(auxtitulo);

        rewind(emovie);
        while(!feof(emovie))
        {
            fread(&movie, sizeof(EMovie), 1, emovie);

            if(strcmpi(auxtitulo,movie.titulo)==0)
            {
                printf("\nTITULO: %s  \nGENERO: %s  \nDURACION: %d  \nDESCRIPCION: %s  \nPUNTAJE: %.2f  \nLINK: %s",movie.titulo,movie.genero,movie.duracion,movie.descripcion,movie.puntaje,movie.linkImagen);

                printf("\nSeguro que desea borrarlos? s/n: ");
                fflush(stdin);
                rta = tolower(getch());


                system("pause");
                system("cls");

                if(rta=='s')
                {

                    strcpy(movie.titulo,"\0");
                    fseek(emovie,(-1)*sizeof(EMovie),SEEK_CUR);
                    fwrite(&movie,sizeof(EMovie),1,emovie);
                    printf("\nSe borraron los datos.");
                    break;
                }
                else
                {
                    printf("\nNo se borraron los datos.");
                    break;
                }
            }
            else
            {
                printf("\nEl titulo no existe");
                break;
            }
        }
    }

void generarPagina(EMovie movie, FILE *emovie)
{

    FILE *emovieHtml;

    char bloque1[]="<!DOCTYPE html><html><head><title>Example</title>alt=''></a><h3><a href='#'>";
    char bloque2[]="</head><body><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src=";
    char bloque3[]="</h3><ul><li>Género:";
    char bloque4[]="</li><li>Puntaje:";
    char bloque5[]="</li><li>Duración:";
    char bloque6[]="</li></ul><p>";
    char bloque7[]="</p></article></html></body>";

    emovieHtml=fopen("archivo.html","w");

    fprintf(emovieHtml,"%s\n",bloque1);

    rewind(emovie);
    while(!feof(emovie))
    {
        fread(&movie,sizeof(EMovie),1,emovie);
        fprintf(emovieHtml,"%s%s%s%s%s%s%.02f%s%d%s%s%s\n",movie.titulo, bloque2, movie.linkImagen, bloque3, movie.genero, bloque4, movie.puntaje,bloque5,movie.duracion,bloque6,movie.descripcion,bloque7);
    }

    fprintf(emovieHtml,"%s",bloque7);
    fclose(emovie);
}

void val_tam(char x[],int tam )
{
    while(strlen(x)>tam-1)
    {
        printf("Error, ingrese cadena que no exceda %d ", tam-1);
        fflush(stdin);
        gets(x);
    }
}
