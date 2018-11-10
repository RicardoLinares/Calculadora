#include "ArrayEmployees.h"



int initEmployees(Employee* list, int len)
{
    int returnValue = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
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



