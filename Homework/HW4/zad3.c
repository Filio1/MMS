#include <stdio.h>

int main()
{
    unsigned int number, base, outputBase;
    printf("Enter a number: ");
    scanf("%u", &number);
    printf("Enter base of the number: ");
    scanf("%u", &base);
    printf("Enter base of the desired number system: ");
    scanf("%u", &outputBase);
    return 0;
}