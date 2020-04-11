#ifndef FUNCIONES_CALCULADORA_H_
#define FUNCIONES_CALCULADORA_H_

void mostrarBienvenida();

void mostrarMenuOpciones(int *resultadoOpcion, int *opcion);

void salir();

int validarIngresoOperandos(int flagIngresoPrimerOperando, int flagIngresoSegundoOperando);

int realizarOperaciones(int flagIngresoPrimerOperando, int flagIngresoSegundoOperando, int numeroUno, int numeroDos,
		int *suma, int *resta, long int *multiplicacion, float *division, long int *factorialPrimerOperando, long int *factorialSegundoOperando);

void mostrarResultados(int flagIngresoPrimerOperando, int flagIngresoSegundoOperando,int numeroUno, int numeroDos, int suma, int resta, long int multiplicacion, float division, long int factorialPrimerOperando, long int factorialSegundoOperando);

//Funciones Matematicas
int dividir(float *resultado, int dividendo, int divisor);
long int factorial(int numero);
int esNegativo(int numero);
int esCero(int numero);
#endif /* FUNCIONES_CALCULADORA_H_ */
