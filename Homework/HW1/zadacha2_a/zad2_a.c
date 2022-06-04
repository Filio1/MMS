#include <stdio.h>
#include <math.h>

int main()
{
    double r, h, volume;
    printf("Enter radius: ");
    scanf("%lf", &r);
    printf("Enter height: ");
    scanf("%lf", &h);
    volume = 3.141592 * pow(r,2) * h;
    printf("The volume of the water is: %.2lf\n", volume);
    return 0;
}