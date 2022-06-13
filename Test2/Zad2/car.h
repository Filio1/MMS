#ifndef _CAR__
#define _CAR__
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
#endif