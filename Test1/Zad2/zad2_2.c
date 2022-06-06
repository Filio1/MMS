#include <stdio.h>
#include <inttypes.h>

void flipOddBits(uint64_t *);

int main()
{
    uint64_t mask = 0UL;
    flipOddBits(&mask);
    for(int i = sizeof(mask) * __CHAR_BIT__ - 1; i > 0; i--)
    {
        printf("%d", !!(mask & (1 << i)));
    }
    return 0;
}

void flipOddBits(uint64_t *mask)
{
    for(int i = 0, counter = 0; i < sizeof(*mask) * __CHAR_BIT__ - 1; i++, counter++)
    {
        if(counter % 2 == 1)
        {
            *mask = (*mask) ^ (1UL << i);
        }
    }
}