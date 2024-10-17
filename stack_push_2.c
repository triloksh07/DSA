#include <stdio.h>
#include <stdlib.h>
// define stack
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
        printf("Stack is overflow! Can't push elements\n");
    } else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("%d is now stored in the stack at index %d.\n", value, ptr->top);
     }
}

//main function
int main(){
    int n, value;

struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    printf("Enter the size of the stack: ");
    scanf("%d", &n);

s->size = n;
s->top = -1;
s->arr = (int*)malloc(s->size*sizeof(int));

//checking if stack is empty initially
if(isEmpty(s)){
    printf("Stack is Empty.\n");
}else {
    printf("Stack is not Empty.\n");
    }
//pushing elements from user input
int numElements;
printf("enter the number of elements you want to push: ");
scanf("%d", &numElements);

for(int i=0; i<numElements; i++){
    printf("Enter value to push : ");
    scanf("%d", &value);
    push(s,value);
}

//pushing elemetns
    // push(s, 7);
    // push(s, 23);
    // push(s, 55);
    // push(s, 78);
    // push(s, 26);
    // push(s, 24);

// checking if elements are stored or not in the stack
if(isEmpty(s)){
    printf("Elements not stored.\n");
}else {
    printf("Elements are stored in the stack.\n");
    }
    return 0;
}