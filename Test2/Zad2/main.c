#include "car.h"

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