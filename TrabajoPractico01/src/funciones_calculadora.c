#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "utn.h"

/**
 * \brief Realiza el factorial de un numero entero.
 * \param numero Es el numero del cual se quiere el factorial.
 * \return Retorna el factorial
 *
 * */
long int factorial(int numero) {
	if (numero == 0) {
		return 1;
	} else {
		return (numero * factorial(numero - 1));
	}
}

/**
 * \brief Verifica si un numero es negativo o no.
 * \param numero Es el numero a saber si es negativo o no.
 * \return 1 si es negativo, 0 si es cero o positivo
 *
 * */
int esNegativo(int numero) {
	return numero < 0;
}

/**
 * \brief Verifica si un numero es cero o no.
 * \param numero Es el numero a saber si es cero o no.
 * \return 1 si es cero, 0 en cualquier otro caso.
 *
 * */
int esCero(int numero) {
	return numero == 0;
}

/**
 * \brief Realiza la division y guarda el resultado en un puntero.
 * \param *pResultado Es el puntero donde se guarda el resultado de la division.
 * \param dividendo Es el dividendo
 * \param divisor Es el divisor.
 * \return -1 (RESULTADO_NO_OK) si da error, 0 (RESULTADO_OK) si se realizo la division
 *
 * */
int dividir(float *pResultado, int dividendo, int divisor) {
	if (esCero(divisor)) {
		return RESULTADO_NO_OK;
	} else {
		*pResultado = (float) dividendo / divisor;
		return RESULTADO_OK;
	}
}

/**
 * \brief Realiza el factorial y guarda el resultado en un puntero.
 * \param *pResultado Es el puntero donde se guarda el resultado del factorial.
 * \param numero Es el numero a cualcular el factorial.
 * \return -1 (RESULTADO_NO_OK) si da error, 0 (RESULTADO_OK) si se realizo el factorial.
 *
 * */
int realizarFactorial(long int *pResultado, int numero) {
	if (esNegativo(numero)) {
		return RESULTADO_NO_OK;
	} else {
		*pResultado = factorial(numero);
		return RESULTADO_OK;
	}
}

/**
 * \brief Muestra la bienvenida al usuario.
 * \param No recibe parametros.
 * \return No retorna nada.
 *
 * */
void mostrarBienvenida() {
	printf("--------------------\n");
	printf("BIENVENIDO A LA SUPER CALCULADORA\n");
	printf("--------------------\n");
}

/**
 * \brief Muestra en pantalla las opciones del usuario.
 * \param pResultadoOpcion Es el puntero que almacena si el usuario ingreso bien los datos.
 * \param pOpcion Es el puntero donde se almacena la opcion que escogio el usuario.
 * \return No retorna nada.
 *
 * */
void mostrarMenuOpciones(int *pResultadoOpcion, int *pOpcion) {
	system("CLS()");
	printf("Opciones disponibles: \n");
	printf("1. Ingresar el primer operando(A=x)\n");
	printf("2. Ingresar el segundo operando(B=y)\n");
	printf("3. Calcular todas las operaciones\n");
	printf("\t a-)Calcular la suma(A+B)\n");
	printf("\t b-)Calcular la resta(A-B)\n");
	printf("\t c-)Calcular la division(A/B)\n");
	printf("\t d-)Calcular la multiplicacion(A*B)\n");
	printf("\t e-)Calcular el factorial(A!)(B!)\n");
	printf("4. Informar resultados\n");
	printf("\t a-)El resultado de la suma A+B\n");
	printf("\t b-)El resultado de la resta A-B\n");
	printf("\t c-)El resultado de la division A/B\n");
	printf("\t d-)El resultado de la multiplicacion A*B\n");
	printf("\t e-)El resultado de el factorial de A! y B!\n");
	printf("5. Salir\n");
	printf("--------------------\n");
	*pResultadoOpcion = utn_getNumero(pOpcion, MENSAJE_INGRESO_OPCION,
	MENSAJE_ERROR_INGRESO_OPCION, INGRESAR_PRIMER_OPERANDO, SALIR,
	REINTENTOS);
}

/**
 * \brief Muestra el mensaje de despedida y cierra la aplicacion.
 * \param No recibe parametros.
 * \return No retorna nada.
 *
 * */
void salir() {
	printf("--------------------\n");
	printf("GRACIAS POR USAR A LA SUPER CALCULADORA\n");
	printf("--------------------\n");
	exit(0);
}

/**
 * \brief Valida que ambos numeros fueron ingresados por el usuario
 * \param flagIngresoPrimerOperando Bandera si el usuario ingreso el primer numero.
 * \param flagIngresoSegundoOperando Bandera si el usuario ingreso el segundo numero.
 * \return Retorna 1 si los dos numeros fueron ingresados, 0 en cualquier otro caso.
 *
 * */
int validarIngresoOperandos(int flagIngresoPrimerOperando,
		int flagIngresoSegundoOperando) {
	return flagIngresoPrimerOperando && flagIngresoSegundoOperando;
}

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
		int *pSuma, int *pResta, long int *pMultiplicacion, float *pDivision, long int *pFactorialPrimerOperando, long int *pFactorialSegundoOperando) {
	int resultado = RESULTADO_NO_OK;
	int resultadoEjecucionDivision = FALSE;
	int resultadoEjecucionFactorialA = FALSE;
	int resultadoEjecucionFactorialB = FALSE;

	if (validarIngresoOperandos(flagIngresoPrimerOperando,
			flagIngresoSegundoOperando)) {
		//Suma
		*pSuma = numeroUno + numeroDos;
		//Resta
		*pResta = numeroUno - numeroDos;
		//Multiplicacion
		*pMultiplicacion = numeroUno * numeroDos;
		//Division
		if (dividir(pDivision, numeroUno, numeroDos) == RESULTADO_OK) {
			resultadoEjecucionDivision = TRUE;
		}
		//Factorial A
		if (realizarFactorial(pFactorialPrimerOperando, numeroUno) == RESULTADO_OK ) {
			resultadoEjecucionFactorialA = TRUE;
		}
		//Factorial B
		if (realizarFactorial(pFactorialPrimerOperando, numeroUno) == RESULTADO_OK) {
			resultadoEjecucionFactorialB = TRUE;
		}

		if (resultadoEjecucionDivision && resultadoEjecucionFactorialA
				&& resultadoEjecucionFactorialB) {
			resultado = RESULTADO_OK;
		}
	}
	return resultado;
}

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
void mostrarResultados(int flagIngresoPrimerOperando,
		int flagIngresoSegundoOperando, int numeroUno, int numeroDos, int suma,
		int resta, long int multiplicacion, float division,
		long int factorialPrimerOperando, long int factorialSegundoOperando) {
	if (validarIngresoOperandos(flagIngresoPrimerOperando,
			flagIngresoSegundoOperando)) {
		printf("%s %d \n", MENSAJE_RESULTADO_SUMA, suma);
		printf("%s %d \n", MENSAJE_RESULTADO_RESTA, resta);
		printf("%s %ld \n", MENSAJE_RESULTADO_MULTIPLICACION, multiplicacion);
		if (esCero(numeroDos)) {
			printf("%s \n", MENSAJE_ERROR_DIVISION);
		} else {
			printf("%s %f \n", MENSAJE_RESULTADO_DIVISION, division);
		}
		if (esNegativo(numeroUno)) {
			printf("%s \n", MENSAJE_ERROR_FACTORIAL);
		} else {
			printf("%s %ld \n", MENSAJE_RESULTADO_FACTORIAL_A,
					factorialPrimerOperando);
		}
		if (esNegativo(numeroDos)) {
			printf("%s \n", MENSAJE_ERROR_FACTORIAL);
		} else {
			printf("%s %ld \n", MENSAJE_RESULTADO_FACTORIAL_B,
					factorialSegundoOperando);
		}
	}else{
		printf("%s", MENSAJE_ERROR_MOSTRAR_RESULTADOS);
	}
}

