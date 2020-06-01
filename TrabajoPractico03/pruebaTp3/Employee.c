#include "Employee.h"

Employee* employee_new() {
	return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char *idStr, char *nombreStr,char *horasTrabajadasStr, char *sueldoStr) {
	Employee *this = employee_new();
	if(idStr != NULL && nombreStr!= NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){
		if(IsNumeric(idStr) && IsOnlyLetters(nombreStr) && IsNumeric(horasTrabajadasStr) && IsNumeric(sueldoStr)){
			if(!employee_setId(this, atoi(idStr)) && !employee_setNombre(this, nombreStr) && !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) && !employee_setSueldo(this, atoi(sueldoStr))){
				return this;
			}
		}
	}
	employee_delete(this);
	return NULL;
}
void employee_delete(Employee *this) {
	free(this);
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
	if (this != NULL && *id != NULL) {
		status = OK;
		*id = this->id;
	}
	return status;
}

int employee_setNombre(Employee *this, char *nombre) {
	int status = ERROR;
	if (this != NULL && *nombre != NULL) {
		status = OK;
		strcpy(this->nombre, nombre);
	}
	return status;
}
int employee_getNombre(Employee *this, char *nombre) {
	int status = ERROR;
	if (this != NULL && *nombre != NULL) {
		status = OK;
		strcpy(nombre, this->nombre);
	}
	return status;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int status = ERROR;
	if (this != NULL && horasTrabajadas > 0) {
		status = OK;
		this->sueldo = horasTrabajadas;
	}
	return status;
}
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int status = ERROR;
	if (this != NULL && *horasTrabajadas != NULL) {
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
	if (this != NULL && *sueldo != NULL) {
		status = OK;
		*sueldo = this->sueldo;
	}
	return status;
}

