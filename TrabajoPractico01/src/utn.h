#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);

int utn_getNumeroSinMinMax(int *pResultado, char *mensaje, char *mensajeError, int reintentos);

int ordenarArrayInt(int* pArray, int limite);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esSoloLetras(char str[]);

int esAlfaNumerico(char str[]);

int esTelefono(char str[]);

#endif /* UTN_H_ */
