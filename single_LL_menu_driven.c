#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
void LinkedListTraversal(struct Node *ptr);
struct Node *insertAtFirst(struct Node *head, int data);
struct Node *insertAtLast(struct Node *head, int data);
struct Node* createNode(int data);
void insertInAscendingOrder(struct Node** head, int data);
struct Node *deleteFirst(struct Node *head);
struct Node *delete_last_node(struct Node *head);
struct Node *delete_after_index(struct Node *head, int index);
struct Node* delete_before_index(struct Node *head, int index);

int main() {
    struct Node *head = NULL;
    int choice, data, index;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert in Ascending Order\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete After Index\n");
        printf("7. Delete Before Index\n");
        printf("8. Display List\n");
        printf("9. Enter Multiple Elements\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at first: ");
                scanf("%d", &data);
                head = insertAtFirst(head, data);
                break;

            case 2:
                printf("Enter value to insert at last: ");
                scanf("%d", &data);
                head = insertAtLast(head, data);
                break;

            case 3:
                printf("Enter value to insert in ascending order: ");
                scanf("%d", &data);
                insertInAscendingOrder(&head, data);
                break;

            case 4:
                head = deleteFirst(head);
                break;

            case 5:
                head = delete_last_node(head);
                break;

            case 6:
                printf("Enter index after which to delete: ");
                scanf("%d", &index);
                head = delete_after_index(head, index);
                break;

            case 7:
                printf("Enter index before which to delete: ");
                scanf("%d", &index);
                head = delete_before_index(head, index);
                break;

            case 8:
                LinkedListTraversal(head);
                break;

            case 9:
                {
                    int n;
                    printf("How many elements do you want to enter? ");
                    scanf("%d", &n);
                    for (int i = 0; i < n; i++) {
                        printf("Enter element %d: ", i + 1);
                        scanf("%d", &data);
                        head = insertAtLast(head, data); 
                    }
                    break;
                }

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);

    // Free the linked list memory before exiting
    struct Node* current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

// Function definitions...

void LinkedListTraversal(struct Node *ptr) {
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while(ptr != NULL) {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *ptr =(struct Node*)malloc(sizeof (struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr; // Return new head
}

struct Node *insertAtLast(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof (struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr; // If the list is empty, return new node as head
    }

    struct Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    
    p->next = ptr; // Link new node at the end
    return head;
}

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

void insertInAscendingOrder(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;

        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

struct Node *deleteFirst(struct Node *head) {
   if (head == NULL) return NULL; // Check for empty list

   struct Node *ptr = head;
   head = head->next; 
   free(ptr);  
   return head; // Return updated head
}

struct Node *delete_last_node(struct Node *head) {
   if (head == NULL) {
       return NULL; // If the list is empty
   }
   
   if (head->next == NULL) { // If there's only one node
       free(head);
       return NULL; 
   }

   struct Node *ptr = head;
   struct Node *q = head->next;

   while (q->next != NULL) { // Traverse to find second last node
       ptr = ptr->next; 
       q = q->next; 
   }

   ptr->next = NULL; // Remove last node
   free(q); // Free memory of last node

   return head; // Return updated head of the list
}

struct Node *delete_after_index(struct Node *head, int index) {
   if (head == NULL || index < 0) {
       printf("The list is empty or index is invalid.\n");
       return head; // Return head as is
   }

   struct Node *ptr = head;

   for (int i = 0; i < index && ptr != NULL; i++) {
       ptr = ptr->next;
   }

   if (ptr == NULL || ptr->next == NULL) { // No valid node to delete after given index
       printf("No node exists after index %d.\n", index);
       return head; 
   }

   struct Node *toDelete = ptr->next; // The node to be deleted
   ptr->next = toDelete->next; // Bypass and free memory of deleted node
   free(toDelete);

   return head; // Return updated head of the list
}

struct Node* delete_before_index(struct Node *head, int index) {
   if (head == NULL || index <= 0) {
       printf("No node exists before index %d.\n", index);
       return head; // No deletion possible
   }

   struct Node *current = head;
   struct Node *prev = NULL;

   for (int i = 0; current != NULL && i < index; i++) {
       prev = current; // Track previous node
       current = current->next; // Move to next node
   }

   if (prev == head) { 
       head = current; // Move head to the next element if deleting the first element
       free(prev); // Free memory of deleted node
       return head; // Return updated head of the list
   }

   struct Node* toDelete = head;

   while(toDelete && toDelete->next != prev){
       toDelete=toDelete->next;
   }
   
   toDelete->next=prev;

   free(prev); 

   return head; 
}