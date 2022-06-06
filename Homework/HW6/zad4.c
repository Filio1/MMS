#include <stdio.h>
#include <stdarg.h>

unsigned bitsNCount(unsigned,unsigned,...);
unsigned countBits(int);

int main()
{
    unsigned count = bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111);
    printf("%u\n", count);
    return 0;
}

unsigned bitsNCount(unsigned count, unsigned bitsCount, ...)
{
    va_list argsl;
    va_start(argsl, bitsCount);
    unsigned countNumers = 0;
    for(int i = 0; i < count; i++)
    {
        if(bitsCount == countBits(va_arg(argsl, int)))
        {
            countNumers++;
        }
    }
    va_end(argsl);
    return countNumers;
}

unsigned countBits(int mask)
{
    unsigned count = 0;
    for(int i = 0; i < sizeof(mask) * __CHAR_BIT__; i++)
    {
        if(mask & (1 << i)) count++;
    }
    return count;
}