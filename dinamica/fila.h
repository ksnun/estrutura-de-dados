#include <stdlib.h>

typedef int Item;

typedef struct node {
    Item item;
    struct node *next;
} * Queue;

void create(Queue *queue) {
    *queue = NULL;
}

void store(Queue *queue, Item item) {
    while (*queue != NULL) queue = &(*queue)->next;
    Queue ptr = (Queue)malloc(sizeof(struct node));
    ptr->item = item;
    ptr->next = NULL;
    *queue = ptr;
}

Item retrieve(Queue *queue) {
    if (*queue == NULL) abort();
    Queue ptr = *queue;
    *queue = ptr->next;
    Item value = ptr->item;
    free(ptr);
    return value;
}

void destroy(Queue *queue) {
    while (*queue != NULL) {
        Queue ptr = *queue;
        *queue = ptr->next;
        free(ptr);
    }
}