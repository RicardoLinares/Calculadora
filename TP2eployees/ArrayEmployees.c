#include "ArrayEmployees.h"



int initEmployees(Employee* list, int len)
{
    int returnValue = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            (list+i)->isEmpty = TRUE;
        }
    }
    return returnValue;
}

int getNextID(Employee* list, int len)
{
    int id = -1;
    int i;
    if(list != NULL && len > 0)
    {
        id = 1;
        for(i = 0; i < len; i++)
        {
            if((list+i)->isEmpty != TRUE)
            {
                id++;
            }
        }
    }
    return id;
}

int getFreeSpace(Employee* list, int len)
{
    int freeSpace = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if((list+i)->isEmpty == TRUE)
            {
                freeSpace = i;
                break;
            }
        }
    }
    return freeSpace;
}

int addEmployee(Employee* list, int len, int id, char name[],char
                lastName[],float salary,int sector)
{
    int estado = -1;
    int position;

    if(list != NULL && lastName != NULL && name != NULL)
    {
        position = getFreeSpace(list,len);
        if(position != -1)
        {
            (list+position)->id = id;
            (list+position)->salary = salary;
            (list+position)->sector = sector;
            strncpy((list+position)->name,name, NAMES);
            strncpy((list+position)->lastName,lastName, NAMES);
            (list+position)->isEmpty = FALSE;
        }
    }

    return estado;
}


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
    int returnAux = 0;
    int i;
    int process;
    if(list != NULL && length > 0)
    {
        printf("%3s %15s %15s %10s %5s\n", "ID","NOMBRE","APELLIDO"
               ,"SALARIO","SECTOR");
        for(i=0; i<length; i++)
        {
            if((list+i)->isEmpty == FALSE)
            {
                process = printEmployee(list+i);
                if(process != 0)
                {
                    returnAux = -1;
                    break;
                }
            }

        }
    }
    return returnAux;
}


int printEmployee(Employee* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        printf("%3d %15s %15s %10.2f %5d\n", this->id,this->name,this->lastName
               ,this->salary,this->sector);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
    int returnAux = -1;
    int i;
    if(list != NULL && len >= 0 && id > -1)
    {
        for(i=0; i<len ; i++)
        {
            if((list+i)->isEmpty == FALSE)
            {
                if((list+i)->id == id)
                {
                    returnAux = i;
                    break;
                }
            }
        }
    }


    return returnAux;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

int DeleteEmployee(Employee* list, int len)
{
    int returnAux = -1;
    int id;
    int process;
    if(list != NULL && len > 0)
    {
        printEmployees(list, len);
        printf("Ingrese el Id del empleado a eliminar: ");
        scanf("%d", &id);
        if(id > 0)
        {
            process = removeEmployee(list, len, id);
            if(process == 0)
            {
                printf("Se Elimino el empleado.\n");
                returnAux = 0;
            }
            else
            {
                printf("No se pudo eliminar el empleado...\n");
            }
        }

    }
    return returnAux;
}
int removeEmployee(Employee* list, int len, int id)
{
    int returnAux = -1;
    int elemento;
    char confirmacion;
    if(list != NULL && len > 0)
    {
        elemento = findEmployeeById(list,len,id);
        if(elemento != -1)
        {
            printf("Estas seguro de eliminar a este empleado (Y):");
            fflush(stdin);
            confirmacion = getchar();
            confirmacion = tolower(confirmacion);
            if(confirmacion == 'y')
            {
            (list+elemento)->isEmpty = TRUE;
            returnAux = 0;
            }
        }
    }
    return returnAux;
}
