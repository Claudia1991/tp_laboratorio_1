#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include "defines.h"
#include "utn_inputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int ShowMainMenu();

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int ShowModifyMenu();

#endif /* MENU_H_ */
