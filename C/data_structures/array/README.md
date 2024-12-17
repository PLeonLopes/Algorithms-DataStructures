# Arrays in C

This project is an example of how to use arrays in C. It implements a contact list that allows operations such as insertion, removal, searching, and sorting. Additionally, it demonstrates the use of sorting and searching algorithms on a linear list.  

## Features  

### Main Functionalities  
- Insert a contact (Name and Phone Number) at a specific position in the list.  
- Remove a contact from the list based on its position.  
- Search for a contact by name.  
- Display the complete list of contacts.  
- Get the current size of the list.  
- Clear the list by removing all contacts.  

### Sorting Algorithms  
This project demonstrates the use of four sorting algorithms to organize the contact list:  
1. **Bubble Sort**: Compares and swaps adjacent elements if they are in the wrong order.  
2. **Selection Sort**: Finds the smallest element in the unsorted part and moves it to the correct position.  
3. **Merge Sort**: Divides the list into smaller sublists, sorts them, and merges them back together.  
4. **Quick Sort**: Uses a pivot to partition the list and recursively sorts the sublists.  

### Search Functionality  
- Allows locating contacts by name and returns their position in the list.  

---

## Project Structure  

### Data Structure  
```c
typedef struct t_elements {  
    char name[50];  
    char telephone[15];  
} t_elements;

typedef struct list {
    t_elements vector[MAX];
    int n;
} t_list; 
```

### Files  

1. **list.h** / **list.c** - Implementation of the contact list structure and its core functions (insertion, removal, clearing, etc.)

2. **sort.h** / **sort.c** - Implementation of sorting algorithms (Bubble Sort, Selection Sort, Merge Sort, and Quick Sort).  

3. **search.h** / **search.c** - Search functions to locate elements in the list.  

4. **main.c** - Program entry point with a menu-based interactive interface.

5. **Makefile** - Automation of the compilation process with predefined rules for building, cleaning, and running the program.  

## How to Compile and Run  

### Using `Makefile`  
1. Compile the program using the command:  
    ```bash
    make
    ```

2. Run the program with:
    ```bash
    ./array
    ```
### Using `gcc` Directly
1. Compile the program manually:
    ```bash
    gcc -Wall -Wextra -std=c11 -o array main.c list.c sort.c search.c
    ```

2. Run the program with:
    ```bash
    ./array
    ```

## Educational Purpose

This project is designed to teach key concepts of linear lists in C, including:

- Array-based data structures.
- Data manipulation in arrays.
- Implementation of search and sorting algorithms in arrays.
