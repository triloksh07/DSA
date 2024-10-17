#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node *next;
};

// Linked List Traversal
void LinkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function isFull
int isFull() {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) {
        return 1; // Stack is full
    }
    free(p); // Free the allocated memory since it's not needed
    return 0; // Stack is not full
}

// Function isEmpty
int isEmpty(struct Node *top) {
    return top == NULL;
}

// Push function
struct Node *push(struct Node *top, int x) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return top; // Return the same top if stack is full
    }
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    return n; // Return the new top
}

// Pop function
struct Node *pop(struct Node *top, int *poppedValue) {
    if (isEmpty(top)) {
        printf("Stack underflow!\n");
        return top; // Return the same top if stack is empty
    }
    struct Node *temp = top;
    top = top->next;
    *poppedValue = temp->data; // Set the popped value
    free(temp); // Free the popped node
    return top; // Return the new top
}

// Main function
int main() {
    struct Node *top = NULL;

    top = push(top, 78);
    top = push(top, 23);
    top = push(top, 26);
    top = push(top, 55);

    // Display stack elements before removing
    printf("Stack elements before removing:\n");
    LinkedListTraversal(top);

    int element;
    top = pop(top, &element); // Update top after popping
    printf("Popped element: %d\n", element);

    // Display stack elements after removing
    printf("Stack elements after removing:\n");
    LinkedListTraversal(top);

    return 0;
}
