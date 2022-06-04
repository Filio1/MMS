#include <stdio.h>
#include <math.h>

int main()
{
    double weight, height, BMI;
    printf("Enter weight: ");
    scanf("%lf", &weight);
    printf("Enter height: ");
    scanf("%lf", &height);
    BMI = 1.3 * (weight / pow(height,2.5));
    printf("BMI: %.2lf\n", BMI);
    return 0;
}