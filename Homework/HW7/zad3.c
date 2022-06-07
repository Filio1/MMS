#include <stdio.h>

void arrayEvaluate(int*, size_t, int(*)(int*,size_t));
int sum(int*, size_t);

int main()
{
    int arr[] = {1, 2, 3, 4};
    arrayEvaluate(arr, sizeof(arr) / sizeof(*arr), sum);
    return 0;
}

void arrayEvaluate(int *arr, size_t n, int(*f)(int *,size_t))
{
    printf("%d\n", f(arr, n));
}

int sum(int *arr, size_t n)
{
    int sum = 0;
    for(int i = 0;i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}