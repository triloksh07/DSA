#include <stdio.h>
#include <stdlib.h>

// Define a node for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->rear == NULL) { // If the queue is empty
        q->front = q->rear = newNode;
        printf("Enqueued %d\n", value);
        return;
    }

    // Add the new node at the end of the queue
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued %d\n", value);
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1;
    }

    struct Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;

    // If front becomes NULL, set rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp); // Free the memory of the dequeued node
    return dequeuedValue;
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create an empty queue
    struct Queue* q = createQueue();

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // Display the queue
    displayQueue(q);

    // Dequeue elements
    printf("Dequeued %d\n", dequeue(q));
    displayQueue(q);

    printf("Dequeued %d\n", dequeue(q));
    displayQueue(q);

    return 0;
}
