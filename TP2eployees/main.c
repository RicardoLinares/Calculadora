#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "menuSystem.h"

#define LISTA_EMPLEADOS 1000
int main()
{
    Employee listaEmpleados[LISTA_EMPLEADOS];
    int opcion;
    int employees;
    int proceso;

    initEmployees(listaEmpleados, LISTA_EMPLEADOS);
    do
    {
        employees = getExistingEmployees(listaEmpleados,LISTA_EMPLEADOS);
        printf("Lista de Empleado: \n");
        printListStrings(5, "ALTA", "MODIFICAR", "BAJA", "INFORMAR", "SALIR");
        opcion = waitsForMenuInput(5,"Eliga su opcion: ");
        switch(opcion)
        {
        case 0:
            proceso = inputEmployee(listaEmpleados, LISTA_EMPLEADOS);
            break;
        case 1:
            if(employees > 0)
            {
                ModifyEmployee(listaEmpleados, LISTA_EMPLEADOS);
            }
            break;
        case 2:
            if(employees > 0)
            {
                proceso = DeleteEmployee(listaEmpleados, LISTA_EMPLEADOS);
            }
            break;
        case 3:
            if(employees > 0)
            {
                informMenuEmployee(listaEmpleados,LISTA_EMPLEADOS);
            }
            break;
        case 4:
            printf("adios");
            break;
        }
        clearConsole();
    }
    while(opcion != 4);
    return 0;
}
