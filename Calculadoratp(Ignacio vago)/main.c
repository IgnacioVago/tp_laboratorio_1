#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,flag=0,flag1=0,result;
    double a,b;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf("ingrese una opcion\n: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese 1er operando: \t");
                scanf("%Lf",&a);
                flag=1;
                break;
            case 2:
                printf("Ingrese 2do operando: \t");
                scanf("%Lf",&b);
                flag1=1;
                break;
            case 3:
                if(flag==0||flag1==0)
                {
                    printf("Error.Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El resultado de la suma es %.2Lf:",suma(a,b));
                system("pause");
                break;
            case 4:
                if(flag==0||flag1==0)
                {
                    printf("Error. Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El resultado de la resta es %.2Lf: ",resta(a,b));
                system("pause");
                break;
            case 5:
                if(flag==0||flag1==0)
                {
                    printf("Error.Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El resultado de la division es %Lf: ",division(a,b));
                system("pause");
                break;
            case 6:
                if(flag==0||flag1==0)
                {
                    printf("Error.Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El resultado de la multiplicacion es %Lf",multiplicacion(a,b));
                system("pause");
                break;
            case 7:
                if(flag==0||flag1==0)
                {
                    printf("Error.Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El factorial del 1er operando es %.2Lf ",factorial(a));
                system("pause");
                break;
            case 8:
                if(flag==0||flag1==0)
                {
                    printf("Error.Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El resultado de la suma es %.2Lf: ",suma(a,b));
                system("pause");


                if(flag==0||flag1==0)
                {
                    printf("Error. Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El resultado de la resta es %.2Lf: ",resta(a,b));
                system("pause");


                if(flag==0||flag1==0)
                {
                    printf("Error.Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El resultado de la division es %Lf: ",division(a,b));
                system("pause");


                if(flag==0||flag1==0)
                {
                    printf("Error.Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El resultado de la multiplicacion es %Lf",multiplicacion(a,b));
                system("pause");


                if(flag==0||flag1==0)
                {
                    printf("Error.Reingrese un numero");
                    system("pause");
                    break;
                }
                printf("El factorial del 1er operando es %.2Lf ",factorial(a));
                system("pause");

                break;
            case 9:
                seguir = 'n';
                break;
        }
         system("cls");

   }



   return 0;
 }

