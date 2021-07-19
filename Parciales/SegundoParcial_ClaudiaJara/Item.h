#ifndef item_H_INCLUDED
#define item_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn_inputs.h"
#include "utn_validators.h"
#include "defines.h"

typedef struct {
	int id;
	char item[SIZE_CHAR_ARRAY];
	int price;
	char measure[SIZE_CHAR_ARRAY];
	int idSection;
} eItem;

/** \brief Crea espacio en memoria para un nuevo empleado sin datos.
 *
 * \param void Nothing
 * \return eItem* Devuelve un puntero a la direccion de memoria.
 *
 */
eItem* item_new();


/** \briefCrea espacio en memoria para un nuevo empleado con datos.
 *
 * \param char* idStr Id para el nuevo empleado.
 * \param char* itemStr item para el nuevo empleado.
 * \param char* horasTrabajadasStr Horas trabajadas para el nuevo empleado.
 * \param char* sueldoStr Sueldo para el nuevo empleado.
 * \return eItem* Devuelve un puntero a la direccion de memoria o NULL si no se pudo crear el empleado.
 *
 */
eItem* item_newParametros(char *idStr, char *itemStr,char *priceStr, char *measureStr, char *idSectionStr);


/** \brief Elimina el empleado y libera memoria.
 *
 * \param eItem* this Puntero al empleado.
 * \return void Nothing
 *
 */
void item_delete(eItem *this);


/** \brief Actualiza el id del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param int id El nuevo id del empleado.
 * \return int Devuelve ERROR(-1) si this es NULL, sino devuelve OK (0)
 * */
int item_setId(eItem *this, int id);


/** \brief Obtiene el id del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param int* id Puentero donde se guardara el id.
 * \return int Devuelve ERROR(-1) si this es NULL o id es NULL, sino devuelve OK (0)
 *
 */
int item_getId(eItem *this, int *id);

/** \brief Actualiza el item del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param char* item El nuevo item del empleado.
 * \return int Devuelve ERROR(-1) si this es NULL o item es NULL, sino devuelve OK (0)
 * */

int item_setItem(eItem *this, char *item);


/** \brief Obtiene item del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param cahr* item Puentero donde se guardara el item.
 * \return int Devuelve ERROR(-1) si this es NULL o item es NULL, sino devuelve OK (0)
 *
 */
int item_getItem(eItem *this, char *item);


/** \brief Actualiza las horas trabajadas del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param int horasTrabajadas Las nuevas horas trabajadas del empleados.
 * \return int Devuelve ERROR(-1) si this es NULL o horasTrabajadas < 0, sino devuelve OK (0)
 *
 */
int item_setPrice(eItem *this, float price);


/** \brief Obtiene las horas trabajadas del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param int* horasTrabajadas Puentero donde se guardara las horas trabajadas.
 * \return int Devuelve ERROR(-1) si this es NULL o horasTrabajadas es NULL, sino devuelve OK (0)
 *
 */
int item_getPrice(eItem *this, float *price);


/** \brief Actualiza el sueldo del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param int sueldo El nuevo sueldo.
 * \return int Devuelve ERROR(-1) si this es NULL o sueldo < 0, sino devuelve OK (0)
 *
 */
int item_setMeasure(eItem *this, char *measure);


/** \brief Obtiene el sueldo del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param int* sueldo Puentero donde se guardara el sueldo.
 * \return int Devuelve ERROR(-1) si this es NULL o sueldo es NULL, sino devuelve OK (0)
 *
 */
int item_getMeasure(eItem *this, char *measure);

/** \brief Actualiza el sueldo del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param int sueldo El nuevo sueldo.
 * \return int Devuelve ERROR(-1) si this es NULL o sueldo < 0, sino devuelve OK (0)
 *
 */
int item_setIdSection(eItem *this, int idSection);


/** \brief Obtiene el sueldo del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param int* sueldo Puentero donde se guardara el sueldo.
 * \return int Devuelve ERROR(-1) si this es NULL o sueldo es NULL, sino devuelve OK (0)
 *
 */
int item_getSectionDescriptionByIdSection(int idSection, char *description);

/** \brief Obtiene el sueldo del empleado.
 *
 * \param eItem* this Puntero al empleado.
 * \param int* sueldo Puentero donde se guardara el sueldo.
 * \return int Devuelve ERROR(-1) si this es NULL o sueldo es NULL, sino devuelve OK (0)
 *
 */
int item_getIdSection(eItem *this, int *idSection);


/** \brief Muestra al empleado.
 *
 * \param eItem* this Puntero al empleado a mostrar.
 * \return void Nothing
 *
 */
void item_show(eItem *this);

/** \brief Compara dos empleados por sus items
 *
 * \param void* itemOne Puntero al primer empleado a comparar.
 * \param void* itemTwo Puntero al segundo empleado a comparar.
 * \return int Devuelve 0 si itemOne es NULL o itemTwo es NULL, sino devuelve 1 si itemOne es mayor sino -1 si itemOne es menor
 *
 */
int item_OrderListItemsByItem(void *itemOne, void *itemTwo);

/** \brief Aplica el descuento
 *
 * \param void* itemOne Puntero al primer empleado a comparar.
 * \return int Devuelve -1 si itemOne es NULL , sino devuelve 1 si se puedo aplicar el descuento
 *
 */
void item_DoDiscount(void *itemOne);

/** \brief Aplica el descuento
 *
 * \param void* itemOne Puntero al primer empleado a comparar.
 * \return int Devuelve -1 si itemOne es NULL , sino devuelve 1 si se puedo aplicar el descuento
 *
 */
int item_isPriceUpperToAhundred(void *itemOne);


/** \brief Aplica el descuento
 *
 * \param void* itemOne Puntero al primer empleado a comparar.
 * \return int Devuelve -1 si itemOne es NULL , sino devuelve 1 si se puedo aplicar el descuento
 *
 */
int item_isSectorOne(void *itemOne);


#endif // item_H_INCLUDED
