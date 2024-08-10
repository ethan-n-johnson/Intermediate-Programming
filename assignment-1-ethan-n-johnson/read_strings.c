#include <stdio.h>
#include <string.h>


int main()
{
    char string[4][32];
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        printf("String %d: ", i+1);
        fgets(string[i], sizeof(string[i]), stdin);
        string[i][strlen(string[i]) - 1] = '\0';
    }
    for (int i = 0; i < n-1; i++) {
        int min_j = i;
        for (int j = i + 1; j < n; j++) {
            if (strlen(string[j]) > strlen(string[min_j])) {
                min_j = j;
            }
        }
        if (min_j != i) {
            char temp[32];
            strcpy(temp, string[i]);
            strcpy(string[i], string[min_j]);
            strcpy(string[min_j], temp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d. %s\n", i+1, string[i]);
    }
    
}  