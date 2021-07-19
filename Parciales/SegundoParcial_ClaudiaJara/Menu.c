#include "Menu.h"


int ShowMainMenu(){
	int option;
	printf(":::INICIO::: MOSTRAR MENU \n");
	printf("1. Cargar los datos de los articulos desde el archivo data.csv (modo texto).\n");
	printf("2. Ordenar la lista por articulo ascendente.\n");
	printf("3. Mostrar la lista.\n");
	printf("4. Aplicar descuentos.\n");
	printf("5. Generar archivo de salida [mapeado.csv]\n");
	printf("6. Realizar informes.\n");
	printf("7. SALIR\n");
	GetIntNumber(&option, "Ingrese una opcion: ", "ERROR: ingrese una opcion correcta(1-6)\n",LOAD_TEXT,EXIT ,RETRIES);
	printf(":::FIN::: MOSTRAR MENU \n");
	return option;
}

