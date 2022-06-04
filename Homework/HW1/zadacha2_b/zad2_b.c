#include <stdio.h>
#include <math.h>

int main()
{
    double r, h, l, volume;
    printf("Enter radius: ");
    scanf("%lf", &r);
    printf("Enter lenght: ");
    scanf("%lf", &l);
    printf("Enter height: ");
    scanf("%lf", &h);
    volume = acos((r-h)/r) * pow(r,2) - (r - h) * sqrt(2 * r * h - pow(h,2));
    printf("The volume of the water is: %.2lf\n", volume);
    return 0;
}