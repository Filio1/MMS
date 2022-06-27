#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

#define ITEMS_COUNT 5

typedef struct 
{
    int n;
    char description[251];
    double weight;
    double price;
}item_t;

typedef struct node
{
    item_t item;
    struct node* next;
}node_t;

void randName(char *);
double randReal(double, double);
uint16_t randint(uint16_t, uint16_t);
void push(node_t**, item_t);
void listFree(node_t**);
double totalItemsWeight(node_t*);
node_t *minPriceItem(node_t*);
void print_list(node_t*);

int main()
{
    srand(time(NULL));
    node_t* head = NULL;
    for(int i = 0; i < ITEMS_COUNT; i++){
        item_t temp;
        temp.n = randint((10 * i), (10 * i) + 10);
        randName(temp.description);
        temp.weight = randReal(0.1, 100.0);
        temp.price = randReal(1.0, 1500.0);
        push(&head, temp);
    }

    print_list(head);
    printf("Total weight: %.2lf\n", totalItemsWeight(head));
    node_t* minItem = minPriceItem(head);
    printf("Min price item:\n");
    printf("%5d ", minItem->item.n);
    printf("%100s ", minItem->item.description);
    printf("%3.2lf ", minItem->item.weight);
    printf("%3.2lf\n", minItem->item.price);


    listFree(&head);
    return 0;
}

node_t *minPriceItem(node_t* items)
{
    if(items == NULL){
        return NULL;
    }
    node_t* minItem = malloc(sizeof(node_t));
    double min = items->item.price;
    minItem = items;
    items = items->next;
    while (items)
    {
        if(items->item.price < min){
            min = items->item.price;
            minItem = items;
        }
        items = items->next;
    }
    return minItem;
}

double totalItemsWeight(node_t* items)
{
    if(items == NULL){
        return -1;
    }
    double sum = 0;
    while(items){
        sum += items->item.weight;
        items = items->next;
    }
    return sum;
}

void print_list(node_t* list){
    node_t* current = list;
    while (current != NULL){
        printf("%5hd ", current->item.n);
        printf("%100s ", current->item.description);
        printf("%3.2lf ", current->item.weight);
        printf("%3.2lf\n", current->item.price);
        current = current->next;
    }
}

void push(node_t** list, item_t value){
    node_t* n = malloc(sizeof(node_t));
    n->item.n = value.n;
    n->item.price = value.price;
    n->item.weight = value.weight;
    strcpy(n->item.description, value.description);
    n->next = *list;
    *list = n;
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

void randName(char *name)
{
    int i = 0;
    name[i] = randint('A', 'Z');
    i++;
    int words = randint(5, 10);
    for(int j = 0;j < words; i++, j++)
    {
        int wordLenght = randint(1, 10);
        for(int k = 0; k < wordLenght; k++){
            name[i] = randint('a', 'z');
            i++;
        }
        name[i] = ' ';
        i++;
    }
    name[i] = 0;
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

uint16_t randint(uint16_t min, uint16_t max)
{
    return (uint16_t)(min + rand() % (max - min + 1));
}