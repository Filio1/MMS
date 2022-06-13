#include <stdio.h>
#include <string.h>

int main()
{
    char bigNumber[501];
    scanf("%s", bigNumber);
    int len = strlen(bigNumber);
    for(int i = 0; i < len; i++)
    {
        bigNumber[i] -= '0';
        if(i % 2 == 0)
        {
            bigNumber[i] += 'A';
        }
        else
        {
            switch (bigNumber[i])
            {
            case 0:
                bigNumber[i] = '!';
                break;
            case 1:
                bigNumber[i] = '#';
                break;
            case 2:
                bigNumber[i] = '/';
                break;
            case 3:
                bigNumber[i] = '~';
                break;
            case 4:
                bigNumber[i] = '=';
                break;
            case 5:
                bigNumber[i] = '`';
                break;
            case 6:
                bigNumber[i] = '\\';
                break;
            case 7:
                bigNumber[i] = '>';
                break;
            case 8:
                bigNumber[i] = '.';
                break;
            case 9:
                bigNumber[i] = ',';
                break;
            default:
                break;
            }
        }
    }
    printf("%s\n", bigNumber);
    return 0;
}