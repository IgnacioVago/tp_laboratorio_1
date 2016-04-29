#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define c 20

void Inicializar(EPersona per[])
{
    int i;
    for(i=0;i<c;i++)
    {
        strcpy(per[i].nombre,"\0");
        per[i].dni=0;
        per[i].edad=0;
        per[i].estaVacio=0;
    }
}

void Agregar(EPersona per[])
{
    int i, indice=-1, flag=0, edad;
    long int dni;
    char auxNom[75];
    indice=Libre(per);

    if(indice!=-1)
    {
        printf("Ingrese DNI: ");
        scanf("%ld",&dni);

        while(dni<1000000||dni>99000000)
        {
            printf("Ingrese un DNI correcto: ");
            scanf("%ld",&dni);
        }

        for(i=0;i<c;i++)
        {
            while(dni==per[i].dni)
            {
                printf("Ingrese DNI nuevamente: ");
                scanf("%ld",&dni);

                while(dni<1000000||dni>99000000)
                {
                    printf("Ingrese un DNI correcto: ");
                    scanf("%ld",&dni);
                }
            }
        }

        if(flag==0)
        {
            per[indice].dni=dni;
            printf("Ingrese NOMBRE: ");
            fflush(stdin);
            gets(auxNom);
            Valtam(auxNom,50);
            strcpy(per[indice].nombre, auxNom);
            printf("Ingrese EDAD: ");
            scanf("%d",&edad);

            while(edad<1 || edad>99)
            {
                printf("Reingrese EDAD: ");
                scanf("%d",&edad);
            }

            per[indice].edad=edad;
            per[indice].estaVacio=1;
        }
    }
    else
        printf("Sin espacio!");
}

void Baja(EPersona per[])
{
    int i, flag=0;
    long int dni;
    char rta='n';

    printf("Ingrese el DNI que quiere borrar: ");
    scanf("%ld",&dni);

    flag=Buscar(per,dni);

    for(i=0;i<c;i++)
    {
        if(dni==per[i].dni)
        {
            printf("NOMBRE: %s\nDNI: %ld\nEDAD: %d",per[i].nombre, per[i].dni, per[i].edad);
            printf("\nDesea borrarlo? <s/n>: ");
            rta=tolower(getch());
            while(rta!='s'&&rta!='n')
            {
                printf("\nResponda si con s o no con n: ");
                rta=tolower(getch());
            }
        }
    }
    if(flag && rta=='s')
    {

        for(i=0;i<c;i++)
        {
            if(dni==per[i].dni)
            {
                per[i].edad=0;
                per[i].dni=0;
                strcpy(per[i].nombre,"\0");
                per[i].estaVacio=0;
                break;
            }
        }
    }

    if(rta=='n')
        printf("\n-");
    if(per[i].dni!=dni)
        printf("\DNI inexistente.\n");


}

int Buscar(EPersona per[],long int dni)
{
    int i, flag=0;

    for(i=0;i<c;i++)
    {
        if(per[i].dni==dni)
        {
            flag=1;
            break;
        }
    }
    return flag;
}


int Libre(EPersona per[])
{
    int i, indice=-1;

    for(i=0;i<c;i++)
    {
        if(per[i].estaVacio==0)
        {
            indice=i;
            break;
        }

    }
    return indice;
}


void Imprimir(EPersona per[])
{
    int i, j;
    EPersona auxPer;
    for(i=0;i<c-1;i++)
    {
        if(per[i].estaVacio==1)
        {
            for(j=i+1;j<c;j++)
            {
                if(strcmp(per[i].nombre,per[j].nombre)>0)
                {
                    auxPer=per[i];
                    per[i]=per[j];
                    per[j]=auxPer;
                }
            }
        }
    }
    for(i=0;i<c;i++)
    {
        if(per[i].estaVacio!=0)
            printf("  DNI:%ld\n  NOMBRE:%s\n  EDAD:%d\n",per[i].dni,per[i].nombre, per[i].edad);
    }
}


void Grafico(EPersona per[])
{
    int i, h18=0, e19y35=0, my35=0, may=0, flag=0;

    for(i=0;i<c;i++)
    {
        if(per[i].estaVacio!=0)
        {
            if(per[i].edad<=18)
                h18++;

            else if(per[i].edad>18 && per[i].edad<=35)
                e19y35++;

            else
                my35++;
        }
    }

    if(h18>=e19y35 && h18>=my35)
        may=h18;

    else if(e19y35>=h18 && e19y35>=my35)
        may=e19y35;

    else
        may=my35;

    for(i=may;i>0;i--)
    {
        if(h18>=may)
            printf("*");

        if(e19y35>=may)
        {
            printf("\t*");
            flag=1;
        }

        if(my35>=may)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag)
                printf("\t*");
        }

        printf("\n");
        may--;
    }
    printf("< 18/19<>35/> 35");
}

char Salir(EPersona per[])
{
    char rta='n';

    printf("\nDesea salir? <s/n>: ");
    rta=tolower(getch());

    while(rta!='s'&&rta!='n')
    {
        printf("\nResponda con s/n: ");
        rta=tolower(getch());
    }

    if(rta=='s')
        rta='n';

    else
        rta='s';

    return rta;
}

void Valtam(char x[], int tam)
{
    while(strlen(x)>tam-1)
    {
        printf("Error, %d excede los caracteres. Reingrese: ", tam-1);
        fflush(stdin);
        gets(x);
    }
}

