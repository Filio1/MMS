#include <stdio.h>
#include <stdint.h>

#define CHECKBIT(mask, bit) (((mask) & ((1) << (bit))) >> (bit))

void swapBytes(uint16_t*);

int main()
{
    uint16_t word = 0b0000000011111111U;
    for(int i = 15; i >= 0; i--)
    {
        printf("%d", CHECKBIT(word, i));
    }
    putchar('\n');
    swapBytes(&word);
    for(int i = 15; i >= 0; i--)
    {
        printf("%d", CHECKBIT(word, i));
    }
    putchar('\n');
    return 0;
}

void swapBytes(uint16_t* word)
{
    uint8_t lowByte = 0;
    uint8_t highByte = 0;
    for(int i = 15, j = 7; i >= 8; i--, j--)
    {
        lowByte |= (CHECKBIT(*word, j)) << j;
        highByte |= (CHECKBIT(*word, i)) << j;
    }
    *word = 0;
    for(int i = 15 , j = 7; i >= 8; i--, j--)
    {
        (*word) |= (CHECKBIT(lowByte, j)) << i;
        (*word) |= (CHECKBIT(highByte, j)) << j;
    }
}