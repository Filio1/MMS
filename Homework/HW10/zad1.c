#include <stdio.h>

#define PRINTBIT(mask, bit) (((mask) & ((1) << (bit))) >> (bit))

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    for(int i = 31; i >= 0; i--)
    {
        printf("%d", PRINTBIT(num, i));
    }
    putchar('\n');
    return 0;
}