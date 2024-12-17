/*
* list.h
*
* Author: Pedro Lopes [https://github.com/PLeonLopes] / [https://www.linkedin.com/in/pedro-leon-lopes/]
* Created on 16/12/2024
*
* Implementation of the contact list structure and its core functions prototypes.
*/

#ifndef LIST_H
#define LIST_H

#define MAX 30

// Base type of elements
typedef struct elements {
    char name[50];
    char telephone[20];
} t_elements;

// List Structure
typedef struct list {
    t_elements vector[MAX];
    int n;                          // position (index) of the last element in the array
} t_list;

// Prototypes
t_list create();
int isEmpty(t_list *list);
int isFull(t_list *list);
int getSize(t_list *list);
t_elements *getElement(t_list *list, int pos);
int compare(t_elements data1, t_elements data2);
int getPos(t_list *list, t_elements data);
int rightShift(t_list *list, int pos);
int leftShift(t_list *list, int pos);
int insert(t_list *list, int pos, t_elements data);
int removeElement(t_list *list, int pos);
void visualize(t_list *list);

#endif
