#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "defines.h"

typedef struct {
	int id;
	char name[SIZE_NAME];
	char lastName[SIZE_LAST_NAME];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;

#endif
/*
 * \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array.
 * \param listEmployee Array of employees
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int InitEmployees(eEmployee listEmployee[], int size);

/*
 * \brief Add in a existing list of employees the values received as parameters in the first empty position.
 * \param listEmployee Array of employees
 * \param size Array length
 * \param id Id unique for the new employee
 * \param name Name for the new employee
 * \param lastName Last Name for the new employee
 * \param salary Salary for the new employee
 * \param sector Sector for the new employee
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght or without free space) - (0) if OK
 * */
int AddEmployees(eEmployee listEmployee[], int size,int id,char name[],char lastName[],float salary,int sector);

/*
 * \brief Find an employee by id and returns the index position in the array.
 * \param listEmployee Array of employees
 * \param size Array length
 * \param id Id to find
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght or employee not found) - (0) if OK
 * */
int FindEmployeeById(eEmployee listEmployee[], int size,int id);

/*
 * \brief Remove a Employee by Id(put isEmpty flag in 1).
 * \param listEmployee Array of employees
 * \param size Array length
 * \param id Id of the employee to remove
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght or employee not found) - (0) if OK
 * */
int RemoveEmployee(eEmployee listEmployee[], int size,int id);

/*
 * \brief Sort the elements in the array of employees, the argument order indicates UP or DOWN.
 * \param listEmployee Array of employees
 * \param size Array length
 * \param order indicates UP or DOWN
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int SortEmployee(eEmployee listEmployee[], int size,int order);

/*
 * \brief Print the content of the array employees.
 * \param listEmployee Array of employees
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
int PrintEmployees(eEmployee listEmployee[], int size);

/*
 * \brief Print the data of an employee.
 * \param employee The employee to print
 * \return Nothing
 * */
void PrintEmployee(eEmployee employee);

/*
 * \brief Show the menu on screem
 * \param Nothing
 * \return int Return the option of the user.
 * */
int ShowMenu();

/*
 * \brief Show the modify menu on screem
 * \param Nothing
 * \return int Return the option of the user.
 * */
int ShowModifyMenu();

/*
 * \brief Get the index of a free position(isEmpty flag in 1)
 * \param listEmployee Array of employees
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght or without free space) - (0) if OK
 * */
int GetFreeIndex(eEmployee listEmployee[], int size);

/*
 * \brief Create a new employee with id, name, last name, salary and sector
 * \param id Id unique for the new employee
 * \param name Name for the new employee
 * \param lastName Last Name for the new employee
 * \param salary Salary for the new employee
 * \param sector Sector for the new employee
 * \return eEmployee Return a new employee
 * */
eEmployee NewEmployee(int id,char name[],char lastName[],float salary,int sector);

/*
 * \brief Get a employee by id
  * \param listEmployee Array of employees
 * \param size Array length
 * \param id Id unique of the employee
 * \return Return a employee is exist or NULL is not exist a employee
 * */
eEmployee GetEmployeeById(eEmployee listEmployee[], int size,int id);

/*
 * \brief Verify is a list of employee has content.
  * \param listEmployee Array of employees
 * \param size Array length
 * \return Return 1 if the list is empty or 0 if is not empyt.
 * */
int IsEmptyList(eEmployee listEmployee[], int size);

/*
 * \brief Do the add operations.
 * \param listEmployee Array of employees
 * \param size Array length
 * \param id Id for the employees
 * \return Nothing.
 * */
void Add(eEmployee listEmployee[], int size, int *id);

/*
 * \brief Do the modify operations.
 * \param listEmployee Array of employees
 * \param size Array length
 * \return Nothing.
 * */
void Modify(eEmployee listEmployee[], int size);

/*
 * \brief Do the delete operations.
 * \param listEmployee Array of employees
 * \param size Array length
 * \return Nothing.
 * */
void Delete(eEmployee listEmployee[], int size);

/*
 * \brief Ask the data for the new employee.
 * \param name Name for the new employee
 * \param lastName Last Name for the new employee
 * \param salary Salary for the new employee
 * \param sector Sector for the new employee
 * \return Save the data of the new employee.
 * */
void GetNewEmployeeData(char name[],char lastName[],float *salary,int *sector);

/*
 * \brief Do the delete operations.
 * \param listEmployee Array of employees
 * \param size Array length
 * \return Nothing.
 * */
float GetTotalSalary(eEmployee listEmployee[], int size);

/*
 * \brief Do the delete operations.
 * \param listEmployee Array of employees
 * \param size Array length
 * \return Nothing.
 * */
float GetAverageSalary(int countEmployees, float totalSalary);

/*
 * \brief Do the delete operations.
 * \param listEmployee Array of employees
 * \param size Array length
 * \return Nothing.
 * */
float GetEmployeeAboveAverageSalary(eEmployee listEmployee[], int size, float averageSalary);

/*
 * \brief Do the delete operations.
 * \param listEmployee Array of employees
 * \param size Array length
 * \return Nothing.
 * */
int GetCountEmployee(eEmployee listEmployee[], int size);

























