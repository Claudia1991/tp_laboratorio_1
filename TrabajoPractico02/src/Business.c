#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Report.h"

int main(){
	setbuf(stdout, NULL);
	int id = 1;
	eEmployee listEmployees[QTY_EMPLOYEES];
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
