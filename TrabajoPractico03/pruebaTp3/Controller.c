#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	printf("--------- :::[INIT]::: LOAD FROM TEXT \n----------");
	printf("--------- :::[END]::: LOAD FROM TEXT \n----------");
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	printf("--------- :::[INIT]::: LOAD FROM BINARY \n----------");
	printf("--------- :::[END]::: LOAD FROM BINARY \n----------");
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	printf("--------- :::[INIT]::: ADD EMPLOYEE \n----------");
	printf("--------- :::[END]::: ADD EMPLOYEE \n----------");
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	printf("--------- :::[INIT]::: EDIT EMPLOYEE \n----------");
	printf("--------- :::[END]::: EDIT EMPLOYEE \n----------");
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	printf("--------- :::[INIT]::: REMOVE EMPLOYEE \n----------");
	printf("--------- :::[END]::: REMOVE EMPLOYEE \n----------");
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	printf("--------- :::[INIT]::: SHOW LIST  EMPLOYEE \n----------");
	printf("--------- :::[END]::: SHOW LIST  EMPLOYEE \n----------");
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	printf("--------- :::[INIT]::: SHOW LIST  EMPLOYEE \n----------");
	printf("--------- :::[END]::: SHOW LIST  EMPLOYEE \n----------");
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	printf("--------- :::[INIT]::: SAVE AS TEXT \n----------");
	printf("--------- :::[END]::: SAVE AS TEXT \n----------");
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	printf("--------- :::[INIT]::: SAVE AS BINARY \n----------");
	printf("--------- :::[END]::: SAVE AS BINARY \n----------");
    return 1;
}

