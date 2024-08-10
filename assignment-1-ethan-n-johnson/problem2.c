#include <stdio.h>
#include <string.h>

void CompareString(char string2[], char string1, int charPosition)
{
    int x = 1;
    for (int i = 0; i < strlen(string2); i++)
    {
        if (string2[i] == string1)
        {
            if (i == charPosition)
            {
                printf("*");
                x = 0;
            }
            else
            {
                printf("^");
                x = 0;
            }
        }
    }
    if (x)
    {
        printf(" ");
    }
}
int main()
{
    char string1[100] = {};
    char string2[100] = {};
    
    printf("Enter your first string: ");
    fgets(string1, 100, stdin);
    string1[strlen(string1) - 1] = '\0';
    printf("Enter your second string: ");
    fgets(string2, 100, stdin);
    string2[strlen(string2) - 1] = '\0';

    if (strlen(string1) != 5 && strlen(string2) != 5)
    {
        printf("Invalid Input");
        return 1;
    }

    printf("%s\n", string1);

    for (int i = 0; i < strlen(string1); i++)
    {
        CompareString(string2,string1[i],i);
    }
}
