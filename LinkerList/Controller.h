#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#define PAGE_SIZE 30
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_getNextID(LinkedList* pArrayListEmployee);

Employee* controller_findEmployeeByID(LinkedList* pArrayListEmployee);

LinkedList* controller_printListSubMenu(LinkedList* pArrayListEmployee, int len, int from, int actualPage);

int controller_inputEmployeeName(Employee*);
int controller_inputEmployeeSalary(Employee*);
int controller_inputEmployeeWorkHours(Employee*);

int controller_printList(LinkedList* pArrayListEmployee);
int controller_previusListPage(int*, int*, int);

int controller_nextListPage(int* page, int* startIndex, int length);
int controller_goToListPage(int* page, int* startIndex, int length);

int controller_editEmployeeMenu(Employee* oldEmployee);


int controller_deleteEmployee(LinkedList* pArrayListEmployee, Employee* target);

int controller_deleteListEmployee(LinkedList* pArrayListEmployee);

int controller_selectSortCriteria(LinkedList* pArrayListEmployee);

int controller_sortTypeOfOrder(void);
