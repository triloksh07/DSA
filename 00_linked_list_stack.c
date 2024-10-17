#include <stdio.h>
#include <stdlib.h>
// Define node
struct Node{
    int data;
    struct Node *next;
};

//Linked List Traversal
void LinkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;
    }  
}
//fun isFull
int isFull(struct Node *top){
    struct Node *p = (struct Node*)malloc(sizeof (struct Node));
    if(p==NULL){
        return 1;
    }else { free(p); return 0;}
}
//fun isEmpty
int isEmpty(struct Node *top){
    if(top==NULL){
        return 1;
    } else{return 0;}
}
//push function
struct Node* push(struct Node *top, int x){
    if(isFull(top)){
        printf("Stack Overflow!\n"); return top;
    }else {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    // top = n;
    return n;
    // return top;
    }
}
//pop fun
int pop(struct Node *top){
    if(isEmpty(top)){
        printf("Stack underflow!\n");
    }else {
        struct Node *n = top;
        top = top->next;
        int y = n->data;
        free(n);
        return y;
    }
}

// main function
int main(){

    struct Node *top = NULL;

    top = push(top, 78);

    top = push(top, 23);

    top = push(top, 26);

    top = push(top, 55);
    

    // Display stack elements before removing
    printf("Stack elements: \n");
    LinkedListTraversal(top);

    int element = pop(top);
    printf("Poped element: %d\n", element);


    // printf("Stack elements after removing:\n");
    // LinkedListTraversal(top);

    return 0;
}