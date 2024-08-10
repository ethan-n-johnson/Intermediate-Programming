#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

// Print Selection Menu
void show_menu() {
    printf("--------------------------\n");
    printf("|      MONSTER LIST      |\n");
    printf("--------------------------\n");
    printf("| 1. Filter by name      |\n");
    printf("| 2. Filter by HP        |\n");
    printf("| 3. Filter by AC        |\n");
    printf("| 4. Filter by stats     |\n");
    printf("| 5. Exit                |\n");
    printf("--------------------------\n");
}

// Sort monsters by total stats (str + dex + con) from greatest to lowest
int compare_total_stats(const void *elem1, const void *elem2)
{
    monster_s *monsterA = (monster_s *) elem1;
    monster_s *monsterB = (monster_s *) elem2;
    int totalStatsA = monsterA->str + monsterA->dex + monsterA->con;
    int totalStatsB = monsterB->str + monsterB->dex + monsterB->con; 
 
    return totalStatsB-totalStatsA;
}

// Sort monsters by AC from greatest to lowest
int compare_ac(const void *elem1, const void *elem2)
{
    monster_s *monsterA = (monster_s *) elem1;
    monster_s *monsterB = (monster_s *) elem2;
 
    return monsterB->ac-monsterA->ac;
}

// Sort monsters by HP from greatest to lowest
int compare_hp(const void *elem1, const void *elem2)
{
    monster_s *monsterA = (monster_s *) elem1;
    monster_s *monsterB = (monster_s *) elem2;
 
    return monsterB->hp-monsterA->hp;
}

// Sort monsters by name alphabetically
int compare_name(const void *elem1, const void *elem2)
{
    monster_s *monsterA = (monster_s *) elem1;
    monster_s *monsterB = (monster_s *) elem2;
 
    return strcmp(monsterA->name, monsterB->name);
}

int main(int argc, char *argv[]) 
{
    // Validate input arguments
    if (argc == 1) {
        printf("Incorrect Input\nCorrect Input: ./a.out FILEPATH");
        return 1;
    }
    FILE *fp = NULL;

    // Attempt to open file given by first command line argument
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    monster_s *monsters_ptr = NULL;    
    int numbersRead = load_monster_csv(&monsters_ptr, fp);
    print_monsters(monsters_ptr, numbersRead);


    // Run menu loop
    int choice = 0;
    while (choice != EXIT_CHOICE) {
        show_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Filters the monster data based on user input
        switch (choice) {
            // Filter by Name
            case 1:
                qsort(monsters_ptr, numbersRead, sizeof(monster_s), compare_name);
                print_monsters(monsters_ptr, numbersRead);
                break;
            // Filter by HP
            case 2:
                qsort(monsters_ptr, numbersRead, sizeof(monster_s), compare_hp);
                print_monsters(monsters_ptr, numbersRead);
                break;
            // Filter by AC
            case 3:
                qsort(monsters_ptr, numbersRead, sizeof(monster_s), compare_ac);
                print_monsters(monsters_ptr, numbersRead);
                break;
            // Filter By Stats
            case 4:
                qsort(monsters_ptr, numbersRead, sizeof(monster_s), compare_total_stats);
                print_monsters(monsters_ptr, numbersRead);
                break;
            case 5:
                if (fp) {
                    fclose(fp);
                    free(monsters_ptr);
                }
                break;
        }
    }
    return 0;
}
