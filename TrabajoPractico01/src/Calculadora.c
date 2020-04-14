#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "funciones_calculadora.h"
#include "utn.h"
int main() {
	setbuf(stdout, NULL);
	int opcionUsuario;
	int codigoEstado;
	int primerOperando;
	int segundoOperando;
	int flagIngresoPrimerOperando = FALSE;
	int flagIngresoSegundoOperando = FALSE;
	int resultadoEjecucionOperaciones;
	int suma;
	int resta;
	long int multiplicacion;
	float division;
	long int factorialPrimerOperando;
	long int factorialSegundoOperando;
	mostrarBienvenida();
	mostrarMenuOpciones(&codigoEstado, &opcionUsuario);
		while(codigoEstado == RESULTADO_OK){
			switch (opcionUsuario) {
				case INGRESAR_PRIMER_OPERANDO:
					codigoEstado = utn_getNumeroSinMinMax(&primerOperando, MENSAJE_INGRESO_NUMERO,MENSAJE_ERROR_INGRESO_NUMERO, REINTENTOS);
					flagIngresoPrimerOperando = 1;
					mostrarMenuOpciones(&codigoEstado, &opcionUsuario);
					break;
				case INGRESAR_SEGUNDO_OPERANDO:
					codigoEstado = utn_getNumeroSinMinMax(&segundoOperando, MENSAJE_INGRESO_NUMERO,MENSAJE_ERROR_INGRESO_NUMERO, REINTENTOS);
					flagIngresoSegundoOperando = 1;
					mostrarMenuOpciones(&codigoEstado, &opcionUsuario);
					break;
				case REALIZAR_OPERACIONES:
					resultadoEjecucionOperaciones = realizarOperaciones(flagIngresoPrimerOperando,flagIngresoSegundoOperando,primerOperando,segundoOperando,&suma, &resta,&multiplicacion, &division, &factorialPrimerOperando, &factorialSegundoOperando);
					if(resultadoEjecucionOperaciones == RESULTADO_OK){
						printf("%s", MENSAJE_EJECUCION_OPERACIONES);
					}else{
						printf("%s", MENSAJE_ERROR_EJECUCION_OPERACIONES);
					}
					mostrarMenuOpciones(&codigoEstado, &opcionUsuario);
					break;
				case MOSTRAR_RESULTADOS:
					mostrarResultados(flagIngresoPrimerOperando,flagIngresoSegundoOperando,primerOperando, segundoOperando,suma, resta,multiplicacion, division, factorialPrimerOperando,factorialSegundoOperando);
					mostrarMenuOpciones(&codigoEstado, &opcionUsuario);
					break;
				case SALIR:
					salir();
					break;
				}
		}
		printf("%s", MENSAJE_ERROR_INGRESO_SIN_REINTENTOS);
	return 0;
}
