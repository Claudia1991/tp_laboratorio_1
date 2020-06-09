#include "Employee.h"

Employee* employee_new() {
	return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *this = employee_new();
	if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL
			&& sueldoStr != NULL) {
		if (IsNumeric(idStr) && IsOnlyLetters(nombreStr)
				&& IsNumeric(horasTrabajadasStr) && IsNumeric(sueldoStr)) {
			if (!employee_setId(this, atoi(idStr))
					&& !employee_setNombre(this, nombreStr)
					&& !employee_setHorasTrabajadas(this,
							atoi(horasTrabajadasStr))
					&& !employee_setSueldo(this, atoi(sueldoStr))) {
				return this;
			}
		}
	}
	employee_delete(this);
	return NULL;
}
void employee_delete(Employee *this) {
	if (this != NULL) {
		free(this);
	}
}

int employee_setId(Employee *this, int id) {
	int status = ERROR;
	static int maxId = 0;
	if (this != NULL) {
		status = OK;
		if (id < 0) {
			maxId++;
			this->id = maxId;
		} else {
			if (id > maxId) {
				maxId = id;
			}
			this->id = id;
		}
	}
	return status;
}
int employee_getId(Employee *this, int *id) {
	int status = ERROR;
	if (this != NULL && id != NULL) {
		status = OK;
		*id = this->id;
	}
	return status;
}

int employee_setNombre(Employee *this, char *nombre) {
	int status = ERROR;
	if (this != NULL && nombre != NULL) {
		status = OK;
		strcpy(this->nombre, nombre);
	}
	return status;
}
int employee_getNombre(Employee *this, char *nombre) {
	int status = ERROR;
	if (this != NULL && nombre != NULL) {
		status = OK;
		strcpy(nombre, this->nombre);
	}
	return status;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int status = ERROR;
	if (this != NULL && horasTrabajadas > 0) {
		status = OK;
		this->horasTrabajadas = horasTrabajadas;
	}
	return status;
}
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int status = ERROR;
	if (this != NULL && horasTrabajadas != NULL) {
		status = OK;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return status;
}

int employee_setSueldo(Employee *this, int sueldo) {
	int status = ERROR;
	if (this != NULL && sueldo > 0) {
		status = OK;
		this->sueldo = sueldo;
	}
	return status;
}
int employee_getSueldo(Employee *this, int *sueldo) {
	int status = ERROR;
	if (this != NULL && sueldo != NULL) {
		status = OK;
		*sueldo = this->sueldo;
	}
	return status;
}

void employee_show(Employee *this) {
	int id, sueldo, horasTrabajadas;
	char nombre[SIZE_CHAR_ARRAY];
	if(!employee_getId(this, &id) && !employee_getNombre(this, nombre) && !employee_getHorasTrabajadas(this, &horasTrabajadas) && !employee_getSueldo(this, &sueldo)){
		printf("ID: %d - NOMBRE: %s - SUELDO: %d - HORAS TRABAJADAS: %d\n",	id, nombre, sueldo, horasTrabajadas);
	}
}

void employee_GetDataForNewEmployee(char *nombre, char *horasTrabajadas,
		char *sueldo, int *statusNombre, int *statusHorasTrabajadas,
		int *statusSueldo) {
	printf(" :::[INICIO]::: OBTENER DATOS NUEVO EMPLEADO \n");
	*statusNombre = GetString(nombre,
			"Ingrese el nombre para el nuevo empleado: ",
			":::[ERROR]::: ingrese nuevamente el nombre\n", RETRIES);
	*statusHorasTrabajadas = GetString(horasTrabajadas,
			"Ingrese las horas trabajadas para el nuevo empleado: ",
			":::[ERROR]::: ingrese nuevamente el nombre\n", RETRIES);
	*statusSueldo = GetString(sueldo,
			"Ingrese el sueldo para el nuevo empleado: ",
			":::[ERROR]::: ingrese nuevamente el nombre\n", RETRIES);
	printf(" :::[FIN]::: OBTENER DATOS NUEVO EMPLEADO \n");
}

int employee_OrderListEmployeesByName(void *itemOne, void *itemTwo) {
	int status = 0;
	if (itemOne != NULL && itemTwo != NULL) {
		Employee *auxEmployeeOne;
		Employee *auxEmployeeTwo;
		char nameOne[SIZE_CHAR_ARRAY], nameTwo[SIZE_CHAR_ARRAY];
		auxEmployeeOne = (Employee*) itemOne;
		auxEmployeeTwo = (Employee*) itemTwo;
		if (employee_getNombre(auxEmployeeOne, nameOne) == OK && employee_getNombre(auxEmployeeTwo, nameTwo) == OK) {
			printf("[INFO] Ordenando...\n");
			if (strcmp(nameOne, nameTwo) > 0) {
				status = 1;
			} else {
				status = -1;
			}
		}
	}
	return status;
}
int employee_OrderListEmployeesByWordedHours(void *itemOne, void *itemTwo) {
	int status = 0;
	if (itemOne != NULL && itemTwo != NULL) {
		Employee *auxEmployeeOne;
		Employee *auxEmployeeTwo;
		int hoursOne, hoursTwo;
		auxEmployeeOne = (Employee*) itemOne;
		auxEmployeeTwo = (Employee*) itemTwo;
		if (employee_getHorasTrabajadas(auxEmployeeOne, &hoursOne) == OK && employee_getHorasTrabajadas(auxEmployeeTwo, &hoursTwo) == OK) {
			printf("[INFO] Ordenando...\n");
			if (hoursOne > hoursTwo) {
				status = 1;
			} else {
				status = -1;
			}
		}
	}
	return status;
}
int employee_OrderListEmployeesBySalary(void *itemOne, void *itemTwo) {
	int status = 0;
	if (itemOne != NULL && itemTwo != NULL) {
		Employee *auxEmployeeOne;
		Employee *auxEmployeeTwo;
		int salaryOne, salaryTwo;
		auxEmployeeOne = (Employee*) itemOne;
		auxEmployeeTwo = (Employee*) itemTwo;
		if (employee_getSueldo(auxEmployeeOne, &salaryOne) == OK && employee_getSueldo(auxEmployeeTwo, &salaryTwo) == OK) {
			printf("[INFO] Ordenando...\n");
			if (salaryOne > salaryTwo) {
				status = 1;
			} else {
				status = -1;
			}
		}
	}
	return status;
}

