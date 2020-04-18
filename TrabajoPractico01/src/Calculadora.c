#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "funciones_calculadora.h"
#include "utn.h"
int main() {
	setbuf(stdout, NULL);
	int optionUser;
	int codeState;
	int numberOne;
	int numberTwo;
	int flagInsertFirstNumber = 0;
	int flagInsertSecondNumber = 0;
	int resultDoOperations = -1;
	int sum;
	int subtraction;
	long int multiplication;
	float division;
	long int factorialFirstNumber;
	long int factorialSecondNumber;
	ShowWelcome();
	ShowOptionMenu(&codeState, &optionUser);
		while(codeState == RESULT_OK){
			switch (optionUser) {
				case INSERT_FIRST_NUMBER:
					codeState = GetNumberNoMinMax(&numberOne, MESSAGE_INSERT_NUMBER,MESSAGE_ERROR_INSERT_NUMBER, RETRIES);
					flagInsertFirstNumber = 1;
					ShowOptionMenu(&codeState, &optionUser);
					break;
				case INSERT_SECOND_NUMBER:
					codeState = GetNumberNoMinMax(&numberTwo, MESSAGE_INSERT_NUMBER,MESSAGE_ERROR_INSERT_NUMBER, RETRIES);
					flagInsertSecondNumber = 1;
					ShowOptionMenu(&codeState, &optionUser);
					break;
				case DO_OPERATIONS:
					resultDoOperations = DoOperations(flagInsertFirstNumber,flagInsertFirstNumber,numberOne,numberTwo,&sum, &subtraction,&multiplication, &division, &factorialFirstNumber, &factorialSecondNumber);
					ShowStatusOperations(resultDoOperations);
					ShowOptionMenu(&codeState, &optionUser);
					break;
				case SHOW_RESULTS:
					ShowResults(resultDoOperations,flagInsertFirstNumber, flagInsertSecondNumber,numberOne,numberTwo, sum,subtraction,multiplication,division,factorialFirstNumber, factorialSecondNumber);
					ShowOptionMenu(&codeState, &optionUser);
					break;
				case EXIT:
					Exit();
					break;
				}
		}
		printf("%s", MESSAGE_ERROR_INSERT_NO_RETIES);
	return 0;
}
