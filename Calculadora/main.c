#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "math.h"

#define clear(); printf("\033[H\033[J") // limpia la consola .para linux
#define ACTIVE 1 // para banderas
#define INACTIVE 0

int main()
{
    int option;

    float operatorTwo;
    float operatorOne;

    int operatorOneFlag = INACTIVE;
    int operatorTwoFlag = INACTIVE;
    int calculosFlag = INACTIVE;

    int divisionCeroFlag = INACTIVE;
    int factorialOneFlag = INACTIVE;
    int factorialTwoFlag = INACTIVE;

    float resultSum;
    float resultResta;
    float resultMultiplicacion;
    long long int resultFactorialOne;
    long long int resultFactorialTwo;
    float resultDivision;



    do
    {
        printf("CALCULADORA, ingrese su opcion:\n");
        printf("1.- Determinar el 1er operador: ");
        if(operatorOneFlag)
        {
            printf("%0.2f", operatorOne);
        }
        printf("\n2.- Determinar el 2do operador: ");
        if(operatorTwoFlag)
        {
            printf("%0.2f", operatorTwo);
        }
        printf("\n3.- Calcular Operaciones:\n");
        printf("4.- Mostrar resultado:\n");
        printf("5.- Salir:\n");
        printf("Su option : ");
        if(!scanf("%d", &option))
        {
            option = 0;
        }
        __fpurge(stdin);

        switch(option)
        {
        case 1:

            ingresarNumero("Ingrese el operador numero uno: ", &operatorOne);
            printf("El operador uno ahora es : %0.2f\n", operatorOne);
            operatorOneFlag = ACTIVE;
            calculosFlag = INACTIVE;
            break;
        case 2:
            ingresarNumero("Ingrese el operator numero Two: ", &operatorTwo);
            printf("El operator Two ahora es : %0.2f\n", operatorTwo);
            operatorTwoFlag = ACTIVE;
            calculosFlag = INACTIVE;
            break;
        case 3:
            if(operatorOneFlag && operatorTwoFlag)
            {
                resultSum = suma(operatorOne,operatorTwo);
                resultResta = resta(operatorOne,operatorTwo);
                resultMultiplicacion = multiplicacion(operatorOne,operatorTwo);
                if(transformarFlotatanteEntero(operatorOne) && operatorOne >= 0)
                {
                    resultFactorialOne = factorial((int)operatorOne);
                    factorialOneFlag = ACTIVE;
                }
                if(transformarFlotatanteEntero(operatorTwo)&& operatorTwo >= 0)
                {
                    resultFactorialTwo = factorial((int)operatorTwo);
                    factorialTwoFlag = ACTIVE;
                }
                if(operatorTwo)
                {
                    resultDivision = division(operatorOne, operatorTwo);
                    divisionCeroFlag = ACTIVE;
                }
                calculosFlag = ACTIVE;
            }
            else
            {
                printf("ERROR: Ingrese los operadores con las dos primeras opciones\n");
            }
            break;
        case 4:
            if(calculosFlag)
            {
                printf("El resultado de (%0.2f)+(%0.2f) es: %0.2f\n", operatorOne, operatorTwo, resultSum);
                printf("El resultado de (%0.2f)-(%0.2f) es: %0.2f\n", operatorOne, operatorTwo, resultResta);
                if(divisionCeroFlag)
                {
                    printf("El resultado de (%0.2f)/(%0.2f) es: %0.2f\n", operatorOne, operatorTwo, resultDivision);
                }
                else
                {
                    printf("El resultado de (%0.2f)/(%0.2f): No es posible dividir por cero\n", operatorOne, operatorTwo);
                }
                printf("El resultado de (%0.2f)*(%0.2f) es: %0.2f\n", operatorOne, operatorTwo, resultMultiplicacion);
                if(factorialOneFlag)
                {
                    printf("Factorial del Primer operador: (%.0f)! = %lld y ", operatorOne, resultFactorialOne);
                }
                else
                {
                    printf("Factorial del Primer operador: (%0.2f)! = El numero debe ser Natural para calcular factorial y ", operatorTwo);
                }
                if(factorialTwoFlag)
                {
                    printf("el factorial del Segundo operador: (%.0f)! = %lld\n", operatorTwo, resultFactorialTwo);
                }
                else
                {
                    printf("el factorial del Segundo operador: (%.0f)! = El numero debe ser Natural para calcular factorial\n", operatorTwo);
                }
            }
            else
            {
                printf("ERROR: Para mostrar los resultado se requiere calcular(opcion 3)...\n");
            }
            break;
        case 5:
            printf("HASTA LUEGO!!\n");
            break;
        default:
            printf("No ingreso una option valida\n");
            break;
        }
        __fpurge(stdin);
        printf("pulse ENTER para continuar");
        getchar();
        clear();
    }
    while(option != 5);


    return 0;

}
