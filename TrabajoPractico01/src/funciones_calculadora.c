#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "utn.h"

long int factorial(int numero) {
	if (numero == 0) {
		return 1;
	} else {
		return (numero * factorial(numero - 1));
	}
}

int esNegativo(int numero) {
	return numero < 0;
}

int esCero(int numero) {
	return numero == 0;
}

int dividir(float *pResultado, int dividendo, int divisor) {
	if (esCero(divisor)) {
		return RESULTADO_NO_OK;
	} else {
		*pResultado = (float) dividendo / divisor;
		return RESULTADO_OK;
	}
}

int realizarFactorial(long int *pResultado, int numero) {
	if (esNegativo(numero)) {
		return RESULTADO_NO_OK;
	} else {
		*pResultado = factorial(numero);
		return RESULTADO_OK;
	}
}


void mostrarBienvenida() {
	printf("--------------------\n");
	printf("BIENVENIDO A LA SUPER CALCULADORA\n");
	printf("--------------------\n");
}


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


void salir() {
	printf("--------------------\n");
	printf("GRACIAS POR USAR A LA SUPER CALCULADORA\n");
	printf("--------------------\n");
	exit(0);
}


int validarIngresoOperandos(int flagIngresoPrimerOperando,
		int flagIngresoSegundoOperando) {
	return flagIngresoPrimerOperando && flagIngresoSegundoOperando;
}


int realizarOperaciones(int flagIngresoPrimerOperando,
		int flagIngresoSegundoOperando, int numeroUno, int numeroDos,
		int *pSuma, int *pResta, long int *pMultiplicacion, float *pDivision,
		long int *pFactorialPrimerOperando, long int *pFactorialSegundoOperando) {
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
		if (realizarFactorial(pFactorialPrimerOperando,
				numeroUno) == RESULTADO_OK) {
			resultadoEjecucionFactorialA = TRUE;
		}
		//Factorial B
		if (realizarFactorial(pFactorialPrimerOperando,
				numeroUno) == RESULTADO_OK) {
			resultadoEjecucionFactorialB = TRUE;
		}

		if (resultadoEjecucionDivision && resultadoEjecucionFactorialA
				&& resultadoEjecucionFactorialB) {
			resultado = RESULTADO_OK;
		}
	}
	return resultado;
}


void mostrarResultados(int flagIngresoPrimerOperando,
		int flagIngresoSegundoOperando, int numeroUno, int numeroDos, int suma,
		int resta, long int multiplicacion, float division,
		long int factorialPrimerOperando, long int factorialSegundoOperando) {
	if (validarIngresoOperandos(flagIngresoPrimerOperando,
			flagIngresoSegundoOperando)) {
		printf("%s %d \n", MENSAJE_PRIMER_NUMERO_INGRESADO, numeroUno);
		printf("%s %d \n", MENSAJE_SEGUNDO_NUMERO_INGRESADO, numeroDos);
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
	} else {
		printf("%s", MENSAJE_ERROR_MOSTRAR_RESULTADOS);
	}
}

