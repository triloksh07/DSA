#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
   scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // printing arr element in reverse order
    
    printf("Elements in reverse order: \n");
    for (int i = n-1; i >= 0; i--) {
    printf("%d\n", arr[i]);
    }

    // Deallocate the memory
    free(arr);

    return 0;
}