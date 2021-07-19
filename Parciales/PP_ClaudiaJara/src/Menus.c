#include "Menus.h"
int MainMenu(){
	int option;
	printf("1- Alta de cliente\n");
	printf("2- Modificar datos cliente\n");
	printf("3-Baja cliente\n");
	printf("4- Prestamo\n");
	printf("5-Saldar prestamo\n");
	printf("6-Reanudar prestamo\n");
	printf("7-Imprimir clientes\n");
	printf("8-Imprimir prestamos\n");
	printf("9-Informar clientes\n");
	printf("10-Informar prestamos\n");
	printf("11-SALIR\n");
	GetIntNumber(&option, "Ingrese una opcion: ", "ERROR: ingrese una opcion correcta(1-10)\n",ADD_CLIENT,EXIT ,RETRIES);
	return option;
}

int ModifyClientMenu(){
	int option;
	printf("1- Modificar nombre cliente\n");
	printf("2- Modificar apellido cliente\n");
	printf("3-Modificar cuil cliente\n");
	GetIntNumber(&option, "Ingrese una opcion: ", "ERROR: ingrese una opcion correcta(1-3)\n",MODIFY_NAME,MODIFY_CUIL ,RETRIES);
	return option;
}

int ReportsClient(){
	int option;
	printf("1- Cliente con mas prestamos activos\n");
	printf("2- Cliente con mas prestamos saldados\n");
	printf("3- Cliente con mas prestamos \n");
	GetIntNumber(&option, "Ingrese una opcion: ", "ERROR: ingrese una opcion correcta(1-2)\n",CLIENT_MORE_ACTIVE_LOANS,CLIENT_MORE_LOANS ,RETRIES);
	return option;
}

int ReportsLoan(){
	int option;
	printf("1- Cantidad de prestamos de importe mayor a 1000\n");
	printf("2- Cantidad de prestamos segun importe\n");
	printf("3- Cantidad de prestamos de 12 cuotas saldados\n");
	printf("4- Cantidad de prestamos segun cuota\n");
	GetIntNumber(&option, "Ingrese una opcion: ", "ERROR: ingrese una opcion correcta(1-2)\n",LOANS_UPPER,LOANS_BY_QUANTITY_FEE ,RETRIES);
	return option;
}
