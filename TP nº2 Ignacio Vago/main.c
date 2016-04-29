#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"
#define c 20

int main()
{
    EPersona per[c];
    char seguir='s';
    int opcion=0,flag=0;

    Inicializar(per);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                Agregar(per);
                flag=1;
                break;
            case 2:
                if(flag==1)
                {
                  Baja(per);
                }
                system("pause");
                break;
            case 3:
                if(flag==1)
                {
                  Imprimir(per);
                }
                system("pause");
                break;
            case 4:
                if(flag==1)
                {
                    Grafico(per);
                }
                system("pause");
                break;
            case 5:
                Salir(per);
                seguir = 'n';
                break;
        }
      system("cls");
    }

     return 0;
}
