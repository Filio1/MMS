#include <stdio.h>

#define MAX(x, y, z) (((x) > (y) && (x) > (z)) ? x : ((y) > (z)) ? y : z)
#define MIN(x, y, z) (((x) < (y) && (x) < (z)) ? x : ((y) < (z)) ? y : z)
#define CHECKBIT(mask, bit) (((mask) & ((1) << (bit))) >> (bit))
#define SETBIT(mask, bit) ((mask) |= ((1) << (bit)))
#define CLEARBIT(mask, bit) ((mask) &= (~(1 << bit)))
#define INVERSEBIT(mask, bit) ((mask) ^= (1 << bit))
#define SWAP(x, y) ((x) = (x) + (y)); ((y) = (x) - (y)); ((x) = (x) - (y)); 

int main(void)
{
    int nums[] = {3, 5, 2};
    printf("%d\n", MAX(nums[0], nums[1], nums[2]));
    printf("%d\n", MIN(nums[0], nums[1], nums[2]));
    SETBIT(nums[1], 5);
    for(int i = 31; i >= 0; i--)
    {
        printf("%d", CHECKBIT(nums[1], i));
    }
    putchar('\n');
    CLEARBIT(nums[1], 0);
    for(int i = 31; i >= 0; i--)
    {
        printf("%d", CHECKBIT(nums[1], i));
    }
    putchar('\n');
    INVERSEBIT(nums[1], 10);
    for(int i = 31; i >= 0; i--)
    {
        printf("%d", CHECKBIT(nums[1], i));
    }
    putchar('\n');
    printf("%d %d\n", nums[0], nums[2]);
    SWAP(nums[0], nums[2]);
    printf("%d %d\n", nums[0], nums[2]);
    return 0;
}