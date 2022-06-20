#include <stdio.h>

typedef struct n
{
    int data;
    struct n* next;
    struct n* prev;
}node_t;

void push(node_t**, int);
void listFree(node_t**);

int main()
{
    int n, value;
    node_t* head;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d ", &value);
        push(&head, value);
    }

    listFree(&head);
    return 0;
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void push(node_t** list, int data){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = data;
    temp->next = *list;
    temp->prev = *list;
    *list = temp;
}