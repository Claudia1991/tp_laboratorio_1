#ifndef FUNCIONES_CALCULADORA_H_
#define FUNCIONES_CALCULADORA_H_

/**
 * \brief Muestra la bienvenida al usuario.
 * \param No recibe parametros.
 * \return No retorna nada.
 *
 * */
void ShowWelcome();

/**
 * \brief Muestra en pantalla las opciones del usuario.
 * \param pResultOption Es el puntero que almacena si el usuario ingreso bien los datos.
 * \param pOption Es el puntero donde se almacena la opcion que escogio el usuario.
 * \return No retorna nada.
 *
 * */
void ShowOptionMenu(int *pResultOption, int *pOption);

/**
 * \brief Muestra el mensaje de despedida y cierra la aplicacion.
 * \param No recibe parametros.
 * \return No retorna nada.
 *
 * */
void Exit();

/**
 * \brief Valida que ambos numeros fueron ingresados por el usuario
 * \param flagInsertFirstNumber Bandera si el usuario ingreso el primer numero.
 * \param flagInsertSecondNumber Bandera si el usuario ingreso el segundo numero.
 * \return Retorna 1 si los dos numeros fueron ingresados, 0 en cualquier otro caso.
 *
 * */
int ValidateInsertNumbers(int flagInsertFirstNumber, int flagInsertSecondNumber);

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
int DoOperations(int flagInsertFirstNumber, int flagInsertSecondNumber, int numberOne, int numberTwo,
		int *pSum, int *pSubtraction, long int *pMultiplication, float *pDivision, long int *pFactorialFirstNumber, long int *pFactorialSecondNumber);

/**
 * \brief Muestra los resultados por pantalla si se cargaron los dos numeros, sino muestra un mensaje de error.
 * \param flagInsertFirstNumber Bandera si el usuario ingreso el primer numero.
 * \param flagInsertSecondNumber Bandera si el usuario ingreso el segundo numero.
 * \param numberOne Es el primer numero ingresado por el usuario.
 * \param numberTwo Es el segundo numero ingresado por el usuario.
 * \param sum Es el resultado de la suma.
 * \param numberTwo Es  el resultado de la resta.
 * \param multiplication Es  el resultado de la multiplicacion.
 * \param division Es el resultado de la division.
 * \param factorialFirstNumber Es el resultado del factorial del primer numero.
 * \param factorialSecondNumber Es el resultado del factorial del segundo numero.
 * \return No retorna nada.
 *
 * */
void ShowResults(int statusDoOperationes, int flagInsertFirstNumber, int flagInsertSecondNumber,int numberOne, int numberTwo, int sum, int subtraction, long int multiplication, float division, long int factorialFirstNumber, long int factorialSecondNumber);

/**
 * \brief Realiza la division y guarda el resultado en un puntero.
 * \param *pResult Es el puntero donde se guarda el resultado de la division.
 * \param dividend Es el dividendo
 * \param divider Es el divisor.
 * \return -1 (RESULTADO_NO_OK) si da error, 0 (RESULTADO_OK) si se realizo la division
 *
 * */
int DoDivide(float *pResult, int dividend, int divider);

/**
 * \brief Realiza el factorial y guarda el resultado en un puntero.
 * \param *pResult Es el puntero donde se guarda el resultado del factorial.
 * \param number Es el numero a cualcular el factorial.
 * \return -1 (RESULTADO_NO_OK) si da error, 0 (RESULTADO_OK) si se realizo el factorial.
 *
 * */
int DoFactorial(long int *pResult, int number);
/**
 * \brief Realiza el factorial de un numero entero.
 * \param number Es el numero del cual se quiere el factorial.
 * \return Retorna el factorial
 *
 * */
long int Factorial(int number);

/**
 * \brief Verifica si un numero es negativo o no.
 * \param number Es el numero a saber si es negativo o no.
 * \return 1 si es negativo, 0 si es cero o positivo
 *
 * */
int IsNegative(int number);

/**
 * \brief Verifica si un numero es cero o no.
 * \param number Es el numero a saber si es cero o no.
 * \return 1 si es cero, 0 en cualquier otro caso.
 *
 * */
int IsZero(int number);

/*
 * \brief Muestra por pantalla si se pudieron realizar todas las operaciones.
 * \param statusOperations Es el estado de la ejecucion de las operaciones.
 * \return No retorna nada.
 * */
void ShowStatusOperations(int statusOperations);

#endif /* FUNCIONES_CALCULADORA_H_ */
