#ifndef UTN_H_
#define UTN_H_

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
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

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
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);

/**
 * \brief Pide al usuario un numero, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResultado Es el puntero donde se guardar el numero ingresado.
 * \param mensaje Es el mensaje que se muestra al usuario pidiendole que ingrese un dato.
 * \param mensajeError Es el mensaje que se muestra en caso de un error.
 * \param reintentos Es la cantidad de veces que el usuario se puede equivocar.
 * \return 0 si Ok o -1 para indicar un error
 *
 * */
int utn_getNumeroSinMinMax(int *pResultado, char *mensaje, char *mensajeError, int reintentos);

/**
 * \brief Ordena un array de enteros DESC
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar si Ok o -1 para indicar un error
 *
 */
int ordenarArrayInt(int* pArray, int limite);

/**
 * \brief Genera un numero aleatorio
 * \param desde Numero aleatorio munimo
 * \param hasta Numero aleatorio muximo
 * \param iniciar Indica si se trata del primer numero solicitado 1 indica que si
 * \return retorna el numero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo numeros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);

#endif /* UTN_H_ */
