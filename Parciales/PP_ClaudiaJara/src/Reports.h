#ifndef REPORTS_H_
#define REPORTS_H_

#include <stdio.h>
#include "utn_inputs.h"
#include "Client.h"
#include "Loan.h"
/*
 * \brief Show the client with more loans active
 * \param arrayClient Array of employees
 * \param size Array length
 * \return void nothing
 * */
void ShowClientWithMoreActiveLoans(eLoan loanArray[], int sizeLoan, eClient clientArray[], int sizeClient);
/*
 * \brief Show the client with more loans paid out
 * \param arrayClient Array of employees
 * \param size Array length
 * \return void nothing
 * */
void ShowClientWithMorePayedLoans(eLoan loanArray[], int sizeLoan, eClient clientArray[], int sizeClient);

/*
 * \brief Show the client with more loans,paid out or active
 * \param arrayClient Array of employees
 * \param size Array length
 * \return void nothing
 * */
void ShowClientWithMoreLoans(eLoan loanArray[], int sizeLoan, eClient clientArray[], int sizeClient);
/*
 * \brief Show the quantity of loans accordind the minimun amount(1000)
 * \param loanArray Array of employees
 * \param sizeLoan Array length
 * \return void nothing
 * */
void ShowLoansUpperDefaultMin(eLoan loanArray[], int sizeLoan);
/*
 * \brief Show the quantity of loans accordind an amount
 * \param loanArray Array of employees
 * \param sizeLoan Array length
 * \return void nothing
 * */
void ShowLoansUpperByAmount(eLoan loanArray[], int sizeLoan);

/*
 * \brief Show the quantity of loans by fee and state
 * \param loanArray Array of employees
 * \param sizeLoan Array length
 * \return void nothing
 * */
void ShowLoansByFeeAndState(eLoan loanArray[], int sizeLoan);
/*
 * \brief Show the quantity of loans accordind a quantity of fees
 * \param loanArray Array of employees
 * \param sizeLoan Array length
 * \return void nothing
 * */
void ShowLoansByFee(eLoan loanArray[], int sizeLoan);


#endif /* REPORTS_H_ */
