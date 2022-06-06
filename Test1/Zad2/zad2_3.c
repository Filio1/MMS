#include <stdio.h>
#include <inttypes.h>

void mirrorBits(uint16_t*);

int main()
{
    uint16_t mask = 0b1111111100000000;
    mirrorBits(&mask);
    for(int i = sizeof(mask) * __CHAR_BIT__ - 1; i >= 0; i--)
    {
        printf("%d", !!(mask & (1 << i)));
    }
    return 0;
}

void mirrorBits(uint16_t* mask)
{
    for(int i = 0; i < sizeof(*mask) * __CHAR_BIT__; i++)
    {
        *mask ^= (1 << i);
    }
}