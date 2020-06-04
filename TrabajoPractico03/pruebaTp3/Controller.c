#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Menu.h"
#include "utn_inputs.h"
#include "LinkedList.h"
#include "Employee.h"

static void ListEmployees(LinkedList *pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	printf(" :::[INICIO]::: LEER DE ARCHIVO DE TEXTO \n");
	int status = ERROR;
	if (path != NULL && pArrayListEmployee != NULL) {
		FILE *pFile;
		pFile = fopen(path, "r");
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		printf(" :::[EXITO]::: Se leyeron los datos correctamente. \n");
		status = OK;
	} else {
		printf(" :::[ERROR]::: No se pueden leer los datos del archivo. \n");
	}
	printf(" :::[FIN]::: LEER DE ARCHIVO DE TEXTO \n");
	return status;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	printf(" :::[INICIO]::: LEER DE ARCHIVO DE BINARIO \n");
	int status = ERROR;
	if (path != NULL && pArrayListEmployee != NULL) {
		FILE *pFile;
		pFile = fopen(path, "rb");
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		printf(" :::[EXITO]::: Se leyeron los datos correctamente. \n");
		status = OK;
	} else {
		printf(" :::[ERROR]::: No se pueden leer los datos del archivo. \n");
	}
	printf(" :::[FIN]::: LEER DE ARCHIVO DE BINARIO \n");
	return status;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int status = ERROR;
	printf(" :::[INICIO]::: AGREGAR EMPLEADO \n");
	if (pArrayListEmployee != NULL) {
		/*Pido los datos del nuevo empleado*/
		//Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
		char nombre[SIZE_CHAR_ARRAY];
		char horasTrabajadas[SIZE_CHAR_ARRAY];
		char sueldo[SIZE_CHAR_ARRAY];
		int resultNombre, resultHorasTrabajadas, resultSueldo;
		employee_GetDataForNewEmployee(nombre, horasTrabajadas, sueldo, &resultNombre,&resultHorasTrabajadas, &resultSueldo);
		if (!resultNombre && !resultHorasTrabajadas && !resultSueldo) {
			printf(":::[EXITO]::: Se ingreso correctamente los datos para el nuevo empleado!!.\n");
			/*Se ingresaron correctamente los datos, creo el empleado y agrego a la lista. Informo que la operacion fue exitosa y salgo*/
			Employee *newEmployee = employee_newParametros(DEFAULT_ID, nombre,horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, (void*) newEmployee);
			printf(
					":::[EXITO]::: Se ingreso correctamente el nuevo empleado!!.\n");
			status = OK;
		} else {
			printf(
					":::[ERROR]::: No se ingresaron correctamente los datos para el nuevo empleado.\n");
		}
	} else {
		printf(
				":::[ERROR]::: La lista esta apuntando a NULL, no se puede agregar elementos.\n");
	}
	printf(" :::[FIN]::: AGREGAR EMPLEADO \n");
	return status;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int status = ERROR;
	printf(" :::[INICIO]::: EDITAR EMPLEADO \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		char nombre[SIZE_CHAR_ARRAY];
		int horasTrabajadas;
		int sueldo;
		char respuestaUsuario = 's';
		int index = ERROR;
		int resultGetIndex;
		//Muestro la lista de empleados..  controller_ListEmployee(LinkedList* pArrayListEmployee) -- obtener por indice los empleados
		int sizeArray = ll_len(pArrayListEmployee);
		ListEmployees(pArrayListEmployee);
		resultGetIndex = GetIntNumber(&index,
				"Ingrese el indice del empleado a modificar: ",
				":::[ERROR]::: ingrese un indice correcto\n", 1, sizeArray,
				RETRIES);
		if (!resultGetIndex && index != ERROR) {
			//Obtengo por indice el empleado y lo muestro
			Employee *currentEmployee = (Employee*) ll_get(pArrayListEmployee,index-1);
			employee_show(currentEmployee);
			do {
				switch (ShowModifyMenu()) {
				case MODIFY_NAME:
					GetString(nombre, "Ingrese el nuevo nombre: ",":::[ERROR]::: ingrese correctamente el nombre\n",RETRIES);
					employee_setNombre(currentEmployee, nombre);
					printf(
							":::[MODIFICACION]::: Se modifico correctamente el nombre del empleado.\n");
					GetCaracter(&respuestaUsuario,
							"Quiere seguir modificando datos? (s - n): ",
							":::[ERROR]::: ingrese s o n\n", 'n', 's', RETRIES);
					break;
				case MODIFY_WORKED_HOURS:
					GetIntNumber(&horasTrabajadas,
							"Ingrese las nuevas horas trabajadas: ",
							":::[ERROR]::: ingrese correctamente las horas trabajadas\n",
							MIN_WORKED_HOURS, MAX_WORKED_HOURS, RETRIES);
					employee_setHorasTrabajadas(currentEmployee,
							horasTrabajadas);
					printf(
							":::[MODIFICACION]::: Se modifico correctamente las horas trabajadas del empleado.\n");
					GetCaracter(&respuestaUsuario,
							"Quiere seguir modificando datos? (s - n): ",
							":::[ERROR]::: ingrese s o n\n", 'n', 's', RETRIES);
					break;
				case MODIFY_SALARY:
					GetIntNumber(&sueldo, "Ingrese el nuevo salario: ",
							":::[ERROR]::: ingrese correctamente el salario\n",
							MIN_SALARY, MAX_SALARY, RETRIES);
					employee_setSueldo(currentEmployee, sueldo);
					printf(
							":::[MODIFICACION]::: Se modifico correctamente el sueldo del empleado.\n");
					GetCaracter(&respuestaUsuario,
							"Quiere seguir modificando datos? (s - n): ",
							":::[ERROR]::: ingrese s o n\n", 'n', 's', RETRIES);
					break;
				case MODIFY_EXIT:
					printf(":::[SALIENDO]::: Menu  de modificar\n");
					respuestaUsuario = 'n';
					break;
				}
			} while (respuestaUsuario == 's');
		} else {
			printf(
					":::[ERROR]::: En el ingreso de datos, no se puede modificar el empleado.\n");
		}
	} else {
		printf(
				":::[ERROR]::: La lista esta apuntando a NULL o la lista esta vacia, no se puede editar elementos.\n");
	}
	printf(" :::[FIN]::: EDITAR EMPLEADO \n");
	return status;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int status = ERROR;
	printf(" :::[INICIO]::: BORRAR EMPLEADO \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		char respuestaUsuario = 's';
		int index = ERROR;
		int resultGetIndex;
		int sizeArray = ll_len(pArrayListEmployee);
		ListEmployees(pArrayListEmployee);
		resultGetIndex = GetIntNumber(&index,
				"Ingrese el indice del empleado a borrar: ",
				":::[ERROR]::: ingrese un indice correcto\n", 1, sizeArray,
				RETRIES);
		if (!resultGetIndex && index != ERROR) {
			Employee *currentEmployee = (Employee*) ll_get(pArrayListEmployee,index-1);
			employee_show(currentEmployee);
			GetCaracter(&respuestaUsuario,"Esta seguro que quiere borrar este empleado (s - n)?: ",":::[ERROR]::: ingrese correctamente la opcion\n", 'n', 's',RETRIES);
			if (respuestaUsuario == 's') {
				employee_delete(currentEmployee);
				ll_remove(pArrayListEmployee, index-1);
				printf(":::[EXITO]::: Se borro correctamente el empleado.\n");
			} else {
				printf(
						":::[CANCELANDO]::: Cancelando operacion eliminar empleado.\n");
			}
		} else {
			printf(
					":::[ERROR]::: En el ingreso de datos, no se puede modificar el empleado.\n");
		}
	} else {
		printf(
				":::[ERROR]::: La lista esta apuntando a NULL o la lista esta vacia, no se puede borrar elementos.\n");
	}
	printf(" :::[FIN]::: BORRAR EMPLEADO \n");
	return status;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int status = ERROR;
	printf(" :::[INICIO]::: LISTAR EMPLEADO \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		status = OK;
		ListEmployees(pArrayListEmployee);
	} else {
		printf(":::[ERROR]::: La lista esta apuntando a NULL o la lista esta vacia, no se puede mostrar elementos.\n");
	}
	printf(" :::[FIN]::: LISTAR EMPLEADO \n");
	return status;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	printf(" :::[INICIO]::: ORDENAR EMPLEADOS \n");
	printf(" :::[FIN]::: ORDENAR EMPLEADOS \n");
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	printf(" :::[INICIO]::: GUARDAR COMO TEXTO \n");
	int status = ERROR;
	if(path != NULL && pArrayListEmployee != NULL){
		FILE *pFile;
		pFile = fopen(path, "w");
		if(pFile != NULL){
			fputs(HEADER, pFile);
			printf(":::[EXITO]::: Insercion header archivo.\n");
			int sizeArray = ll_len(pArrayListEmployee);
				int i = 0;
				Employee *currentEmployee;
				Node *nodo = pArrayListEmployee->pFirstNode;

				do {
					currentEmployee = (Employee*) nodo->pElement;
					fprintf(pFile,"%d,%s,%d,%d\n",currentEmployee->id,currentEmployee->nombre, currentEmployee->horasTrabajadas, currentEmployee->sueldo);
					i++;
					nodo = nodo->pNextNode;
				} while (i < sizeArray && nodo != NULL);
				printf(":::[EXITO]::: Proceso finalizado.\n");
		}else{
			printf(":::[ERROR]::: En la apertura de archivo.\n");
		}
		fclose(pFile);
	}else{
		printf(":::[ERROR]::: La lista esta apuntando a NULL o el nombre del archivo no es valido, no se pueden guardar los datos en un archivo.\n");
	}
	printf(" :::[FIN]::: GUARDAR COMO TEXTO \n");
	return status;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	printf(" :::[INICIO]::: GUARDAR COMO BINARIO \n");
	int status = ERROR;
	if(path != NULL && pArrayListEmployee != NULL){

	}else{
		printf(":::[ERROR]::: La lista esta apuntando a NULL o el nombre del archivo no es valido, no se pueden guardar los datos en un archivo.\n");
	}
	printf(" :::[FIN]::: GUARDAR COMO BINARIO \n");
	return status;
}

static void ListEmployees(LinkedList *pArrayListEmployee) {
	printf(":::[INICIO] LISTA DE EMPLEADOS\n");
	int sizeArray = ll_len(pArrayListEmployee);
	int i = 0;
	Employee *currentEmployee;
	Node *nodo = pArrayListEmployee->pFirstNode;

	do {
		currentEmployee = (Employee*) nodo->pElement;
		printf("INDICE:[%d] -",(i+1));
		employee_show(currentEmployee);
		i++;
		nodo = nodo->pNextNode;
	} while (i < sizeArray && nodo != NULL);
	printf(":::[FIN] LISTA DE EMPLEADOS\n");
}
