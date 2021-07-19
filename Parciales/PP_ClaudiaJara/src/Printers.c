#include "Printers.h"

void ShowClientsAndActivesLoans(eClient clientArray[], int sizeClient,
		eLoan loanArray[], int sizeLoan) {
	if (clientArray != NULL && loanArray != NULL && sizeClient > 0
			&& sizeLoan > 0) {
		printf("********* INGRESO MOSTRAR CLIENTES *********\n");
		if (!IsEmptyClientArray(clientArray, sizeClient)) {
			int quantityLoans;
			for (int i = 0; i < sizeClient; i++) {
				if (clientArray[i].isEmpty == NO_EMPTY) {
					quantityLoans = GetActivesLoansByIdClient(loanArray,
							sizeLoan, clientArray[i].id, 1);
					ShowClientAndActivesLoans(clientArray[i], quantityLoans);
				}
			}
		} else {
			printf(":::[LA LISTA DE CLIENTES ESTA VACIA]:::\n");
		}
		printf("********* FIN MOSTRAR CLIENTES *********\n");
	}
}
void ShowClientAndActivesLoans(eClient client, int quantityActiveLoans) {
	printf(
			"Id: %d - Nombre: %s - Apellido: %s - Cuil: %d - Prestamos activos: %d\n",
			client.id, client.name, client.lastName, client.cuil,
			quantityActiveLoans);
}

void ShowLoansWithCuilClient(eLoan loanArray[], int sizeLoan,
		eClient clientArray[], int sizeClient) {
	if (clientArray != NULL && loanArray != NULL && sizeClient > 0
			&& sizeLoan > 0) {
		printf("********* INGRESO MOSTRAR PRESTAMOS *********\n");
		if (!IsEmptyLoanArray(loanArray, sizeLoan)) {
			int cuil=0;
			for(int i = 0; i < sizeLoan; i++) {
				if (loanArray[i].isEmpty == NO_EMPTY) {
					GetCuilByIdClint(clientArray, sizeClient,loanArray[i].idClient, &cuil);
					ShowLoanWithCuilClient(loanArray[i], cuil);
				}
			}
		} else {
			printf(":::[LA LISTA DE PRESTAMOS ESTA VACIA]:::\n");
		}
		printf("********* FIN MOSTRAR PRESTAMOS *********\n");
	}
}
void ShowLoanWithCuilClient(eLoan loan, int cuilClient) {
	printf(
			"Id prestamo: %d - Monto: %2f - Cuotas: %d - Estado: %s - Id cliente: %d - Cuil: %d\n",
			loan.id, loan.amount, loan.fees, loan.state, loan.idClient,
			cuilClient);
}
