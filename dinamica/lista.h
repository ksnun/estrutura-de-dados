/* Lista encadeada */
#include <stdlib.h>

typedef int Item;

typedef struct node {
    Item item;
    struct node *next;
} * List;

void create(List *list) {
    *list = NULL;
}

// inserção desordenada
void dinsert(List *list, Item item) {
    while (*list != NULL)
        list = &(*list)->next;
    List ptr = (List)malloc(sizeof(struct node));
    ptr->item = item;
    ptr->next = *list;
    *list = ptr;
}

// inserção ordenada
void oinsert(List *list, Item item) {
    while (*list != NULL && (*list)->item < item)
        list = &(*list)->next;
    List ptr = (List)malloc(sizeof(struct node));
    ptr->item = item;
    ptr->next = *list;
    *list = ptr;
}

void destroy(List *list) {
    while (*list != NULL) {
        List ptr = *list;
        *list = ptr->next;
        free(ptr);
    }
}
