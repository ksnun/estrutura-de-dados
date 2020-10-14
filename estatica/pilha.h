#include <stdlib.h>

typedef int Item;

typedef struct stack {
    int size;
    int top;
    Item *item;
} * Stack;

Stack create(int size) {
    Stack ptr = (Stack)malloc(sizeof(struct stack));
    ptr->top = -1;
    ptr->size = size;
    ptr->item = (Item *)malloc(ptr->size * sizeof(int));
    return ptr;
}

int isfull(Stack stack) {
    return stack->top == stack->size - 1 ? 1 : 0;
}

int isempty(Stack stack) {
    return stack->top == -1 ? 1 : 0;
}

void push(Stack stack, Item item) {
    if (isfull(stack)) abort();
    stack->top++;
    stack->item[stack->top] = item;
}

Item pop(Stack stack) {
    if (isempty(stack)) abort();
    Item valor = stack->item[stack->top];
    stack->top--;
    return valor;
}

Item top(Stack stack) {
    return stack->item[stack->top];
}

void destroy(Stack *stack) {
    free((*stack)->item);
    free(*stack);
    *stack = NULL;
}