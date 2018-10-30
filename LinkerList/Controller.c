#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int estado;
    FILE* pArchivo;
    char* idAux = malloc(sizeof(char)*100);
    char* nameAux = malloc(sizeof(char)*TAMANIO_NOMBRE);
    char* workHoursAux = malloc(sizeof(char)*100);
    char* salaryAux = malloc(sizeof(char)*100);
    Employee* empleadoAux;
    pArchivo = fopen(path,"r");
    int i = -1;
    while(!feof(pArchivo))
    {

        fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux, workHoursAux,salaryAux);
        if(i != -1)
        {
            empleadoAux = employee_newParametros(idAux,nameAux,workHoursAux,salaryAux);
            if(empleadoAux != NULL)
            {
                ll_add(pArrayListEmployee, empleadoAux);
            }
            else
            {
                printf("\n ERROR AL AÑADIR UN ELEMNTO EMPLOYEE\n");
                break;
            }
        }
        i++;
    }

    estado = !feof(pArchivo);
    fclose(pArchivo);

    return estado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

