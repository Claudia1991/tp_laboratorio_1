/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto) y los carga dentro de la lista de empleados.
 *
 * \param FILE* pFile Puntero al archivo de texto.
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) si pFile es NULL o pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario) y los carga dentro de la lista de empleados..
 *
 * \param FILE* pFile Puntero al archivo de texto.
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) si pFile es NULL o pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados. Agrega un empleado a la lista dinamica de empleados.
 *
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado. Edita un empleado de la lista dinamica de empleados.
 *
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado. Elimina un empleado de la lista dinamica de empleados.
 *
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados. Muestra los empleados de la lista dinamica de empleados.
 *
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados.
 *
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param FILE* pFile Puntero al archivo de texto.
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) si pFile es NULL o pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param FILE* pFile Puntero al archivo de texto.
 * \param LinkedList* pArrayListEmployee Lista dinamica de empleados.
 * \return int Devuelve ERROR(-1) si pFile es NULL o pArrayListEmployee es NULL, sino devuelve OK (0)
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
