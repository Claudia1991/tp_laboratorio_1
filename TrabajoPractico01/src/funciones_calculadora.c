#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "utn.h"

long int Factorial(int number) {
	if (number == 0) {
		return 1;
	} else {
		return (number * Factorial(number - 1));
	}
}

int IsNegative(int number) {
	return number < 0;
}

int IsZero(int number) {
	return number == 0;
}

int DoDivide(float *pResult, int dividend, int divider) {
	if (IsZero(divider)) {
		return RESULT_NO_OK;
	} else {
		*pResult = (float) dividend / divider;
		return RESULT_OK;
	}
}

int DoFactorial(long int *pResult, int number) {
	if (IsNegative(number)) {
		return RESULT_NO_OK;
	} else {
		*pResult = Factorial(number);
		return RESULT_OK;
	}
}


void ShowWelcome(){
	printf("--------------------\n");
	printf("BIENVENIDO A LA SUPER CALCULADORA\n");
	printf("--------------------\n");
}


void ShowOptionMenu(int *pResultOption, int *pOption) {
	system("CLS");
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
	*pResultOption = GetNumber(pOption, MESSAGE_INSERT_OPTION,
			MESSAGE_ERROR_INSERT_OPTION, INSERT_FIRST_NUMBER, EXIT,
	RETRIES);
}


void Exit() {
	printf("--------------------\n");
	printf("GRACIAS POR USAR A LA SUPER CALCULADORA\n");
	printf("--------------------\n");
	exit(0);
}


int  ValidateInsertNumbers(int flagInsertFirstNumber, int flagInsertSecondNumber) {
	return flagInsertFirstNumber && flagInsertSecondNumber;
}


int DoOperations(int flagInsertFirstNumber, int flagInsertSecondNumber, int numberOne, int numberTwo,
		int *pSum, int *pSubtraction, long int *pMultiplication, float *pDivision, long int *pFactorialFirstNumber, long int *pFactorialSecondNumber) {
	int resultado = RESULT_NO_OK;
	int resultadoEjecucionDivision = 0;
	int resultadoEjecucionFactorialA = 0;
	int resultadoEjecucionFactorialB = 0;

	if (ValidateInsertNumbers(flagInsertFirstNumber,flagInsertSecondNumber)) {
		//Suma
		*pSum = numberOne + numberTwo;
		//Resta
		*pSubtraction = numberOne - numberTwo;
		//Multiplicacion
		*pMultiplication = numberOne * numberTwo;
		//Division
		if (DoDivide(pDivision, numberOne, numberTwo) == RESULT_OK) {
			resultadoEjecucionDivision = 1;
		}
		//Factorial A
		if (DoFactorial(pFactorialFirstNumber,numberOne) == RESULT_OK) {
			resultadoEjecucionFactorialA = 1;
		}
		//Factorial B
		if (DoFactorial(pFactorialSecondNumber,numberOne) == RESULT_OK) {
			resultadoEjecucionFactorialB = 1;
		}

		if (resultadoEjecucionDivision && resultadoEjecucionFactorialA
				&& resultadoEjecucionFactorialB) {
			resultado = RESULT_OK;
		}
	}
	return resultado;
}


void ShowResults(int statusDoOperationes, int flagInsertFirstNumber, int flagInsertSecondNumber,int numberOne, int numberTwo, int sum, int subtraction, long int multiplication, float division,
		long int factorialFirstNumber, long int factorialSecondNumber) {
	if (ValidateInsertNumbers(flagInsertFirstNumber,flagInsertSecondNumber) && statusDoOperationes == RESULT_OK) {
		printf("%s %d \n", MESSAGE_INSERT_FIRST_NUMBER, numberOne);
		printf("%s %d \n", MESSAGE_INSERT_SECOND_NUMBER, numberTwo);
		printf("%s %d \n", MESSAGE_RESULT_SUM, sum);
		printf("%s %d \n", MESSAGE_RESULT_SUBTRACTION, subtraction);
		printf("%s %ld \n", MESSAGE_RESULT_MULTIPLICATION, multiplication);
		if (IsZero(numberTwo)) {
			printf("%s \n", MESSAGE_ERROR_DIVISION);
		} else {
			printf("%s %f \n", MESSAGE_RESULT_DIVISION, division);
		}
		if (IsNegative(numberOne)) {
			printf("%s \n", MESSAGE_ERROR_FACTORIAL);
		} else {
			printf("%s %ld \n", MESSAGE_RESULT_FACTORIAL_A,factorialFirstNumber);
		}
		if (IsNegative(numberTwo)) {
			printf("%s \n", MESSAGE_ERROR_FACTORIAL);
		} else {
			printf("%s %ld \n", MESSAGE_RESULT_FACTORIAL_B,factorialSecondNumber);
		}
	} else {
		printf("%s", MESSAGE_ERROR_SHOW_RESULTS);
	}
}

void ShowStatusOperations(int statusOperations){
	if(statusOperations == RESULT_OK){
		printf("%s", MESSAGE_DO_OPERATIONS);
	}else{
		printf("%s", MESSAGE_ERROR_DO_OPERATIONS_STATUS);
	}
}

