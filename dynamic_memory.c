// Write a program showing the implementation of dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a pointer to an integer
    int *ptr;

    // Dynamically allocate memory for one integer
    ptr = (int*)malloc(sizeof(int));

    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    // Ask user for input
    printf("Enter an integer value: ");
    scanf("%d", ptr);

    // Print the value
    printf("Value stored at dynamically allocated memory: %d\n", *ptr);

    // Deallocate the dynamically allocated memory
    free(ptr);

    return 0;
}
