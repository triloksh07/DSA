#include <stdio.h>
#include <stdlib.h>
// define queue
struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->f==q->r){
        printf("Queue underflow!\n");
        return 1;
    } return 0;
}

int isFull(struct queue *q){
    if((q->r+1)%q->size== q->f){
        printf("Queue Overflow!\n"); 
        return 1;
    } return 0;
}

int enQueue(struct queue *q, int value){
    if(isFull(q)){
        return 1;
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = value;
         printf("Enqueued %d\n", value);
    }
}

int deQueue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        return 1;
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
        return a;
    }
}
// Function to print all stored elements
void printQueue(struct queue *q) {
    if(isEmpty(q)){
        // printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for(int i = q->f + 1; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    struct queue q; 
    // q = (struct queue*)malloc(sizeof(struct queue));
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    if(isEmpty(&q)){
        // printf("Queue is empty!\n");
    }

    //enque element
    enQueue(&q, 7);
    enQueue(&q, 23);
    enQueue(&q, 55);
    enQueue(&q, 78);

    if(isEmpty(&q)){
        printf("Queue is empty!\n");
        }
     printQueue(&q);    
// Dequeue elements
    int dequeued = deQueue(&q);
    if(dequeued != -1){
        printf("Dequeued %d\n", dequeued);
    }
    
    printQueue(&q);

    // enQueue(&q, 26);
    // enQueue(&q, 24);
    // enQueue(&q, 20);

    // printQueue(&q);

    return 0;
}