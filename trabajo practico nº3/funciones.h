#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[150];
    float puntaje;
    char linkImagen[500];
}EMovie;


void agregarPelicula(EMovie movie, FILE *emovie);

void borrarPelicula(EMovie movie, FILE *emovie);

void generarPagina(EMovie moovie,FILE *emovie);

void modificar(EMovie movie,FILE *emovie);

int buscar(EMovie movie,int auxtitulo);

void val_tam(char x[],int tam );

#endif // FUNCIONES_H_INCLUDED





