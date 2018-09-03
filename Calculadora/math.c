#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <limits.h>

#define SUCCESS 1
#define FAILURE 0

/*
funcionalidad: Suma dos valores enteros y devuelve el resulado entero
parametro: int Operador 1.
parametro: int Operador 2.
retorno: int el resultado de la Suma.
*/
int suma(int sumando, int sumado)
{

    int total;
    total = sumando + sumado;

    return total;
}
/*
funcionalidad: Resta dos valores enteros y devuelve el resulado entero
parametro: int Operador 1.
parametro: int Operador 2.
retorno: int el resultado de la Resta.
*/
int resta(int restando, int restado)
{
    int total;

    total = restando - restado;

    return total;
}

/*
funcionalidad: Resta dos valores enteros y devuelve el resulado flotante
parametro: int Operador 1.
parametro: int Operador 2.
retorno: int el resulatado de la Multiplicacion.
*/
int multiplicacion(int multiplicando, int multiplicado)
{

    int total;

    total = multiplicando * multiplicado;
    return total;
}

/*
funcionalidad:
parametros:
retorno:
*/
long long int factorial(int numero)
{
    long long int total = 1;
    long long int contador;
    for(contador = numero; contador >= 1; contador--)
    {
        total = total * contador;
    }
    return total;
}
/*
funcionalidad: Resta dos valores enteros y devuelve el resulado flotante
parametro: int Dividiendo.
parametro: int Divisor.
parametro: float* la direccion de memoria donde se guarda el total
retorno: int devuelve si se completo la operacion
*/
int division(int dividiendo, int divisor, float* total)
{

    (*total) = (float)dividiendo / divisor;

    return SUCCESS;

}
/*
funcionalidad: Pide un numero y despues lo guarda en su direccion de memoria.
parametro: Char[] mensaje para el mensaje
parametro: int* la direccion de memoria de una variable INT.
retorno: Int Se devuelse si se pudo completar el ingreso o no (0/1)
*/
int ingresarNumero(char mensaje[],int* numero)
{
    int operacion = FAILURE;
    printf("%s", mensaje);
    if(scanf("%d", numero))
    {
        operacion = SUCCESS;
    }
    return operacion;
}
