#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "defines.h"
//Las funcines estaticas, las declaro con el prototipo aca, para que sean visibles solo en este archivo.
//• esNumerica: Recibe una cadena de caracteres y devuelve 1 en el caso de que el texto
//este compuesto solo por números.
static int IsNumeric(char *string);
//getInt: Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto
//a numero y lo devuelve como int.
static int GetInt(int *pResult);

/**
 * \brief Verifica si el valor recibido es numurico
 * \param cadena Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 *
 * */
static int IsNumeric(char *string) {
	int ret = -1;
	int i = 0;
	if (string != NULL) {
		while (string[i] != '\0') {
			printf("%c",string[i]);
			if (string[i] < '0' || string[i] > '9'){
				printf("%c",string[i]);
				break;
			}
			i++;
		}
		if (string[i] == '\0'){
			ret = 1;
		}
	}
	return ret;
}

/**
 * \brief Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto a numero y lo devuelve como int
 * \param pResultado Es el puntero en el cual se guarda el numero obtenido.
 * \return 1 si OK sino -1
 *
 * */
static int GetInt(int *pResult) {
	int ret = -1;
	char buffer[TAM_CHAR_ARRAY];
	fflush(stdin);
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';
	if (IsNumeric(buffer)) {
		*pResult = atoi(buffer);
		ret = 1;
	}
	return ret;
}


int GetNumber(int *pResult, char *message, char *errorMessage, int minimun, int maximun, int retries) {
	int ret;
	int num;
	while (retries > 0) {
		printf(message);
		if (GetInt(&num) == 1) {
			if (num <= maximun && num >= minimun){
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
	return ret;
}


int GetNumberNoMinMax(int *pResult, char *message, char *errorMessage, int retries) {
	int ret;
	int num;
	while (retries > 0) {
		printf(message);
		if (GetInt(&num) == 1) {
			break;
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
	return ret;
}


int GetCaracter(char* pResult, char* message,char* errorMessage, char minimun,char maximun,int retries)
{
	int retorno = -1;
	char buffer;
	if(pResult != NULL && message != NULL && errorMessage != NULL && minimun <= maximun && retries >= 0)
	{
		do
		{
			printf("%s",message);
			fflush(stdin);
			scanf("%c",&buffer);
			if(buffer >= minimun && buffer <= maximun)
			{
				*pResult = buffer;
				retorno = 0;
				break;
			}
			printf("%s",errorMessage);
			retries--;
		}while(retries>=0);

	}
	return retorno;
}



int SortArrayInt(int* pArray, int size)
{
	int flagSwap;
	int i;
	int counter=0;
	int retorno = -1;
	int buffer;

	if(pArray != NULL && size >= 0)
	{
		do
		{
			flagSwap=0;
			for( i=0 ; i<size - 1 ; i++)
			{
				counter++;
				if(pArray[i] < pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			size--;
		}while(flagSwap);
		retorno = counter;
	}
	return retorno;
}


char GetRandomNumber(int from , int to, int init)
{
    if(init){
        srand (time(NULL));
    }
    return from + (rand() % (to + 1 - from)) ;
}


int IsOnlyLetters(char string[])
{
   int i=0;
   while(string[i] != '\0')
   {
       if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z')){
           return 0;
       }
       i++;
   }
   return 1;
}


int IsAlphanumeric(char string[])
{
   int i=0;
   while(string[i] != '\0')
   {
       if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] < '0' || string[i] > '9')){
           return 0;
       }
       i++;
   }
   return 1;
}



int IsPhoneNumber(char string[])
{
   int i=0;
   int contadorGuiones=0;
   while(string[i] != '\0')
   {
       if((string[i] != ' ') && (string[i] != '-') && (string[i] < '0' || string[i] > '9')){
           return 0;
       }
       if(string[i] == '-'){
            contadorGuiones++;
       }
       i++;
   }
   if(contadorGuiones==1){ // debe tener un guion
        return 1;
   }
    return 0;
}
