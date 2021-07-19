#ifndef PRINTERS_H_
#define PRINTERS_H_
#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "Loan.h"
/*
 * \brief Show the data of an array client and the quantity of loans
 * \param loanArray Array of loans
 * \param sizeLoan Loan Array length
 * \param arrayClient Array of clients
 * \param sizeClient Client Array length
 * \return nothing
 * */
void ShowClientsAndActivesLoans(eClient clientArray[], int sizeClient, eLoan loanArray[], int sizeLoan);
/*
 * \brief Show the data of the client and the quantity of loans
 * \param eClient Array of employees
 * \param quantityActiveLoans Quantity of loans of the client
 * \return nothing
 * */
void ShowClientAndActivesLoans(eClient client, int quantityActiveLoans);
/*
 * \brief Show the data of an array loan an the cuil of the client to whom the loan belongs
 * \param loanArray Array of loans
 * \param sizeLoan Loan Array length
 * \param arrayClient Array of clients
 * \param sizeClient Client Array length
 * \return nothing
 * */

void ShowLoansWithCuilClient(eLoan loanArray[], int sizeLoan,eClient clientArray[], int sizeClient);
/*
 * \brief Show the data of a loan an the cuil of the client to whom the loan belongs
 * \param eLoan Loan to show data
 * \param cuilClient Cuil of the client to whom the loan belongs
 * \return nothing
 * */
void ShowLoanWithCuilClient(eLoan loan, int cuilClient);

#endif /* PRINTERS_H_ */
