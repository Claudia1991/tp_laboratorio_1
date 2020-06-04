#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn_inputs.h"
#include "utn_validators.h"
#include "defines.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_show(Employee* this);
void employee_GetDataForNewEmployee(char *nombre, char *horasTrabajadas,char *sueldo, int *statusNombre, int *statusHorasTrabajadas,int *statusSueldo);

#endif // employee_H_INCLUDED
