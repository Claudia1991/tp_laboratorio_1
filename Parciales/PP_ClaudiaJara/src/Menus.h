#ifndef MENUS_H_
#define MENUS_H_
#include <stdio.h>
#include "utn_inputs.h"
#include "defines.h"
/*
 * \brief Show the main menu.
 * \param void Nothing
 * \return int Return the option of the user
 * */
int MainMenu();
/*
 * \brief Show the modify client menu.
 * \param void Nothing
 * \return int Return the option of the user
 * */
int ModifyClientMenu();
/*
 * \brief Show the reports clients menu.
 * \param void Nothing
 * \return int Return the option of the user
 * */
int ReportsClient();
/*
 * \brief Show the reports loans menu.
 * \param void Nothing
 * \return int Return the option of the user
 * */
int ReportsLoan();

#endif /* MENUS_H_ */
