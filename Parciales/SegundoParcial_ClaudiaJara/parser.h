#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "LinkedList.h"
#include "Item.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto) y los carga dentro de la lista de empleados.
 *
 * \param FILE* pFile Puntero al archivo de texto.
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) si pFile es NULL o pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int parser_fromText(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
