#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int status = ERROR;
	int result =0;
	char auxId[SIZE_CHAR_ARRAY], auxNombre[SIZE_CHAR_ARRAY], auxHorasTrabajadas[SIZE_CHAR_ARRAY], auxSueldo[SIZE_CHAR_ARRAY];
	Employee *newEmployee;
	if(pFile != NULL && pArrayListEmployee != NULL){
		pFile = fopen(SOURCE_DATA, "r");
		if(pFile != NULL){
			status = OK;
			do{
				result = fscanf(pFile, DATA_FORMAT, auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
				if(result == 4){
					newEmployee =  employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
					if(newEmployee != NULL){
						ll_add(pArrayListEmployee, newEmployee);
					}
				}
			}while(!feof(pFile));
			fclose(pFile);
		}
	}
    return status;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int status = ERROR;
		int result =0;
		char auxId[SIZE_CHAR_ARRAY], auxNombre[SIZE_CHAR_ARRAY], auxHorasTrabajadas[SIZE_CHAR_ARRAY], auxSueldo[SIZE_CHAR_ARRAY];
		Employee *newEmployee;
		if(pFile != NULL && pArrayListEmployee != NULL){
			pFile = fopen(SOURCE_DATA, "rb");
			if(pFile != NULL){
				status = OK;
				do{
					result = fscanf(pFile, DATA_FORMAT, auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
					if(result == 4){
						newEmployee =  employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
						if(newEmployee != NULL){
							ll_add(pArrayListEmployee, newEmployee);
						}
					}
				}while(!feof(pFile));
				fclose(pFile);
			}
		}
	    return status;
}
