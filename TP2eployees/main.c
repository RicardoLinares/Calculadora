#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define LISTA_EMPLEADOS 1000
int main()
{
    Employee list[LISTA_EMPLEADOS];

    initEmployees(list, LISTA_EMPLEADOS);

    return 0;
}
