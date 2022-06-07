#include <stdio.h>
#include <limits.h>

int secondMax(const int*, size_t, int*);

int main()
{
    int sm;
    int arr[] = {12, 34, 5, 70, 46};
    int result = secondMax(arr, sizeof(arr) / sizeof(*arr), &sm);
    if(result == -1) fprintf(stderr, "The array is empty!\n");
    else if(result == 1) printf("There is only one number in the array\n");
    else if(result == 2) printf("All elements in the array are equal\n");
    else printf("%d\n", sm);
    return 0;
}

int secondMax(const int* arr, size_t n, int* secondMax)
{
    if(n == 0) return -1;
    if(n == 1) return 1;
    int flag = 1;
    int max = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[0] != arr[i])
        {
            flag = 0;
        }
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    if(flag) return 2; 
    *secondMax = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > *secondMax && arr[i] < max)
        {
            *secondMax = arr[i];
        }
    }
    return 0;
}