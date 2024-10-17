#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node{
    int data;
    struct Node *next;
    // struct Node *prev;
};

// //Linked List Traversal
// void LinkedListTraversal(struct Node *ptr){
//     while(ptr != Null){
//         printf("Element : %d\n", ptr -> data);
//         ptr = ptr -> next;
//     }
// }

//Linked List Traversal
void LinkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do {
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;

    } while(ptr != head);
}

// Insertion at first
struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof (struct Node));
    ptr -> data = data;

    struct Node *p = head -> next;
    while(p->next != head){
        p=p->next;
    } 
    //At this point p points to the last node of this circular linked list 
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// main function
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    // struct Node *sixth;
    // struct Node *seventh;
    // struct Node *eighth;
    // struct Node *nineth;
    // struct Node *tenth;
// Allocate memory for node in linked list in heap
    head = (struct Node*)malloc(sizeof (struct Node));
    second = (struct Node*)malloc(sizeof (struct Node));
    third = (struct Node*)malloc(sizeof (struct Node));
    fourth = (struct Node*)malloc(sizeof (struct Node));
    fifth = (struct Node*)malloc(sizeof (struct Node));
    // sixth = (struct Node*)malloc(sizeof (struct Node));
    // seventh = (struct Node*)malloc(sizeof (struct Node));
    // eighth = (struct Node*)malloc(sizeof (struct Node));
    // nineth = (struct Node*)malloc(sizeof (struct Node));
    // tenth = (struct Node*)malloc(sizeof (struct Node));

    head -> data = 10;
    head -> next = second;
    second -> data = 20;
    second -> next = third;
    third -> data = 30;
    third -> next = fourth;
    fourth -> data = 40;
    fourth -> next = fifth;
    fifth -> data = 50;
    fifth -> next = head;
    // sixth -> data = 60;
    // sixth -> next = seventh;
    // seventh -> data = 70;
    // seventh -> next = eighth;
    // eighth -> data = 80;
    // eighth -> next = nineth;
    // nineth -> data = 90;
    // nineth -> next = tenth;
    // tenth -> data = 100;
    // tenth -> next = NULL;
   printf("Circular Linked list before insertion\n");
    LinkedListTraversal(head);
   printf("Circular Linked list after insertion\n");
    head = insertAtFirst(head, 78);
    LinkedListTraversal(head);
    // LinkedListTraversal_reverse(head);

    return 0;
}