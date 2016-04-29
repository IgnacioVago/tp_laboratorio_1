#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estaVacio;
    long int dni;

}EPersona;

void Inicializar(EPersona per[]);
void Agregar(EPersona per[]);
void Baja(EPersona lista[]);
int Buscar(EPersona lista[],long int dni);
void Imprimir(EPersona lista[]);
int Libre(EPersona lista[]);
void Grafico(EPersona lista[]);
char Salir(EPersona lista[]);
void Valtam(char x[], int tam);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
//int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
//int buscarPorDni(EPersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED


