#define PI 3.141592
#include <stdio.h>

int cylinder(double,double,double*,double*);

int main()
{
    double r, h, S = 0, V = 0;
    while(scanf("%lf %lf", &r, &h) != -1)
    {
        if(cylinder(r, h, &V, &S) == -1)
        {
            fprintf(stderr,"Invalid data\n");
        }
        else
        {
            printf("V = %.2lf, S = %.2lf\n", V , S);
        }
    }
    return 0;
}

int cylinder(double r, double h, double *V, double *S)
{
    if(r <= 0 || h <= 0){
        return -1;
    }
    *V = PI * r * r * h;
    *S = 2 * PI * r * (r + h);
    return 0;
}