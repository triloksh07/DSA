#include <stdio.h>
#include <stdlib.h>

// define queue
struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q) {
    // Queue is empty if front and rear are both at the same position (initially -1)
    if(q->f == q->r) {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q) {
    // Queue is full if the next position of rear wraps around to front
    if((q->r + 1) % q->size == q->f) {
        printf("Queue Overflow!\n"); 
        return 1;
    }
    return 0;
}

void enQueue(struct queue *q, int value) {
    if(isFull(q)) {
        return;
    } else {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = value;
        printf("Enqueued %d\n", value);
    }
}

int deQueue(struct queue *q) {
    int a = -1;
    if(isEmpty(q)) {
        printf("Queue Underflow!\n");
        return a;
    } else {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        return a;
    }
}

// Function to print all stored elements
void printQueue(struct queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        int i = (q->f + 1) % q->size;
        while(i != (q->r + 1) % q->size) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % q->size;
        }
        printf("\n");
    }
}

int main() {
    struct queue q; 
    q.size = 5;  // Size needs to be one more than the actual capacity for circular queue
    q.f = q.r = 0;  // Initializing front and rear to 0 for circular queue
    q.arr = (int*)malloc(q.size * sizeof(int));

    // Enqueue elements
    enQueue(&q, 7);
    enQueue(&q, 23);
    enQueue(&q, 55);
    enQueue(&q, 78);
    enQueue(&q, 26);  // This will cause Queue Overflow due to the size limit

    printQueue(&q);    

    // Dequeue elements
    int dequeued = deQueue(&q);
    if(dequeued != -1) {
        printf("Dequeued %d\n", dequeued);
    }

    printQueue(&q);

    enQueue(&q, 26);
    enQueue(&q, 24);
    enQueue(&q, 20);

    printQueue(&q);

    return 0;
}
