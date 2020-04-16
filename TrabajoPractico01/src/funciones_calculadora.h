#ifndef FUNCIONES_CALCULADORA_H_
#define FUNCIONES_CALCULADORA_H_

/**
 * \brief Muestra la bienvenida al usuario.
 * \param No recibe parametros.
 * \return No retorna nada.
 *
 * */
void mostrarBienvenida();

/**
 * \brief Muestra en pantalla las opciones del usuario.
 * \param pResultadoOpcion Es el puntero que almacena si el usuario ingreso bien los datos.
 * \param pOpcion Es el puntero donde se almacena la opcion que escogio el usuario.
 * \return No retorna nada.
 *
 * */
void mostrarMenuOpciones(int *pResultadoOpcion, int *pOpcion);

/**
 * \brief Muestra el mensaje de despedida y cierra la aplicacion.
 * \param No recibe parametros.
 * \return No retorna nada.
 *
 * */
void salir();

/**
 * \brief Valida que ambos numeros fueron ingresados por el usuario
 * \param flagIngresoPrimerOperando Bandera si el usuario ingreso el primer numero.
 * \param flagIngresoSegundoOperando Bandera si el usuario ingreso el segundo numero.
 * \return Retorna 1 si los dos numeros fueron ingresados, 0 en cualquier otro caso.
 *
 * */
int validarIngresoOperandos(int flagIngresoPrimerOperando, int flagIngresoSegundoOperando);

/**
 * \brief Realiza todas las operaciones con los numeros ingresados por el usuario.
 * \param flagIngresoPrimerOperando Bandera si el usuario ingreso el primer numero.
 * \param flagIngresoSegundoOperando Bandera si el usuario ingreso el segundo numero.
 * \param numeroUno Es el primer numero ingresado por el usuario.
 * \param numeroDos Es el segundo numero ingresado por el usuario.
 * \param pSuma Es el puntero donde se guarda el resultado de la suma.
 * \param pResta Es el puntero donde se guarda el resultado de la resta.
 * \param pMultiplicacion Es el puntero donde se guarda el resultado de la multiplicacion.
 * \param pDivision Es el puntero donde se guarda el resultado de la division.
 * \param pFactorialPrimerOperando Es el puntero donde se guarda el resultado del factorial del primer numero.
 * \param pFactorialSegundoOperando Es el puntero donde se guarda el resultado del factorial del segundo numero.
 * \return RESULTADO_OK(0) si se pudo realizar todas las operaciones, RESULTADO_NO_OK(-1) si hubo algun error.
 *
 * */
int realizarOperaciones(int flagIngresoPrimerOperando, int flagIngresoSegundoOperando, int numeroUno, int numeroDos,
		int *pSuma, int *pResta, long int *pMultiplicacion, float *pDivision, long int *pFactorialPrimerOperando, long int *pFactorialSegundoOperando);

/**
 * \brief Muestra los resultados por pantalla si se cargaron los dos numeros, sino muestra un mensaje de error.
 * \param flagIngresoPrimerOperando Bandera si el usuario ingreso el primer numero.
 * \param flagIngresoSegundoOperando Bandera si el usuario ingreso el segundo numero.
 * \param numeroUno Es el primer numero ingresado por el usuario.
 * \param numeroDos Es el segundo numero ingresado por el usuario.
 * \param suma Es el resultado de la suma.
 * \param resta Es  el resultado de la resta.
 * \param multiplicacion Es  el resultado de la multiplicacion.
 * \param division Es el resultado de la division.
 * \param factorialPrimerOperando Es el resultado del factorial del primer numero.
 * \param factorialSegundoOperando Es el resultado del factorial del segundo numero.
 * \return No retorna nada.
 *
 * */
void mostrarResultados(int flagIngresoPrimerOperando, int flagIngresoSegundoOperando,int numeroUno, int numeroDos, int suma, int resta, long int multiplicacion, float division, long int factorialPrimerOperando, long int factorialSegundoOperando);

/**
 * \brief Realiza la division y guarda el resultado en un puntero.
 * \param *pResultado Es el puntero donde se guarda el resultado de la division.
 * \param dividendo Es el dividendo
 * \param divisor Es el divisor.
 * \return -1 (RESULTADO_NO_OK) si da error, 0 (RESULTADO_OK) si se realizo la division
 *
 * */
int dividir(float *pResultado, int dividendo, int divisor);

/**
 * \brief Realiza el factorial y guarda el resultado en un puntero.
 * \param *pResultado Es el puntero donde se guarda el resultado del factorial.
 * \param numero Es el numero a cualcular el factorial.
 * \return -1 (RESULTADO_NO_OK) si da error, 0 (RESULTADO_OK) si se realizo el factorial.
 *
 * */
int realizarFactorial(long int *pResultado, int numero);
/**
 * \brief Realiza el factorial de un numero entero.
 * \param numero Es el numero del cual se quiere el factorial.
 * \return Retorna el factorial
 *
 * */
long int factorial(int numero);

/**
 * \brief Verifica si un numero es negativo o no.
 * \param numero Es el numero a saber si es negativo o no.
 * \return 1 si es negativo, 0 si es cero o positivo
 *
 * */
int esNegativo(int numero);

/**
 * \brief Verifica si un numero es cero o no.
 * \param numero Es el numero a saber si es cero o no.
 * \return 1 si es cero, 0 en cualquier otro caso.
 *
 * */
int esCero(int numero);

#endif /* FUNCIONES_CALCULADORA_H_ */
