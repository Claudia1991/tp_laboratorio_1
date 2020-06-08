#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Menu.h"
#include "utn_inputs.h"
#include "LinkedList.h"
#include "Employee.h"

static void ListEmployees(LinkedList *pArrayListEmployee);
static int OrderListEmployees(LinkedList *pArrayListEmployee, int dataToOrder,
		int order);
static int OrderListEmployeesByName(LinkedList *pArrayListEmployee, int order);
static int OrderListEmployeesByWordedHours(LinkedList *pArrayListEmployee,
		int order);
static int OrderListEmployeesBySalary(LinkedList *pArrayListEmployee, int order);

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

int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	printf(" :::[INICIO]::: LEER DE ARCHIVO DE BINARIO \n");
	int status = ERROR;
	if (path != NULL && pArrayListEmployee != NULL) {
		//Primero leo el archivo en texto y lo guardo en binario y leo binario
		FILE *pFile;
		pFile = fopen(path, "wb");
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		printf(" :::[EXITO]::: Se leyeron los datos correctamente. \n");
		status = OK;
	} else {
		printf(" :::[ERROR]::: No se pueden leer los datos del archivo. \n");
	}
	printf(" :::[FIN]::: LEER DE ARCHIVO DE BINARIO \n");
	return status;
}

int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int status = ERROR;
	printf(":::[INICIO]::: AGREGAR EMPLEADO \n");
	if (pArrayListEmployee != NULL) {
		char nombre[SIZE_CHAR_ARRAY];
		char horasTrabajadas[SIZE_CHAR_ARRAY];
		char sueldo[SIZE_CHAR_ARRAY];
		int resultNombre, resultHorasTrabajadas, resultSueldo;
		employee_GetDataForNewEmployee(nombre, horasTrabajadas, sueldo,
				&resultNombre, &resultHorasTrabajadas, &resultSueldo);
		if (!resultNombre && !resultHorasTrabajadas && !resultSueldo) {
			printf(
					":::[EXITO]::: Se ingreso correctamente los datos para el nuevo empleado!!.\n");
			Employee *newEmployee = employee_newParametros(DEFAULT_ID, nombre,
					horasTrabajadas, sueldo);
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
		int sizeArray = ll_len(pArrayListEmployee);
		ListEmployees(pArrayListEmployee);
		resultGetIndex = GetIntNumber(&index,
				"Ingrese el indice del empleado a modificar: ",
				":::[ERROR]::: ingrese un indice correcto\n", 1, sizeArray,
				RETRIES);
		if (!resultGetIndex && index != ERROR) {
			status = OK;
			Employee *currentEmployee = (Employee*) ll_get(pArrayListEmployee,
					index - 1);
			employee_show(currentEmployee);
			do {
				switch (ShowModifyMenu()) {
				case MODIFY_NAME:
					GetString(nombre, "Ingrese el nuevo nombre: ",
							":::[ERROR]::: ingrese correctamente el nombre\n",
							RETRIES);
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
	printf(":::[FIN]::: EDITAR EMPLEADO \n");
	return status;
}

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
			status = OK;
			Employee *currentEmployee = (Employee*) ll_get(pArrayListEmployee,
					index - 1);
			employee_show(currentEmployee);
			GetCaracter(&respuestaUsuario,
					"Esta seguro que quiere borrar este empleado (s - n)?: ",
					":::[ERROR]::: ingrese correctamente la opcion\n", 'n', 's',
					RETRIES);
			if (respuestaUsuario == 's') {
				employee_delete(currentEmployee);
				ll_remove(pArrayListEmployee, index - 1);
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

int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int status = ERROR;
	printf(" :::[INICIO]::: LISTAR EMPLEADO \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		status = OK;
		ListEmployees(pArrayListEmployee);
	} else {
		printf(
				":::[ERROR]::: La lista esta apuntando a NULL o la lista esta vacia, no se puede mostrar elementos.\n");
	}
	printf(" :::[FIN]::: LISTAR EMPLEADO \n");
	return status;
}

int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int status = ERROR;
	int order;
	int dataToOrder;
	printf(" :::[INICIO]::: ORDENAR EMPLEADOS \n");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		status = OK;
		GetIntNumber(&order,
				"Ingrese el orden de ordenamiento de la lista(0 - DESC / 1 - ASC): ",
				":::[ERROR]::: ingrese 0 o 1\n", ORDER_DESC, ORDER_ASC,
				RETRIES);
		GetIntNumber(&dataToOrder,
				"1-Nombre\n2-Horas Trabajadas\n3-Salario\nIngrese el por que quiere ordenar la lista: ",
				":::[ERROR]::: ingrese 1 o 2 o 3\n", ORDER_BY_NAME,
				ORDER_BY_SALARY, RETRIES);
		OrderListEmployees(pArrayListEmployee, dataToOrder, order);
		printf(" :::[EXITO]::: Se ordeno exitosamente \n");
		ListEmployees(pArrayListEmployee);
	} else {
		printf(
				":::[ERROR]::: La lista esta apuntando a NULL o la lista esta vacia, no se puede ordenar elementos.\n");
	}
	printf(" :::[FIN]::: ORDENAR EMPLEADOS \n");
	return status;
}

int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	printf(" :::[INICIO]::: GUARDAR COMO TEXTO \n");
	int status = ERROR;
	if (path != NULL && pArrayListEmployee != NULL) {
		FILE *pFile;
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			fputs(HEADER, pFile);
			printf(":::[EXITO]::: Insercion header archivo.\n");
			int sizeArray = ll_len(pArrayListEmployee);
			int i = 0;
			Employee *currentEmployee;
			Node *nodo = pArrayListEmployee->pFirstNode;

			do {
				currentEmployee = (Employee*) nodo->pElement;
				fprintf(pFile, "%d,%s,%d,%d\n", currentEmployee->id,
						currentEmployee->nombre,
						currentEmployee->horasTrabajadas,
						currentEmployee->sueldo);
				i++;
				nodo = nodo->pNextNode;
			} while (i < sizeArray && nodo != NULL);
			printf(":::[EXITO]::: Proceso finalizado.\n");
			status = OK;
		} else {
			printf(":::[ERROR]::: En la apertura de archivo.\n");
		}
		fclose(pFile);
	} else {
		printf(
				":::[ERROR]::: La lista esta apuntando a NULL o el nombre del archivo no es valido, no se pueden guardar los datos en un archivo.\n");
	}
	printf(" :::[FIN]::: GUARDAR COMO TEXTO \n");
	return status;
}

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	printf(" :::[INICIO]::: GUARDAR COMO BINARIO \n");
	int status = ERROR;
	if (path != NULL && pArrayListEmployee != NULL) {
		FILE *pFile;
		pFile = fopen(path, "wb");
		if (pFile != NULL) {
			int sizeArray = ll_len(pArrayListEmployee);
			int i = 0;
			Employee *currentEmployee;
			Employee currentEmployeeToSave;
			Node *nodo = pArrayListEmployee->pFirstNode;

			while (i < sizeArray && nodo != NULL) {
				currentEmployee = (Employee*) nodo->pElement;
				employee_getId(currentEmployee, &currentEmployeeToSave.id);
				employee_getNombre(currentEmployee, currentEmployeeToSave.nombre);
				employee_getHorasTrabajadas(currentEmployee, &currentEmployeeToSave.horasTrabajadas);
				employee_getSueldo(currentEmployee, &currentEmployeeToSave.sueldo);
				printf("[TEST] EMPLEADO A AGREGAR - ID %d - NOMBRE %s - HORAS %d - SUELDO %d",currentEmployeeToSave.id, currentEmployeeToSave.nombre, currentEmployeeToSave.horasTrabajadas, currentEmployeeToSave.sueldo);
				fseek(pFile, 0L, SEEK_END);
				fwrite(&currentEmployeeToSave, sizeof(currentEmployeeToSave), 1, pFile);
				i++;
				nodo = nodo->pNextNode;
			}
			fclose(pFile);
		}
		printf(":::[EXITO]::: Proceso finalizado.\n");
		status = OK;
	} else {
		printf(
				":::[ERROR]::: La lista esta apuntando a NULL o el nombre del archivo no es valido, no se pueden guardar los datos en un archivo.\n");
	}
	printf(" :::[FIN]::: GUARDAR COMO BINARIO \n");
	return status;
}

static void ListEmployees(LinkedList *pArrayListEmployee) {
	printf(":::[INICIO]::: LISTA DE EMPLEADOS\n");
	int sizeArray = ll_len(pArrayListEmployee);
	int i = 0;
	Employee *currentEmployee;
	Node *nodo = pArrayListEmployee->pFirstNode;
	do {
		currentEmployee = (Employee*) nodo->pElement;
		printf("INDICE:[%d] -", (i + 1));
		employee_show(currentEmployee);
		i++;
		nodo = nodo->pNextNode;
	} while (i < sizeArray && nodo != NULL);
	printf(":::[FIN]::: LISTA DE EMPLEADOS\n");
}

static int OrderListEmployees(LinkedList *pArrayListEmployee, int dataToOrder,
		int order) {
	int status = ERROR;
	printf(":::[INICIO]::: ORDENAMIENTO LISTA DE EMPLEADOS\n");
	if (pArrayListEmployee != NULL && dataToOrder > 0 && order > -1) {
		status = OK;
		if (order) {
			printf(":::[INFO]::: Ordenamiento ascendente\n");
		} else {
			printf(":::[INFO]::: Ordenamiento descendente\n");
		}
		switch (dataToOrder) {
		case ORDER_BY_NAME:
			printf(":::[INFO]::: Ordenamiento por nombre\n");
			OrderListEmployeesByName(pArrayListEmployee, order);
			break;
		case ORDER_BY_WORKED_HOURS:
			printf(":::[INFO]::: Ordenamiento por horas trabajadas\n");
			OrderListEmployeesByWordedHours(pArrayListEmployee, order);
			break;
		case ORDER_BY_SALARY:
			printf(":::[INFO]::: Ordenamiento por salario\n");
			OrderListEmployeesBySalary(pArrayListEmployee, order);
			break;
		}
		printf(":::[EXITO]::: Ordenamiento finalizado\n");
	} else {
		printf(":::[ERROR]::: La lista esta apuntando a NULL .\n");
	}
	printf(":::[FIN]::: ORDENAMIENTO LISTA DE EMPLEADOS\n");
	return status;
}

static int OrderListEmployeesByName(LinkedList *pArrayListEmployee, int order) {
	int status = ERROR;
	if (pArrayListEmployee != NULL && order > -1) {
		status = OK;
		Employee *employeeAux, *employeeActual, *employeeSiguiente;
		Node *nodoActual, *nodoSiguiente;
		nodoActual = pArrayListEmployee->pFirstNode;
		while (nodoActual->pNextNode != NULL) {
			nodoSiguiente = nodoActual->pNextNode;
			while (nodoSiguiente != NULL) {
				employeeActual = (Employee*) nodoActual->pElement;
				employeeSiguiente = (Employee*) nodoSiguiente->pElement;
				if (strcmp(employeeActual->nombre, employeeSiguiente->nombre)
						> 0 && order) {
					employeeAux = nodoSiguiente->pElement;
					nodoSiguiente->pElement = nodoActual->pElement;
					nodoActual->pElement = employeeAux;
				} else if (strcmp(employeeActual->nombre,
						employeeSiguiente->nombre) < 0 && !order) {
					employeeAux = nodoSiguiente->pElement;
					nodoSiguiente->pElement = nodoActual->pElement;
					nodoActual->pElement = employeeAux;
				}
				nodoSiguiente = nodoSiguiente->pNextNode;
			}
			nodoActual = nodoActual->pNextNode;
			nodoSiguiente = nodoActual->pNextNode;
		}
	}
	return status;
}
static int OrderListEmployeesByWordedHours(LinkedList *pArrayListEmployee,
		int order) {
	int status = ERROR;
	if (pArrayListEmployee != NULL && order > -1) {
		status = OK;
		Employee *employeeAux, *employeeActual, *employeeSiguiente;
		Node *nodoActual, *nodoSiguiente;
		nodoActual = pArrayListEmployee->pFirstNode;
		while (nodoActual->pNextNode != NULL) {
			nodoSiguiente = nodoActual->pNextNode;
			while (nodoSiguiente != NULL) {
				employeeActual = (Employee*) nodoActual->pElement;
				employeeSiguiente = (Employee*) nodoSiguiente->pElement;
				if (employeeActual->horasTrabajadas
						> employeeSiguiente->horasTrabajadas && order) {
					employeeAux = nodoSiguiente->pElement;
					nodoSiguiente->pElement = nodoActual->pElement;
					nodoActual->pElement = employeeAux;
				} else if (employeeActual->horasTrabajadas
						< employeeSiguiente->horasTrabajadas && !order) {
					employeeAux = nodoSiguiente->pElement;
					nodoSiguiente->pElement = nodoActual->pElement;
					nodoActual->pElement = employeeAux;
				}
				nodoSiguiente = nodoSiguiente->pNextNode;
			}
			nodoActual = nodoActual->pNextNode;
			nodoSiguiente = nodoActual->pNextNode;
		}
	}
	return status;
}
static int OrderListEmployeesBySalary(LinkedList *pArrayListEmployee, int order) {
	int status = ERROR;
	if (pArrayListEmployee != NULL && order > -1) {
		status = OK;
		Employee *employeeAux, *employeeActual, *employeeSiguiente;
		Node *nodoActual, *nodoSiguiente;
		nodoActual = pArrayListEmployee->pFirstNode;
		while (nodoActual->pNextNode != NULL) {
			nodoSiguiente = nodoActual->pNextNode;
			while (nodoSiguiente != NULL) {
				employeeActual = (Employee*) nodoActual->pElement;
				employeeSiguiente = (Employee*) nodoSiguiente->pElement;
				if (employeeActual->sueldo > employeeSiguiente->sueldo
						&& order) {
					employeeAux = nodoSiguiente->pElement;
					nodoSiguiente->pElement = nodoActual->pElement;
					nodoActual->pElement = employeeAux;
				} else if (employeeActual->sueldo > employeeSiguiente->sueldo
						&& !order) {
					employeeAux = nodoSiguiente->pElement;
					nodoSiguiente->pElement = nodoActual->pElement;
					nodoActual->pElement = employeeAux;
				}
				nodoSiguiente = nodoSiguiente->pNextNode;
			}
			nodoActual = nodoActual->pNextNode;
			nodoSiguiente = nodoActual->pNextNode;
		}
	}
	return status;
}

