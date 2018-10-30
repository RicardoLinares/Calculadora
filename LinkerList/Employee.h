#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

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
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
