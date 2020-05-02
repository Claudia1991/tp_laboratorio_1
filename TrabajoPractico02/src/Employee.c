#include "defines.h"
#include "Employee.h"
#include "utn_inputs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int InitEmployees(eEmployee listEmployee[], int size){
	int status = -1;
	if(listEmployee != NULL && size >0){
		status = 0;
		for (int i=0; i<size;i++){
			listEmployee[i].isEmpty = 1;
		}
	}
	return status;
}


int AddEmployees(eEmployee listEmployee[], int size,int id,char name[],char lastName[],float salary,int sector){
	int status = -1;
	int freeIndex;
	eEmployee employeeToAdd;
	if(listEmployee != NULL && size>0 && id >0 && name != NULL && lastName!= NULL && salary >0 && sector >0){
		//verifico el indice libre
		freeIndex = GetFreeIndex(listEmployee,size);
		if(freeIndex != ERROR){
			//obtengo el new employee
			employeeToAdd = NewEmployee(id, name, lastName, salary, sector);
			//le hago alto insert
			listEmployee[freeIndex] = employeeToAdd;
			status = 0;
		}
	}
	return status;
}


int FindEmployeeById(eEmployee listEmployee[], int size,int id){
	int index = -1;
	if(listEmployee != NULL && size>0 && id >0 ){
		for(int i = 0; i<size; i++){
				if(listEmployee[i].id == id && listEmployee[i].isEmpty == 0){
					index = i;
					break;
				}
			}
	}
	return index;
}


int RemoveEmployee(eEmployee listEmployee[], int size,int id){
	int status = -1;
	int indexToDelete;
	if(listEmployee != NULL && size>0 && id >0 ){
		indexToDelete = FindEmployeeById(listEmployee, size, id);
		if(indexToDelete != ERROR){
			status = 0;
			listEmployee[indexToDelete].isEmpty = 1;
		}
	}
	return status;
}


int SortEmployee(eEmployee listEmployee[], int size,int order){
	int flagSwap;
	int i;
	int counter;
	int retorno = -1;
	eEmployee buffer;
	if (listEmployee != NULL && size >= 0) {
		do {
			flagSwap = 0;
			for (i = 0; i < size - 1; i++) {
				counter++;
				if (strncmp(listEmployee[i].lastName , listEmployee[i + 1].lastName,SIZE_LAST_NAME)>0 && order && listEmployee[i].isEmpty == 0) {
					//de menor a mayor y criteria =1
					//ascendente a -z
					flagSwap = 1;
					buffer = listEmployee[i];
					listEmployee[i] = listEmployee[i + 1];
					listEmployee[i + 1] = buffer;
				}else if (strncmp(listEmployee[i].lastName , listEmployee[i + 1].lastName,SIZE_LAST_NAME)<0 && !order && listEmployee[i].isEmpty == 0) {
					//de mayor a menor y criteria =0 descendente
					//descendente z - a
					flagSwap = 1;
					buffer = listEmployee[i];
					listEmployee[i] = listEmployee[i + 1];
					listEmployee[i + 1] = buffer;
				}
			}
			size--;
		} while (flagSwap);
		retorno = counter;
	}
	return retorno;
}


int PrintEmployees(eEmployee listEmployee[], int size){
	int status = -1;
	if(listEmployee != NULL && size >0){
		for(int i = 0; i< size; i++){
			PrintEmployee(listEmployee[i]);
			status = 0;
		}
	}
	return status;
}


void PrintEmployee(eEmployee employee){
	printf("ID: %d - Nombre: %s - Apellido: %s - Sueldo: %f - Sector: %d\n",employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
}


int ShowMenu(){
	int option;
	printf("1- Altas de nuevos empleados\n");
	printf("2- Modificar empleados\n");
	printf("3- Eliminar empleados\n");
	printf("4- Informes\n");
	GetIntNumber(&option, "Ingrese una opcion:\n", "ERROR: ingrese una opcion correcta:\n", ADD, SHOW, RETRIES);
	return option;
}

int ShowModifyMenu(){
	int option;
	printf("1- Modificar Nombre\n");
	printf("2- Modificar Apellido\n");
	printf("3- Modificar Sueldo\n");
	printf("4- Modificar Sector\n");
	GetIntNumber(&option, "Ingrese una opcion(del 1 al 4):", "ERROR: ingrese una opcion correcta(del 1 al 4):", MODIFY_NAME, MODIFY_SECTOR, RETRIES);
	return option;
}

int GetFreeIndex(eEmployee listEmployee[], int size){
	int index = -1;
	for(int i = 0; i<size; i++){
		if(listEmployee[i].isEmpty == 1){
			index = i;
			break;
		}
	}
	return index;
}

eEmployee NewEmployee(int id,char name[],char lastName[],float salary,int sector){
	eEmployee employee;
	employee.id = id;
	strcpy(employee.name, name);
	strcpy(employee.lastName, lastName);
	employee.salary = salary;
	employee.sector = sector;
	employee.isEmpty = 0;
	return employee;
}

eEmployee GetEmployeeById(eEmployee listEmployee[], int size,int id){
	eEmployee employee;
	for(int i = 0; i<size; i++){
		if(listEmployee[i].id == id && listEmployee[i].isEmpty == 0){
			employee = listEmployee[i];
			break;
		}
	}
	return employee;
}

int IsEmptyList(eEmployee listEmployee[], int size){
	int isEmpty = 1;
	for(int i = 0; i<size; i++){
		if(listEmployee[i].isEmpty == 0){
			isEmpty = 0;
			break;
		}
	}
	return isEmpty;
}


void Add(eEmployee listEmployee[], int size, int *id){
	//Primero Verifico que haya espacio para agregar uno nuevo
	if(GetFreeIndex(listEmployee, size) != ERROR){
		//PIDO LOS DATOS DE NUEVO EMPLOYEE
		char name[SIZE_NAME];
		char lastName[SIZE_LAST_NAME];
		float salary;
		int sector;
		int currentId = *id;
		GetNewEmployeeData(name,lastName,&salary,&sector);
		if(AddEmployees( listEmployee,  size, currentId, name, lastName, salary,sector) == OK){
			//aumento el id
			currentId++;
			*id = currentId;
			//Informo que todo salio ok
			printf("Se ingreso el usuario con exito!!\n");
			system("PAUSE");
		}
	}else{
		printf("No hay espacio para agregar nuevos empleados.\n");
		printf("Pruebe de borrar o modificar los existentes.\n");
		system("PAUSE");
	}

}

void Modify(eEmployee listEmployee[], int size){
	//Verifico que la lista no este vacia
	if(!IsEmptyList(listEmployee,size)){
		//SE PIDE EL ID DEL EMPLEADO A MODIFICAR
		int idToModify;
		int index;
		char userResponse = 's';
		char name[SIZE_NAME];
		char lastName[SIZE_NAME];
		float salary;
		int sector;
		do{
			GetIntNumberNoMinMax(&idToModify, "Ingrese el id del empleado a modificar: ", "ERROR: ingrese solo numeros: ", RETRIES);
			index = FindEmployeeById(listEmployee,size,idToModify);
			if(index != ERROR){
				//Existe un empleado con ese id
				//obtengo el empleado
				eEmployee employeeToModify = GetEmployeeById(listEmployee,size,idToModify);
				//muestro el empleado
				printf("Los datos actuales del empleado son:\n");
				PrintEmployee(employeeToModify);
				//Muestro las opciones de lo que se puede modificar de los empleados
				do{
					switch (ShowModifyMenu()){
					case MODIFY_NAME:
						printf("** Modificar nombre **\n");
						GetString(name,"Ingrese el nuevo nombre: ", "ERROR: ingrese solo letras mijo: ", RETRIES);
						strcpy(employeeToModify.name, name);
						GetCaracter(&userResponse, "Quiere modificar algo mas? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
						break;
					case MODIFY_LAST_NAME:
						printf("** Modificar apellido **\n");
						GetString(lastName,"Ingrese el nuevo apellido: ", "ERROR: ingrese solo letras mijo: ", RETRIES);
						strcpy(employeeToModify.lastName, lastName);
						GetCaracter(&userResponse, "Quiere modificar algo mas? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
						break;
					case MODIFY_SALARY:
						printf("** Modificar salario **\n");
						GetFloatNumberNoMinMax(&salary, "Ingrese el nuevo salario: ", "ERROR: ingrese solo numeros", RETRIES);
						employeeToModify.salary = salary;
						GetCaracter(&userResponse, "Quiere modificar algo mas? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
						break;
					case MODIFY_SECTOR:
						printf("** Modificar sector **\n");
						GetIntNumberNoMinMax(&sector, "Ingrese el nuevo sector: ", "ERROR: ingrese solo numeros", RETRIES);
						GetCaracter(&userResponse, "Quiere modificar algo mas? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
						break;
					}
				}while(userResponse == 's');
				GetCaracter(&userResponse, "Quiere modificar otro empleado? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
			}else{
				printf("El id del empleado no existe.\n");
				GetCaracter(&userResponse, "Quiere seguir intentando con otro id? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
			}
		}while(userResponse == 's');
	}else{
		printf("La lista de empleados esta vacia.\n");
		printf("No se puede modificar elementos.\n");
		system("PAUSE");
	}
}


void Delete(eEmployee listEmployee[], int size){
	//Verifico que la lista no este vacia
	if(!IsEmptyList(listEmployee,size)){
		//pido el id a eliminar
		int idToDelete;
		int index;
		char userResponse = 's';
		do{
			GetIntNumberNoMinMax(&idToDelete, "Ingrese el id del empleado a modificar: ", "ERROR: ingrese solo numeros: ", RETRIES);
			index = FindEmployeeById(listEmployee,size,idToDelete);
			if(index != ERROR){
				//Existe un empleado con ese id
				//obtengo el empleado
				eEmployee employeeToDelete = GetEmployeeById(listEmployee,size,idToDelete);
				//muestro el empleado
				printf("El empleado a borrar es:\n");
				PrintEmployee(employeeToDelete);
				GetCaracter(&userResponse, "Esta seguro que quiere borrar este empleado? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
				if(userResponse == 's'){
					//se elimina empleado
					RemoveEmployee( listEmployee, size,idToDelete);
					//se informa por pantalla de la operacion
					printf("***Operacion realizada con exito...!***");
					GetCaracter(&userResponse, "Quiere seguir eliminando? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
				}else{
					printf("***Cancelando operacion***");
					GetCaracter(&userResponse, "Quiere seguir intentando con otro id? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
				}
			}else{
				printf("El id del empleado no existe.\n");
				GetCaracter(&userResponse, "Quiere seguir intentando con otro id? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
			}
		}while(userResponse == 's');
	}else{
		printf("La lista de empleados esta vacia.\n");
		printf("No se puede eliminar elementos.\n");
		system("PAUSE");
	}
}

void GetNewEmployeeData(char name[],char lastName[],float *salary,int *sector){
	GetString(name, "Ingrese el nombre del nuevo empleado:\n", "ERROR:Ingrese el nombre del nuevo empleado:\n", RETRIES);
	GetString(lastName, "Ingrese el apellido del nuevo empleado:\n", "ERROR:Ingrese el apellido del nuevo empleado:\n", RETRIES);
	GetFloatNumberNoMinMax(salary, "Ingrese el salario del nuevo empleado:\n", "ERROR: ingrese solo numeros", RETRIES);
	GetIntNumberNoMinMax(sector, "Ingrese el sector del nuevo empleado:\n", "ERROR: ingrese solo numeros", RETRIES);
}


float GetTotalSalary(eEmployee listEmployee[], int size){
	float totalSalary=0;
		//Verificamos que la lista no este vacia
		if(!IsEmptyList(listEmployee,size)){
			//acumulamos
			for(int i = 0; i<size; i++){
				if(listEmployee[i].isEmpty == 0){
					totalSalary = totalSalary + listEmployee[i].salary;
				}
			}
		}else{
			totalSalary = -1;
		}
		return totalSalary;
}


float GetAverageSalary(int countEmployees, float totalSalary){
	return totalSalary/countEmployees;
}


float GetEmployeeAboveAverageSalary(eEmployee listEmployee[], int size, float averageSalary){
	int employees=0;
	if(!IsEmptyList(listEmployee,size)){
			//contamos
			for(int i = 0; i<size; i++){
				if(listEmployee[i].salary > averageSalary){
					employees++;
				}
			}
		}else{
			employees = -1;
		}
		return employees;
}

int GetCountEmployee(eEmployee listEmployee[], int size){
	int count=0;
	//Verificamos que la lista no este vacia
	if(!IsEmptyList(listEmployee,size)){
		//contamos
		for(int i = 0; i<size; i++){
			if(listEmployee[i].isEmpty == 0){
				count++;
			}
		}
	}else{
		count = -1;
	}
	return count;
}















