/* fila circular */
#include <stdlib.h>
#define next(x) (x = (x + 1) % queue->size)

typedef int Item;

typedef struct queue {
    int size;
    int total;
    int front;
    int rear;
    Item *item;
} * Queue;

Queue create(int size) {
    Queue ptr = (Queue)malloc(sizeof(struct queue));
    ptr->size = size;
    ptr->total = 0;
    ptr->front = 0;
    ptr->rear = 0;
    ptr->item = (Item *)malloc(sizeof(ptr->size * sizeof(Item)));
    return ptr;
}

int isempty(Queue queue) {
    return (queue->total == 0);
}

int isfull(Queue queue) {
    return (queue->total == queue->size);
}

void store(Queue queue, Item item) {
    if (isfull(queue)) abort();
    queue->item[queue->rear] = item;
    next(queue->rear);
    queue->total++;
}

Item retrieve(Queue queue) {
    if (isempty(queue)) abort();
    Item item = queue->item[queue->front];
    next(queue->front);
    queue->total--;
    return item;
}

void destroy(Queue *queue) {
    free((*queue)->item);
    free(*queue);
    *queue = NULL;
}