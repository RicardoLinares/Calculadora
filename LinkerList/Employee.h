#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO_NOMBRE 128

typedef struct
{
    int id;
    char nombre[TAMANIO_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new(void);
Employee* employee_newParametros(char*,char*,char*, char*);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_print(Employee* this);


int employee_ordenSueldo(void* cajaA,void* cajaB);
int employee_ordenHoras(void* cajaA,void* cajaB);
int employee_ordenNombre(void* cajaA,void* cajaB);
#endif // employee_H_INCLUDED
