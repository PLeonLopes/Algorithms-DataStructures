/*
* search.h
*
* Author: Pedro Lopes [https://github.com/PLeonLopes] / [https://www.linkedin.com/in/pedro-leon-lopes/]
* Created on 16/12/2024
*
* Search functions prototypes to locate elements in the list.
*/

#ifndef SEARCH_H
#define SEARCH_H

# include "list.h"

int recLinearSearch(t_list *list, int pos, t_elements key);
int iterLinearSearch(t_list *list, t_elements key);
int recBinarySearch(t_list *list, int ini, int end, t_elements key);
int iterBinarySearch(t_list *list, t_elements key);

#endif
