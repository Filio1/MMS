#include <stdio.h>
#include <math.h>

int triangle(double,double,double,double*,double*);

int main()
{
    double a, b, c, P = 0, S = 0;
    while(scanf("%lf %lf %lf", &a, &b, &c) != -1)
    {
        if(triangle(a,b,c,&P,&S) == -1)
        {
            printf("Invalid triangle sides!\n");
        }
        else
        {
            printf("S = %.2lf\nP = %.2lf\n", S, P);
        }
    }
    return 0;
}

int triangle(double a, double b, double c, double *P, double *S)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return -1;
    }
    *P = a + b + c;
    double sp = *P / 2;
    *S = sqrt(sp * (sp - a) * (sp - b) * (sp -c));
    return 0;
}