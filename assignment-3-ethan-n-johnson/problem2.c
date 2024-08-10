#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

/*
    **Part 2**

        Complete `load_monster_csv` in `utils.c` which accepts the following arguments:
        - `monster_s **monsters` - a pointer-to-`monster_s`, this will be your array.
        - `FILE *fp` - a file pointer referencing an open file of CSV data.

        The function returns an `int` representing the number of monsters read from the file. The code in this function is only partially complete. Follow the comments to complete the function.
*/

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    if (argc == 1)
    {
        printf("Input Invalid\n Correct Input: ./a.out FILEPATH\n");
        return 0;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Invalid Filename or path\n");
        return 0;
    }

    monster_s *monster_ptr = NULL;
    int numRead = load_monster_csv(&monster_ptr, fp);
    for (int i = 0; i < numRead; i++)
    {
        printf("%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON\n", monster_ptr[i].name, monster_ptr[i].type, monster_ptr[i].hp, monster_ptr[i].ac, monster_ptr[i].str, monster_ptr[i].dex, monster_ptr[i].con);
    }

    fclose(fp);
    free(monster_ptr);

    return 0;
}