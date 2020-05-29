#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "defines.h"
#include "Menu.h"

int main() {
	setbuf(stdout, NULL);
	LinkedList *listaEmpleados = ll_newLinkedList();
	printf("---------- INICIO ----------\n");
	do {
		switch (ShowMainMenu()) {
		case LOAD_TEXT:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case LOAD_BINARY:
			controller_loadFromBinary(SOURCE_DATA, listaEmpleados);
			break;
		case ADD_EMPLOYEE:
			controller_addEmployee( listaEmpleados);
			break;
		case MODIFY_EMPLOYEE:
			controller_editEmployee( listaEmpleados);
			break;
		case DELETE_EMPLOYEE:
			controller_removeEmployee( listaEmpleados);
			break;
		case SHOW_EMPLOYEE:
			controller_ListEmployee( listaEmpleados);
			break;
		case SORT_EMPLOYEE:
			controller_sortEmployee( listaEmpleados);
			break;
		case SAVE_TEXT:
			controller_saveAsText(SOURCE_DATA, listaEmpleados);
			break;
		case SAVE_BINARY:
			controller_saveAsBinary(SOURCE_DATA, listaEmpleados);
			break;
		case EXIT:
			ll_deleteLinkedList(listaEmpleados);
			printf("---------- FIN ----------\n");
			exit(0);
			break;
		}
	} while (1);
	return 0;
}
