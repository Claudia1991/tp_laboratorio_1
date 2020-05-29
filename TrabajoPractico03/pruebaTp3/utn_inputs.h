#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

//GETTERS NUMBERS
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
int GetIntNumber(int *pResult, char *message, char *errorMessage, int minimun, int maximun, int retries);

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
int GetFloatNumber(float *pResult, char *message, char *errorMessage, float minimun, float maximun, int retries);


/**
 * \brief Pide al usuario un numero, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResult Es el puntero donde se guardar el numero ingresado.
 * \param message Es el mensaje que se muestra al usuario pidiendole que ingrese un dato.
 * \param errorMessage Es el mensaje que se muestra en caso de un error.
 * \param retries Es la cantidad de veces que el usuario se puede equivocar.
 * \return 0 si Ok o -1 para indicar un error
 *
 * */
int GetIntNumberNoMinMax(int *pResult, char *message, char *errorMessage, int retries);

/**
 * \brief Pide al usuario un numero, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResult Es el puntero donde se guardar el numero ingresado.
 * \param message Es el mensaje que se muestra al usuario pidiendole que ingrese un dato.
 * \param errorMessage Es el mensaje que se muestra en caso de un error.
 * \param retries Es la cantidad de veces que el usuario se puede equivocar.
 * \return 0 si Ok o -1 para indicar un error
 *
 * */
int GetFloatNumberNoMinMax(float *pResult, char *message, char *errorMessage, int retries);

/**
 * \brief Genera un numero aleatorio
 * \param from Numero aleatorio munimo
 * \param to Numero aleatorio muximo
 * \param init Indica si se trata del primer numero solicitado 1 indica que si
 * \return retorna el numero aleatorio generado
 *
 */
char GetRandomNumber(int from , int to, int init);

// GETTERS CHARACTERS
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
 * \brief Pide al usuario un caracter, con un minimo y maximo segun la cantidad de reintentos.
 * \param pResult Es el puntero donde se guardar el caracter ingresado.
 * \return 0 si Ok o -1 para indicar un error
 *
 * */
int GetString(char* pResult, char* message,char* errorMessage,int retries);


#endif
