#include <stdio.h>
#define PI 3.141592
#define n 20

int fact (int);
double sinus(double);

int main()
{
    printf("%.2lf\n", sinus(90.0));
    return 0;
}


double sinus(double x) //sin calculation
{
    double sum;
    double fa;
    double pow;
    x = (PI * x) / 180.0;
    sum = 0.0;
    for(int i = 0; i <= n; i++)
    {
        fa = 1.0;
        pow = 1.0;
        for(int j = 1; j <= 2*i+1; j++)
        {
            fa *= j;
            pow *= x;
        }
        sum += ((i%2?-1.0:1.0)/fa)*pow;
    }
    return sum;
}
/*
 int fact (int a)
{
    int i;
    int k = 1;
    for (i=1;i<=a;i++)
    {
        k = k * i;
    }
    return k;
}

 double sinus(double x)
{
    double sum=0;
    int i,j=0;
    int power = 1;
    for (i=0;i<=x;i++)
    {
        if (i%2!=0)
        {
            j++;
            double numaretor = x;
            while(power < i)
            {
                numaretor *= numaretor;
                power;
            }
            double denominator = fact (i);
            double term = numaretor/denominator;
            if (j%2!=0)
            {
                 sum = sum - term;
            }
            else
            sum = sum + term;
        }
    }
    return sum;
}
*/