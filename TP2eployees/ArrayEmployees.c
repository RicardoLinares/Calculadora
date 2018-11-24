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
            estado = 0;
        }
    }

    return estado;
}

int inputEmployee(Employee* list, int len)
{
    int returnAux = -1;
    int proceso;
    int id;
    int sector;
    float salary;
    char name[NAMES];
    char lastName[NAMES];
    if(list != NULL && len > 0)
    {
        system("cls");
        inputNamesEmployee(name, NAMES, "Ingrese el Nombre(Minimo 3 Caracteres): ");
        inputNamesEmployee(lastName, NAMES, "Ingrese el Apellido(Minimo 3 Caracteres): ");
        id = getNextID(list, len);
        sector = inputSectorEmployee();
        salary = inputSalaryEmployee();

        proceso = addEmployee(list, len, id, name, lastName, salary, sector);
        if(proceso == 0)
        {
            returnAux = 0;
        }
        else
        {
            printf("ERROR: No se pudo agregar el empleado...");
        }
    }
    return returnAux;
}

int inputSectorEmployee(void)
{
    int sector = -1;
    int errorFlag = 0;
    do
    {
        if(errorFlag == 1)
        {
            printf("ERROR: solo se permiten numeros naturales...\n");
        }
        printf("Ingrese el Sector: ");
        fflush(stdin);
        if(!(scanf("%d",&sector)))
        {
            errorFlag = 1;
        }
        system("cls");
    }
    while(sector <= 0);

    return sector;
}

int inputNamesEmployee(char nameString[], int size, char mensaje[])
{
    int returnValue = -1;
    int errorCont;
    if(nameString != NULL && size > 0 )
    {
        do
        {
            errorCont = 0;
            fflush(stdin);
            printf("%s", mensaje);
            fgets(nameString, size, stdin);
            errorCont += validateFormatName(nameString, size);
            errorCont += nameCapitalization(nameString, size);
            system("cls");
            if(errorCont == -1)
            {
                printf("ERROR: Solo se permiten letras del abecedario...\n");
            }
            else if(errorCont == -2)
            {
                printf("ERROR: variable NULL abortando funcion\n");
                break;
            }
        }
        while(errorCont < 0);
    }


    return returnValue;
}

int validateFormatName(char nameString[], int size)
{
    int returnValue = -1;
    int errorFlag = 0;
    int i;
    if(nameString != NULL && size > 0)
    {
        for(i=0; i<size; i++)
        {
            if(nameString[i] == '\n')
            {
                nameString[i] = '\0';
                break;
            }
            if(isalpha(nameString[i]) == 0)
            {
                if(isspace(nameString[i]) && i != 0)
                {
                    continue;
                }
                else
                {
                    errorFlag = 1;
                    printf("\n%c break;", nameString[i]);
                    break;
                }
            }
        }
        if(i >= 3 && errorFlag == 0)
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

int nameCapitalization(char origin[], int len)
{
    int returnAux = -1;
    int firstLetterFlag = 1;
    int index;
    if(origin != NULL)
    {
        for(index = 0; index < len && origin[index] != '\0'; index++)
        {
            if(origin[index] == ' ' && firstLetterFlag == 1)
            {
                continue;
            }
            if(origin[index] == ' ')
            {
                firstLetterFlag = 1;
            }
            else if(firstLetterFlag)
            {
                origin[index] = toupper(origin[index]);
                firstLetterFlag = 0;
            }
            else
            {
                origin[index] = tolower(origin[index]);
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

float inputSalaryEmployee(void)
{
    char buffer[BUFSIZ];
    float salary = -1;
    int errorFlag = 0;
    do
    {
        if(errorFlag == 1)
        {
            printf("ERROR: tiene que ingresar un numero decimal positivo para el sueldo...\n");
        }
        printf("Ingrese el Sueldo: ");
        fflush(stdin);
        fgets(buffer,BUFSIZ,stdin);
        salary = atof(buffer);
        if(salary <= 0)
        {
            errorFlag = 1;
        }
        system("cls");
    }
    while(salary <= 0);

    return salary;
}


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


/** \brief asks the if of an employee to remove
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
    int id = -1;
    int process;
    if(list != NULL && len > 0)
    {
        system("cls");
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
                printf("No se elimino el empleado...\n");
            }
        }
        else
        {
            printf("Id invalido...");
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

int ModifyEmployee(Employee* list, int len)
{
    int returnAux = -1;
    int id = -1;
    int process;
    if(list != NULL && len > 0)
    {
        system("cls");
        printEmployees(list, len);
        printf("Ingrese el Id del empleado a Modificar: ");
        scanf("%d", &id);
        if(id > 0)
        {
            process = ModifyMenuEmployee(list, len, id);
            if(process == 0)
            {
                returnAux = 0;
            }
            else
            {
                printf("no se modifico el empleado...\n");
            }
        }
        else
        {
            printf("Id invalido...");
        }

    }
    return returnAux;
}
int ModifyMenuEmployee(Employee list[], int len, int id)
{
    int returnAux = -1;
    int opcion;
    int elemento;
    Employee auxliar;
    if(list != NULL && len > 0)
    {
        elemento = findEmployeeById(list,len,id);
        if(elemento != -1)
        {
            auxliar = list[elemento];
            if(auxliar.isEmpty != TRUE)
            {
                system("cls");
                do
                {
                    printEmployee(&auxliar);
                    printf("Eliga que modificar: \n");
                    printListStrings(6, "Nombre", "Apellido", "Sector", "Salario", "Guardar Y Salir",
                                     "Salir sin Guardar");
                    opcion = waitsForMenuInput(6,"Eliga su opcion: ");
                    switch(opcion)
                    {
                    case 0:
                        inputNamesEmployee(auxliar.name,NAMES,"Ingrese el nuevo nombre : ");
                        break;
                    case 1:
                        inputNamesEmployee(auxliar.lastName,NAMES,"Ingrese el nuevo apellido : ");
                        break;
                    case 2:
                        auxliar.sector = inputSectorEmployee();
                        break;
                    case 3:
                        auxliar.salary = inputSalaryEmployee();
                        break;
                    case 4:
                        list[elemento] = auxliar;
                        returnAux = 0;
                        break;
                    case 5:
                        printf("Modificacion Cancelada");
                        break;
                    }
                    clearConsole();
                }
                while(opcion != 4 && opcion != 5);
            }
        }

    }
    return returnAux;
}

int informMenuEmployee(Employee list[], int len)
{
    int returnAux = -1;
    int opcion;
    int orden;
    int proceso;
    if(list != NULL && len > 0)
    {
        system("cls");
        printf("Eliga que modificar: \n");
        printListStrings(3, " Listado de los empleados ordenados alfabeticamente por Apellido y Sector.",
                         "Total y promedio de los salarios, y cuantos empleados superan el salario promedio.",
                         "Cancelar");
        opcion = waitsForMenuInput(6,"Eliga su opcion: ");
        switch(opcion)
        {
        case 0:
            printf("Orden Acendente(1) o decendiente(0)? : ");
            scanf("%d", &orden);
            proceso = sortEmployees(list,len,orden);
            printEmployees(list,len);
            break;
        case 1:
            printSalaryStatsEmployee(list,len);
            break;
        case 2:
            printf("Volviendo al menu...");
            break;
        default:
            printf("No eligio una opcion valida");
        }

    }
    return returnAux;
}
int sortEmployees(Employee* list, int len, int order)
{
    int returnAux = -1;
    int i;
    int j;
    Employee auxiliar;
    if(list != NULL && len > 1)
    {
        for(i = 0; i < len - 1; i++)
        {
            if(list[i].isEmpty != TRUE)
            {
                for(j = i + 1; j < len; j++)
                {
                    if(list[j].isEmpty != TRUE)
                    {
                        if(list[i].sector > list[j].sector)
                        {
                            if(order == 1)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                        }
                        else if(list[i].sector != list[j].sector)
                        {
                            if(order == 0)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                        }
                    }
                }
            }
        }
        for(i = 0; i < len - 1; i++)
        {
            if(list[i].isEmpty != TRUE)
            {
                for(j = i + 1; j < len; j++)
                {
                    if(list[j].isEmpty != TRUE && list[i].sector == list[j].sector)
                    {
                        if(strcmp(list[i].name, list[j].name) == 1)
                        {
                            if(order == 1)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                        }
                        else if(strcmp(list[i].name, list[j].name) != 0)
                        {
                            if(order == 0)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                        }
                    }
                }
            }
        }

        returnAux = 0;
    }
    return returnAux;
}

int printSalaryStatsEmployee(Employee list[], int len)
{
    int returnAuxiliar = -1;
    int i;
    Employee auxiliar;
    int salaryTotal = 0;
    int contEmployee = 0;
    int contAboveAvergeSalary = 0;
    int avergeSalary;
    if( list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            auxiliar = list[i];
            if(auxiliar.isEmpty != TRUE)
            {
                contEmployee++;
                salaryTotal += auxiliar.salary;
            }
        }

        avergeSalary = salaryTotal / contEmployee;
        for(i=0; i<len; i++)
        {
            auxiliar = list[i];
            if(auxiliar.isEmpty != TRUE)
            {
                if(avergeSalary < auxiliar.salary)
                {
                    contAboveAvergeSalary++;
                }
            }
        }

        printf("Total de los salarios: %d $\n", salaryTotal);
        printf("Promedio de los salarios: %d $\n", avergeSalary);
        printf("Empleados que supera en salario promedio: %d empleados\n", contAboveAvergeSalary);
        returnAuxiliar = 0;
    }
    return returnAuxiliar;
}

int getExistingEmployees(Employee list[], int len)
{
    int retorno = -1;
    int contEmployee = 0;
    int i;
    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != TRUE)
            {
                contEmployee++;
            }
        }
        retorno = contEmployee;
    }
    return retorno;
}
