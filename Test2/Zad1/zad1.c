#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define EPS 0.001
#define COUNT 10

typedef struct 
{
    char model[21];
    uint8_t maxSpeed;
    double price;
}Car;

int cmpModelASC(const void*, const void*);
int cmpModelDEC(const void*, const void*);
int cmpSpeedASC(const void*, const void*);
int cmpSpeedDEC(const void*, const void*);
int cmpPriceASC(const void*, const void*);
int cmpPriceDEC(const void*, const void*);
int randint(int, int);
double randReal(double, double);
void randName(char *);
int (*getComparator(int))(const void*, const void*);

int main()
{
    srand(time(NULL));
    Car cars[COUNT];
    for (int i = 0; i < COUNT; i++)
    {
        randName(cars[i].model);
        cars[i].maxSpeed = randint(100, 300);
        cars[i].price = randReal(1000.00, 100000.00);
    }
    int choice;
    printf("Choose compare method: ");
    scanf("%d", &choice);
    qsort(cars, COUNT, sizeof(*cars), getComparator(choice));
    for(int i = 0; i < COUNT; i++)
    {
        printf("Model: %21s MaxSpeed: %3d Price: %.2lf\n", cars[i].model, cars[i].maxSpeed, cars[i].price);
    }
    return 0;
}

int (*getComparator(int n))(const void*, const void*)
{
    switch (n)
    {
    case 1:
        return cmpModelASC;
    case 2:
        return cmpModelDEC;
    case 3:
        return cmpSpeedASC;
    case 4:
        return cmpSpeedDEC;
    case 5:
        return cmpPriceASC;
    case 6:
        return cmpPriceDEC;
    default:
        return NULL;
        break;
    }
}

void randName(char *name)
{
    int i = 0;
    name[i] = randint('A', 'Z');
    i++;
    int n = randint(4, 10);
    for(int j = 0;j < n; i++, j++)
    {
        name[i] = randint('a', 'z');
    }
    name[i] = 0;
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int cmpModelASC(const void* el1, const void* el2)
{
    Car c1 = *((Car *)el1);
    Car c2 = *((Car *)el2);
    return strcmp(c1.model, c2.model);
}

int cmpModelDEC(const void* el1, const void* el2)
{
    Car c1 = *((Car *)el1);
    Car c2 = *((Car *)el2);
    return strcmp(c2.model, c1.model);
}

int cmpSpeedASC(const void* el1, const void* el2)
{
    Car c1 = *((Car *)el1);
    Car c2 = *((Car *)el2);
    return c1.maxSpeed - c2.maxSpeed;
}

int cmpSpeedDEC(const void* el1, const void* el2)
{
    Car c1 = *((Car *)el1);
    Car c2 = *((Car *)el2);
    return c2.maxSpeed - c1.maxSpeed;
}

int cmpPriceASC(const void* el1, const void* el2)
{
    Car c1 = *((Car *)el1);
    Car c2 = *((Car *)el2);
    if(fabs(c1.price - c2.price) < EPS)
    {
        return 0;
    }
    else if(c1.price > c2.price)
    {
        return 1;
    }
    return -1;
}

int cmpPriceDEC(const void* el1, const void* el2)
{
    Car c1 = *((Car *)el1);
    Car c2 = *((Car *)el2);
    if(fabs(c1.price - c2.price) < EPS)
    {
        return 0;
    }
    else if(c1.price > c2.price)
    {
        return -1;
    }
    return 1;
}