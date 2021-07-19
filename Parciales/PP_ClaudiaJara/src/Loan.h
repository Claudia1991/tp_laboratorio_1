#ifndef LOAN_H_
#define LOAN_H_
#include "defines.h"
#include "Client.h"
#include "utn_inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menus.h"
typedef struct{
	int id;
	int idClient;
	float amount;
	int fees;
	char state[SIZE_CHAR_ARRAY];
	int isEmpty;
}eLoan;

#endif /* LOAN_H_ */
/*
 * \brief Add a new loan to the array.
 * \param loanArray Array of loans
 * \param size Array of loans length
 * \param clientArray Array of clients
 * \param sizeClient Array of clients length
 * \param id Id to the new loan
 * \return void nothing
 * */
void AddLoan(eLoan loanArray[], int size, eClient clientArray[],  int sizeClient, int *id);
/*
 * \brief Create a new loan.
 * \param id Id of the new loan
 * \param idClient Id of the client whom the loan belongs
 * \param amount total loan amount
 * \param fees amount of fees to pay
 * \return eLoan Return a new loan
 * */
eLoan NewLoan(int id,int idClient, float amount, int fees);
/*
 * \brief Ask the data for a new loan.
 * \param idClient Id of the client whom the loan belongs
 * \param amount total loan amount
 * \param fees amount of fees to pay
 * \return void nothing
 * */
void GetDataNewLoan(int *idClient, float *amount, int *fees);
/*
 * \brief Pay a loan by id.
 * \param loanArray Array of loans
 * \param size Array of loans length
 * \param clientArray Array of clients
 * \param sizeClient Array of clients length
 * \return void nothing
 * */
void PayLoan(eLoan loanArray[], int size, eClient clientArray[], int sizeClient);
/*
 * \brief Change the state of a loan.
 * \param loanArray Array of loans
 * \param index The index of the loan to change the state
 * \param state The new state
 * \return void nothing
 * */
void ChangeState(eLoan loanArray[],int index, int state);
/*
 * \brief Resume a loan by id.
 * \param loanArray Array of loans
 * \param size Array of loans length
 * \param clientArray Array of clients
 * \param sizeClient Array of clients length
 * \return void nothing
 * */
void ResumeLoan(eLoan loanArray[], int size, eClient clientArray[], int sizeClient);
/*
 * \brief Show the data of an array of loans.
 * \param loanArray Array of loans
 * \param size Array length
 * \return void nothing
 * */
void ShowLoanArray(eLoan loanArray[], int size);
/*
 * \brief Show the data of a loan.
 * \param eLoan A loan to show
 * \return int void nothing
 * */
void ShowLoan(eLoan loan);
/*
 * \brief To indicate if the array is empty..
 * \param loanArray Array of loan
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int IsEmptyLoanArray(eLoan loanArray[], int size);
/*
 * \brief Get the first empty position..
 * \param loanArray Array of loan
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - the empty positon if OK
 * */
int GetFreeIndexLoan(eLoan loanArray[], int size);
/*
 * \brief Delete all the loans of a client by id client.
 * \param loanArray Array of loans
 * \param size Array length
 * \param idClient The id of the client
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int DeleteLoanByClient(eLoan loanArray[], int size, int idClient);
/*
 * \brief Initialize the array, put the flag isEmpty in (1)..
 * \param loanArray Array of loans
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int InitLoanArray(eLoan loanArray[], int size);
/*
 * \brief Get the position of a loan by id..
 * \param loanArray Array of loan
 * \param size Array length
 * \param id Id of the loan
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int GetLoanById(eLoan loanArray[], int size, int id);
/*
 * \brief Get the quantity of loans by client.
 * \param loanArray Array of loan
 * \param size Array length
 * \param idClient The id of the client
 * \param statusLoan The state of the loan to search
 * \return int Return the quantity of loans by client
 * */
int GetActivesLoansByIdClient(eLoan loanArray[], int size, int idClient, int statusLoan);
/*
 * \brief Get the id of the client with more loans active o paid out.
 * \param arrayClient Array of clients
 * \param sizeClient Array of clients length
 * \param loanArray Array of loan
 * \param size Array of loan length
 * \param state The state of the loan to search
 * \return int Return the id of the client with more loans active o paid out
 * */
int GetClientIdWihtMoreLoansByState(eClient clientArray[], int sizeClient,eLoan loanArray[], int size, int state);

/*
 * \brief Get the id of the client with more loans active o paid out.
 * \param arrayClient Array of clients
 * \param sizeClient Array of clients length
 * \param loanArray Array of loan
 * \param size Array of loan length
 * \param state The state of the loan to search
 * \return int Return the id of the client with more loans active o paid out
 * */
int GetClientIdWihtMoreLoans(eClient clientArray[], int sizeClient,eLoan loanArray[], int size);
/*
 * \brief Get the quantity of loans by criteria.
 * \param loanArray Array of loan
 * \param size Array length
 * \param useDefaultMin Indicates if use the default criteria amount
 * \param amount The total loan amount
 * \return int Return the quantity of loans by criteria
 * */
int QuantityLoansUpper(eLoan loanArray[], int size, int useDefaultMin, float amount);

/*
 * \brief Get the quantity of loans by fees.
 * \param loanArray Array of loan
 * \param size Array length
 * \param useDefaultMin Indicates if use the default criteria amount
 * \param amount The total loan amount
 * \return int Return the quantity of loans by criteria
 * */
int QuantityLoansByFees(eLoan loanArray[], int size, int fees,int state);


























