#include <stdio.h>
#include <inttypes.h>

int onesCount(uint64_t);

int main()
{
    uint64_t mask;
    unsigned count;
    scanf("%lu", &mask);
    count = onesCount(mask);
    printf("%u\n", count);
    return 0;
}

int onesCount(uint64_t mask)
{
    unsigned count = 0;
    for(int i = sizeof(mask) * __CHAR_BIT__ - 1;i >= 0; i--)
    {
        if(mask & (1UL << i)) count++;
    }
    return count;
}