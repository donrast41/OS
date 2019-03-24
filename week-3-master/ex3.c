#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int x;
    struct LinkedList *successor;
};

void print_list(struct LinkedList *curr);
void insert_node(int position, int value, struct LinkedList **curr);
void delete_node(int position, struct LinkedList **curr);

void print_list(struct LinkedList *curr) {
    while (curr != NULL) {
        printf("%d, ", curr->x);
        curr = curr->successor;
    }
}

void insert_node(int position, int value, struct LinkedList **curr) {
    struct LinkedList *new_linkNode = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    new_linkNode->x = value;
    new_linkNode->successor = NULL;

    struct LinkedList *end = *curr;

    if (*curr == NULL) {
        *curr = new_linkNode;
        return;
    }
    int i = 0;
    while (end->successor != NULL && ++i < position) {
        end = end->successor;
    }
    new_linkNode->successor = end->successor;
    end->successor = new_linkNode;
}

void delete_node(int position, struct LinkedList **curr) {
    if (*curr == NULL) return;
    struct LinkedList *end = *curr;

    if (position == 0) {
        *curr = end->successor;
        free(end);
        return;
    }
    int i = 0;
    while (end->successor != NULL && ++i < position) {
        end = end->successor;
    }
    struct LinkedList *successor_to_the_one_to_be_deleted = end->successor->successor;
    free(end->successor);
    end->successor = successor_to_the_one_to_be_deleted;
}

int main() {
    struct LinkedList *start = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    start->x = 10;
    start->successor = NULL;
    print_list(start);
    printf("\n");
    insert_node(10, 30, &start);
    print_list(start);
    printf("\n");
    insert_node(20, 50, &start);
    print_list(start);
    printf("\n");
    insert_node(10, 20, &start);
    print_list(start);
    printf("\n");
    insert_node(30, 40, &start);
    print_list(start);
    printf("\n");
    delete_node(0, &start);
    print_list(start);
    return 0;
}
