/*
* sort.h
*
* Author: Pedro Lopes [https://github.com/PLeonLopes] / [https://www.linkedin.com/in/pedro-leon-lopes/]
* Created on 16/12/2024
*
* Implementation of sorting algorithms prototypes (Bubble Sort, Selection Sort, Merge Sort, and Quick Sort). 
*/

#ifndef SORT_H
#define SORT_H

# include "list.h"

// Prototypes -> Sorting Algorithms
void bubbleSort(t_elements arr[], int size);
void selectionSort(t_elements arr[], int size);
void mergeSort(t_elements arr[], int left, int right);
void quickSort(t_elements arr[], int low, int high);

#endif
