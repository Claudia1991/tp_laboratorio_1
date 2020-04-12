#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//Las funcines estaticas, las declaro con el prototipo aca, para que sean visibles solo en este archivo.
//• esNumerica: Recibe una cadena de caracteres y devuelve 1 en el caso de que el texto
//este compuesto solo por números.
static int esNumerica(char *cadena);
//getInt: Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto
//a numero y lo devuelve como int.
static int getInt(int *pResultado);

/**
 * \brief Verifica si el valor recibido es numurico
 * \param cadena Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
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

	/*
	 * int esNumero(char* cadena)
{
	int retorno = 1;
	int i;
	for(i=0;cadena[i]!='\0';i++)
	{
		if(i==0 && cadena[i] == '-')
		{
			continue;
		}
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
	 * */
}

/**
 * \brief Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto a numero y lo devuelve como int
 * \param pResultado Es el puntero en el cual se guarda el numero obtenido.
 * \return 1 si OK sino -1
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
 * \brief Pide al usuario un numero, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResultado Es el puntero donde se guardar el numero ingresado.
 * \param mensaje Es el mensaje que se muestra al usuario pidiendole que ingrese un dato.
 * \param mensajeError Es el mensaje que se muestra en caso de un error.
 * \param minimo Es el minimo valor aceptado.
 * \param maximo Es el maximo valor aceptado.
 * \param reintentos Es la cantidad de veces que el usuario se puede equivocar.
 * \return 0 si Ok o -1 para indicar un error
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
 * \brief Pide al usuario un numero, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResultado Es el puntero donde se guardar el numero ingresado.
 * \param mensaje Es el mensaje que se muestra al usuario pidiendole que ingrese un dato.
 * \param mensajeError Es el mensaje que se muestra en caso de un error.
 * \param reintentos Es la cantidad de veces que el usuario se puede equivocar.
 * \return 0 si Ok o -1 para indicar un error
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

/**
 * \brief Pide al usuario un caracter, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResultado Es el puntero donde se guardar el caracter ingresado.
 * \param mensaje Es el mensaje que se muestra al usuario pidiendole que ingrese un dato.
 * \param mensajeError Es el mensaje que se muestra en caso de un error.
 * \param minimo Es el minimo valor aceptado.
 * \param maximo Es el maximo valor aceptado.
 * \param reintentos Es la cantidad de veces que el usuario se puede equivocar.
 * \return 0 si Ok o -1 para indicar un error
 *
 * */
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}


/**
 * \brief Ordena un array de enteros DESC
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar si Ok o -1 para indicar un error
 *
 */
int ordenarArrayInt(int* pArray, int limite)
{
	int flagSwap;
	int i;
	int contador=0;
	int retorno = -1;
	int buffer;

	if(pArray != NULL && limite >= 0)
	{
		do
		{
			flagSwap=0;
			for( i=0 ; i<limite - 1 ; i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			limite--;
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}

/**
 * \brief Genera un numero aleatorio
 * \param desde Numero aleatorio munimo
 * \param hasta Numero aleatorio muximo
 * \param iniciar Indica si se trata del primer numero solicitado 1 indica que si
 * \return retorna el numero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo numeros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
