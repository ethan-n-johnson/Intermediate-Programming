#include "csv_check.h"

int ValidateFile(char *data)
{
    int result = 0;
    char *token = strtok(data, ",");

    while (token != NULL) {
        result++;
        token = strtok(NULL, ",");
    }
    return result;
}

int main()
{
    char filename[BUFFER_SIZE] = {};
    FILE *csvFile = NULL;
    char data[BUFFER_SIZE] = {};
    int validate = 1;
    
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strlen(filename) - 1] = '\0';
    csvFile = fopen(filename, "r");
    
    if (csvFile == NULL)
    {
        printf("File did not open");
        return 1;
    }

    while(fgets(data, BUFFER_SIZE, csvFile))
    {
        char data_copy[BUFFER_SIZE] = {};
        strcpy(data_copy, data);
        int num_tokens = ValidateFile(data);
        if (num_tokens != 4)
        {
            printf("%s", data_copy);
            validate = 0;
        }
    }
    if (validate)
    {
        printf("The file %s is valid.", filename);
    }
    fclose(csvFile);
}