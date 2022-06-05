#include <stdio.h>

int rectangle(double, double, double*,double*);

int main()
{
    double width, height, S = 0, P = 0;
    while(scanf("%lf %lf", &width, &height) != -1)
    {
        if(rectangle(width,height,&S,&P) == -1)
        {
            printf("Invalid rectangle sizes!\n");
        }
        else
        {
            printf("S = %.2lf\nP = %.2lf\n", S, P);
        }
    }
    return 0;
}

int rectangle(double w, double h, double *S, double *P)
{
    if(w <=0 || h <= 0)
    {
        return -1;
    }
    *S = w * h;
    *P = 2 * (w + h);
    return 0;
}