#include "parser.h"

int parser_fromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	int status = ERROR;
	int hasHeader = HAS_HEADER;
	int result = 0;
	char auxId[SIZE_CHAR_ARRAY], auxItem[SIZE_CHAR_ARRAY],auxPrice[SIZE_CHAR_ARRAY], auxMeasure[SIZE_CHAR_ARRAY],auxIdSection[SIZE_CHAR_ARRAY];
	eItem *newItem;
	if (pFile != NULL && pArrayListEmployee != NULL) {
		if (pFile != NULL) {
			status = OK;
			while (!feof(pFile)) {
				if(hasHeader){
					hasHeader = 0;
					fscanf(pFile, DATA_FORMAT, auxId, auxItem,auxPrice, auxMeasure,auxIdSection);
				}else{
					result =  fscanf(pFile, DATA_FORMAT, auxId, auxItem,auxMeasure,auxPrice ,auxIdSection);
					if (result == 5) {
						newItem = item_newParametros(auxId, auxItem,auxMeasure,auxPrice ,auxIdSection);
						if (newItem != NULL) {
							ll_add(pArrayListEmployee, newItem);
						}
					}
				}
			}
			fclose(pFile);
		}
	}
	return status;
}
