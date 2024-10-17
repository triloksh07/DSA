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

struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr =(struct Node*)malloc(sizeof (struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

// insert element at last in the linked list 

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

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in ascending order

void insertInAscendingOrder(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If the list is empty or the new node should be placed at the front
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;

        // Traverse the list to find the correct position
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }

        // Insert the new node at the correct position
        newNode->next = current->next;
        current->next = newNode;
    }
}
// structure to delete First node in the Linked List
  struct Node *deleteFirst(struct Node *head){
    struct Node *ptr = head;
        head = head -> next;
        free(ptr);  
        return head;
    }; 

// structure to delete the last node of the linked list
struct Node *delete_last_node(struct Node *head) {
    // If the list is empty
    if (head == NULL) {
        return NULL;
    }
    
    // If there's only one node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *ptr = head;
    struct Node *q = head->next;

    // Traverse to the second last node
    while (q->next != NULL) {
        ptr = ptr->next;
        q = q->next;
    }

    // Now ptr is the second last node, and q is the last node
    ptr->next = NULL; // Remove the last node
    free(q); // Free memory of last node

    return head; // Return the updated head of the list
}

// Structure to delete a node after a specific index
struct Node *delete_after_index(struct Node *head, int index) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head; // Return head as is
    }

    struct Node *ptr = head;
    int i = 0;

    // Traverse to the specified index
    while (ptr != NULL && i < index) {
        ptr = ptr->next;
        i++;
    }

    // If ptr is NULL or ptr->next is NULL, we cannot delete
    if (ptr == NULL || ptr->next == NULL) {
        printf("No node exists after index %d.\n", index);
        return head; // Return head as is
    }

    // Node to be deleted
    struct Node *p = ptr->next;

    // Bypass the node and free memory
    ptr->next = p->next;
    free(p);

    return head; // Return updated head
}

// Structure to delete a node before a specific index (0-based)
struct Node* delete_before_index(struct Node *head, int index) {
    // Check for edge cases
    if (head == NULL || index <= 0) {
        printf("No node exists before index %d.\n", index);
        return head; // No deletion possible
    }

    struct Node *current = head;
    struct Node *prev = NULL;

    // Traverse to find the (index-1)th node
    for (int i = 0; current != NULL && i < index; i++) {
        prev = current; // Track previous node
        current = current->next; // Move to next node
    }

    // If prev is NULL, it means we are trying to delete before the first element
    if (prev == head) {
        head = current; // Move head to the next element if deleting the first element
        free(prev); // Free memory of deleted node
        return head; // Return updated head of the list
    }

    // If we reach here, prev is the node before the one we want to delete
    struct Node *toDelete = head; // The node we want to delete

    while (toDelete->next != prev) { 
        toDelete = toDelete->next; // Traverse to find the node before 'prev'
    }

    // Bypass the node to be deleted
    toDelete->next = prev->next; 
    free(prev); // Free memory of deleted node

    return head; // Return updated head of the list
}

// Main function
int main(){
    struct Node *head;
    struct Node *second;
    // struct Node *third;
    // struct Node *fourth;

// Allocate memory for node in linked list in heap
    head = (struct Node*)malloc(sizeof (struct Node));
    second = (struct Node*)malloc(sizeof (struct Node));
    // third = (struct Node*)malloc(sizeof (struct Node));
    // fourth = (struct Node*)malloc(sizeof (struct Node));

    head -> data = 10;
    head -> next = second;
    second -> data = 20;
    second -> next = NULL;
    // third -> data = 30;
    // third -> next = fourth;
    // fourth -> data = 40;
    // fourth -> next = NULL;
    
// linked List before insertion
    printf("linked list before insertion.\n");
    LinkedListTraversal(head);
    
// Insert nodes in ascending order
    insertInAscendingOrder(&head, 5);
    insertInAscendingOrder(&head, 1); 
    insertInAscendingOrder(&head, 7);

// Linked List after insertion 
    printf("linked list after inserting at first.\n");
    head = insertAtFirst(head, 55);
    LinkedListTraversal(head);   
    printf("linked list after inserting at last.\n");
    head = insertAtLast(head, 78);
    LinkedListTraversal(head);   


// Linked List after deletion    
    printf("Linked List after deleting 1st node.\n");
    head = deleteFirst(head);
    LinkedListTraversal(head); 

    printf("Linked List after deleting last node.\n");    
    head = delete_last_node(head);
    LinkedListTraversal(head);

    printf("Linked List after deleting node next to index.\n");   
    head = delete_after_index(head, 3);
    LinkedListTraversal(head);

    printf("Linked List after deleting node before index.\n");  
    head = delete_before_index(head, 5);
    LinkedListTraversal(head);

    return 0;
}