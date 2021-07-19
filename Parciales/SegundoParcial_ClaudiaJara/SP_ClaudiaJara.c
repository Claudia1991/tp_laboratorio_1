#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "Menu.h"

int main() {
	setbuf(stdout, NULL);
	LinkedList *listaVentaArticulos = ll_newLinkedList();
	printf(":::::::::: INICIO DISTRIBUIDORA ::::::::::\n");
	do {
		switch (ShowMainMenu()) {
		case LOAD_TEXT:
			controller_loadFromText(listaVentaArticulos);
			break;
		case SORT_LIST:
			controller_sortList(listaVentaArticulos);
			break;
		case SHOW:
			controller_showList(listaVentaArticulos);
			break;
		case DO_DISCOUNT:
			controller_doDiscountList(listaVentaArticulos);
			break;
		case DO_FILE:
			controller_doListToFileMapped(listaVentaArticulos);
			break;
		case REPORTS:
			controller_doReports(listaVentaArticulos);
			break;
		case EXIT:
			ll_clear(listaVentaArticulos);
			ll_deleteLinkedList(listaVentaArticulos);
			printf("::::::::::: FIN DISTRIBUIDORA :::::::::::\n");
			exit(EXIT_SUCCESS);
			break;
		}
	} while (1);
	return EXIT_SUCCESS;
}
