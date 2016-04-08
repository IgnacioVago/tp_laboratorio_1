#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#endif // FUNCIONES_H_INCLUDED
double suma(double a, double b);
double resta(double a,double b);
double division(double a,double b);
double multiplicacion(double a,double b);
double factorial(double a);

double suma(double a,double b)
{
    double result;
    result=a+b;
    return result;
}

double resta(double a,double b)
{
    double result;
    result=a-b;
    return result;
}

double division(double a,double b)
{
    if(b==0)
    {
        printf("Error, ingrese un numero mayor a cero");
        return 0;
    }
    double result;
    result=a/b;
    return result;
}

double multiplicacion(double a,double b)
{
    double result;
    result=a*b;
    return result;
}

double factorial(double a)
{
    double i,result=1;
    for(i=1;i<=a;i++)
    {
        result=result*i;
    }
    return result;
}
