#ifndef DEFINES_H_
#define DEFINES_H_

#define SIZE_CHAR_ARRAY 128

#define RETRIES 3
#define OK 0
#define ERROR -1

//Main menu
#define LOAD_TEXT 1
#define SORT_LIST 2
#define SHOW 3
#define	DO_DISCOUNT 4
#define DO_FILE 5
#define REPORTS 6
#define EXIT 7

#define HAS_HEADER 1
#define HEADER "id,articulo,medida,precio,rubroId\n"
#define SOURCE_DATA "mapeado.csv"
#define DATA_FORMAT "%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
#define DATA_FORMAT_SAVE "%d,%s,%s,%.2f,%d\n"

#define ORDER_DESC 0
#define ORDER_ASC 1

#define ID_SECTION_CLOTHES 1
#define ID_SECTION_CLEAN 2
#define ID_SECTION_PERSONAL_CARE 3
#define ID_SECTION_CAR 4

#endif /* DEFINES_H_ */
