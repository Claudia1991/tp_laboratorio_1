#ifndef CLIENT_H_
#define CLIENT_H_
#include "defines.h"

typedef struct{
	int id;
	char name[SIZE_CHAR_ARRAY];
	char lastName[SIZE_CHAR_ARRAY];
	int cuil;
	int isEmpty;
}eClient;

#endif /* CLIENT_H_ */
/*
 * \brief Initialize the array, put the flag isEmpty in (1).
 * \param arrayClient Array of employees
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int InitClientArray(eClient arrayClient[], int size);
/*
 * \brief To indicate if the array is empty.
 * \param arrayClient Array of employees
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int IsEmptyClientArray(eClient arrayClient[], int size);
/*
 * \brief Get the first empty position.
 * \param arrayClient Array of employees
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - the empty positon if OK
 * */
int GetFreeIndexClientArray(eClient arrayClient[], int size);
/*
 * \brief Get the entity client by id.
 * \param arrayClient Array of employees
 * \param size Array length
 * \param id The id of the client to return
 * \return eClient Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
eClient GetClientById(eClient arrayClient[], int size, int id);
/*
 * \brief Add a new client to the array.
 * \param arrayClient Array of employees
 * \param size Array length
 * \param id Id to the new client .
 * \return nothing
 * */
void AddClient(eClient arrayClient[], int size, int *id);
/*
 * \brief Add a new client to the array.
 * \param id Id of the client
 * \param name Name of the client
 * \param lastName Lastname of the client.
 * \param cuil Cuil of the client
 * \return eClient The new client created
 * */
eClient NewClient(int id,char *name, char *lastName, int cuil);
/*
 * \brief Get the position of a client by id.
 * \param arrayClient Array of employees
 * \param size Array length
 * \param id Id of the client to find
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght or no exist the id) - the position in the array if OK
 * */
int FindClientById(eClient arrayClient[], int size, int id);
/*
 * \brief Ask the data for the new client.
 * \param name Name of the new client
 * \param lastName LastName of the new client
 * \param cuil Cuil of the new client
 * \return nothing
 * */
void GetDataNewClient(char *name, char *lastName,  int *cuil);
/*
 * \brief Modify the client's data, show a menu.
 * \param arrayClient Array of employees
 * \param size Array length
 * \return nothing
 * */
void ModifyClient(eClient arrayClient[], int size);
/*
 * \brief Delete the client, put the flag isEmpty in (1).
 * \param arrayClient Array of employees
 * \param size Array length
 * \return int Return the id of the deleted client.
 * */
int DeleteClient(eClient arrayClient[], int size);
/*
 * \brief Show data of a client.
 * \param eClient Client to show data
 * \return nothing
 * */
void ShowClient(eClient client);
/*
 * \brief Show the data of the clients.
 * \param arrayClient Array of employees
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int ShowClients(eClient arrayClient[], int size);
/*
 * \brief Get the cuil of a client by id.
 * \param arrayClient Array of employees
 * \param size Array length
 * \param id The id of a client
 * \param cuil The cuil of a client
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int GetCuilByIdClint(eClient arrayClient[], int size, int id,  int *cuil);
