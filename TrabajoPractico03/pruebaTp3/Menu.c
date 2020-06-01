#include "Menu.h"


int ShowMainMenu(){
	int option;

	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. SALIR\n");

	GetIntNumber(&option, "Ingrese una opcion: ", "ERROR: ingrese una opcion correcta(1-10)\n",LOAD_TEXT,EXIT ,RETRIES);
	return option;
}

int ShowModifyMenu(){
	int option;

	printf("1. Modificar nombre.\n");
	printf("2. Modificar horas trabajadas.\n");
	printf("3. Modificar sueldo.\n");
	printf("4. SALIR\n");

	GetIntNumber(&option, "Ingrese una opcion: ", "ERROR: ingrese una opcion correcta(1-10)\n",MODIFY_NAME,MODIFY_EXIT ,RETRIES);
	return option;
}
