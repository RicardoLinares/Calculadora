#include "Controller.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    char idAux[100];
    char nameAux[TAMANIO_NOMBRE];
    char workHoursAux[100];
    char salaryAux[100];
    Employee* empleadoAux;
    pArchivo = fopen(path,"r");
    int i = -1;
    while(!feof(pArchivo))
    {

        fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux, salaryAux,workHoursAux);
        if(i != -1)
        {
            empleadoAux = employee_newParametros(idAux,nameAux,workHoursAux,salaryAux);
            if(empleadoAux != NULL)
            {
                ll_add(pArrayListEmployee, empleadoAux);
            }
            else
            {
                printf("\n ERROR: SE ENCONTRO UN ELEMNTO INCOMPATIBLE\n");
                ll_clear(pArrayListEmployee);
                i = 0;
                break;
            }
        }
        i++;
    }
    fclose(pArchivo);

    return i;
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
    int estado;
    FILE* pArchivo;
    Employee* empleadoAux;
    pArchivo = fopen(path,"rb");
    if(pArchivo != NULL)
    {

        empleadoAux = employee_new();
        fread(empleadoAux,sizeof(Employee),10000,pArchivo);
        if(empleadoAux != NULL)
        {
            ll_add(pArrayListEmployee, empleadoAux);
        }
        else
        {
            printf("\n ERROR AL AÑADIR UN ELEMNTO EMPLOYEE\n");
        }
        estado = 0;
        fclose(pArchivo);
    }

    return estado;
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
    int estado = -1;
    Employee* newEmployee;
    int idAux;
    // pasar mas tarde a otra funcion
    if(pArrayListEmployee != NULL)
    {
        newEmployee = employee_new();

        controller_inputEmployeeName(newEmployee);

        controller_inputEmployeeSalary(newEmployee);

        controller_inputEmployeeWorkHours(newEmployee);

        idAux = controller_getNextID(pArrayListEmployee);
        employee_setId(newEmployee,idAux);


        if(ll_add(pArrayListEmployee,newEmployee))
        {
            printf("El empleado no se pudo agregar a la lista");
        }
        else
        {
            estado = 0;
        }
    }

    return estado;
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
    int estado = -1;
    Employee* targetEmployee;
    LinkedList* subLista;
    int subListaInicio = 0;
    int subListaFin;
    int subListaLen;
    int len;
    char option = 's';
    int pagina = 0;
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            do
            {
                if(len < subListaInicio + 30)
                {
                    subListaFin = len;
                }
                else
                {
                    subListaFin = subListaInicio + 30;
                }
                subLista = ll_subList(pArrayListEmployee,subListaInicio,subListaFin);
                subListaLen = ll_len(subLista);
                printf("Lista de empleados: Pagina %d de %d\n",pagina + 1, 1+(len / 30));
                printf("A)Pagina Anterior: D) Pagina Siguiente: W)Ir a pagina: S) Salir\n");
                printf("E) Ingresar el Id de el empleado a modificar: \n");
                controller_printList(subLista, subListaLen);
                ll_deleteLinkedList(subLista);

                fflush(stdin);
                option = getche();
                option = tolower(option);
                switch(option)
                {
                case 'a':
                    controller_previusListPage(&pagina,&subListaInicio,len);
                    break;
                case 'd':
                    controller_nextListPage(&pagina,&subListaInicio,len);
                    break;
                case 'w':
                    controller_goToListPage(&pagina,&subListaInicio,len);
                    break;
                case 'e':
                    targetEmployee = controller_findEmployeeByID(pArrayListEmployee);

                    break;
                default:
                    break;
                }
                system("cls");

            }
            while(option != 's');
            estado = 0;
        }
    }
    return estado;
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
    int estado = -1;
    Employee* targetEmployee;
    LinkedList* subLista;
    int empleadoEliminadoFlag;
    int subListaInicio = 0;
    int subListaFin;
    int subListaLen;
    int len;
    char option = 's';
    int pagina = 0;
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            do
            {
                if(len < subListaInicio + 30)
                {
                    subListaFin = len;
                }
                else
                {
                    subListaFin = subListaInicio + 30;
                }
                subLista = ll_subList(pArrayListEmployee,subListaInicio,subListaFin);
                subListaLen = ll_len(subLista);
                printf("Lista de empleados: Pagina %d de %d\n",pagina + 1, 1+(len / 30));
                printf("A)Pagina Anterior: D) Pagina Siguiente: W)Ir a pagina: S) Salir\n");
                printf("E) Ingresar el Id de el empleado a eleminar: \n");
                controller_printList(subLista, subListaLen);
                ll_deleteLinkedList(subLista);

                fflush(stdin);
                option = getche();
                option = tolower(option);
                switch(option)
                {
                case 'a':
                    controller_previusListPage(&pagina,&subListaInicio,len);
                    break;
                case 'd':
                    controller_nextListPage(&pagina,&subListaInicio,len);
                    break;
                case 'w':
                    controller_goToListPage(&pagina,&subListaInicio,len);
                    break;
                case 'e':
                    targetEmployee = controller_findEmployeeByID(pArrayListEmployee);
                     empleadoEliminadoFlag = controller_deleteEmployee(pArrayListEmployee,targetEmployee);
                    if(empleadoEliminadoFlag == 0)
                    {
                        len = ll_len(pArrayListEmployee);
                        if(pagina*PAGE_SIZE >= len)
                        {
                            pagina--;
                            subListaInicio -= PAGE_SIZE;
                        }
                    }
                    break;
                default:
                    break;
                }
                system("cls");

            }
            while(option != 's');
            estado = 0;
        }
    }
    return estado;
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
    int estado = -1;
    LinkedList* subLista;
    int subListaInicio = 0;
    int subListaFin;
    int subListaLen;
    int len;
    char option = 's';
    int pagina = 0;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            do
            {
                if(len < subListaInicio + 30)
                {
                    subListaFin = len;
                }
                else
                {
                    subListaFin = subListaInicio + 30;
                }
                subLista = ll_subList(pArrayListEmployee,subListaInicio,subListaFin);
                subListaLen = ll_len(subLista);
                printf("Lista de empleados: Pagina %d de %d\n",pagina + 1, 1+(len / 30));
                printf("A)Pagina Anterior: D) Pagina Siguiente: W)Ir a pagina: S) Salir\n");
                controller_printList(subLista, subListaLen);
                ll_deleteLinkedList(subLista);

                fflush(stdin);
                option = getche();
                option = tolower(option);
                switch(option)
                {
                case 'a':
                    controller_previusListPage(&pagina,&subListaInicio,len);
                    break;
                case 'd':
                    controller_nextListPage(&pagina,&subListaInicio,len);
                    break;
                case 'w':
                    controller_goToListPage(&pagina,&subListaInicio,len);
                    break;
                default:
                    break;
                }
                system("cls");

            }
            while(option != 's');
            estado = 0;
        }
    }
    return estado;
}

int controller_printList(LinkedList* pArrayListEmployee, int elements)
{
    int i;
    Employee* pEmpleadoAux;
    if(pArrayListEmployee != NULL && elements > 0)
    {
        printf("%5s %20s %10s %12s","ID", "NOMBRE", "SUELDO", "HORAS TRABAJADAS\n");
        for(i=0; i < elements; i++)
        {
            pEmpleadoAux = ll_get(pArrayListEmployee, i);
            employee_print(pEmpleadoAux);
        }/**/

    }
    return i;
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
    int estado = -1;
    FILE* pArchivo;
    Employee* empleadoAux;
    int i;
    int listLen;
    int* idAux;
    char* nameAux;
    int* sueldoAux;
    int* horasAux;
    if(pArrayListEmployee != NULL && path != NULL)
    {
        idAux = malloc(sizeof(int));
        nameAux = malloc(sizeof(char)*TAMANIO_NOMBRE);
        sueldoAux = malloc(sizeof(int));
        horasAux = malloc(sizeof(int));

        pArchivo = fopen(path,"w");
        listLen = ll_len(pArrayListEmployee);
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i<listLen; i++)
        {
            empleadoAux = ll_get(pArrayListEmployee,i);
            employee_getId(empleadoAux,idAux);
            employee_getSueldo(empleadoAux,sueldoAux);
            nameAux = employee_getNombre(empleadoAux);
            employee_getHorasTrabajadas(empleadoAux,horasAux);
            fprintf(pArchivo,"%d,%s,%d,%d\n",*idAux,nameAux,*sueldoAux,*horasAux);
        }

        fclose(pArchivo);
    }
    return estado;
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
    int estado = -1;
    FILE* pArchivo;
    Employee* empleadoAux;
    int i;
    int listLen;
    if(pArrayListEmployee != NULL && path != NULL)
    {

        pArchivo = fopen(path,"wb");
        listLen = ll_len(pArrayListEmployee);
        empleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
        fwrite(pArrayListEmployee, sizeof(LinkedList),1,pArchivo);

        fclose(pArchivo);
    }
    return estado;
}


int controller_inputEmployeeName(Employee* empleado)
{
    int estado = -1;
    char nombre[TAMANIO_NOMBRE];
    int errorFlag = 0;
    int length;
    if(empleado != NULL)
    {
        printf("Ingrese el Nombre del Empleado: ");
        do
        {
            if(errorFlag != 0)
            {
                printf("ERROR: Reingrese el Nombre del Empleado: ");
            }
            fflush(stdin);
            fgets(nombre,TAMANIO_NOMBRE,stdin);
            length = strlen(nombre);
            if(nombre[length - 1] == '\n')
            {
                nombre[length - 1] = '\0';
            }
            errorFlag = employee_setNombre(empleado, nombre);
            system("cls");
        }
        while(errorFlag != 0);
        estado = 0;
    }
    return estado;
}


int controller_inputEmployeeSalary(Employee* empleado)
{
    int estado = -1;
    int sueldo;
    int errorFlag = 0;
    if(empleado != NULL)
    {
        printf("Ingrese el Sueldo del Empleado: ");
        do
        {
            if(errorFlag != 0)
            {
                printf("ERROR reingrese el Sueldo del Empleado: ");
            }
            fflush(stdin);
            if(scanf("%d", &sueldo))
            {
                errorFlag = employee_setSueldo(empleado, sueldo);
            }
            else
            {
                errorFlag = -1;
            }
            system("cls");
        }
        while(errorFlag != 0);
    }
    return estado;
}

int controller_inputEmployeeWorkHours(Employee* empleado)
{
    int estado = -1;
    int horas;
    int errorFlag = 0;
    if(empleado != NULL)
    {
        printf("Ingrese la Horas trabajadas por el Empleado: ");
        do
        {
            if(errorFlag != 0)
            {
                printf("ERROR: reingrese la Horas trabajadas por el Empleado: ");
            }
            fflush(stdin);
            if(scanf("%d", &horas))
            {
                errorFlag = employee_setHorasTrabajadas(empleado, horas);
            }
            else
            {
                errorFlag = -1;
            }
            system("cls");
        }
        while(errorFlag != 0);
    }
    return estado;
}
int controller_getNextID(LinkedList* pArrayListEmployee)
{
    int id = -2;
    int auxiliar;
    Employee* employeeAux;
    int listLen;
    int i;

    if(pArrayListEmployee != NULL)
    {
        listLen = ll_len(pArrayListEmployee);
        if(listLen > 0)
        {
            for(i = 0; i<listLen; i++)
            {
                employeeAux = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(employeeAux,&auxiliar);
                if(auxiliar > id)
                {

                    id = auxiliar;
                }
            }
            id++;

        }
        else
        {
            id = 1;
        }

    }
    return id;
}

int controller_previusListPage(int* page, int* startIndex, int length)
{
    int estado = -1;
    if(page != NULL && startIndex != NULL)
    {
        if(*page != 0)
        {
            *startIndex -= PAGE_SIZE;
            *page -= 1;
        }
        else
        {
            *startIndex = PAGE_SIZE * (length/PAGE_SIZE);
            *page = (length/PAGE_SIZE);
        }
        estado = 0;
    }
    return estado;
}

int controller_nextListPage(int* page, int* startIndex, int length)
{
    int estado = -1;
    if(page != NULL && startIndex != NULL)
    {
        if(*page != length/PAGE_SIZE)
        {
            *startIndex += PAGE_SIZE;
            *page += 1;
        }
        else
        {
            *startIndex = 0;
            *page = 0;
        }
        estado = 0;
    }
    return estado;
}

int controller_goToListPage(int* page, int* startIndex, int length)
{
    int estado = -1;
    int auxiliar;
    if(page != NULL && startIndex != NULL)
    {
        printf(") Indique la pagina donde quiere ir: ");
        scanf("%d", &auxiliar);
        if(auxiliar > 0 && auxiliar <= (length/PAGE_SIZE)+1)
        {
            *page = auxiliar - 1;
            *startIndex = (auxiliar - 1) * PAGE_SIZE;
        }
        estado = 0;
    }
    return estado;
}

Employee* controller_findEmployeeByID(LinkedList* pArrayListEmployee)
{
    Employee* employee = NULL;
    Employee* employeeAuxliar;
    int id;
    int idAuxiliar;
    int i;
    int listLength;
    if(pArrayListEmployee != NULL)
    {
        printf(") Ingrese el Id del empleado: ");
        if(scanf("%d", &id))
        {
            listLength = ll_len(pArrayListEmployee);
            for(i=0; i<listLength; i++)
            {
                employeeAuxliar = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(employeeAuxliar,&idAuxiliar);
                if(id == idAuxiliar)
                {
                    employee = employeeAuxliar;
                    break;
                }
            }
        }
    }

    return employee;
}


int controller_editEmployeeMenu(Employee* oldEmployee)
{
    Employee* newEmployee;
    char option;
    int salir = -1;

    if(oldEmployee != NULL)
    {

        *newEmployee = *oldEmployee;
        do
        {
            printf("Empleado Original: ");
            printf("%5s %20s %10s %12s","ID", "NOMBRE", "SUELDO", "HORAS TRABAJADAS\n");
            employee_print(oldEmployee);
            printf("Empleado Editado: ");
            printf("%5s %20s %10s %12s","ID", "NOMBRE", "SUELDO", "HORAS TRABAJADAS\n");

            employee_print(newEmployee);

            printf("A) Cambiar Nombre.");
            printf("D) Cambiar Sueldo.");
            printf("W) Cambiar Horas Trabajadas.");
            printf("S) Guardar Y Salir.");
            printf("C) Cancelar Cambios.");

            fflush(stdin);
            option = getche();
            option = tolower(option);
            switch(option)
            {
            case 'a':
                controller_inputEmployeeName(newEmployee);
                break;
            case 'd':
                controller_inputEmployeeSalary(newEmployee);
                break;
            case 'w':
                controller_inputEmployeeWorkHours(newEmployee);
                break;
            case 's':
                printf("Cambios Guardados");
                *oldEmployee = *newEmployee;
                salir = 0;
                break;
            case 'q':
                printf("Modificacion Cancelada");
                salir = 0;
                break;
            }
        }while(salir != 0);

        free(oldEmployee);
    }
}

int controller_deleteEmployee(LinkedList* pArrayListEmployee, Employee* target)
{
    int estado = -1;
    char* buffer;
    int lastChar;
    int id;
    int errorFlag;
    if(pArrayListEmployee != NULL && target != NULL)
    {
        system("cls");
        buffer = (char*) malloc(sizeof(char)* 1024);
        do
        {
            errorFlag = 0;
            printf("%5s %20s %10s %12s","ID", "NOMBRE", "SUELDO", "HORAS TRABAJADAS\n");
            employee_print(target);

            printf("\nESTAS SEGURO QUE QUIERES ELIMINAR AL EMPLEADO.\n");
            printf("toda su informacion se borrara del sistema(SI/NO): ");
            fflush(stdin);
            fgets(buffer,1024, stdin);
            lastChar = strcspn(buffer, "\n");
            *(buffer + lastChar) = 0;
            if(!stricmp(buffer, "SI"))
            {
                id = ll_indexOf(pArrayListEmployee,target);
                if(!ll_remove(pArrayListEmployee,id))
                {
                    printf("Empleado Eliminado...");
                    estado = 0;
                }
                else
                {
                    printf("Hubo un Error al borrar el empleado...");
                }
            }
            else if(!stricmp(buffer, "NO"))
            {
                printf("Eliminacion Cancelada...");
            }
            else
            {
                errorFlag = -1;
            }
            getche();
            system("cls");
        }
        while(errorFlag != 0);
        free(buffer);
    }
    return estado;
}
