#ifndef UTN_H_
#define UTN_H_

/**
 * \brief Pide al usuario un numero, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResult Es el puntero donde se guardar el numero ingresado.
 * \param message Es el mensaje que se muestra al usuario pidiendole que ingrese un dato.
 * \param errorMessage Es el mensaje que se muestra en caso de un error.
 * \param minimun Es el minimo valor aceptado.
 * \param maximun Es el maximo valor aceptado.
 * \param retries Es la cantidad de veces que el usuario se puede equivocar.
 * \return 0 si Ok o -1 para indicar un error
 *
 * */
int GetNumber(int *pResult, char *message, char *errorMessage, int minimun, int maximun, int retries);

/**
 * \brief Pide al usuario un caracter, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResult Es el puntero donde se guardar el caracter ingresado.
 * \param message Es el mensaje que se muestra al usuario pidiendole que ingrese un dato.
 * \param errorMessage Es el mensaje que se muestra en caso de un error.
 * \param minimun Es el minimo valor aceptado.
 * \param maximun Es el maximo valor aceptado.
 * \param retries Es la cantidad de veces que el usuario se puede equivocar.
 * \return 0 si Ok o -1 para indicar un error
 *
 * */
int GetCaracter(char* pResult, char* message,char* errorMessage, char minimun,char maximun,int retries);

/**
 * \brief Pide al usuario un numero, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResult Es el puntero donde se guardar el numero ingresado.
 * \param message Es el mensaje que se muestra al usuario pidiendole que ingrese un dato.
 * \param errorMessage Es el mensaje que se muestra en caso de un error.
 * \param retries Es la cantidad de veces que el usuario se puede equivocar.
 * \return 0 si Ok o -1 para indicar un error
 *
 * */
int GetNumberNoMinMax(int *pResult, char *message, char *errorMessage, int retries);

/**
 * \brief Ordena un array de enteros DESC
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar si Ok o -1 para indicar un error
 *
 */
int SortArrayInt(int* pArray, int size);

/**
 * \brief Genera un numero aleatorio
 * \param from Numero aleatorio munimo
 * \param to Numero aleatorio muximo
 * \param init Indica si se trata del primer numero solicitado 1 indica que si
 * \return retorna el numero aleatorio generado
 *
 */
char GetRandomNumber(int from , int to, int init);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int IsOnlyLetters(char string[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros, y 0 si no lo es
 *
 */
int IsAlphanumeric(char string[]);

/**
 * \brief Verifica si el valor recibido contiene solo numeros, + y -
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int IsPhoneNumber(char string[]);

#endif /* UTN_H_ */
