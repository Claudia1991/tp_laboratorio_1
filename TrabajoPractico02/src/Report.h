#ifndef REPORT_H_
#define REPORT_H_

#include "defines.h"
#include "Employee.h"

/*
 * \brief Show employees ordered by Last Name and Sector.
 * \param listEmployee Array of employees.
 * \param size Array length.
 * \return Nothing.
 * */
void ShowEmployeesOrderByLastNameAndSector(eEmployee listEmployees[], int size);
/*
 * \brief Show total and average salary , and employee's salary upper the average.
 * \param listEmployee Array of employees.
 * \param size Array length.
 * \return Nothing.
 * */
void ShowAverageSalary(eEmployee listEmployees[], int size);

/*
 * \brief Show the report menu on screem.
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
