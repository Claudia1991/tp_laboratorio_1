#ifndef FUNCIONES_CALCULADORA_H_
#define FUNCIONES_CALCULADORA_H_

void mostrarBienvenida();

void mostrarMenuOpciones(int *pResultadoOpcion, int *pOpcion);

void salir();

int validarIngresoOperandos(int flagIngresoPrimerOperando, int flagIngresoSegundoOperando);

int realizarOperaciones(int flagIngresoPrimerOperando, int flagIngresoSegundoOperando, int numeroUno, int numeroDos,
		int *pSuma, int *pResta, long int *pMultiplicacion, float *pDivision, long int *pFactorialPrimerOperando, long int *pFactorialSegundoOperando);

void mostrarResultados(int flagIngresoPrimerOperando, int flagIngresoSegundoOperando,int numeroUno, int numeroDos, int suma, int resta, long int multiplicacion, float division, long int factorialPrimerOperando, long int factorialSegundoOperando);

//Funciones Matematicas
int dividir(float *pResultado, int dividendo, int divisor);
int realizarFactorial(long int *pResultado, int numero);
long int factorial(int numero);
int esNegativo(int numero);
int esCero(int numero);
#endif /* FUNCIONES_CALCULADORA_H_ */
