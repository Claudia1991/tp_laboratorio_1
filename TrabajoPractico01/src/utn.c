#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Las funcines estaticas, las declaro con el prototipo aca, para que sean visibles solo en este archivo.
//• esNumerica: Recibe una cadena de caracteres y devuelve 1 en el caso de que el texto
//este compuesto solo por números.
static int esNumerica(char *cadena);
//getInt: Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto
//a numero y lo devuelve como int.
static int getInt(int *pResultado);

/**
 * \brief
 * \param
 * \return
 *
 * */
static int esNumerica(char *cadena) {
	int ret = -1;
	int i = 0;
	if (cadena != NULL) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9')
				break;
			i++;
		}
		if (cadena[i] == '\0')
			ret = 1;
	}
	return ret;
}

/**
 * \brief
 * \param
 * \return
 *
 * */
static int getInt(int *pResultado) {
	int ret = -1;
	char buffer[8];
	fflush(stdin);
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';
	if (esNumerica(buffer)) {
		*pResultado = atoi(buffer);
		ret = 1;
	}
	return ret;
}

/**
 * \brief
 * \param
 * \return
 *
 * */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int ret;
	int num;
	while (reintentos > 0) {
		printf(mensaje);
		if (getInt(&num) == 1) {
			if (num <= maximo && num >= minimo)
				break;
		}
		reintentos--;
		printf(mensajeError);
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;
	}
	return ret;
}

/**
 * \brief
 * \param
 * \return
 *
 * */
int utn_getNumeroSinMinMax(int *pResultado, char *mensaje, char *mensajeError,int reintentos) {
	int ret;
	int num;
	while (reintentos > 0) {
		printf(mensaje);
		if (getInt(&num) == 1) {
			break;
		}
		reintentos--;
		printf(mensajeError);
	}
	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;
	}
	return ret;
}
