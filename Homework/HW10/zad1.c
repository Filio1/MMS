#include <stdio.h>
#include <stdint.h>

#define PRINTBIT(mask, bit) (((mask) & ((1UL) << (bit))) >> (bit))

typedef union real
{
    double num;
    uint64_t bits;
}real_t;


int main()
{
    real_t realNum;
    printf("Enter a number: ");
    scanf("%lf", &(realNum.num));
    for(int i = 63; i >= 0; i--)
    {
        printf("%lu", PRINTBIT(realNum.bits, i));
        //printf("%lu", (realNum.bits & (1UL << i)) >> i);
    }
    putchar('\n');
    return 0;
}