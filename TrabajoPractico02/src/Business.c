#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Report.h"

int main(){
	setbuf(stdout, NULL);
	int id = 1;
	eEmployee listEmployees[QTY_EMPLOYEES];
	/*int id = 11;
	eEmployee listEmployees[QTY_EMPLOYEES] = {
			{1,"Juan","Perez", 200.00,1,0},
			{2,"Marta","Sanchez", 300.00,1,0},
			{3,"Oscar","Acosta", 250.00,3,0},
			{4,"Juliana","Valenzuela", 350.00,1,0},
			{5,"Ricky","Martin", 400.00,2,0},
			{6,"Juan","Pereira", 200.00,1,0},
			{7,"Marta","Sanchez", 300.00,1,0},
			{8,"Oscar","Acosta", 250.00,1,0},
			{9,"Juliana","Baez", 350.00,1,0},
			{10,"Ricky","Martin", 400.00,2,0}
	};*/
	InitEmployees(listEmployees, QTY_EMPLOYEES);
	printf("************ INICIO EMPRESA ************\n");
	do{
		switch (ShowMenu()){
		case ADD:
			Add( listEmployees,QTY_EMPLOYEES, &id);
			break;
		case MODIFY:
			Modify( listEmployees,QTY_EMPLOYEES);
			break;
		case DELETE:
			Delete( listEmployees, QTY_EMPLOYEES);
			break;
		case SHOW :
			ShowReports( listEmployees,QTY_EMPLOYEES);
			break;
		case EXIT:
			printf("************ FIN EMPRESA ************\n");
			exit(0);
			break;
		}
	}while(1);
	return 0;
}
