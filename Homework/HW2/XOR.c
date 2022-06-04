#include <stdio.h>

int main()
{
    int num1, num2, num3, num4;
    scanf("%d %d %d", &num1, &num2, &num3);
    //bitwise XOR
    //num4 = num1 ^ num2 ^ num3;
    //logical XOR
    if(num1 != num2) num4 = 1;
    else num4 = 0;
    if(num3 != num4) num4 = 1;
    else num4 = 0;
    printf("%d\n", num4);
    return 0;
}

//komandi za 3ta zadacha
//cat numbers3.txt | sort -n | head -1 - nai - malkoto chislo
//cat numbers3.txt | sort -n | tail -1 - nai - golqmoto chislo