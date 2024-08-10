#include <stdio.h>
#include <stdlib.h>

// Sort values based on their divisibility and size
int compare_int(const void *elem1, const void *elem2)
{

    int value1 = *((int *)elem1);
    int value2 = *((int *)elem2);

    if (value1 % 2 && !(value2 % 2))
    {
        return 1;
    }
    else if (value2 % 2 && !(value1 % 2))
    {
        return -1;
    }
    else if (value1 > value2)
    {
        return 1;
    }
    else if (value2 > value1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int arraySize = 0;

    // Get array size from user.
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    // Allocate memory for the array
    int *array = (int *)malloc(arraySize * sizeof(int));

    // Get array values from user
    printf("Enter %d values: ", arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &array[i]);
    }

    // Print array before sort
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sort array
    qsort(array, arraySize, sizeof(int), compare_int);

    // Print array after sort
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
}