#include <stdio.h>

int main()
{
    int students = 0, choice, shift;
    int doCycle = 1;
    while(doCycle){
        printf("Enter 1 to set attendance.\n");
        printf("Enter 2 to clear attendance.\n");
        printf("Enter 3 to print attendance.\n");
        printf("Enter 4 to change attendance.\n");
        printf("Enter 5 to exit.\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Set attendance of student (number from 0 to 31): ");
            scanf("%d", &shift);
            while(shift > 31 || shift < 0)
            {
                printf("Error! Ivalid number! Please try again!\n");
                scanf("%d", &shift);
            }
            students |= (1 << shift);
            break;
        case 2:
            printf("Clear attendance of student (number from 0 to 31): ");
            scanf("%d", &shift);
            while(shift > 31 || shift < 0)
            {
                printf("Error! Ivalid number! Please try again!\n");
                scanf("%d", &shift);
            }
            students &= ~(1 << shift); 
            break;
        case 3:
            for(int i = 31; i >= 0; i--){
                printf("%d", !!(students & (1 << i)));
            }
            printf("\n");
            break;
        case 4:
            printf("Change attendance of student (number from 0 to 31): ");
            scanf("%d", &shift);
            while(shift > 31 || shift < 0)
            {
                printf("Error! Ivalid number! Please try again!\n");
                scanf("%d", &shift);
            }
            students ^= (1 << shift);
            break;
        case 5:
            doCycle = 0;
            break;
        
        default:
            printf("Invalid option! Please try again!\n");
            break;
        }
    }
    return 0;
}