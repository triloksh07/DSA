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
//
//fun to check if stack is Full

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    } else{
        return 0;
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
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty!\n");
    }else { 
        int popedValue = ptr->arr[ptr->top];
        ptr->top--;
    return popedValue;
    }
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

//removing (pop) an element from stack 
int poppedValue = pop(s);
    if (poppedValue != -1) {
        printf("Popped value: %d\n", poppedValue);
    }
int poppedValue1 = pop(s);
if (poppedValue1 != -1) {
    printf("Popped value: %d\n", poppedValue1);
}
int poppedValue2 = pop(s);
    if (poppedValue2 != -1) {
        printf("Popped value: %d\n", poppedValue2);
    }
// checking if elements are stored or not 
if(isEmpty(s)){
    printf("Elements not stored.\n");
}else {
    printf("Elements are stored in the stack.\n");
    }
    return 0;
}