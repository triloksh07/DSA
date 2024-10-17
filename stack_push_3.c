#include <stdio.h>
#include <stdlib.h>

// define node
struct stack {
    int size;
    int top;
    int *arr;
};

// function to check if the stack is Empty
int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

// function to check if the stack is Full
int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

// function to push element
void push(struct stack *ptr, int value) {
    if (isFull(ptr)) {
        printf("Stack is overflow! Can't push %d\n", value);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("%d is now stored in the stack at index %d.\n", value, ptr->top);
    }
}

// function to print elements of the stack
void printStack(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is empty, no elements to print.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = 0; i <= ptr->top; i++) {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, value;

    struct stack *s = (struct stack*)malloc(sizeof(struct stack));

    // Ask the user for the size of the stack
    printf("Enter the size of the stack: ");
    scanf("%d", &n);

    s->size = n;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));

    // checking if stack is empty initially
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
    } else {
        printf("Stack is not Empty.\n");
    }

    // pushing elements from user input
    int numElements;
    printf("Enter the number of elements you want to push: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        printf("Enter value to push: ");
        scanf("%d", &value);
        push(s, value);
    }

    // print the stored elements
    printStack(s);

    // checking if elements are stored in the stack
    if (isEmpty(s)) {
        printf("Elements not stored.\n");
    } else {
        printf("Elements are stored in the stack.\n");
    }

    return 0;
}
