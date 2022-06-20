#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 5

typedef struct p
{
    double x, y;
}point_t;

typedef struct r
{
    point_t A;
    point_t B;
}rectangle_t;

typedef struct l
{
    rectangle_t rect;
    struct l* next;
}node_t;

double randReal(double, double);
void listFree(node_t**);
void push(node_t**, rectangle_t);
double areaRects(node_t*);

int main(void)
{
    srand(time(NULL));
    node_t* head = NULL;
    rectangle_t rect;
    for(int i = 0; i < COUNT; i++)
    {
        rect.A.x = randReal(-10.0, 10.0);
        rect.A.y = randReal(-10.0, 10.0);
        rect.B.x = randReal(-10.0, 10.0);
        rect.B.y = randReal(-10.0, 10.0);
        push(&head, rect);
    }
    printf("%.2lf\n", areaRects(head));
    listFree(&head);
    return 0;
}

double areaRects(node_t* list)
{
    double sumArea = 0;
    double a;
    double b;
    double area_current = 0;
    while(list)
    {
        if(list->rect.A.x == list->rect.B.y || list->rect.A.y == list->rect.B.y)
        {
            continue;
        }
        a = abs(list->rect.A.x - list->rect.B.x);
        b = abs(list->rect.A.y - list->rect.B.y);
        area_current = a * b;
        sumArea += area_current;
        list = list->next;
    }
    return sumArea;
}

void push(node_t** list, rectangle_t r){
    node_t* temp = malloc(sizeof(node_t));
    temp->rect.A.x = r.A.x;
    temp->rect.A.y = r.A.y;
    temp->rect.B.x = r.B.x;
    temp->rect.B.y = r.B.y;
    temp->next = *list;
    *list = temp;
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

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}