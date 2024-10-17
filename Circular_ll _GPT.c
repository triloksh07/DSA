#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node *next;
};

// Linked List Traversal
void LinkedListTraversal(struct Node *head) {
    if (head == NULL) return; // Edge case: empty list
    struct Node *ptr = head;
    do {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Insertion at the beginning of the circular linked list
struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    ptr->data = data;

    // Edge case: if the list is empty, create a single-node circular list
    if (head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    // Traverse to the last node of the circular linked list
    struct Node *p = head;
    while (p->next != head) {
        p = p->next;
    }
    
    // Insert the new node at the beginning
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;
    struct Node *fifth = NULL;

    // Allocate memory for nodes in the circular linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL || second == NULL || third == NULL || fourth == NULL || fifth == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Initialize data and create the circular linked list
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = head; // Circular link

    // Circular Linked list before insertion
    printf("Circular Linked List before insertion:\n");
    LinkedListTraversal(head);

    // Insert a new node at the beginning
    head = insertAtFirst(head, 78);

    // Circular Linked list after insertion
    printf("\nCircular Linked List after insertion:\n");
    LinkedListTraversal(head);

    return 0;
}
