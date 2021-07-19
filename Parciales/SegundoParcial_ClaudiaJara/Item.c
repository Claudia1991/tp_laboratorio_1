#include "Item.h"

eItem* item_new() {
	return (eItem*) malloc(sizeof(eItem));
}
eItem* item_newParametros(char *idStr, char *itemStr, char *measureStr,
		char *priceStr, char *idSectionStr) {
	eItem *this = item_new();
	if (this != NULL) {
		if (idStr != NULL && itemStr != NULL && priceStr != NULL
				&& measureStr != NULL && idSectionStr != NULL) {
			if (IsNumeric(idStr) && strlen(itemStr) > 0 && IsNumeric(priceStr)
					&& IsAlphanumeric(measureStr) && IsNumeric(idSectionStr)) {
				if (!item_setId(this, atoi(idStr))
						&& !item_setItem(this, itemStr)
						&& !item_setPrice(this, atof(priceStr))
						&& !item_setMeasure(this, measureStr)
						&& !item_setIdSection(this, atoi(idSectionStr))) {
					return this;
				}
			}
		}
	}
	item_delete(this);
	return NULL;
}

int item_setId(eItem *this, int id) {
	int status = ERROR;
	static int maxId = 0;
	if (this != NULL) {
		status = OK;
		if (id < 0) {
			maxId++;
			this->id = maxId;
		} else {
			if (id > maxId) {
				maxId = id;
			}
			this->id = id;
		}
	}
	return status;
}

void item_delete(eItem *this) {
	if (this != NULL) {
		free(this);
	}
}

int item_getId(eItem *this, int *id) {
	int status = ERROR;
	if (this != NULL && id != NULL) {
		status = OK;
		*id = this->id;
	}
	return status;
}

int item_setItem(eItem *this, char *item) {
	int status = ERROR;
	if (this != NULL && item != NULL) {
		status = OK;
		strcpy(this->item, item);
	}
	return status;
}
int item_getItem(eItem *this, char *item) {
	int status = ERROR;
	if (this != NULL && item != NULL) {
		status = OK;
		strcpy(item, this->item);
	}
	return status;
}

int item_setPrice(eItem *this, float price) {
	int status = ERROR;
	if (this != NULL && price > 0) {
		status = OK;
		this->price = price;
	}
	return status;
}
int item_getPrice(eItem *this, float *price) {
	int status = ERROR;
	if (this != NULL && price != NULL) {
		status = OK;
		*price = this->price;
	}
	return status;
}

int item_setMeasure(eItem *this, char *measure) {
	int status = ERROR;
	if (this != NULL && measure != NULL) {
		status = OK;
		strcpy(this->measure, measure);
	}
	return status;
}
int item_getMeasure(eItem *this, char *measure) {
	int status = ERROR;
	if (this != NULL && measure != NULL) {
		status = OK;
		strcpy(measure, this->measure);
	}
	return status;
}

int item_setIdSection(eItem *this, int idSection) {
	int status = ERROR;
	if (this != NULL && idSection > 0) {
		status = OK;
		this->idSection = idSection;
	}
	return status;
}
int item_getIdSection(eItem *this, int *idSection) {
	int status = ERROR;
	if (this != NULL && idSection != NULL) {
		status = OK;
		*idSection = this->idSection;
	}
	return status;
}

void item_show(eItem *this) {
	if (this != NULL) {
		int id, idSection;
		float price;
		char item[SIZE_CHAR_ARRAY], measure[SIZE_CHAR_ARRAY],
				section[SIZE_CHAR_ARRAY];
		if (!item_getId(this, &id) && !item_getItem(this, item)
				&& !item_getPrice(this, &price)
				&& !item_getMeasure(this, measure)
				&& !item_getIdSection(this, &idSection)) {
			item_getSectionDescriptionByIdSection(idSection, section);
			printf(
					"ID: %d - ARTICULO: %s - PRECIO: %.2f - MEDIDA: %s - RUBRO: %s\n",
					id, item, price, measure, section);
		}
	}
}

int item_OrderListItemsByItem(void *itemOne, void *itemTwo) {
	int status = 0;
	if (itemOne != NULL && itemTwo != NULL) {
		eItem *auxeItemOne;
		eItem *auxeItemTwo;
		char nameOne[SIZE_CHAR_ARRAY], nameTwo[SIZE_CHAR_ARRAY];
		auxeItemOne = (eItem*) itemOne;
		auxeItemTwo = (eItem*) itemTwo;
		if (item_getItem(auxeItemOne, nameOne) == OK
				&& item_getItem(auxeItemTwo, nameTwo) == OK) {
			if (strcmp(nameOne, nameTwo) > 0) {
				status = 1;
			} else {
				status = -1;
			}
		}
	}
	return status;
}

void item_DoDiscount(void *itemOne) {

	if (itemOne != NULL) {
		int idSection;
		float price;
		int discount;
		eItem *auxItem = (eItem*) itemOne;
		if (!item_getIdSection(auxItem, &idSection)
				&& !item_getPrice(auxItem, &price)) {
			switch (idSection) {
			case ID_SECTION_CLOTHES:
				if (price >= 120) {
					discount = price - (price * 0.2);
					item_setPrice(auxItem, discount);
				}
				break;
			case ID_SECTION_CLEAN:
				if (price <= 200) {
					discount = price - (price * 0.1);
					item_setPrice(auxItem, discount);
				}
				break;
			}
		}
	}

}

int item_getSectionDescriptionByIdSection(int idSection, char *description) {
	int status = ERROR;
	if (description != NULL && idSection > 0) {
		switch (idSection) {
		case ID_SECTION_CLOTHES:
			strcpy(description, "CUIDADO DE ROPA");
			break;
		case ID_SECTION_CLEAN:
			strcpy(description, "LIMPIEZA Y DESINFECCION");
			break;
		case ID_SECTION_PERSONAL_CARE:
			strcpy(description, "CUIDADO PERSONAL E HIGUIENE");
			break;
		case ID_SECTION_CAR:
			strcpy(description, "CUIDADO DEL AUTOMOTOR");
			break;
		}
		status = OK;
	}
	return status;
}

int item_isPriceUpperToAhundred(void *itemOne) {
	int status = 0;
	if (itemOne != NULL) {
		float price;
		eItem *auxItem = (eItem*) itemOne;
		if (!item_getPrice(auxItem, &price)) {
			if (price > 100) {
				status = 1;
			}
		}
	}
	return status;
}

int item_isSectorOne(void *itemOne) {
	int status = 0;
	if (itemOne != NULL) {
		int idSection;
		eItem *auxItem = (eItem*) itemOne;
		if (!item_getIdSection(auxItem, &idSection)) {
			if (idSection == ID_SECTION_CLOTHES) {
				status = 1;
			}
		}
	}
	return status;
}

