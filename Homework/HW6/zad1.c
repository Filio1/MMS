#include <stdio.h>

double root(double);

int main()
{
    printf("%.6lf\n", root(50.5));
    return 0;
}

double root(double number)
{
    double error = 0.0001;
    double temp = number;
    while((temp - (number / temp)) > error)
    {
        temp = (temp + (number / temp)) / 2;
    }
    return temp;
}