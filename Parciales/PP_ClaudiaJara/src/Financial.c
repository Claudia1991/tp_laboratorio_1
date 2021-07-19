#include "Client.h"
#include "Loan.h"
#include "Menus.h"
#include "Reports.h"
#include "Printers.h"
#include "defines.h"

int main(void) {
	setbuf(stdout, NULL);
	int idClientToDelete;
	int idClient = 1;
	int idLoan = 1;
	char respuesta = 's';
	eClient clients[SIZE_ARRAY_CLIENTS];
	eLoan loans[SIZE_ARRAY_LOANS];
	InitClientArray(clients, SIZE_ARRAY_CLIENTS);
	InitLoanArray(loans, SIZE_ARRAY_LOANS);
	printf("---*** INICIO EMPRESA FINANCIERA ***---\n");
	do {
		switch (MainMenu()) {
		case ADD_CLIENT:
			AddClient(clients, SIZE_ARRAY_CLIENTS, &idClient);
			break;
		case MODIFY_CLIENT:
			ModifyClient(clients, SIZE_ARRAY_CLIENTS);
			break;
		case DELETE_CLIENT:
			idClientToDelete = DeleteClient(clients, SIZE_ARRAY_CLIENTS);
			DeleteLoanByClient(loans, SIZE_ARRAY_LOANS, idClientToDelete);
			break;
		case NEW_LOAN:
			AddLoan(loans, SIZE_ARRAY_LOANS, clients, SIZE_ARRAY_CLIENTS,
					&idLoan);
			break;
		case PAY_LOAN:
			PayLoan(loans, SIZE_ARRAY_LOANS, clients, SIZE_ARRAY_CLIENTS);
			break;
		case RESUME_LOAN:
			ResumeLoan(loans, SIZE_ARRAY_LOANS, clients, SIZE_ARRAY_CLIENTS);
			break;
		case SHOW_CLIENTS:
			ShowClientsAndActivesLoans(clients, SIZE_ARRAY_CLIENTS, loans,
			SIZE_ARRAY_LOANS);
			break;
		case SHOW_LOANS:
			ShowLoansWithCuilClient(loans, SIZE_ARRAY_LOANS, clients,
					SIZE_ARRAY_CLIENTS);
			break;
		case REPORTS_CLIENTS:
			if (!IsEmptyClientArray(clients, SIZE_ARRAY_CLIENTS)) {
				do {
					switch (ReportsClient()) {
					case CLIENT_MORE_ACTIVE_LOANS:
						ShowClientWithMoreActiveLoans(loans,
						SIZE_ARRAY_LOANS, clients, SIZE_ARRAY_CLIENTS);
						break;
					case CLIENT_MORE_ACTIVE_PAYED:
						ShowClientWithMorePayedLoans(loans,
						SIZE_ARRAY_LOANS, clients, SIZE_ARRAY_CLIENTS);
						break;
					case CLIENT_MORE_LOANS:
						ShowClientWithMoreLoans(loans,
						SIZE_ARRAY_LOANS, clients, SIZE_ARRAY_CLIENTS);
						break;
					}
					GetCaracter(&respuesta, "Quiere ver otro informe? s - n: ",
							"ERROR: ingrese s o n: ", 'n', 's', RETRIES);
				} while (respuesta == 's');
			} else {
				printf(":::[LA LISTA DE CLIENTES ESTA VACIA]:::\n");
			}
			break;
		case REPORTS_LOANS:
			if (!IsEmptyLoanArray(loans, SIZE_ARRAY_LOANS)) {
				do {
					switch (ReportsLoan()) {
					case LOANS_UPPER:
						ShowLoansUpperDefaultMin(loans, SIZE_ARRAY_LOANS);
						break;
					case LOANS_BY_IMPORT:
						ShowLoansUpperByAmount(loans, SIZE_ARRAY_LOANS);
						break;
					case LOANS_PAID_OUT:
						ShowLoansByFeeAndState(loans, SIZE_ARRAY_LOANS);
						break;
					case LOANS_BY_QUANTITY_FEE:
						ShowLoansByFee(loans, SIZE_ARRAY_LOANS);
						break;
					}
					GetCaracter(&respuesta, "Quiere ver otro informe? s - n: ",
							"ERROR: ingrese s o n: ", 'n', 's', RETRIES);
				} while (respuesta == 's');
			} else {
				printf(":::[LA LISTA DE PRESTAMOS ESTA VACIA]:::\n");
			}
			break;
		case EXIT:
			printf("---*** FIN EMPRESA FINANCIERA ***---\n");
			exit(0);
			break;
		}
	} while (1);
	return EXIT_SUCCESS;
}
