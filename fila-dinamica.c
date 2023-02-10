#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;    
    int valid;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue *createQueue() {
    struct Queue *q = malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int data) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->valid = 0;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Node dequeue(struct Queue *q) {
    if (q->front == NULL){
        struct Node empty = {0, NULL, 1};
        return empty;
        }
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
        struct Node res = {temp->data, NULL, 0};
                    
        free(temp);            
    return res;
}

int main() {
    struct Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    struct Node n = dequeue(q);
    if (n.valid == 0)
        printf("Dequeued item is %d\n", n.data);
    return 0;
}
