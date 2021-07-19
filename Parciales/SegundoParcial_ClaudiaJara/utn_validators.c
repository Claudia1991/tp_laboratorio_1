#include <stdlib.h>

int IsOnlyLetters(char string[]) {
	int ret = 0;
	int i=0;
	while (string[i] != '\0') {
		if ((string[i] != ' ' || string[i] != '.' || string[i] != '/') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') ) {
			return ret;
		}
		i++;
	}
	if (string[i] == '\0') {
				ret = 1;
			}
	return ret;
}

int IsAlphanumeric(char string[]) {
	int i = 0;
	while (string[i] != '\0') {
		if ((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z')&& (string[i] < '0' || string[i] > '9')) {
			return 0;
		}
		i++;
	}
	return 1;
}

int IsPhoneNumber(char string[]) {
	int i = 0;
	int contadorGuiones = 0;
	while (string[i] != '\0') {
		if ((string[i] != ' ') && (string[i] != '-')
				&& (string[i] < '0' || string[i] > '9')) {
			return 0;
		}
		if (string[i] == '-') {
			contadorGuiones++;
		}
		i++;
	}
	if (contadorGuiones == 1) { // debe tener un guion
		return 1;
	}
	return 0;
}

int IsNumeric(char *string) {
	int ret = -1;
	int i = 0;
	//printf("");
	if (string != NULL) {
		while (string[i] != '\0') {
			if (i == 0 && (string[i] == '-' || string[i] == '+')) {
				i++;
				continue;
			}
			if (string[i] < '0' || string[i] > '9') {
				break;
			}
			i++;
		}
		if (string[i] == '\0') {
			ret = 1;
		}
	}
	return ret;
}
