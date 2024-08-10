#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"


void swap_int(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

void parse_monster(monster_s *monster, char *csv_line) {
    char *token = strtok(csv_line, ",");

    int attr = 0;

    while (token) {
        switch(attr) {
            case 0:
                strcpy(monster->name, token);
                break;
            case 1:
                strcpy(monster->type, token);
                break;
            case 2:
                monster->hp = atoi(token);
                break;
            case 3:
                monster->ac = atoi(token);
                break;
            case 4:
                monster->str = atoi(token);
                break;
            case 5:
                monster->dex = atoi(token);
                break;
            case 6:
                monster->con = atoi(token);
                break;
        }
        attr++;
        token = strtok(NULL, ",");

    }
}

/*
 * Loads all monsters from a CSV file into memory.
 * Allocates memory pointed to by `*monsters_ptr`
 *
 * Args
 * ----
 *  monster_s **monsters_ptr - A double pointer to `monster_s`.
 *      Dereferencing this once (`*monsters_ptr`) returns the value to where the
 *      allocated memory should be stored. That is, you should assign the result
 *      of an allocation call to `*monsters_ptr`.
 *
 *  FILE *fp - A file pointer representing an open CSV file.
 *
 * Return
 * ------
 *  Returns an `int` representing the number of monsters loaded.
 */
int load_monster_csv(monster_s **monsters_ptr, FILE *fp) {
    char buffer[MAX_LEN] = { 0 };
    int num_read = 0;

    while (fgets(buffer, MAX_LEN, fp)) {
        trim(buffer);
        monster_s *temp_monster = (monster_s *)malloc(sizeof(monster_s));
        parse_monster(temp_monster, buffer);

        *monsters_ptr = (monster_s *)realloc(*monsters_ptr, sizeof(monster_s) * (num_read+1));
        // Reminder not to forget the parentheses for (*monster_ptr)
        // If forgotten you will get the error Segmentation fault
        (*monsters_ptr)[num_read] = *temp_monster;
        free(temp_monster);
            
        num_read++;
    }
    
    return num_read;
}

void print_monsters(monster_s *monster_ptr, int numbersRead)
{
    int maxNameLength = 0, maxTypeLength = 0, maxHpLength = 0, maxAcLength = 0, maxStrLength = 0, maxDexLength = 0, maxConLength = 0;

    // Gets the length for each attribute
    for (int i = 0; i < numbersRead; i++)
    {
        int tempNameLength = strlen(monster_ptr[i].name);
        int tempTypeLength = strlen(monster_ptr[i].type);
        int tempHpLength = (int)log10(monster_ptr[i].hp) + 1;
        int tempAcLength = (int)log10(monster_ptr[i].ac) + 1;
        int tempStrLength = (int)log10(monster_ptr[i].str) + 1;
        int tempDexLength = (int)log10(monster_ptr[i].dex) + 1;
        int tempConLength = (int)log10(monster_ptr[i].con) + 1;

        if (tempNameLength > maxNameLength)
        {
            maxNameLength = tempNameLength;
        }
        if (tempTypeLength > maxTypeLength)
        {
            maxTypeLength = tempTypeLength;
        }
        if (tempHpLength > maxHpLength)
        {
            maxHpLength = tempHpLength;
        }
        if (tempAcLength > maxAcLength)
        {
            maxAcLength = tempAcLength;
        }
        if (tempStrLength > maxStrLength)
        {
            maxStrLength = tempStrLength;
        }
        if (tempDexLength > maxDexLength)
        {
            maxDexLength = tempDexLength;
        }
        if (tempConLength > maxConLength)
        {
            maxConLength = tempConLength;
        }
    }

    if (maxStrLength < 3)
    {
        maxStrLength = 3;
    }
    if (maxDexLength < 3)
    {
        maxDexLength = 3;
    }
    if (maxConLength < 3)
    {
        maxConLength = 3;
    }

    // Prints the header in the same format as provided in the README
    print_header(maxNameLength, maxTypeLength, maxHpLength, maxAcLength, maxStrLength, maxDexLength, maxConLength);
    
    // Prints the attributes in the same format as provided in the README
    for (int i = 0; i < numbersRead; i++)
    {
        printf("| %-*s | %-*s | %-*d | %-*d | %-*d | %-*d | %-*d |\n", maxNameLength, monster_ptr[i].name, maxTypeLength, monster_ptr[i].type, maxHpLength, monster_ptr[i].hp, maxAcLength, monster_ptr[i].ac, maxStrLength, monster_ptr[i].str, maxDexLength, monster_ptr[i].dex, maxConLength, monster_ptr[i].con);

    }    
}

// Function prints the header above the csv data
void print_header(int maxNameLength, int maxTypeLength, int maxHpLength, int maxAcLength, int maxStrLength, int maxDexLength, int maxConLength)
{
    printf("| %-*s | %-*s | %-*s | %-*s | %-*s | %-*s | %-*s |\n", maxNameLength, "NAME", maxTypeLength, "TYPE", maxHpLength, "HP", maxAcLength, "AC", maxStrLength, "STR", maxDexLength, "DEX", maxConLength, "CON");

    printf("| ");
    for (int i = 0; i < maxNameLength; i++)
    {
        printf("-");
    }
    printf(" |");
    printf(" ");
    for (int i = 0; i < maxTypeLength; i++)
    {
        printf("-");
    }    
    printf(" |");
    printf(" ");
    for (int i = 0; i < maxHpLength; i++)
    {
        printf("-");
    }    
    printf(" |");
    printf(" ");
    for (int i = 0; i < maxAcLength; i++)
    {
        printf("-");
    }    
    printf(" |");
    printf(" ");
    for (int i = 0; i < maxStrLength; i++)
    {
        printf("-");
    }    
    printf(" |");
    printf(" ");
    for (int i = 0; i < maxDexLength; i++)
    {
        printf("-");
    }    
    printf(" |");
    printf(" ");
    for (int i = 0; i < maxConLength; i++)
    {
        printf("-");
    }    
    printf(" |");
    printf("\n");
}