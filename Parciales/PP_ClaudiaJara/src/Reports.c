#include "Reports.h"

void ShowClientWithMoreActiveLoans(eLoan loanArray[], int sizeLoan,
		eClient clientArray[], int sizeClient) {
	if (clientArray != NULL && loanArray != NULL && sizeClient > 0
			&& sizeLoan > 0) {
		int idClient;
		int index;
		printf(
				"********** INICIO REPORTE CLIENTE CON MAS PRESTAMOS ACTIVOS **********\n");
		if (!IsEmptyClientArray(clientArray, sizeClient)) {
			idClient = GetClientIdWihtMoreLoansByState(clientArray, sizeClient,
					loanArray, sizeLoan, 1);
			index = FindClientById(clientArray, sizeClient, idClient);
			ShowClient(clientArray[index]);
		} else {
			printf(":::[LA LISTA DE CLIENTES ESTA VACIA]:::\n");
		}
		printf(
				"********** FIN REPORTE CLIENTE CON MAS PRESTAMOS ACTIVOS **********\n");
	}
}
void ShowClientWithMorePayedLoans(eLoan loanArray[], int sizeLoan,
		eClient clientArray[], int sizeClient) {
	if (clientArray != NULL && loanArray != NULL && sizeClient > 0
			&& sizeLoan > 0) {
		int idClient;
		int index;
		printf(
				"********** INICIO REPORTE CLIENTE CON MAS PRESTAMOS SALDADOS **********\n");
		if (!IsEmptyClientArray(clientArray, sizeClient)) {
			idClient = GetClientIdWihtMoreLoansByState(clientArray, sizeClient,
					loanArray, sizeLoan, 0);
			index = FindClientById(clientArray, sizeClient, idClient);
			ShowClient(clientArray[index]);
		} else {
			printf(":::[LA LISTA DE CLIENTES ESTA VACIA]:::\n");
		}
		printf(
				"********** FIN REPORTE CLIENTE CON MAS PRESTAMOS SALDADOS **********\n");
	}
}

void ShowClientWithMoreLoans(eLoan loanArray[], int sizeLoan,
		eClient clientArray[], int sizeClient) {
	if (clientArray != NULL && loanArray != NULL && sizeClient > 0
			&& sizeLoan > 0) {
		int idClient;
		int index;
		printf(
				"********** INICIO REPORTE CLIENTE CON MAS PRESTAMOS  **********\n");
		if (!IsEmptyClientArray(clientArray, sizeClient)) {
			idClient = GetClientIdWihtMoreLoans(clientArray, sizeClient,
					loanArray, sizeLoan);
			index = FindClientById(clientArray, sizeClient, idClient);
			if (index != ERROR) {
				ShowClient(clientArray[index]);
			} else {
				printf(":::[NO SE PUEDE MOSTRAR EL INFORME]:::\n");
			}
		} else {
			printf(":::[LA LISTA DE CLIENTES ESTA VACIA]:::\n");
		}
		printf(
				"********** FIN REPORTE CLIENTE CON MAS PRESTAMOS  **********\n");
	}
}

void ShowLoansUpperDefaultMin(eLoan loanArray[], int sizeLoan) {
	if (loanArray != NULL && sizeLoan > 0) {
		printf(
				"********** INICIO REPORTE PRESTAMOS MAYORES A 1000 **********\n");
		if (!IsEmptyLoanArray(loanArray, sizeLoan)) {
			int quantity = QuantityLoansUpper(loanArray, sizeLoan, 1, 0);
			printf("Prestamos mayores a 1000: [%d]\n", quantity);
		} else {
			printf(":::[LA LISTA DE PRESTAMOS ESTA VACIA]:::\n");
		}
		printf("********** FIN REPORTE PRESTAMOS MAYORES A 1000 **********\n");
	}
}
void ShowLoansUpperByAmount(eLoan loanArray[], int sizeLoan) {
	if (loanArray != NULL && sizeLoan > 0) {
		int quantity;
		float amount;
		printf(
				"********** INICIO REPORTE PRESTAMOS MAYORES A UN MONTO **********\n");
		if (!IsEmptyLoanArray(loanArray, sizeLoan)) {
			GetFloatNumberNoMinMax(&amount,
					"Ingrese el monto para realizar el reporte: ",
					"ERROR: ingrese numeros correctamente\n", RETRIES);
			quantity = QuantityLoansUpper(loanArray, sizeLoan, 0, amount);
			printf("Prestamos iguales a [%2f]: [%d]\n", amount, quantity);
		} else {
			printf(":::[LA LISTA DE PRESTAMOS ESTA VACIA]:::\n");
		}
		printf(
				"********** FIN REPORTE PRESTAMOS MAYORES A UN MONTO **********\n");
	}
}

void ShowLoansByFee(eLoan loanArray[], int sizeLoan) {
	if (loanArray != NULL && sizeLoan > 0) {
		int quantity;
		int fees;
		//por criterio tome cantidad de cuotas minima : 1 y maxina : 100
		printf("********** INICIO REPORTE SEGUN CANTIDAD DE CUOTAS **********\n");
		if (!IsEmptyLoanArray(loanArray, sizeLoan)) {
			GetIntNumber(&fees, "Ingrese la cantidad de cuotas:",
						"ERROR: ingrese de nuevo, solo se admiten hasta 100 cuotas", 1, 100,
						RETRIES);
			quantity = QuantityLoansByFees( loanArray, sizeLoan,  fees, 1);
			printf("Prestamos con cantidad de cuotas [%d]: [%d]\n", fees, quantity);
		} else {
			printf(":::[LA LISTA DE PRESTAMOS ESTA VACIA]:::\n");
		}
		printf(
				"********** FIN REPORTE SEGUN CANTIDAD DE CUOTAS **********\n");
	}
}

void ShowLoansByFeeAndState(eLoan loanArray[], int sizeLoan) {
	if (loanArray != NULL && sizeLoan > 0) {
		int quantity;
		printf(
				"********** INICIO REPORTE PRESTAMOS DE 12 CUOTAS SALDADOS **********\n");
		if (!IsEmptyLoanArray(loanArray, sizeLoan)) {
			quantity = QuantityLoansByFees( loanArray, sizeLoan,  0, 0);
			printf("Prestamos saldados con 12 cuotas: [%d]\n",quantity);
		} else {
			printf(":::[LA LISTA DE PRESTAMOS ESTA VACIA]:::\n");
		}
		printf(
				"********** FIN REPORTE PRESTAMOS DE 12 CUOTAS SALDADOS **********\n");
	}
}

