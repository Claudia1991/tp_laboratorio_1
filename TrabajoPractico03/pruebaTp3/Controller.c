#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "utn_inputs.h"
#include "LinkedList.h"
#include "Employee.h"

static void GetDataForNewEmployee(char *nombre, char *horasTrabajadas,
		char *sueldo, int *statusNombre, int *statusHorasTrabajadas,
		int *statusSueldo);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	printf("--------- :::[INIT]::: LOAD FROM TEXT \n----------");
	printf("--------- :::[END]::: LOAD FROM TEXT \n----------");
	return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	printf("--------- :::[INIT]::: LOAD FROM BINARY \n----------");
	printf("--------- :::[END]::: LOAD FROM BINARY \n----------");
	return 1;
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
	printf("--------- :::[INICIO]::: AGREGAR EMPLEADO \n----------");
	if (pArrayListEmployee != NULL) {
		/*Pido los datos del nuevo empleado*/
		//Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
		char nombre[SIZE_CHAR_ARRAY];
		char horasTrabajadas[SIZE_CHAR_ARRAY];
		char sueldo[SIZE_CHAR_ARRAY];
		int resultNombre, resultHorasTrabajadas, resultSueldo;
		GetDataForNewEmployee(nombre, horasTrabajadas, sueldo, &resultNombre,&resultHorasTrabajadas, &resultSueldo);
		if (!resultNombre && !resultHorasTrabajadas && !resultSueldo) {
			/*Se ingresaron correctamente los datos, creo el empleado y agrego a la lista. Informo que la operacion fue exitosa y salgo*/
			Employee *newEmployee = employee_newParametros("-1", nombre,
					horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, newEmployee);
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
	printf("--------- :::[FIN]::: AGREGAR EMPLEADO \n----------");
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
	printf("--------- :::[INICIO]::: EDITAR EMPLEADO \n----------");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		char nombre[SIZE_CHAR_ARRAY];
		int horasTrabajadas;
		int sueldo;
		char respuestaUsuario = 's';
		int index = ERROR;
		int resultGetIndex;
		//Muestro la lista de empleados..  controller_ListEmployee(LinkedList* pArrayListEmployee) -- obtener por indice los empleados
		int sizeArray = ll_len(pArrayListEmployee);
		resultGetIndex = GetIntNumber(&index,
				"Ingrese el indice del empleado a modificar: ",
				":::[ERROR]::: ingrese un indice correcto\n", 1, sizeArray,
				RETRIES);
		if (!resultGetIndex && index != ERROR) {
			//Obtengo por indice el empleado y lo muestro
			Employee *currentEmployee = (Employee*) ll_get(pArrayListEmployee,
					index);
			printf("ID: %d - NOMBRE: %s - SUELDO: %d - HORAS TRABAJADAS: %d",
					currentEmployee->id, currentEmployee->nombre,
					currentEmployee->sueldo, currentEmployee->horasTrabajadas);
			do {
				switch (ShowModifyMenu()) {
				case MODIFY_NAME:
					GetString(nombre, "Ingrese el nuevo nombre: ",
							":::[ERROR]::: ingrese correctamente el nombre\n",
							RETRIES);
					//strcpy(currentEmployee->nombre, nombre);
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
							1, 100, RETRIES);
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
							1, 100000, RETRIES);
					employee_setSueldo(currentEmployee, sueldo);
					printf(
							":::[MODIFICACION]::: Se modifico correctamente el sueldo del empleado.\n");
					GetCaracter(&respuestaUsuario,
							"Quiere seguir modificando datos? (s - n): ",
							":::[ERROR]::: ingrese s o n\n", 'n', 's', RETRIES);
					break;
				case MODIFY_EXIT:
					printf(":::[SALIENDO]::: Menu  de modificar");
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
	printf("--------- :::[FIN]::: EDITAR EMPLEADO \n----------");
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
	printf("--------- :::[INICIO]::: BORRAR EMPLEADO \n----------");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		char respuestaUsuario = 's';
		int index = ERROR;
		int resultGetIndex;
		int sizeArray = ll_len(pArrayListEmployee);
		resultGetIndex = GetIntNumber(&index,
				"Ingrese el indice del empleado a borrar: ",
				":::[ERROR]::: ingrese un indice correcto\n", 1, sizeArray,
				RETRIES);
		if (!resultGetIndex && index != ERROR) {
			Employee *currentEmployee = (Employee*) ll_get(pArrayListEmployee,index);
			printf("ID: %d - NOMBRE: %s - SUELDO: %d - HORAS TRABAJADAS: %d",
					currentEmployee->id, currentEmployee->nombre,
					currentEmployee->sueldo, currentEmployee->horasTrabajadas);
			GetCaracter(&respuestaUsuario, "Esta seguro que quiere borrar este empleado?", ":::[ERROR]::: ingrese correctamente la opcion\n", 'n','s', RETRIES);
			if(respuestaUsuario == 's'){
				employee_delete(currentEmployee);
				ll_remove(pArrayListEmployee, index);
				printf(":::[EXITO]::: Se borro correctamente el empleado.\n");
			}else{
				printf(":::[CANCELANDO]::: Cancelando operacion eliminar empleado.\n");
			}
		} else {
			printf(
					":::[ERROR]::: En el ingreso de datos, no se puede modificar el empleado.\n");
		}
	} else {
		printf(
				":::[ERROR]::: La lista esta apuntando a NULL o la lista esta vacia, no se puede borrar elementos.\n");
	}
	printf("--------- :::[FIN]::: BORRAR EMPLEADO \n----------");
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
	printf("--------- :::[INICIO]::: LISTAR EMPLEADO \n----------");
	if (pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) {
		int sizeArray = ll_len(pArrayListEmployee);
		int i = 0;
		Employee *currentEmployee;
		Node *nodo = pArrayListEmployee->pFirstNode;
		currentEmployee = nodo->pElement;
		while (i < sizeArray && currentEmployee != NULL) {
			printf("ID: %d - NOMBRE: %s - SUELDO: %d - HORAS TRABAJADAS: %d",
					currentEmployee->id, currentEmployee->nombre,
					currentEmployee->sueldo, currentEmployee->horasTrabajadas);
			i++;
			nodo = nodo->pNextNode;
			currentEmployee = nodo->pElement;
		}
	} else {
		printf(
				":::[ERROR]::: La lista esta apuntando a NULL o la lista esta vacia, no se puede mostrar elementos.\n");
	}
	printf("--------- :::[FIN]::: LISTAR EMPLEADO \n----------");
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
	printf("--------- :::[INIT]::: SHOW LIST  EMPLOYEE \n----------");
	printf("--------- :::[END]::: SHOW LIST  EMPLOYEE \n----------");
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
	printf("--------- :::[INIT]::: SAVE AS TEXT \n----------");
	printf("--------- :::[END]::: SAVE AS TEXT \n----------");
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	printf("--------- :::[INIT]::: SAVE AS BINARY \n----------");
	printf("--------- :::[END]::: SAVE AS BINARY \n----------");
	return 1;
}

static void GetDataForNewEmployee(char *nombre, char *horasTrabajadas,
		char *sueldo, int *statusNombre, int *statusHorasTrabajadas,
		int *statusSueldo) {
	*statusNombre = GetString(nombre,
			"Ingrese el nombre para el nuevo empleado: ",
			":::[ERROR]::: ingrese nuevamente el nombre\n", RETRIES);
	*statusHorasTrabajadas = GetString(horasTrabajadas,
			"Ingrese el nombre para el nuevo empleado: ",
			":::[ERROR]::: ingrese nuevamente el nombre\n", RETRIES);
	*statusSueldo = GetString(sueldo,
			"Ingrese el nombre para el nuevo empleado: ",
			":::[ERROR]::: ingrese nuevamente el nombre\n", RETRIES);
}
