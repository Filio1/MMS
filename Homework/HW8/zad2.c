#include <stdio.h>

void map(int*, size_t, int(*)(int));
int increment(int);
int doubleNumber(int);
int main()
{
    int arr[] = {1,2,3,4,5};
    for(int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    map(arr, sizeof(arr) / sizeof(*arr), increment);
    for(int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    map(arr, sizeof(arr) / sizeof(*arr), doubleNumber);
    for(int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}

void map(int *arr, size_t n, int(*func)(int))
{
    for(int i = 0;i < n; i++)
    {
        arr[i] = func(arr[i]);
    }
}

int doubleNumber(int num)
{
    return 2 * num;
}

int increment(int num)
{
    return ++num;
}