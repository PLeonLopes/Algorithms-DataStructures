/*
* selectionSort_rec.c
*
* Author: Pedro Lopes [https://github.com/PLeonLopes] / [https://www.linkedin.com/in/pedro-leon-lopes/]
* Created on 18/12/2024
*
* Implementation of Selection Sort (Recursive) and arrays examples
*/

# include <stdio.h>
# include <time.h>

// Recursive Selection Sort implementation
void selectionSort_rec(int arr[], int n, int index) {
    if (index == n - 1) {
        return; // Base case: only one element left
    }

    int minIndex = index;
    int j;
    for (j = index + 1; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    // Swap arr[index] and arr[minIndex]
    int temp = arr[index];
    arr[index] = arr[minIndex];
    arr[minIndex] = temp;

    // Recursive call for the next part of the array
    selectionSort_rec(arr, n, index + 1);
}

// Auxiliary function to print array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};       // pre-made array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    clock_t start = clock(); // Start the timer
    selectionSort_rec(arr, n, 0);
    clock_t end = clock();   // End the timer

    printf("Sorted array (Recursive Selection Sort):\n");
    printArray(arr, n);

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.6f seconds\n", timeTaken);

    return 0;
}
