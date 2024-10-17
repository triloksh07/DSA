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
    // head = deleteLastNode(head);
}
// structure to delete First node in the Linked List
/*
  struct Node *deleteFirst(struct Node *head){
    struct Node *ptr = head;
        head = head -> next;
        free(ptr);  
        return head;
    }; 
}
*/
// Structure to delete node at given value in the Linked List
/*
struct Node *deleteAtValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = p -> next;
    while (q->data != value || q->next != NULL){
        p = p -> next;
        q = q-> next;
    }
    if(q->data==value){
        p->next = q-> next;
        // free (q);
    } free(q);
    return head;
}
*/
// Structure to delete node in btw AT INDEX in the Linked List
/*
struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = p -> next;
    for(int i=0; i < index-1; i++){
        p = p -> next;
        q = q-> next;
    }
    p-> next = q-> next ;
    // head = deleteLastNode(head);
    free(q);
    return head;
}
*/
// Structure to delete last node in the Linked List
/*
    struct Node *deleteLastNode(struct Node *head){
      struct Node *p = head;
      struct Node *q = head -> next;
        while (q-> next != NULL){
            p = p -> next;
            q = q -> next;
        } p-> next = NULL; 
        free(q);
    return head;
    } 
*/

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
    
// Linked List before deletion
printf("Linked List before deletion.\n");
    LinkedListTraversal(head);

// Linked List after deletion    
// printf("Linked List after deletion.\n");
    // head = deleteFirst(head);
    // head = deleteLastNode(head);
    // head = deleteAtIndex(head, 3);
    // head = deleteAtValue(head, 3);
    // LinkedListTraversal(head);
    return 0;
}