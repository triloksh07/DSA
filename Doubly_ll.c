#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

//Linked List Traversal NEXT
void LinkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;
    }   
}
// Linked List Traversal PREV (Reverse)
void LinkedListTraversalReverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

//Linked List Traversal PREV
/*
void LinkedListTraversal_reverse(struct Node *ptr){
    struct Node *head = ptr;
    do {
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> prev;
    } while(ptr != NULL);
}
*/
// main function
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // struct Node *fifth;

// Allocate memory for node in linked list in heap
    head = (struct Node*)malloc(sizeof (struct Node));
    second = (struct Node*)malloc(sizeof (struct Node));
    third = (struct Node*)malloc(sizeof (struct Node));
    fourth = (struct Node*)malloc(sizeof (struct Node));
    // fifth = (struct Node*)malloc(sizeof (struct Node));

// Link Nodes
    head -> data = 10;
    head -> next = second;
    head -> prev = NULL;
    second -> data = 20;
    second -> next = third;
    second -> prev = head;
    third -> data = 30;
    third -> next = fourth;
    third -> prev = second;
    fourth -> data = 40;
    fourth -> next = NULL;
    fourth -> prev = third;
    // fifth -> data = 50;
    // fifth -> next = sixth;

// ll traversal 
    printf("Sequence\n");
    LinkedListTraversal(head);
// Reverse
    printf("Reverse\n");
    LinkedListTraversalReverse(fourth);

    return 0;
}