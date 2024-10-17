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
// main function
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    
// Allocate memory for node in linked list in heap
    head = (struct Node*)malloc(sizeof (struct Node));
    second = (struct Node*)malloc(sizeof (struct Node));
    third = (struct Node*)malloc(sizeof (struct Node));
    fourth = (struct Node*)malloc(sizeof (struct Node));
    fifth = (struct Node*)malloc(sizeof (struct Node));

// linking nodes and input data
    head -> data = 10;
    head -> next = second;
    second -> data = 20;
    second -> next = third;
    third -> data = 30;
    third -> next = fourth;
    fourth -> data = 40;
    fourth -> next = fifth;
    fifth -> data = 50;
    fifth -> next = NULL;
    
    LinkedListTraversal(head);

    return 0;
}