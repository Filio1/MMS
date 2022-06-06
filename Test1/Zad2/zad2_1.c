#include <stdio.h>
#include <inttypes.h>

unsigned bitsNCount(uint64_t, uint32_t, uint16_t, uint8_t);

int main()
{
    unsigned count = 0;
    uint64_t mask1 = 1024;
    uint32_t mask2 = 512;
    uint16_t mask3 = 256;
    uint8_t mask4 = 3;
    count = bitsNCount(mask1, mask2, mask3, mask4);
    printf("%u\n", count);
    return 0;
}

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4)
{
    unsigned countAll = 0;
    for(int i = sizeof(mask1) * __CHAR_BIT__ - 1; i >= 0; i--)
    {
        if(mask1 & (1UL << i))
        {
            countAll++;
        }
    }
    for(int i = sizeof(mask2) * __CHAR_BIT__ - 1; i >= 0; i--)
    {
        if(mask2 & (1U << i))
        {
            countAll++;
        }
    }
    for(int i = sizeof(mask3) * __CHAR_BIT__ - 1; i >= 0; i--)
    {
        if(mask3 & (1 << i))
        {
            countAll++;
        }
    }
    for(int i = sizeof(mask4) * __CHAR_BIT__ - 1; i >= 0; i--)
    {
        if(mask4 & (1 << i))
        {
            countAll++;
        }
    }
    return countAll;
}