#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n* next;
    struct n* prev;
}node_t;

void pushEnd(node_t**, int);
void listFree(node_t**);
void print_list(node_t*);

int main()
{
    int n;
    node_t* head;
    scanf("%d", &n);
    int* numbers = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
        pushEnd(&head, numbers[i]);
    }
    print_list(head);
    listFree(&head);
    free(numbers);
    return 0;
}

void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("%d ", current->data);
        current = current->next;
        if(current->next == list) break;
    }
    putchar('\n');
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current && current->next != *list){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void pushEnd(node_t** list, int data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    if (*list == NULL){
        *list = n;
        return;
    }
    node_t* current = *list;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = n;
}