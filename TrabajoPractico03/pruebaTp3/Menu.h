#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include "defines.h"
#include "utn_inputs.h"

/** \brief Muestra el menu principal de la aplicacion
 * \param void Nothing
 * \return int Devuelve la opcion ingresada por el usuario.
 */
int ShowMainMenu();

/** \brief Muestra el menu de modificacion.
 * \param void Nothing
 * \return int Devuelve la opcion ingresada por el usuario.
 */
int ShowModifyMenu();

#endif /* MENU_H_ */
