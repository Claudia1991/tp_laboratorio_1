#ifndef DEFINES_H_
#define DEFINES_H_

#define SIZE_CHAR_ARRAY 128

#define RETRIES 3
#define OK 0
#define ERROR -1

//Main menu
#define LOAD_TEXT 1
#define LOAD_BINARY 2
#define ADD_EMPLOYEE 3
#define	MODIFY_EMPLOYEE 4
#define DELETE_EMPLOYEE 5
#define	SHOW_EMPLOYEE 6
#define	SORT_EMPLOYEE 7
#define	SAVE_TEXT 8
#define	SAVE_BINARY 9
#define EXIT 10

//Modify employee menu
#define MODIFY_NAME 1
#define MODIFY_WORKED_HOURS 2
#define MODIFY_SALARY 3
#define MODIFY_EXIT 4

#define MIN_WORKED_HOURS 1
#define MAX_WORKED_HOURS 100

#define MIN_SALARY 1000
#define MAX_SALARY 1000000

#define HAS_HEADER 1
#define HEADER "id,nombre,horasTrabajadas,sueldo\n"
#define DEFAULT_ID "-1"
#define SOURCE_DATA "data.csv"
#define SOURCE_DATA_BIN "data.bin"
#define DATA_FORMAT "%[^,],%[^,],%[^,],%[^\n]\n"

#define ORDER_DESC 0
#define ORDER_ASC 1

#define ORDER_BY_NAME 1
#define ORDER_BY_WORKED_HOURS 2
#define ORDER_BY_SALARY 3

#endif /* DEFINES_H_ */
