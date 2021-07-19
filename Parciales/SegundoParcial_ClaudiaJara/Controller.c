#include "Controller.h"

int controller_loadFromText(LinkedList *pList) {
	int status = ERROR;
	char nameFile[SIZE_CHAR_ARRAY];
	FILE *pFile;
	if (pList != NULL) {
		status = OK;
		printf(":::INICIO::: cargar archivo\n");
		GetString(nameFile,
				"Ingrese el nombre del archivo para levantar los datos: ",
				":::ERROR::: ingrese nuevamente\n", RETRIES);
		strcat(nameFile, ".csv");
		pFile = fopen(nameFile, "r");
		if (pFile == NULL) {
			printf(
					":::ERROR::: No se pudo abrir el archivo en modo lectura.\n");
			pFile = fopen(nameFile, "r+");
			if (pFile == NULL) {
				printf(
						":::ERROR::: No se pudo abrir el archivo en modo escritura, verifique el nombre.\n");
			}
		} else {
			parser_fromText(pFile, pList);
			printf(":::EXITO::: Se leyo el archivo correctamente.\n");
		}
		printf(":::FIN::: cargar archivo\n");
	}
	return status;
}

int controller_sortList(LinkedList *pList) {
	int status = ERROR;
	if (pList != NULL) {
		status = OK;
		printf(":::INICIO::: Ordenar Lista\n");
		if (!ll_isEmpty(pList)) {
			ll_sort(pList, item_OrderListItemsByItem, ORDER_ASC);
			printf(":::EXITO::: Lista ordenada\n");
		} else {
			printf(":::ERROR::: La lista de articulos esta vacia.\n");
		}
		printf(":::FIN::: Ordenar Lista\n");
	}
	return status;
}

int controller_showList(LinkedList *pList) {
	int status = ERROR;
	if (pList != NULL) {
		status = OK;
		printf(":::INICIO::: Mostrar Lista\n");
		if (!ll_isEmpty(pList)) {
			eItem *auxItem;
			for (int i = 0; i < ll_len(pList); i++) {
				auxItem = (eItem*) ll_get(pList, i);
				if (auxItem != NULL) {
					item_show(auxItem);
				}
			}
		} else {
			printf(":::ERROR::: La lista de articulos esta vacia.\n");
		}
		printf(":::FIN::: Mostrar Lista\n");
	}
	return status;
}

int controller_doDiscountList(LinkedList *pList) {
	int status = ERROR;
	if (pList != NULL) {
		printf(":::INICIO::: Aplicar descuento\n");
		if (!ll_isEmpty(pList)) {
			ll_map(pList, item_DoDiscount);
		} else {
			printf(":::ERROR::: La lista de articulos esta vacia.\n");
		}
		printf(":::FIN::: Aplicar descuento\n");
	}
	return status;
}

int controller_doListToFileMapped(LinkedList *pList) {
	int status = ERROR;
	FILE *pFile;
	if (pList != NULL) {
		status = OK;
		printf(":::INICIO::: Crear archivo mapeado\n");
		if (!ll_isEmpty(pList)) {
			pFile = fopen(SOURCE_DATA, "w");
			if (pFile != NULL) {
				fputs(HEADER, pFile);
				printf(":::[EXITO]::: Insercion header archivo.\n");
				int id, idSection;
				float price;
				char item[SIZE_CHAR_ARRAY], measure[SIZE_CHAR_ARRAY];
				eItem *currentItem;

				for (int i = 0; i < ll_len(pList); i++) {
					currentItem = (eItem*) ll_get(pList, i);
					if ((!item_getId(currentItem, &id)
							&& !item_getItem(currentItem, item)
							&& !item_getPrice(currentItem, &price)
							&& !item_getMeasure(currentItem, measure)
							&& !item_getIdSection(currentItem, &idSection))) {
						fprintf(pFile, DATA_FORMAT_SAVE, id, item, measure,
								price, idSection);
					}
				}
				printf(":::[EXITO]::: Proceso finalizado.\n");
			} else {
				printf(":::[ERROR]::: En la apertura de archivo.\n");
			}
			fclose(pFile);
		} else {
			printf(":::ERROR::: La lista de articulos esta vacia.\n");
		}
		printf(":::FIN::: Crear archivo mapeado\n");
	}
	return status;
}

int controller_doReports(LinkedList *pList){
	int status =  ERROR;
	printf(":::INICIO::: INFORMES\n");
	if(pList != NULL){
		int quantityItemUpperPrice = ll_count(pList, item_isPriceUpperToAhundred);
		int quantityItemById = ll_count(pList, item_isSectorOne);
		if(quantityItemUpperPrice != ERROR){
			printf("Cantidad de articulos cuyo precio sea mayor a 100 : %d\n", quantityItemUpperPrice);
		}else{
			printf(":::ERROR::: Ocurrio un error al realizar el siguiente informe [Cantidad de articulos cuyo precio sea mayor a 100]\n");
		}

		if(quantityItemById != ERROR){
			printf("Cantidad de articulos del rubro 1 - CUIDADO DE ROPA: %d\n", quantityItemById);
		}else{
			printf(":::ERROR::: Ocurrio un error al realizar el siguiente informe [Cantidad de articulos del rubro 1 - CUIDADO DE ROPA]\n");
		}

	}
	printf(":::FIN::: INFORMES\n");
	return status;
}





