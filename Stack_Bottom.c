#include <stdio.h>
#include <stdlib.h>
// define node
struct stack {
    int size;
    int top;
    int *arr;
};

//fun to check if stack is Empty
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }else{ return 0; }
 }

//fun to check if stack is Full
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    } else{
        return 0;
    }
}

// function to print elements of the stack
void printStack(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is empty, no elements to print.\n");
    } else {
        printf("Stack elements are : ");
        for (int i = 0; i <= ptr->top; i++) {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}

// function to push element
void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack is overflow\n");
    } else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("%d is now stored in the stack at index %d.\n", value, ptr->top);
    }
}

//function to pop elements (remove)
// /*
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty!\n"); 
        return -1;
    }else { 
        int popedElement = ptr->arr[ptr->top];
        ptr->top--;
    return popedElement;
    }
}
// */

//function to get peek element (Top Element)
void peek(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty!\n");
    }else { 
        int Top = ptr->arr[ptr->top];
        printf("%d\n", Top);
        return Top;
    }
}

//function to get bottom element
int bottom(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is Empty\n");
        return -1;
    }else {
        int n = ptr->arr[0];
        printf("Bottom element of stack : %d\n", n );
    }
    return 0;
}

//main function
int main(){

struct stack *s = (struct stack*)malloc(sizeof(struct stack));

s->size = 80;
s->top = -1;
s->arr = (int*)malloc(s->size*sizeof(int));

//checking if stack is empty initially
if(isEmpty(s)){
    printf("Stack is Empty.\n");
}else {
    printf("Stack is not Empty.\n");
    }

//pushing elemetns
    push(s, 7);
    push(s, 23);
    push(s, 55);
    push(s, 78);
    push(s, 26);
    push(s, 24);

// checking if elements are stored or not 
if(isEmpty(s)){
    printf("Elements not stored.\n");
}else {
    printf("Elements are stored in the stack.\n");
    }

    printStack(s);
    printf("Top element before removing : ");
    peek(s);
    
    printf("Removing elements from the stack:\n");

//removing (pop) multiple element from stack using for loop
for(int i=0; i<3; i++){
    int poppedElement = pop(s);
    if (poppedElement != -1) {
        printf("Popped element: %d\n", poppedElement);
    }
}
    // pop(s);
    printf("Top element after removing multiple elements : ");
    peek(s);

    printStack(s);
    bottom(s);

    return 0;
}