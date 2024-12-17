/*
* main.c
*
* Author: Pedro Lopes [https://github.com/PLeonLopes] / [https://www.linkedin.com/in/pedro-leon-lopes/]
* Created on 16/12/2024
*
* Program entry point with a menu-based interactive interface.
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <windows.h>
# include "list.h"
# include "search.h"
# include "sort.h"

// Terminal Colors
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"
#define CRESET "\e[0m"

// Options Menu
void menu() {
    system("cls");
    printf("\nMENU - LIST EDITOR\n");
    printf("1 - Insert name and phone number\n");
    printf("2 - Remove an element\n");
    printf("3 - Search for an element by name\n");
    printf("4 - Display the list\n");
    printf("5 - Get the size of the list\n");
    printf("6 - Clear the list (remove all elements)\n");
    printf("7 - Sort the list\n");
    printf("0 - Exit the program\n");
}

// Sort Menu
void sortMenu() {
    system("cls");
    printf("\nSORT MENU\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Merge Sort\n");
    printf("4 - Quick Sort\n");
}

int main() {
    t_list List = create();         // Creates the list
    int choice, sortChoice, pos;
    t_elements elem;
    char searchName[50];

    do {
        menu();
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert (Name and Phone Number)
                if (isFull(&List)) {
                    printf(RED"The list is full. Cannot insert more elements.\n"CRESET);
                } else {
                    system("cls");
                    printf("Enter the name: ");
                    scanf(" %[^\n]", elem.name);
                    printf("Enter the phone number: ");
                    scanf(" %[^\n]", elem.telephone);
                    printf("Enter the position to insert (0 to %d): ", getSize(&List));
                    scanf("%d", &pos);

                    if (insert(&List, pos, elem)) {
                        printf(GREEN"Element successfully inserted!\n"CRESET);
                    } else {
                        printf(RED"Failed to insert element. Check the position.\n"CRESET);
                    }
                    system("pause");
                    system("cls");
                }
                break;
            case 2: // Remove an element
                if (isEmpty(&List)) {
                    printf(BLUE"The list is empty. No elements to remove.\n"CRESET);
                } else {
                    system("cls");
                    printf("Enter the position of the element to remove (0 to %d): ", getSize(&List) - 1);
                    scanf("%d", &pos);

                    if (removeElement(&List, pos)) {
                        printf(GREEN"Element successfully removed!\n"CRESET);
                    } else {
                        printf(RED"Failed to remove the element. Check the position.\n"CRESET);
                    }
                    system("pause");
                    system("cls");
                }
                break;
            case 3: // Search for an element by name
                if (isEmpty(&List)) {
                    printf(BLUE"The list is empty. No elements to search for.\n"CRESET);
                } else {
                    system("cls");
                    printf("Enter the name to search: ");
                    scanf(" %[^\n]", searchName);

                    pos = -1;
                    for (int i = 0; i < getSize(&List); i++) {
                        if (strcmp(List.vector[i].name, searchName) == 0) {
                            pos = i;
                            break;
                        }
                    }

                    if (pos != -1) {
                        printf(GREEN"Element found at position: %d\n"CRESET, pos);
                    } else {
                        printf(RED"Element not found.\n"CRESET);
                    }
                    system("pause");
                    system("cls");
                }
                break;
            case 4: // Display the list
                if (isEmpty(&List)) {
                    printf(BLUE"The list is empty.\n"CRESET);
                } else {
                    system("cls");
                    visualize(&List);
                }
                system("pause");
                system("cls");
                break;
            case 5: // Get the size of the list
                system("cls");
                printf("The current size of the list is: %d\n", getSize(&List));
                system("pause");
                system("cls");
                break;
            case 6: // Clear the list
                while (!isEmpty(&List)) {
                    removeElement(&List, 0);
                }
                system("cls");
                printf(GREEN"List successfully cleared!\n"CRESET);
                system("pause");
                system("cls");
                break;

            case 7: // Sort the list
                if (isEmpty(&List)) {
                    printf(RED"The list is empty. Cannot sort.\n"CRESET);
                } else {
                    system("cls");
                    sortMenu();
                    printf("\nChoose a sorting algorithm: ");
                    scanf("%d", &sortChoice);

                    clock_t start, end;
                    start = clock();

                    switch (sortChoice) {
                        case 1:
                            bubbleSort(List.vector, getSize(&List));
                            system("cls");
                            printf(GREEN"Bubble Sort completed!\n"CRESET);
                            printf("Sorting time: %.4f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            selectionSort(List.vector, getSize(&List));
                            system("cls");
                            printf(GREEN"Selection Sort completed!\n"CRESET);
                            printf("Sorting time: %.4f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            mergeSort(List.vector, 0, getSize(&List) - 1);
                            system("cls");
                            printf(GREEN"Merge Sort completed!\n"CRESET);
                            printf("Sorting time: %.4f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            quickSort(List.vector, 0, getSize(&List) - 1);
                            system("cls");
                            printf(GREEN"Quick Sort completed!\n"CRESET);
                            printf("Sorting time: %.4f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
                            system("pause");
                            break;
                        default:
                            printf(RED"Invalid sorting option.\n"CRESET);
                            break;
                    }
                    end = clock();
                }
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf(RED"Invalid option. Please try again.\n"CRESET);
        }
    } while (choice != 0);

    return 0;
}
