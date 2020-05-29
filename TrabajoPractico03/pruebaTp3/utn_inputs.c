#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "defines_utn.h"
#include "utn_validators.h"

static int IsNumeric(char *string);
static int IsFloat(char *string);
static int GetInt(int *pResult);
static int GetFloat(float *pResult);

static int IsNumeric(char *string) {
	int ret = -1;
	int i = 0;
	if (string != NULL) {
		while (string[i] != '\0') {
			if (i == 0 && (string[i] == '-' || string[i] == '+')) {
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

static int IsFloat(char *string) {
	int ret=1;
	int i = 0;
	int contadorPuntos=0;
	if (string != NULL && strlen(string) > 0) {
		while (string[i] != '\0') {
			if (i == 0 && (string[i] == '-' || string[i] == '+')) {
				continue;
			}
			if (string[i] < '0' || string[i] > '9') {
				if(string[i]=='.' && contadorPuntos==0){
					contadorPuntos++;
				}else{
					ret =0;
					break;
				}

			}
			i++;
		}
		if (string[i] == '\0') {
			ret = 1;
		}
	}
	return ret;
}

static int GetInt(int *pResult) {
	int ret = -1;
	char buffer[SIZE_BUFFER_INT];
	fflush(stdin);
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';
	if (IsNumeric(buffer)) {
		*pResult = atoi(buffer);
		ret = 1;
	}
	return ret;
}

static int GetFloat(float *pResult) {
	int ret = -1;
	char buffer[SIZE_BUFFER_FLOAT];
	fflush(stdin);
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';
	if (IsFloat(buffer)) {
		*pResult = atof(buffer);
		ret = 1;
	}
	return ret;
}

int GetIntNumber(int *pResult, char *message, char *errorMessage, int minimun,
		int maximun, int retries) {
	int ret = -1;
	int num;
	if (pResult != NULL && message != NULL && errorMessage != NULL && minimun <= maximun && retries >= 0) {
		while (retries > 0) {
			printf(message);
			if (GetInt(&num) == 1) {
				if (num <= maximun && num >= minimun) {
					break;
				}
			}
			retries--;
			printf(errorMessage);
		}
		if (retries == 0) {
			ret = -1;
		} else {
			ret = 0;
			*pResult = num;
		}
	}
	return ret;
}

int GetFloatNumber(float *pResult, char *message, char *errorMessage,
		float minimun, float maximun, int retries) {
	int ret;
	float num;
	if (pResult != NULL && message != NULL && errorMessage != NULL && minimun <= maximun && retries >= 0) {
		while (retries > 0) {
			printf(message);
			if (GetFloat(&num) == 1) {
				if (num <= maximun && num >= minimun) {
					break;
				}
			}
			retries--;
			printf(errorMessage);
		}
	}
	if (retries == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResult = num;
	}
	return ret;
}

int GetIntNumberNoMinMax(int *pResult, char *message, char *errorMessage,int retries) {
	int ret;
	int num;
	if (pResult != NULL && message != NULL && errorMessage != NULL && retries >= 0) {
		while (retries > 0) {
			printf(message);
			if (GetInt(&num) == 1) {
				break;
			}
			retries--;
			printf(errorMessage);
		}
	}
	if (retries == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResult = num;
	}
	return ret;
}

int GetFloatNumberNoMinMax(float *pResult, char *message, char *errorMessage,int retries) {
	int ret;
	float num;
	if (pResult != NULL && message != NULL && errorMessage != NULL && retries >= 0) {
		while (retries > 0) {
			printf(message);
			if (GetFloat(&num) == 1) {
				break;
			}
			retries--;
			printf(errorMessage);
		}
	}
	if (retries == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResult = num;
	}
	return ret;
}

int GetCaracter(char *pResult, char *message, char *errorMessage, char minimun,
		char maximun, int retries) {
	int retorno = -1;
	char buffer;
	if (pResult != NULL && message != NULL && errorMessage != NULL && minimun <= maximun && retries >= 0) {
		do {
			printf("%s", message);
			fflush(stdin);
			scanf("%c", &buffer);
			if (buffer >= minimun && buffer <= maximun) {
				*pResult = buffer;
				retorno = 0;
				break;
			}
			printf("%s", errorMessage);
			retries--;
		} while (retries >= 0);

	}
	return retorno;
}

int GetString(char* pResult, char* message,char* errorMessage,int retries) {
	int retorno = -1;
	char buffer[SIZE_BUFFER_CHAR];
	if (pResult != NULL && message != NULL && errorMessage != NULL && retries >= 0) {
		do {
			printf("%s", message);
			fflush(stdin);
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer) - 1] = '\0';
			if (IsOnlyLetters(buffer)) {
				strcpy(pResult, buffer);
				retorno = 0;
				break;
			}
			printf("%s", errorMessage);
			retries--;
		} while (retries >= 0);
	}
	return retorno;
}

char GetRandomNumber(int from, int to, int init) {
	if (init) {
		srand(time(NULL));
	}
	return from + (rand() % (to + 1 - from));
}
