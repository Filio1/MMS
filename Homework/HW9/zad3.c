#include <stdio.h>
#include <stdlib.h>

int binarySearch(int*, size_t, int);
int compareIntigers(const void*, const void*);

int main()
{
    int arr[] = {521, 2136, 21, 8712, 1000, 1312, 1312, 912, 7010};
    int length = sizeof(arr) / sizeof(*arr);
    int key = 1312;
    qsort(arr, length, sizeof(*arr), compareIntigers);
    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    int index = binarySearch(arr, length, key);
    if(index == -1)
    {
        printf("Key not found in the array!\n");
    }
    else
    {
        printf("%d found at index %d\n", key, index);
    }
    return 0;
}

int compareIntigers(const void* i1, const void* i2)
{
    int num1 = *((int *)i1);
    int num2 = *((int *)i2);
    return num1 - num2;
}

int binarySearch(int* array, size_t n, int key)
{
    void* element = bsearch(&key,array,n,sizeof(*array), compareIntigers);
    if(!element)
    {
        return -1;
    }
    else
    {
        return ((size_t)element - (size_t)array) / sizeof(*array);
    }
}