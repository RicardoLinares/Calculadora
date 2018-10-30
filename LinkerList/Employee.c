#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* newEmploye;

    newEmploye = (Employee*)malloc(sizeof(Employee));
    if(newEmploye != NULL)
    {
        newEmploye->horasTrabajadas = 0;
        newEmploye->sueldo = 0;
        newEmploye->id = 0;
        strcpy(newEmploye->nombre, " ");
    }
    return newEmploye;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmploye;
    int aux;
    int errorFlag;
    newEmploye = employee_new();
    if(newEmploye != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL
       && sueldoStr != NULL)
    {
        if(!employee_setNombre(newEmploye, nombreStr))
        {
            errorFlag = 1;
        }

        aux = atoi(sueldoStr);
        if(employee_setSueldo(newEmploye, aux))
        {
            errorFlag = 1;
        }

        aux = atoi(horasTrabajadasStr);
        if(employee_setHorasTrabajadas(newEmploye, aux))
        {
            errorFlag = 1;
        }
        aux = atoi(idStr);
        if(employee_setId(newEmploye, aux))
        {
            errorFlag = 1;
        }

        if(errorFlag == 1)
        {
            free(newEmploye);
            newEmploye = NULL;
        }
    }
    return newEmploye;
}
int employee_setId(Employee* this,int id)
{
    int estado = -1;
    if(this != NULL)
    {
        if(id > 0)
        {
           this->id = id;
           estado = 0;
        }
    }
    return estado;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int estado = -1;
    if(this != NULL)
    {
        if(sueldo > 0)
        {
           this->sueldo = sueldo;
           estado = 0;
        }
    }
    return estado;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int estado = -1;
    if(this != NULL)
    {
        if(horasTrabajadas >= 0)
        {
           this->horasTrabajadas = horasTrabajadas;
           estado = 0;
        }
    }
    return estado;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int estado = -1;
    int len;
    if(this != NULL && nombre != NULL)
    {
        len = strlen(nombre);
        if(len > 0 && len < TAMANIO_NOMBRE)
        {
            strcpy(this->nombre,nombre);
        }
    }
    return estado;
}
