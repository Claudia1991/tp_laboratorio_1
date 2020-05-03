#include "Employee.h"
#include "utn_inputs.h"
#include <stdio.h>
#include <stdlib.h>

void ShowEmployeesOrderByLastNameAndSector(eEmployee listEmployees[], int size){
	//SortEmployee(listEmployees, size,order)
	//pido el orden de ordenamiento
	int order;
	system("CLS()");
	printf("********** Listado ordenado por apellido**********\n");
	GetIntNumber(&order, "Ingrese el orden(1 ascendente - 0 descendente):\n", "ERROR: ingrese una opcion correcta:\n", ORDER_DOWN, ORDER_UP, RETRIES);
	if(order){
		printf("Listado ordenado por apellido ascendente\n");
	}else{
		printf("Listado ordenado por apellido descendente\n");
	}
	SortEmployee(listEmployees, size,order);
	PrintEmployees(listEmployees, size);
}

void ShowAverageSalary(eEmployee listEmployees[], int size){
	float totalSalary = GetTotalSalary(listEmployees, size);
	int countEmployees =GetCountEmployee(listEmployees, size);
	float averageSalary = GetAverageSalary(countEmployees,totalSalary);
	int countEmployeesAboveAverageSalary = GetEmployeeAboveAverageSalary(listEmployees, size,averageSalary);
	printf("********** Listado total salarios, promedio salarios y cantidad de empleados superior al salario**********\n");
	printf("Total salarios: %f\n",totalSalary);
	printf("Promedio salarios: %f \n", averageSalary);
	printf("Cantidad de empleados superior al salario: %d\n", countEmployeesAboveAverageSalary);

}

int ShowReportMenu(){
	int option;
	printf("********** MENU REPORTES **********\n");
	printf("1- Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
	printf("2- Total y promedio de los salarios y cuantos empleados superan el salario promedio.\n");
	GetIntNumber(&option, "Ingrese una opcion:\n", "ERROR: ingrese una opcion correcta:\n", SHOW_ORDERED, SHOW_AVERAGE, RETRIES);
	return option;
}

void ShowReports(eEmployee listEmployee[], int size){
	printf("********** SECCION INFORMES **********\n");
	//Verifico que la lista no este vacia
	if(!IsEmptyList(listEmployee,size)){
		char userResponse = 's';
		//pregunto que clase de reporte quiere
		do{
			switch(ShowReportMenu()){
			case SHOW_ORDERED:
				ShowEmployeesOrderByLastNameAndSector(listEmployee, size);
				break;
			case SHOW_AVERAGE:
				ShowAverageSalary(listEmployee, size );
				break;
			}
			GetCaracter(&userResponse, "Quiere seguir con otro informe? Ingrese s o n: ", "ERROR: ingrese s o n: ", 'n', 's', RETRIES);
		}while(userResponse == 's');
	}else{
		printf("La lista de empleados esta vacia.\n");
		printf("No se puede mostrar elementos.\n");
	}
	printf("********** FIN SECCION INFORMES **********\n");
}


