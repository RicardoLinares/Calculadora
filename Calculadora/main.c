#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "math.h"

#define clear(); printf("\033[H\033[J") // para linux
int main()
{
    int opcion = 5;

    int operandoDos;
    int operandoUno;

    int operandoUnoFlag = 0;
    int operandoDosFlag = 0;
    int divisionCeroFlag;
    int calculosFlag = 0;

    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    long long int resultadoFactorialUno;
    long long int resultadoFactorialDos;
    float resultadoDivision;



    do
    {
        printf("CALCULADORA, ingrese su opcion:\n");
        printf("1.- Determinar el 1er Operando:\n");
        printf("2.- Determinar el 2do Operando:\n");
        printf("3.- Calcular Operaciones:\n");
        printf("4.- Mostrar Resultados:\n");
        printf("5.- Salir:\n");
        printf("Su Opcion : ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(ingresarNumero("Ingrese el Operando numero uno: ", &operandoUno))
            {
                __fpurge(stdin);
                printf("El Operando uno ahora es : %d\n", operandoUno);
                operandoUnoFlag = 1;
            }
            else
            {
                printf("ERROR: El nuevo operando uno que ingreso no es valido\n");
            }
            break;
        case 2:
            if(ingresarNumero("Ingrese el Operando numero do: ", &operandoDos))
            {
                printf("El Operando dos ahora es : %d\n", operandoDos);
                operandoDosFlag = 2;
            }
            else
            {
                printf("ERROR: El nuevo operando dos que ingreso no es valido\n");
            }

            break;
        case 3:
            if(operandoUnoFlag && operandoDosFlag)
            {
                resultadoSuma = suma(operandoUno,operandoDos);
                resultadoResta = resta(operandoUno,operandoDos);
                resultadoMultiplicacion = multiplicacion(operandoUno,operandoDos);
                factorialFlag = factorial(operandoUno);
                resultadoFactorialDos = factorial(operandoDos);
                if(!operandoDos)
                {
                    divisionCeroFlag = 1;
                }
                else
                {
                    division(operandoUno, operandoDos, &resultadoDivision);

                }
                calculosFlag = 1;
            }
            else
            {
                printf("ERROR: Ingrese los Operandos con las dos primeras opciones\n");
            }
            break;
        case 4:
            if(calculosFlag)
            {
                printf("Suma: %d + %d = %d\n", operandoUno, operandoDos, resultadoSuma);
                printf("Resta: %d - %d = %d\n", operandoUno, operandoDos, resultadoResta);
                printf("Multiplicacion: %d * %d = %d\n", operandoUno, operandoDos, resultadoMultiplicacion);
                printf("Division: %d / %d = %f\n", operandoUno, operandoDos, resultadoDivision);
                printf("Factorial del Primer Operando: %d! = %lld\n", operandoUno, resultadoFactorialUno);
                printf("Factorial del Segundo Operando: %d! = %lld\n", operandoDos, resultadoFactorialDos);
            }
            else
            {
                printf("ERROR: Para mostrar los resultados se requiere calcular(Opcion 3)...\n");
            }
            break;
        case 5:
            printf("HASTA LUEGO!!\n");
            break;
        default:
            printf("No ingreso una Opcion valida\n");
            break;
        }
        __fpurge(stdin);
        printf("pulse ENTER para continuar");
        getchar();
        clear();
    }
    while(opcion != 5);


}
