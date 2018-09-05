#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "math.h"

#define clear(); printf("\033[H\033[J") // limpia la consola .para linux
#define ACTIVA 1 // para banderas
#define INACTIVA 0

int main()
{
    int opcion;

    float operandoDos;
    float operandoUno;

    int operandoUnoFlag = INACTIVA;
    int operandoDosFlag = INACTIVA;
    int calculosFlag = INACTIVA;

    int divisionCeroFlag = INACTIVA;
    int factorialUnoFlag = INACTIVA;
    int factorialDosFlag = INACTIVA;

    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    long long int resultadoFactorialUno;
    long long int resultadoFactorialDos;
    float resultadoDivision;



    do
    {
        printf("CALCULADORA, ingrese su opcion:\n");
        printf("1.- Determinar el 1er Operando: ");
        if(operandoUnoFlag)
        {
            printf("%0.2f", operandoUno);
        }
        printf("\n2.- Determinar el 2do Operando: ");
        if(operandoDosFlag)
        {
            printf("%0.2f", operandoDos);
        }
        printf("\n3.- Calcular Operaciones:\n");
        printf("4.- Mostrar Resultados:\n");
        printf("5.- Salir:\n");
        printf("Su Opcion : ");
        if(!scanf("%d", &opcion))
        {
            opcion = 0;
        }

        switch(opcion)
        {
        case 1:
            __fpurge(stdin);
            if(ingresarNumero("Ingrese el Operando numero uno: ", &operandoUno))
            {
                __fpurge(stdin);
                printf("El Operando uno ahora es : %0.2f\n", operandoUno);
                operandoUnoFlag = ACTIVA;
                // desactiva la bandera ya que hay un nuevo valor
                calculosFlag = INACTIVA;
            }
            else
            {
                printf("ERROR: El nuevo operando uno que ingreso no es valido\n");
            }


            break;
        case 2:
            __fpurge(stdin);
            if(ingresarNumero("Ingrese el Operando numero dos: ", &operandoDos))
            {
                printf("El Operando dos ahora es : %0.2f\n", operandoDos);
                operandoDosFlag = ACTIVA;
                // desactiva la bandera ya que hay un nuevo valor
                calculosFlag = INACTIVA;
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
                if(transformarFlotatanteEntero(operandoUno) && operandoUno >= 0)
                {
                    resultadoFactorialUno = factorial((int)operandoUno);
                    factorialUnoFlag = ACTIVA;
                }
                if(transformarFlotatanteEntero(operandoDos)&& operandoDos >= 0)
                {
                    resultadoFactorialDos = factorial((int)operandoDos);
                    factorialDosFlag = ACTIVA;
                }
                if(operandoDos)
                {
                    resultadoDivision = division(operandoUno, operandoDos);
                    divisionCeroFlag = ACTIVA;
                }
                calculosFlag = ACTIVA;
            }
            else
            {
                printf("ERROR: Ingrese los Operandos con las dos primeras opciones\n");
            }
            break;
        case 4:
            if(calculosFlag)
            {
                printf("El resultado de (%0.2f)+(%0.2f) es: %0.2f\n", operandoUno, operandoDos, resultadoSuma);
                printf("El resultado de (%0.2f)-(%0.2f) es: %0.2f\n", operandoUno, operandoDos, resultadoResta);
                if(divisionCeroFlag)
                {
                    printf("El resultado de (%0.2f)/(%0.2f) es: %0.2f\n", operandoUno, operandoDos, resultadoDivision);
                }
                else
                {
                    printf("Division: No es posible dividir por cero\n");
                }
                printf("El resultado de (%0.2f)*(%0.2f) es: %0.2f\n", operandoUno, operandoDos, resultadoMultiplicacion);
                if(factorialUnoFlag)
                {
                    printf("Factorial del Primer Operando: (%.0f)! = %lld y ", operandoUno, resultadoFactorialUno);
                }
                else
                {
                    printf("Factorial de (%0.2f)! es: El numero debe ser Natural para calcular factorialy \n", operandoDos);
                }
                if(factorialDosFlag)
                {
                    printf("el factorial de (%.0f)! es: %lld\n", operandoDos, resultadoFactorialDos);
                }
                else
                {
                    printf("el factorial de (%0.2f)! es: El numero debe ser Natural para calcular factorial\n", operandoDos);
                }
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


    return 0;

}
