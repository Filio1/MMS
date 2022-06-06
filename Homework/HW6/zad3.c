#include <stdio.h>
#include <stdint.h>
#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8 5
#define TUINT16 6
#define TUINT32 7
#define TUINT64 8

void printValue(const void *, uint8_t);

int main()
{
    char num = 'F';// s vsichki tipove
    printValue(&num, TCHAR);
    return 0;
}

void printValue(const void *ptr, uint8_t flag)
{
    switch (flag)
    {
    case TINT:
        printf("%d\n", *((int *)ptr));
        break;
    case TCHAR:
        printf("%c\n", *((char *)ptr));
        break;
    case TDOUBLE:
        printf("%.2lf\n", *((double *)ptr));
        break;
    case TFLOAT:
        printf("%.2f\n", *((float *)ptr));
        break;
    case TUINT8:
        printf("%d\n", *((uint8_t *)ptr));
        break;
    case TUINT16:
        printf("%d\n", *((uint16_t *)ptr));
        break;
    case TUINT32:
        printf("%u\n", *((uint32_t *)ptr));
        break;
    case TUINT64:
        printf("%ld\n", *((uint64_t *)ptr));
        break;
    default:
        break;
    }
}