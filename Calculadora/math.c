#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#define SUCCESS 1
#define FAILURE 0

/**
*\brief Suma dos numeros y devuelve el resulado.
*\param float Operador 1.
*\param float Operador 2.
*\return float El total de la Suma.
*
*/
float suma(float sumandoUno, float sumandoDos)
{

    float total;
    total = sumandoUno + sumandoDos;

    return total;
}

/**
*\brief Resta dos numeros y devuelve el resulado.
*\param float Operador 1.
*\param float Operador 2.
*\return float El total de la Resta.
*
*/
float resta(float restandoUno, float restandoDos)
{
    float total;

    total = restandoUno - restandoDos;

    return total;
}

/**
*\brief Divide dos valores flotantes y devuelve el resulado.
*\param float Multiplicando.
*\param float Multiplicador.
*\return float El total de la multiplicacion.
*
*/
float multiplicacion(float multiplicando, float multiplicador)
{

    float total;

    total = multiplicando * multiplicador;
    return total;
}



/**
*\brief Saca el factorial de un numero natural
*\param int El numero que se le sacara el factorial
*\return long long int El factorial del numero
*
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

/**
*\brief Divide dos valores flotantes y devuelve el resulado.
*\param float Dividiendo.
*\param float Divisor.
*\return float El total de la division.
*
*/
float division(float dividiendo, float divisor)
{
    float total;

    total = dividiendo / divisor;

    return total;

}
/**
*\brief Pide un numero flotante y verifica si se puede convertir a un entero.
*\param Float el numero a convertir
*\return Int si es posible convertir el valor a entero.
*
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

/**
*\brief Pide un numero y despues lo guarda en su direccion de memoria.
*\param Char[] mensaje para el mensaje
*\param int* la direccion de memoria de una variable INT.
*\return Int Se devuelse si se pudo completar el ingreso.
*
*/
int ingresarNumero(char mensaje[],float* numero)
{
    printf("%s", mensaje);
    scanf("%f", numero);
    return SUCCESS;
}
