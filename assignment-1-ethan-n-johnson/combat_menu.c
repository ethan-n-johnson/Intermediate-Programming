#include <stdio.h>

int main()
{
    int menuInput = 0;
    int itemInput = 0;
    int attackInput = 0;
    do
    {
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Use Item\n");
        printf("4. Exit\n> ");
        scanf("%d", &menuInput);

        if (menuInput == 1)
        {
            printf("1. Weapon Attack\n");
            printf("2. Magic Attack\n");
            printf("3. Back\n> ");
            scanf("%d", &attackInput);

            if (attackInput == 1 || attackInput == 2)
            {
                printf("Success!\n");
            }
        }
        if (menuInput == 3)
        {
            printf("1. Potion\n");
            printf("2. Elixir\n");
            printf("3. Back\n> ");
            scanf("%d", &itemInput);

            if (itemInput == 1 || itemInput == 2)
            {
                printf("Success!\n");
            }
            else
            {
                menuInput = 1;
            }
        }
        if (menuInput == 2)
        {
            printf("Success!\n");
        }
        
    } while (menuInput != 4);
}