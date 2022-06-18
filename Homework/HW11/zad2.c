#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    double *numbers = malloc(n * sizeof(double));
    if(!numbers)
    {
        fprintf(stderr, "Malloc error!\n");
        return EXIT_FAILURE;
    }
    for(int i = 0;i < n; i++)
    {
        numbers[i] = randReal(0.0, 1.0);
    }
    int m;
    printf("Enter m: ");
    scanf("%d", &m);
    numbers = realloc(numbers, sizeof(double) * (n + m));
    if(!numbers)
    {
        fprintf(stderr, "Realloc error!\n");
        return EXIT_FAILURE;
    }
    for(int i = n; i < n + m; i++)
    {
        numbers[i] = randReal(1.0, 2.0);
    }
    int p;
    printf("Enter p: ");
    scanf("%d", &p);
    numbers = realloc(numbers, sizeof(double) * (n + m + p));
    if(!numbers)
    {
        fprintf(stderr, "Realloc error!\n");
        return EXIT_FAILURE;
    }
    for(int i = n + m; i < n + m + p; i++)
    {
        numbers[i] = randReal(2.0, 3.0);
    }
    for(int i = 0; i < n + m + p; i++)
    {
        printf("%.2lf ", numbers[i]);
    }
    putchar('\n');
    free(numbers);
    return EXIT_SUCCESS;
}