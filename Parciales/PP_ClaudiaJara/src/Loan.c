#include "Loan.h"

void AddLoan(eLoan loanArray[], int size, eClient clientArray[], int sizeClient,
		int *id) {
	if (loanArray != NULL && clientArray != NULL && size > 0 && sizeClient > 0
			&& *id > 0) {
		//Verifico si hay lugar libre
		printf("********** INICIO AGREGAR PRESTAMO ***********\n");
		int index = GetFreeIndexLoan(loanArray, size);
		if (index != ERROR && !IsEmptyClientArray(clientArray, sizeClient)) {
			int idClient;
			float amount;
			int fees;
			int indexClient;
			int currentId;
			currentId = *id;
			//Pido los datos
			GetDataNewLoan(&idClient, &amount, &fees);
			//Valido que el cliente exista
			indexClient = FindClientById(clientArray, sizeClient, idClient);
			while (indexClient == ERROR) {
				GetIntNumberNoMinMax(&idClient, "Ingrese el id del cliente: ",
						"ERROR: ingrese numeros\n", RETRIES);
				indexClient = FindClientById(clientArray, sizeClient, idClient);
			}
			//agrego el nuevo prestamo
			loanArray[index] = NewLoan(currentId, idClient, amount, fees);
			//muestro el id por pantalla
			printf(
					"Se agrego el nuevo prestamo con exito, el id generado es: %d\n",
					currentId);
			currentId++;
			*id = currentId;
		} else {
			printf(
					":::AGREGAR::: No hay lugar libre para agregar nuevos prestamos.\n");
		}
		printf("********** FIN AGREGAR PRESTAMO ***********\n");
	}
}

eLoan NewLoan(int id, int idClient, float amount, int fees) {
	eLoan newLoan;
	newLoan.id = id;
	newLoan.idClient = idClient;
	newLoan.amount = amount;
	newLoan.fees = fees;
	strcpy(newLoan.state, STATE_ACTIVE);
	newLoan.isEmpty = NO_EMPTY;
	return newLoan;
}

void GetDataNewLoan(int *idClient, float *amount, int *fees) {
	GetIntNumberNoMinMax(idClient, "Ingrese el id del cliente: ",
			"ERROR: ingrese numeros\n", RETRIES);
	GetFloatNumber(amount, "Ingrese el importe:", "ERROR: ingrese numeros\n", 1,
			1000000, RETRIES);
	GetIntNumber(fees, "Ingrese la cantidad de cuotas:",
			"ERROR: ingrese de nuevo, solo se admiten hasta 100 cuotas", 1, 100,
			RETRIES);
}
//Pausar
void PayLoan(eLoan loanArray[], int size, eClient clientArray[], int sizeClient) {
	if (loanArray != NULL && clientArray != NULL && size > 0
			&& sizeClient > 0) {
		printf("********** INICIO SALDAR PRESTAMO ***********\n");
		if (!IsEmptyLoanArray(loanArray, size)
				&& !IsEmptyClientArray(clientArray, sizeClient)) {
			//pido el id del prestamo
			int indexLoan;
			int idLoan;
			char response;
			ShowLoanArray(loanArray, size);
			do {
				GetIntNumberNoMinMax(&idLoan, "Ingrese el id del prestamo: ",
						"ERROR: ingrese numeros\n", RETRIES);
				indexLoan = GetLoanById(loanArray, size, idLoan);
			} while (indexLoan == ERROR);
			//obtengo el cliente y muestro los datos
			printf("Cliente al que pertenece el prestamo\n");
			ShowClient(
					GetClientById(clientArray, sizeClient,
							loanArray[indexLoan].idClient));
			ShowLoan(loanArray[indexLoan]);
			GetCaracter(&response, "Esta seguro de saldar la deuda?(s - n) :",
					"ERROR: ingrese s - n\n", 'n', 's', RETRIES);
			if (response == 's') {
				printf("Realizando el pago...\n");
				ChangeState(loanArray, indexLoan, 0);
				printf("Se realizo el pago.\n");
			} else {
				printf("Cancelando el pago.\n");
			}
		} else {
			printf(":::SALDAR::: La lista de prestamos esta vacia.\n");
		}
		printf("********** FIN SALDAR PRESTAMO ***********\n");
	}
}

void ChangeState(eLoan loanArray[], int index, int state) {
	if (state) {
		strcpy(loanArray[index].state, STATE_ACTIVE);
	} else {
		strcpy(loanArray[index].state, STATE_PAYED);
	}
}

//Reanudar
void ResumeLoan(eLoan loanArray[], int size, eClient clientArray[],
		int sizeClient) {
	if (loanArray != NULL && clientArray != NULL && size > 0
			&& sizeClient > 0) {
		printf("********** INICIO REANUDAR PRESTAMO ***********\n");
		if (!IsEmptyLoanArray(loanArray, size)
				&& !IsEmptyClientArray(clientArray, sizeClient)) {
			//pido el id del prestamo
			int indexLoan;
			int idLoan;
			char response;
			ShowLoanArray(loanArray, size);
			do {
				GetIntNumberNoMinMax(&idLoan, "Ingrese el id del prestamo: ",
						"ERROR: ingrese numeros\n", RETRIES);
				indexLoan = GetLoanById(loanArray, size, idLoan);
			} while (indexLoan == ERROR);
			//obtengo el cliente y muestro los datos
			ShowClient(
					GetClientById(clientArray, sizeClient,
							loanArray[indexLoan].idClient));
			ShowLoan(loanArray[indexLoan]);
			GetCaracter(&response, "Esta seguro de reanudar la deuda?(s - n) :",
					"ERROR: ingrese s - n\n", 'n', 's', RETRIES);
			if (response == 's') {
				printf("Reanudando el pago...\n");
				ChangeState(loanArray, indexLoan, 1);
				printf("Se reanudo el pago.\n");
			} else {
				printf("Cancelando la reanudacion del pago.\n");
			}
		} else {
			printf(":::REANUDAR::: La lista de prestamos esta vacia.\n");
		}
		printf("********** FIN REANUDAR PRESTAMO ***********\n");
	}

}

//Mostrar
void ShowLoanArray(eLoan loanArray[], int size) {
	if (loanArray != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			if (loanArray[i].isEmpty == NO_EMPTY) {
				ShowLoan(loanArray[i]);
			}
		}
	}
}
void ShowLoan(eLoan loan) {
	printf("Id: %d - Importe: %f - Cuotas: %d - Estado: %s\n", loan.id,
			loan.amount, loan.fees, loan.state);
}

//Genericas
int IsEmptyLoanArray(eLoan loanArray[], int size) {
	int status = ERROR;
	if (loanArray != NULL && size > 0) {
		status = EMPTY;
		for (int i = 0; i < size; i++) {
			if (loanArray[i].isEmpty == NO_EMPTY) {
				status = NO_EMPTY;
				break;
			}
		}

	}
	return status;
}

int GetFreeIndexLoan(eLoan loanArray[], int size) {
	int status = ERROR;
	if (loanArray != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			if (loanArray[i].isEmpty == EMPTY) {
				status = i;
				break;
			}
		}
	}
	return status;
}

int DeleteLoanByClient(eLoan loanArray[], int size, int idClient) {
	int status = ERROR;
	if (loanArray != NULL && size > 0 && idClient > 0) {
		for (int i = 0; i < size; i++) {
			if (loanArray[i].idClient
					== idClient&& loanArray[i].isEmpty == NO_EMPTY) {
				loanArray[i].isEmpty = EMPTY;
			}
		}
		status = OK;
	}
	return status;
}

int InitLoanArray(eLoan loanArray[], int size) {
	int status = ERROR;
	if (loanArray != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			loanArray[i].isEmpty = EMPTY;
		}
		status = OK;
	}
	return status;
}

int GetLoanById(eLoan loanArray[], int size, int id) {
	int status = ERROR;
	if (loanArray != NULL && size > 0 && id > 0) {
		for (int i = 0; i < size; i++) {
			if (loanArray[i].id == id && loanArray[i].isEmpty == NO_EMPTY) {
				status = i;
				break;
			}
		}
	}
	return status;
}

int GetActivesLoansByIdClient(eLoan loanArray[], int size, int idClient,
		int statusLoan) {
	int status = ERROR;
	int quantity = 0;
	if (loanArray != NULL && size > 0 && idClient > 0) {
		for (int i = 0; i < size; i++) {
			if (statusLoan) {
				if (loanArray[i].idClient
						== idClient&& strcmp(loanArray[i].state, STATE_ACTIVE)==0 && loanArray[i].isEmpty == NO_EMPTY) {
					quantity++;
				}
			} else {
				if (loanArray[i].idClient
						== idClient&& strcmp(loanArray[i].state, STATE_PAYED)==0 && loanArray[i].isEmpty == NO_EMPTY) {
					quantity++;
				}
			}
		}
		status = quantity;
	}
	return status;
}

int GetClientIdWihtMoreLoansByState(eClient clientArray[], int sizeClient,
		eLoan loanArray[], int size, int state) {
	int status = ERROR;
	int idClient;
	int maxQuantityLoans;
	int quantityLoans;
	if (loanArray != NULL && size > 0 && clientArray != NULL
			&& sizeClient > 0) {
		for (int i = 0; i < size; i++) {
			if (clientArray[i].isEmpty == NO_EMPTY) {
				quantityLoans = GetActivesLoansByIdClient(loanArray, size,
						clientArray[i].id, state);
			}
			//busco maximo
			if (state) {
				if (maxQuantityLoans < quantityLoans || i == 0) {
					idClient = clientArray[i].id;
					maxQuantityLoans = quantityLoans;
				}
			} else {
				if (maxQuantityLoans < quantityLoans || i == 0) {
					idClient = clientArray[i].id;
					maxQuantityLoans = quantityLoans;
				}
			}
		}
		status = idClient;
	}
	return status;
}

int GetClientIdWihtMoreLoans(eClient clientArray[], int sizeClient,
		eLoan loanArray[], int size) {
	//Busco todos los prestamos de los clientes, activos o no
	int status = ERROR;
	int idClient;
	int maxQuantityLoans;
	int totalLoans;
	int quantityLoansActive;
	int quantityLoansPaid;
	if (loanArray != NULL && size > 0 && clientArray != NULL
			&& sizeClient > 0) {
		for (int i = 0; i < size; i++) {
			if (clientArray[i].isEmpty == NO_EMPTY) {
				//busco los activos
				quantityLoansActive = GetActivesLoansByIdClient(loanArray, size,
						clientArray[i].id, 1);
				//busco los saldados
				quantityLoansPaid = GetActivesLoansByIdClient(loanArray, size,
						clientArray[i].id, 0);
				//total
				totalLoans = quantityLoansActive + quantityLoansPaid;
			}
			//busco maximo
			if (maxQuantityLoans < totalLoans || i == 0) {
				idClient = clientArray[i].id;
				maxQuantityLoans = totalLoans;
			}
		}
		status = idClient;
	}
	return status;
}

int QuantityLoansUpper(eLoan loanArray[], int size, int useDefaultMin,
		float amount) {
	int status = ERROR;
	int quantity = 0;
	float currentAmount;
	if (loanArray != NULL && size > 0) {
		if (useDefaultMin) {
			currentAmount = 1000;
			for (int i = 0; i < size; i++) {
				if (loanArray[i].isEmpty == NO_EMPTY) {
					if (loanArray[i].amount > currentAmount) {
						quantity++;
					}
				}
			}
		} else {
			currentAmount = amount;
			for (int i = 0; i < size; i++) {
				if (loanArray[i].isEmpty == NO_EMPTY) {
					if (loanArray[i].amount == currentAmount) {
						quantity++;
					}
				}
			}
		}
		status = quantity;
	}
	return status;
}

int QuantityLoansByFees(eLoan loanArray[], int size, int fees, int state) {
	int status = ERROR;
	int quantity = 0;
	float currentFees;
	if (loanArray != NULL && size > 0) {
		if (state) {
			currentFees = fees;
			for (int i = 0; i < size; i++) {
				if (loanArray[i].isEmpty == NO_EMPTY) {
					if (loanArray[i].fees == currentFees && strcmp(loanArray[i].state, STATE_ACTIVE)==0) {
						quantity++;
					}
				}
			}
		} else {
			currentFees = 12;
			for (int i = 0; i < size; i++) {
				if (loanArray[i].isEmpty == NO_EMPTY) {
					if (loanArray[i].fees == currentFees && strcmp(loanArray[i].state, STATE_PAYED)==0) {
						quantity++;
					}
				}
			}
		}
		status = quantity;
	}
	return status;
}

