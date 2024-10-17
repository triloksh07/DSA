#include <stdio.h>
#include <stdlib.h>

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
// insert element at First in the Linked List
/*
struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr =(struct Node*)malloc(sizeof (struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}
*/
// insert element in btw in the linked list
/*
struct Node *insertInBtw(struct Node *head, int data, int index){
        struct Node *ptr = (struct Node*)malloc(sizeof (struct Node));
        struct Node *p = head;
        int i =0;
        while(i != index-1){
            p = p->next;
            i++; }
        ptr->data = data;
        ptr->next = p->next ;
        p->next = ptr;
        return head;
}
*/
// insert element at last in the linked list 
/*
struct Node *insertAtLast(struct Node *head, int data){
    // struct Node *ptr = head;
    // struct Node *p;
    struct Node *ptr = (struct Node *)malloc(sizeof (struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL){
        p = p->next;
    } 
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
*/
// inser value at given value
/*
struct Node *insertAtValue(struct Node *head, int data, struct Node *q){
    struct Node *p = (struct Node*)malloc(sizeof (struct Node));

    p->data = data;
    p->next = q->next ;
    q->next = p;

    return head;
}
*/
// Main function
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

// Allocate memory for node in linked list in heap
    head = (struct Node*)malloc(sizeof (struct Node));
    second = (struct Node*)malloc(sizeof (struct Node));
    third = (struct Node*)malloc(sizeof (struct Node));
    fourth = (struct Node*)malloc(sizeof (struct Node));

    head -> data = 10;
    head -> next = second;
    second -> data = 20;
    second -> next = third;
    third -> data = 30;
    third -> next = fourth;
    fourth -> data = 40;
    fourth -> next = NULL;
    
// linked List before insertion
    printf("linked list before insertion.\n");
    LinkedListTraversal(head);
// Linked List after insertion 
    // printf("linked list after insertion.\n");
    // head = insertAtFirst(head, 50);
    // head = insertInBtw(head, 55, 2);
    // head = insertInBtw(head, 78, 4);
    // head = insertAtLast(head, 78);
    // head = insertAtValue(head, 78, second);
    // LinkedListTraversal(head);
    
    return 0;
}