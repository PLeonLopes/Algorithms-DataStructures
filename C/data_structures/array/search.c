/*
* search.c
*
* Author: Pedro Lopes [https://github.com/PLeonLopes] / [https://www.linkedin.com/in/pedro-leon-lopes/]
* Created on 16/12/2024
*
* Search functions to locate elements in the list.
*/

# include "search.h"

/*
* Performs a recursive linear search for an element in the list. O(n)
*
* @param (list) -> Pointer to the List (Already Created).
* @param (pos) -> Current position in the list.
* @param (key) -> Key element to search for.
*
* @return -> Position of the found element (if found), or -1 if not found.
*/
int recLinearSearch(t_list *list, int pos, t_elements key) {
    if (pos > list->n)
        return -1;
    if (compare(list->vector[pos], key) == 0)
        return pos;
    return recLinearSearch(list, pos + 1, key);
}

/*
* Performs an iterative linear search for an element in the list. O(n)
*
* @param (list) -> Pointer to the List (Already Created).
* @param (key) -> Key element to search for.
*
* @return -> Position of the found element (if found), or -1 if not found.
*/
int iterLinearSearch(t_list *list, t_elements key) {
	int i;
    for (i = 0; i <= list->n; i++) {
        if (compare(list->vector[i], key) == 0)
            return i;
    }
    return -1;
}

/*
* Performs a recursive binary search for an element in the sorted list. O(logN)
*
* @param (list) -> Pointer to the List (Already Created and Sorted).
* @param (ini) -> Initial index of the search range.
* @param (end) -> End index of the search range.
* @param (key) -> Key element to search for.
*
* @return -> Position of the found element (if found), or -1 if not found.
*/
int recBinarySearch(t_list *list, int ini, int end, t_elements key) {
    if (end < ini)
        return -1;

    int middle = ini + (end - ini) / 2;

    if (compare(list->vector[middle], key) == 0)
        return middle;

    if (compare(list->vector[middle], key) < 0)
        return recBinarySearch(list, middle + 1, end, key);
    else
        return recBinarySearch(list, ini, middle - 1, key);
}

/*
* Performs an iterative binary search for an element in the sorted list. O(logN)
*
* @param (list) -> Pointer to the List (Already Created and Sorted).
* @param (key) -> Key element to search for.
*
* @return -> Position of the found element (if found), or -1 if not found.
*/
int iterBinarySearch(t_list *list, t_elements key) {
    int ini = 0, end = list->n;
    while (ini <= end) {
        int middle = (ini + end) / 2;
        if (compare(list->vector[middle], key) == 0)
            return middle;
        else if (compare(list->vector[middle], key) < 0)
            ini = middle + 1;
        else
            end = middle - 1;
    }
    return -1;
}
