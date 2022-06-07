#include <stdio.h>

unsigned sumArrayDigits(const int*, size_t);

int main()
{
    int arr[] = {12, 34, 5, 70, 0, 5};
    printf("%d\n", sumArrayDigits(arr, sizeof(arr) / sizeof(*arr)));
    return 0;
}

unsigned sumArrayDigits(const int* arr, size_t n)
{
    unsigned sum = 0;
    for(int i = 0; i < n; i++)
    {
        int currentNum = arr[i];
        while(currentNum)
        {
            sum += currentNum % 10;
            currentNum /= 10;
        }
    }
    return sum;
}