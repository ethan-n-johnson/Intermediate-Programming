// Ethan Johnson 1002008374

#include <stdio.h> 
#include <string.h>

#define BUFSIZE 1024

int main() 
{
    FILE *fp = NULL;
    char buffer[BUFSIZE] = { 0 };

    printf("Enter a filename: ");
    fgets(buffer, BUFSIZE, stdin);
    int length = strlen(buffer);
    buffer[length - 1]=0;
    fp = fopen(buffer, "r");
    
    if(fp == NULL)
    {
        printf("File did not open.\n");
        return 1;
    }

    while (fgets(buffer, BUFSIZE, fp))
    {
        printf("%s", buffer);
    }

    fclose(fp);
    
    return 0;
}