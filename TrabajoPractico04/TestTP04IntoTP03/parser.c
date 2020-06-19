#include "parser.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	int status = ERROR;
	int hasHeader = HAS_HEADER;
	int result = 0;
	char auxId[SIZE_CHAR_ARRAY], auxNombre[SIZE_CHAR_ARRAY],auxHorasTrabajadas[SIZE_CHAR_ARRAY], auxSueldo[SIZE_CHAR_ARRAY];
	Employee *newEmployee;
	if (pFile != NULL && pArrayListEmployee != NULL) {
		if (pFile != NULL) {
			status = OK;
			while (!feof(pFile)) {
				if(hasHeader){
					hasHeader = 0;
					fscanf(pFile, DATA_FORMAT, auxId, auxNombre,auxHorasTrabajadas, auxSueldo);
				}else{
					result =  fscanf(pFile, DATA_FORMAT, auxId, auxNombre,auxHorasTrabajadas, auxSueldo);
					if (result == 4) {
						newEmployee = employee_newParametros(auxId, auxNombre,auxHorasTrabajadas, auxSueldo);
						if (newEmployee != NULL) {
							ll_add(pArrayListEmployee, newEmployee);
						}
					}
				}
			}
			fclose(pFile);
		}
	}
	return status;
}

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee, int existFile) {
	int hasHeader = HAS_HEADER;
	int status = ERROR;
	int result = 0;
	char auxId[SIZE_CHAR_ARRAY], auxNombre[SIZE_CHAR_ARRAY],auxHorasTrabajadas[SIZE_CHAR_ARRAY], auxSueldo[SIZE_CHAR_ARRAY];
	Employee currentEmployee;
	Employee *newEmployee;

	if(!existFile){
		//Primero leo el archivo en texto y lo guardo en binario y leo binario
		FILE *pFileText;
		pFileText = fopen(SOURCE_DATA, "r");
		if (pFile != NULL && pArrayListEmployee != NULL && pFileText != NULL) {
			status = OK;
			while (!feof(pFile) && !feof(pFileText)) {
				if (hasHeader) {
					hasHeader = 0;
					result = fscanf(pFileText, DATA_FORMAT, auxId, auxNombre,auxHorasTrabajadas, auxSueldo);
				} else {
					result = fscanf(pFileText, DATA_FORMAT, auxId, auxNombre,auxHorasTrabajadas, auxSueldo);
					currentEmployee.id = atoi(auxId);
					strcpy(currentEmployee.nombre, auxNombre);
					currentEmployee.horasTrabajadas = atoi(auxHorasTrabajadas);
					currentEmployee.sueldo = atoi(auxSueldo);
					if (result == 4) {
						fseek(pFile, 0L, SEEK_END);
						fwrite(&currentEmployee, sizeof(currentEmployee), 1, pFile);
					}
				}
			}
			fclose(pFileText);
			fclose(pFile);
			pFile = fopen(SOURCE_DATA_BIN, "rb");
		}

		while (!feof(pFile)) {
			result = fread(&currentEmployee, sizeof(currentEmployee), 1, pFile);
			if (result == 1) {
				newEmployee = employee_new();
				employee_setId(newEmployee,currentEmployee.id);
				employee_setNombre(newEmployee,currentEmployee.nombre);
				employee_setHorasTrabajadas(newEmployee,currentEmployee.horasTrabajadas);
				employee_setSueldo(newEmployee,currentEmployee.sueldo);
				if (newEmployee != NULL) {
					ll_add(pArrayListEmployee, newEmployee);
				}
			}
		}
		fclose(pFile);
	}
	return status;
}
