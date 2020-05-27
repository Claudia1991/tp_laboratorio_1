#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "defines.h"
#include "Menu.h"

int main() {

	LinkedList *listaEmpleados = ll_newLinkedList();
	do {
		switch (ShowMainMenu()) {
		case LOAD_TEXT:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case LOAD_BINARY:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case ADD_EMPLOYEE:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case MODIFY_EMPLOYEE:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case DELETE_EMPLOYEE:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case SHOW_EMPLOYEE:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case SORT_EMPLOYEE:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case SAVE_TEXT:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case SAVE_BINARY:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		case EXIT:
			controller_loadFromText(SOURCE_DATA, listaEmpleados);
			break;
		}
	} while (1);
	return 0;
}
