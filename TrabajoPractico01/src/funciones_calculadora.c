#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "utn.h"

/**
 * \brief
 * \param
 * \return
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
 * \brief
 * \param
 * \return
 *
 * */
int esNegativo(int numero) {
	return numero < 0;
}

/**
 * \brief
 * \param
 * \return
 *
 * */
int esCero(int numero) {
	return numero == 0;
}

/**
 * \brief
 * \param
 * \return
 *
 * */
int dividir(float *dividir, int dividendo, int divisor) {
	if (esCero(divisor)) {
		return RESULTADO_NO_OK;
	} else {
		*dividir = (float) dividendo / divisor;
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
 * \param No recibe parametros.
 * \return No retorna nada.
 *
 * */
void mostrarMenuOpciones(int *resultadoOpcion, int *opcion) {
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
	*resultadoOpcion = utn_getNumero(opcion, MENSAJE_INGRESO_OPCION,
	MENSAJE_ERROR_INGRESO_OPCION, INGRESAR_PRIMER_OPERANDO, SALIR,
	REINTENTOS);
}

/**
 * \brief Muestra el mensaje de despedida y cierra la aplicacion.
 * \param
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
 * \param ingresoPrimerOperando
 * \param ingresoSegundoOperando
 * \return Retorna 1 si los dos numeros fueron ingresados, 0 en cualquier otro caso.
 *
 * */
int validarIngresoOperandos(int flagIngresoPrimerOperando,
		int flagIngresoSegundoOperando) {
	return flagIngresoPrimerOperando && flagIngresoSegundoOperando;
}

/**
 * \brief Realiza todas las operaciones con los numeros ingresados por el usuario.
 * \param
 * \return
 *
 * */
int realizarOperaciones(int flagIngresoPrimerOperando,
		int flagIngresoSegundoOperando, int numeroUno, int numeroDos, int *suma,
		int *resta, long int *multiplicacion, float *division,
		long int *factorialPrimerOperando, long int *factorialSegundoOperando) {
	int resultado = RESULTADO_NO_OK;
	int resultadoEjecucionDivision = FALSE;
	int resultadoEjecucionFactorialA = FALSE;
	int resultadoEjecucionFactorialB = FALSE;

	if (validarIngresoOperandos(flagIngresoPrimerOperando,
			flagIngresoSegundoOperando)) {
		//Suma
		*suma = numeroUno + numeroDos;
		//Resta
		*resta = numeroUno - numeroDos;
		//Multiplicacion
		*multiplicacion = numeroUno * numeroDos;
		//Division
		if (dividir(division, numeroUno, numeroDos) == RESULTADO_OK) {
			resultadoEjecucionDivision = TRUE;
		}
		//Factorial A
		if (!esNegativo(numeroUno)) {
			*factorialPrimerOperando = factorial(numeroUno);
			resultadoEjecucionFactorialA = TRUE;
		}
		//Factorial B
		if (!esNegativo(numeroDos)) {
			*factorialSegundoOperando = factorial(numeroDos);
			resultadoEjecucionFactorialA = TRUE;
		}

		if (resultadoEjecucionDivision && resultadoEjecucionFactorialA
				&& resultadoEjecucionFactorialB) {
			resultado = RESULTADO_OK;
		}
	}
	return resultado;
}

/**
 * \brief Muestra los resultados por pantalla.
 * \param suma
 * \param resta
 * \param multiplicacion
 * \param division
 * \param factorialPrimerOperando
 * \param factorialSegundoOperando
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

