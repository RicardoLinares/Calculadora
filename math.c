#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <limits.h>



/*
funcionalidad:
parametros:
retorno:
*/
int suma(int sumando, int sumado)
{

    int total;
    total = sumando + sumado;

    printf("%d + %d = %d\n", sumado, sumando, total);
    return 0;
}

/*
funcionalidad:
parametros:
retorno:
*/
int resta(int restando, int restado)
{
    int total;

    total = restando - restado;
    printf("%d - %d = %d\n", restando, restado, total);

    return 0;
}

/*
funcionalidad:
parametros:
retorno:
*/
int multiplicacion(int multiplicando, int multiplicado)
{

    int total;

    total = multiplicando * multiplicado;
    printf("%d * %d = %d\n", multiplicado, multiplicado, total);
    return 0;
}

/*
funcionalidad:
parametros:
retorno:
*/
int factorial(int numero)
{
    int total = 1;
    int contador;
    for(contador = 1; contador <= numero; contador++)
    {
        total = total * contador;
    }
    printf("el facotrial de %d! es %d\n", numero, total);
    return 0;
}
/*
funcionalidad:
parametros:
retorno:
*/
int division(int dividiendo, int divisor)
{
    if(divisor == 0)
    {
        printf("No se puede divir por Cero");
        return -1;
    }

    int total;

    total = dividiendo / divisor;
    printf("%d / %d = %d\n", dividiendo, divisor, total);
    return 0;

}
/*
funcionalidad: Se ingresa un valor entero por scanf y se lo almacena en una direcion de memoria.
parametros: se pide una direccion de memoria de una variable INT.
retorno: no devuelve nada.
*/
void ingresarNumero(int* numero)
{
    printf("Ingrese Un Numero : ");
    scanf("%d", numero);
    __fpurge(stdin);
}
