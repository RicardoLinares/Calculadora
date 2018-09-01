#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "math.h"

#define clear(); printf("\033[H\033[J") // para linux
int main()
{

    int opcion = 6;
    int operandoDos;
    int operandoUno;
    int resultado;
    printf("CALCULADORA, ingrese su opcion:\n");

    ingresarNumero(&operandoUno);
    ingresarNumero(&operandoDos);


    do
    {
        printf("eliga la operacion para %d y %d:\n", operandoUno, operandoDos);
        __fpurge(stdin);
        printf("1.- Sumar: %d + %d\n", operandoUno, operandoDos);
        printf("2.- Restar: %d - %d\n", operandoUno, operandoDos);
        printf("3.- Multiplicar: %d * %d\n", operandoUno, operandoDos);
        printf("4.- Dividir: %d / %d\n", operandoUno, operandoDos);
        printf("5.- Factorial: %d! y %d!\n", operandoUno, operandoDos);
        printf("6.- Salir:\n");
        printf("Su Opcion : ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            resultado = suma(operandoUno, operandoDos);
            break;
        case 2:
            resultado = resta(operandoUno, operandoDos);
            break;
        case 3:
            resultado = multiplicacion(operandoUno, operandoDos);
            break;
        case 4:
            resultado = division(operandoUno, operandoDos);
            break;
        case 5:
            factorial(operandoUno);
            factorial(operandoUno);
            break;
        case 6:
            printf("HASTA LUEGO!!\n");
            break;
        default:
            printf("No ingreso una Opcion valida\n");
            break;
        }
        __fpurge(stdin);
        printf("pulse ENTER para continuar", resultado);
        getchar();
        clear();
    }
    while(opcion != 6);


}
