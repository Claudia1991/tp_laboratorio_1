#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "Item.h"
#include "LinkedList.h"
#include "defines.h"

int controller_loadFromText(LinkedList *pList);

int controller_sortList(LinkedList *pList);

int controller_showList(LinkedList *pList);

int controller_doDiscountList(LinkedList *pList);

int controller_doListToFileMapped(LinkedList *pList);

int controller_doReports(LinkedList *pList);

#endif /* CONTROLLER_H_ */
