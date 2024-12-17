/*
* list.c
*
* Author: Pedro Lopes [https://github.com/PLeonLopes] / [https://www.linkedin.com/in/pedro-leon-lopes/]
* Created on 16/12/2024
*
* Implementation of the contact list structure and its core functions (insertion, removal, clearing, etc.)
*/

# include <stdio.h>
# include <string.h>
# include "list.h"

/*
* Creates a new list, initializes n and returns the new list.
*
* @return -> Initialized List.
*/
t_list create() {
    t_list list;
    list.n = -1;
    return list;
}

/* 
* Verifies if the list is empty.
*
* @param (list) -> Pointer to the List (Already Created).
*
* @return -> True (1) if the list is Empty; False (0) if not.
*/
int isEmpty(t_list *list) {
    return (list->n == -1);
}

/* 
* Verifies if the list is Full.
*
* @param (list) -> Pointer to the List (Already Created).
*
* @return -> True (1) if the list is Full; False (0) if not.
*/
int isFull(t_list *list) {
    return (list->n == MAX - 1);
}

/* 
* Get the current size of the list (Not the maximum size).
*
* @param (list) -> Pointer to the List (Already Created).
*
* @return -> Number of elements that are in the list.
*/
int getSize(t_list *list) {
    return list->n + 1;
}

/* 
* Gets a list element specified by the position ("pos").
*
* @param (list) -> Pointer to the List (Already Created).
* @param (pos) -> Position of the desired element.
*
* @return -> Pointer to the desired element (if the position is invalid, it returns 0).
*/
t_elements *getElement(t_list *list, int pos) {
    if ((pos > list->n) || (pos < 0)) {
        return NULL;
    }
    return &(list->vector[pos]);
}

/* 
* Compares two elements based on their names.
*
* @param (data1) -> First element to compare (data1).
* @param (data2) -> Second element to compare (data2).
*
* @return -> An integer less than, equal to, or greater than zero if the name 
*            in data1 is found to be respectively less than, equal to, or greater 
*            than the name in data2 (uses strcmp for comparison).
*/
int compare(t_elements data1, t_elements data2) {
    return strcmp(data1.name, data2.name);
}

/*
* Get the position of an element, based on its value.
* 
* @param (list) -> Pointer to the List (Already Created). 
* @param (data) -> data to be searched.
*
* @return -> The position of the element, or -1 if the element is not in the list.
*/
int getPos(t_list *list, t_elements data) {
    int i;
    for (i = 0; i <= list->n; i++) {
        if (compare(list->vector[i], data) == 0)
            return i;
    }
    return -1;
}

/* 
* Shifts list elements to the right from pos.
*
* @param (list) -> Pointer to the List (Already Created). 
* @param (pos) -> Position of the element, from which the displacement will begin.
* 
* @return -> False (0) if the Position is Invalid or the List is Full, otherwise, returns True(1).
*
*/
int rightShift(t_list *list, int pos) {
    int i;
    for (i = list->n + 1; i > pos; i--)
        list->vector[i] = list->vector[i - 1];
    return 1;
}

/* 
* Shifts list elements to the left from pos
*
* @param (list) -> Pointer to the List (Already Created). 
* @param (pos) -> Position of the element, from which the displacement will begin.
* 
* @return -> False (0) if the Position is Invalid or the List is Full, otherwise, returns True (1).
*
*/
int leftShift(t_list *list, int pos) {
    int i;
    for (i = pos; i < (list->n); i++) {
        list->vector[i] = list->vector[i + 1];
    }
    return 1;
}

/* 
* Inserts an element (data) into a specific position in the list.
* 
* @param (list) -> Pointer to the List (Already Created).
* @param (pos) -> Position of the element, from which the displacement will begin.
* @param (data) -> Element to be inserted.
* 
* @return -> False (0) if the position is invalid or if the list is Full, otherwise, returns True (1).
*/
int insert(t_list *list, int pos, t_elements data) {
    if (isFull(list) || (pos > list->n + 1) || (pos < 0))
        return 0;

    rightShift(list, pos);
    list->vector[pos] = data;
    (list->n)++;
    return 1;
}

/* 
* Removes an element from a given position in the list.
*
* @param (list) -> Pointer to the List (Already Created).
* @param (pos) -> Position of the element, from which the displacement will begin.
* 
* @return -> False (0) if the position is invalid or if the list is Full, otherwise, returns True (1).
*/
int removeElement(t_list *list, int pos) {
    if ((pos > list->n) || (pos < 0))
        return 0;

    leftShift(list, pos);
    (list->n)--;
    return 1;
}

/*
* Displays all elements stored in the list.
* 
* @param (list) -> Pointer to the List (Already Created).
*/
void visualize(t_list *list) {
    int i;
    for (i = 0; i <= list->n; i++)
        printf("Position: [%d]\nName: [%s]\nTelephone Number: [%s]\n\n\n", i + 1, list->vector[i].name, list->vector[i].telephone);
}
