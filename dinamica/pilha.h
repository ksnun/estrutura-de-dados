#include <stdlib.h>

typedef int Item;

typedef struct node {
    Item item;
    struct node *next;
} * Stack;

void create(Stack *stack) {
    *stack = NULL;
}

void push(Stack *stack, Item item) {
    Stack ptr = (Stack)malloc(sizeof(struct node));
    ptr->item = item;
    ptr->next = *stack;
    *stack = ptr;
}

Item pop(Stack *stack) {
    if (*stack == NULL) abort();
    Item item = (*stack)->item;
    Stack ptr = *stack;
    *stack = ptr->next;
    free(ptr);
    return item;
}

Item top(Stack stack) {
    return stack->item;
}

void destroy(Stack *stack) {
    while (*stack != NULL) {
        Stack ptr = *stack;
        *stack = ptr->next;
        free(ptr);
    }
}