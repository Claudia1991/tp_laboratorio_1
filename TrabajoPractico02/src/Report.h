#ifndef REPORT_H_
#define REPORT_H_

#include "defines.h"
#include "Employee.h"

/*
 * \brief Show employees ordered by Last Name and Sector
 * \param listEmployee Array of employees
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
void ShowEmployeesOrderByLastNameAndSector(eEmployee listEmployees[], int size);
/*
 * \brief Show the report menu on screem
 * \param listEmployee Array of employees
 * \param size Array length
 * \return int Return (-1) if ERROR(NULL pointer or Invalid lenght) - (0) if OK
 * */
void ShowAverageSalary(eEmployee listEmployees[], int size);

/*
 * \brief Verify is a list of employee has content.
 * \param listEmployee Array of employees
 * \param size Array length
 * \return Nothing.
 * */
void ShowReports(eEmployee listEmployee[], int size);

/*
 * \brief Show the report menu on screem
 * \param Nothing
 * \return int Return the option of the user.
 * */
int ShowReportMenu();

#endif /* REPORT_H_ */
