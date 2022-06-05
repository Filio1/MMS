#include <stdio.h>

int main()
{
    double num1, num2;
    char operator;
    while(scanf("%lf %c %lf", &num1, &operator, &num2) != -1)
    {
        switch (operator)
        {
        case '+':
            printf("%.2lf\n", num1 + num2);
            break;
        case '-':
            printf("%.2lf\n", num1 - num2);
            break;
        case '*':
            printf("%.2lf\n", num1 * num2);
            break;
        case '/':
            printf("%.2lf\n", num1 / num2);
            break;
        default:
            fprintf(stderr,"Invalid operator!\n");
            break;
        }
    }
    return 0;
}