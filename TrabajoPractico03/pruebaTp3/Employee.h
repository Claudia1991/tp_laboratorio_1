#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn_inputs.h"
#include "utn_validators.h"
#include "defines.h"

typedef struct {
	int id;
	char nombre[SIZE_CHAR_ARRAY];
	int horasTrabajadas;
	int sueldo;
} Employee;

/** \brief Crea espacio en memoria para un nuevo empleado sin datos.
 *
 * \param void Nothing
 * \return Employee* Devuelve un puntero a la direccion de memoria.
 *
 */
Employee* employee_new();


/** \briefCrea espacio en memoria para un nuevo empleado con datos.
 *
 * \param char* idStr Id para el nuevo empleado.
 * \param char* nombreStr Nombre para el nuevo empleado.
 * \param char* horasTrabajadasStr Horas trabajadas para el nuevo empleado.
 * \param char* sueldoStr Sueldo para el nuevo empleado.
 * \return Employee* Devuelve un puntero a la direccion de memoria o NULL si no se pudo crear el empleado.
 *
 */
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr);


/** \brief Elimina el empleado y libera memoria.
 *
 * \param Employee* this Puntero al empleado.
 * \return void Nothing
 *
 */
void employee_delete(Employee *this);


/** \brief Actualiza el id del empleado.
 *
 * \param Employee* this Puntero al empleado.
 * \param int id El nuevo id del empleado.
 * \return int Devuelve ERROR(-1) si this es NULL, sino devuelve OK (0)
 * */
int employee_setId(Employee *this, int id);


/** \brief Obtiene el id del empleado.
 *
 * \param Employee* this Puntero al empleado.
 * \param int* id Puentero donde se guardara el id.
 * \return int Devuelve ERROR(-1) si this es NULL o id es NULL, sino devuelve OK (0)
 *
 */
int employee_getId(Employee *this, int *id);

/** \brief Actualiza el nombre del empleado.
 *
 * \param Employee* this Puntero al empleado.
 * \param char* nombre El nuevo nombre del empleado.
 * \return int Devuelve ERROR(-1) si this es NULL o nombre es NULL, sino devuelve OK (0)
 * */

int employee_setNombre(Employee *this, char *nombre);


/** \brief Obtiene nombre del empleado.
 *
 * \param Employee* this Puntero al empleado.
 * \param cahr* nombre Puentero donde se guardara el nombre.
 * \return int Devuelve ERROR(-1) si this es NULL o nombre es NULL, sino devuelve OK (0)
 *
 */
int employee_getNombre(Employee *this, char *nombre);


/** \brief Actualiza las horas trabajadas del empleado.
 *
 * \param Employee* this Puntero al empleado.
 * \param int horasTrabajadas Las nuevas horas trabajadas del empleados.
 * \return int Devuelve ERROR(-1) si this es NULL o horasTrabajadas < 0, sino devuelve OK (0)
 *
 */
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);


/** \brief Obtiene las horas trabajadas del empleado.
 *
 * \param Employee* this Puntero al empleado.
 * \param int* horasTrabajadas Puentero donde se guardara las horas trabajadas.
 * \return int Devuelve ERROR(-1) si this es NULL o horasTrabajadas es NULL, sino devuelve OK (0)
 *
 */
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);


/** \brief Actualiza el sueldo del empleado.
 *
 * \param Employee* this Puntero al empleado.
 * \param int sueldo El nuevo sueldo.
 * \return int Devuelve ERROR(-1) si this es NULL o sueldo < 0, sino devuelve OK (0)
 *
 */
int employee_setSueldo(Employee *this, int sueldo);


/** \brief Obtiene el sueldo del empleado.
 *
 * \param Employee* this Puntero al empleado.
 * \param int* sueldo Puentero donde se guardara el sueldo.
 * \return int Devuelve ERROR(-1) si this es NULL o sueldo es NULL, sino devuelve OK (0)
 *
 */
int employee_getSueldo(Employee *this, int *sueldo);


/** \brief Muestra al empleado.
 *
 * \param Employee* this Puntero al empleado a mostrar.
 * \return void Nothing
 *
 */
void employee_show(Employee *this);


/** \brief Pide los datos para el nuevo empleado.
 *
 * \param char* nombre Puntero donde se guarda el nombre del empleado.
 * \param char* horasTrabajadas Puntero donde se guarda las horas trabajadas del empleado.
 * \param char* sueldo Puntero donde se guarda el sueldo del empleado.
 * \param int* statusNombre Resultado de la obtencion de nombre.
 * \param int* statusHorasTrabajadas Resultado de la obtencion de horas trabajadas.
 * \param int* statusSueldo Resultado de la obtencion de sueldo.
 * \return void Nothing
 *
 */
void employee_GetDataForNewEmployee(char *nombre, char *horasTrabajadas,
		char *sueldo, int *statusNombre, int *statusHorasTrabajadas,
		int *statusSueldo);



/** \brief Compara dos empleados por sus nombres
 *
 * \param void* itemOne Puntero al primer empleado a comparar.
 * \param void* itemTwo Puntero al segundo empleado a comparar.
 * \return int Devuelve 0 si itemOne es NULL o itemTwo es NULL, sino devuelve 1 si itemOne es mayor sino -1 si itemOne es menor
 *
 */
int employee_OrderListEmployeesByName(void *itemOne, void *itemTwo);


/** \brief Compara dos empleados por sus horas trabajadas
 *
 * \param void* itemOne Puntero al primer empleado a comparar.
 * \param void* itemTwo Puntero al segundo empleado a comparar.
 * \return int Devuelve 0 si itemOne es NULL o itemTwo es NULL, sino devuelve 1 si itemOne es mayor sino -1 si itemOne es menor
 *
 */
int employee_OrderListEmployeesByWordedHours(void *itemOne, void *itemTwo);


/** \brief Compara dos empleados por sus salarios
 *
 * \param void* itemOne Puntero al primer empleado a comparar.
 * \param void* itemTwo Puntero al segundo empleado a comparar.
 * \return int Devuelve 0 si itemOne es NULL o itemTwo es NULL, sino devuelve 1 si itemOne es mayor sino -1 si itemOne es menor
 *
 */
int employee_OrderListEmployeesBySalary(void *itemOne, void *itemTwo);

#endif // employee_H_INCLUDED
