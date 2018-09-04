#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#define SUCCESS 1
#define FAILURE 0

/*
funcionalidad: Suma dos valores enteros y devuelve el resulado entero
parametro: int Operador 1.
parametro: int Operador 2.
retorno: int el resultado de la Suma.
*/
float suma(float sumando, float sumado)
{

    float total;
    total = sumando + sumado;

    return total;
}
/*
funcionalidad: Resta dos valores enteros y devuelve el resulado entero
parametro: int Operador 1.
parametro: int Operador 2.
retorno: int el resultado de la Resta.
*/
float resta(float restando, float restado)
{
    float total;

    total = restando - restado;

    return total;
}

/*
funcionalidad: Resta dos valores enteros y devuelve el resulado flotante
parametro: int Operador 1.
parametro: int Operador 2.
retorno: int el resulatado de la Multiplicacion.
*/
float multiplicacion(float multiplicando, float multiplicado)
{

    float total;

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
float division(float dividiendo, float divisor)
{
    float total;

    total = dividiendo / divisor;

    return total;

}
/*
funcionalidad: Pide un numero y verifica si se puede convertir a un entero.
parametro: Float el numero a convertir
retorno: Int si es posible convertir el valor a entero.
*/
int transformarFlotatanteEntero(float numero)
{
    int operacion;
    int parteEntera = (int)numero;
    float parteDecimal = numero - parteEntera;

    if(parteDecimal != 0.0f)
    {
        operacion = FAILURE;
    }
    else
    {
        operacion = SUCCESS;
    }
    return operacion;
}
/*
funcionalidad: Pide un numero y despues lo guarda en su direccion de memoria.
parametro: Char[] mensaje para el mensaje
parametro: int* la direccion de memoria de una variable INT.
retorno: Int Se devuelse si se pudo completar el ingreso o no (0/1)
*/
int ingresarNumero(char mensaje[],float* numero)
{
    int operacion = FAILURE;
    int input[50];
    int changes[10];
    printf("%s", mensaje);
    fgets(input, 50, stdin);
    if(sscanf(input," %s %f ", changes, numero))
    {
        operacion = SUCCESS;
    }
    return operacion;
}
