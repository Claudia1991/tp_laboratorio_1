#include "Client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menus.h"
#include "utn_inputs.h"

int InitClientArray(eClient arrayClient[], int size) {
	int status = ERROR;
	if (arrayClient != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			arrayClient[i].isEmpty = EMPTY;
		}
		status = OK;
	}
	return status;
}
//Generics
int IsEmptyClientArray(eClient arrayClient[], int size) {
	int status = ERROR;
	if (arrayClient != NULL && size > 0) {
		status = EMPTY;
		for (int i = 0; i < size; i++) {
			if (arrayClient[i].isEmpty == NO_EMPTY) {
				status = OK;
				break;
			}
		}

	}
	return status;
}

int GetFreeIndexClientArray(eClient arrayClient[], int size) {
	int status = ERROR;
	if (arrayClient != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			if (arrayClient[i].isEmpty == EMPTY) {
				status = i;
				break;
			}
		}

	}
	return status;
}

eClient GetClientById(eClient arrayClient[], int size, int id) {
	eClient client;
	if (arrayClient != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			if (arrayClient[i].id == id && arrayClient[i].isEmpty == NO_EMPTY) {
				client = arrayClient[i];
				break;
			}
		}

	}
	return client;
}

//Add
void AddClient(eClient arrayClient[], int size, int *id) {
	//Primero verifico que le lista no este vacia
	printf("+++ INGRESO ALTA CLIENTE +++\n");
	int index;
	index = GetFreeIndexClientArray(arrayClient, size);
	if (index != ERROR) {
		//pido los datos para cargar el nuevo cliente
		char name[SIZE_CHAR_ARRAY];
		char lastName[SIZE_CHAR_ARRAY];
		int cuil;
		int currentId = *id;
		GetDataNewClient(name, lastName, &cuil);
		//agrego el nuevo cliente
		arrayClient[index] = NewClient(currentId, name, lastName, cuil);
		//imprimo el id creado
		printf("Se agrego el cliente correctamente. Id generado: %d\n",
				currentId);
		//sumo el id y lo devuelvo
		currentId++;
		*id = currentId;
	} else {
		printf(":::ALTA CLIENTE::: No hay lugar para agregar.\n");
	}
	printf("+++ FIN INGRESO ALTA CLIENTE +++\n");
}

eClient NewClient(int id, char *name, char *lastName, int cuil) {
	eClient newClient;
	newClient.id = id;
	strcpy(newClient.name, name);
	strcpy(newClient.lastName, lastName);
	newClient.cuil=cuil;
	newClient.isEmpty = NO_EMPTY;
	return newClient;
}

int FindClientById(eClient arrayClient[], int size, int id) {
	int status = ERROR;
	if (arrayClient != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			if (arrayClient[i].id == id && arrayClient[i].isEmpty == NO_EMPTY) {
				status = i;
				break;
			}
		}

	}
	return status;
}

void GetDataNewClient(char *name, char *lastName, int *cuil) {
	printf("+++ INGRESO DATOS CLIENTE +++\n");
	GetString(name, "Ingrese el nombre del nuevo cliente: ",
			"ERROR: ingrese el nobre correctamente\n", RETRIES);
	GetString(lastName, "Ingrese el apellido del nuevo cliente: ",
			"ERROR: ingrese el apellido correctamente\n", RETRIES);
	GetIntNumberNoMinMax(cuil, "Ingrese el cuil del nuevo cliente: ",
			"ERROR: ingrese el cuil correctamente\n", RETRIES);
	printf("+++ FIN DATOS CLIENTE +++\n");
}
//Modify
void ModifyClient(eClient arrayClient[], int size) {
	printf("+++ INGRESO MODIFICAR CLIENTE +++\n");
	//verifico que la lista no este vacia
	if (!IsEmptyClientArray(arrayClient, size)) {
		int id;
		int index;
		char name[SIZE_CHAR_ARRAY];
		char lastName[SIZE_CHAR_ARRAY];
		int cuil;
		char response = 's';
		//Mostrar arrayClient
		ShowClients(arrayClient, size);
		do {
			//pido el id para modificar
			GetIntNumberNoMinMax(&id, "Ingrese el id:",
					"ERROR: ingrese numeros:", RETRIES);
			//verifico que el id sea de un cliente que exista
			index = FindClientById(arrayClient, size, id);
		} while (index == ERROR);
		//existe el cliente y tengo el index en el cual se encuentra, muestro los datos del cliente
		ShowClient(arrayClient[index]);
		//Muestro opciones a modificar para el cliente
		do {
			switch (ModifyClientMenu()) {
			case MODIFY_NAME:
				GetString(name, "Ingrese el nombre: ", "ERROR: ingrese letras: ",
						RETRIES);
				strcpy(arrayClient[index].name, name);
				printf("Nombre Modificado.\n");
				break;
			case MODIFY_LASTNAME:
				GetString(lastName, "Ingrese el apellido: ",
						"ERROR: ingrese letras: ", RETRIES);
				strcpy(arrayClient[index].lastName, lastName);
				printf("apellido Modificado.\n");
				break;
			case MODIFY_CUIL:
				GetIntNumberNoMinMax(&cuil, "Ingrese el cuil: ", "ERROR: cuil: ", RETRIES);
				arrayClient[index].cuil= cuil;
				printf("Cuil Modificado.\n");
				break;
			}
			GetCaracter(&response,
					"Quiere modificar algo mas para este cliente? (s(SI) - n(NO)): ",
					"ERROR: ingrese letras: ", 'n', 's', RETRIES);
		} while (response == 's');
	} else {
		printf(":::MODIFICAR CLIENTE:::La lista esta vacia.\n");
	}
	printf("+++ FIN MODIFICAR CLIENTE +++\n");
}
//Delete
int DeleteClient(eClient arrayClient[], int size) {
	printf("+++ INGRESO ELIMINAR CLIENTE +++\n");
	int id;
	int index;
	char respuesta;
	if (!IsEmptyClientArray(arrayClient, size)) {
		ShowClients(arrayClient, size);
		do {
			//pido el id para modificar
			GetIntNumberNoMinMax(&id, "Ingrese el id:",
					"ERROR: ingrese numeros:", RETRIES);
			//verifico que el id sea de un cliente que exista
			index = FindClientById(arrayClient, size, id);
		} while (index == ERROR);
		//existe el cliente y tengo el indice en el cual se encuentra, muestro los datos del cliente
		ShowClient(arrayClient[index]);
		//muestro las publicaciones de ese cliente
		//MostrarPublicacionesSegunCliente(publicaciones, tamPub,clientes[indice].idCliente);
		GetCaracter(&respuesta, "Desea borrar el cliente? s (SI) - n(NO): ",
				"ERROR: ingrese s o n: ", 'n', 's', RETRIES);
		if (respuesta == 's') {
			//EliminarPublicacionesSegunCliente(publicaciones,tamPub,clientes[indice].idCliente);
			arrayClient[index].isEmpty = EMPTY;
			printf("Cliente borrado y sus prestamos.\n");
		} else {
			id = ERROR;
			printf("Cancelando operacion.\n");
		}
	} else {
		printf(":::ELIMINAR CLIENTE:::Lista vacia.\n");
	}
	printf("+++ FIN ELIMINAR CLIENTE +++\n");
	return id;
}

void ShowClient(eClient client) {
	printf("Id: %d - name: %s - lastName: %s - CUIL: %d\n", client.id, client.name,
			client.lastName, client.cuil);
}

int ShowClients(eClient arrayClient[], int size) {
	int status = ERROR;
	if (arrayClient != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			if (arrayClient[i].isEmpty == NO_EMPTY) {
				ShowClient(arrayClient[i]);
			}
		}
		status = OK;
	}
	return status;
}

int GetCuilByIdClint(eClient arrayClient[], int size, int id, int *cuil) {
	int status = ERROR;
	if (arrayClient != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			if (arrayClient[i].id == id && arrayClient[i].isEmpty == NO_EMPTY) {
				*cuil =  arrayClient[i].cuil;
				status = OK;
				break;
			}
		}
	}
	return status;
}

