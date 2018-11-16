#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define LISTA_EMPLEADOS 1000
int main()
{
    int index;

    Employee list[LISTA_EMPLEADOS];

    initEmployees(list, LISTA_EMPLEADOS);

    addEmployee(list, LISTA_EMPLEADOS, getNextID(list,LISTA_EMPLEADOS), "ALFONSO", "MEDINA", 111,4);
    addEmployee(list, LISTA_EMPLEADOS, getNextID(list,LISTA_EMPLEADOS), "CASTOR", "VIENA",233,4);

    DeleteEmployee(list,LISTA_EMPLEADOS);

    printEmployees(list,LISTA_EMPLEADOS);

    return 0;
}
