/*
* selectionSort_iter.c
*
* Author: Pedro Lopes [https://github.com/PLeonLopes] / [https://www.linkedin.com/in/pedro-leon-lopes/]
* Created on 18/12/2024
*
* Implementation of Selection Sort (interactive) and arrays examples
*/

# include <stdio.h>
# include <time.h>

// Interactive Selection Sort implementation
void selectionSort_iter(int arr[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        int minIndex = i;
        int j;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Auxiliary function to print array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("[%d]", arr[i]);
    }
    printf("\n\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};           // pre-made array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    clock_t start = clock(); // Start the timer
    selectionSort_iter(arr, n);
    clock_t end = clock();   // End the timer

    printf("Sorted array (Iterative Selection Sort):\n");
    printArray(arr, n);

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.6f seconds\n", timeTaken);

    return 0;
}
