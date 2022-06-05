#include <stdio.h>
#include <math.h>

int quadEq(double, double, double, double*, double*);

int main()
{
    double a, b, c, x1 = 0, x2 = 0;
    while(scanf("%lf %lf %lf", &a, &b, &c) != -1)
    {
        if(quadEq(a,b,c,&x1,&x2) == -1)
        {
            printf("No real roots\n");
        }
        else
        {
            printf("x1 = %.2lf\nx2 = %.2lf\n", x1, x2);
        }
    }
    return 0;
}

int quadEq(double a, double b, double c, double *x1, double *x2)
{
    double D = b * b - 4 * a * c;
    if(D < 0) return -1;
    else if(D == 0) *x1 = *x2 = -b / (2 * a);
    else
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
    }
    return 0;
}