#ifndef UTN_VALIDATORS_H_
#define UTN_VALIDATORS_H_


//VALIDATIONS
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int IsOnlyLetters(char string[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros, y 0 si no lo es
 *
 */
int IsAlphanumeric(char string[]);

/**
 * \brief Verifica si el valor recibido contiene solo numeros, + y -
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int IsPhoneNumber(char string[]);

/**
 * \brief Verifica si el valor recibido contiene solo numeros positivos
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros positivos
 *
 */
int IsNumeric(char *string);


#endif /* UTN_VALIDATORS_H_ */
