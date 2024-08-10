#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "queue_utils.h"

int roll_dice()
{
    int dice = (rand() % 20) + 1;
    return dice;
}

int compare_rolls(const void *elem1, const void *elem2)
{
    struct node_s *turnOrderA = (struct node_s *)elem1;
    struct node_s *turnOrderB = (struct node_s *)elem2;

    if (turnOrderB->roll == turnOrderA->roll)
    {
        int i = rand() % 2;

        if (i == 0)
            return 1;

        else
        {
            return -1;
        }
    }
    return turnOrderB->roll - turnOrderA->roll;
}

int main(int argc, char *argv[])
{
    srand(time(0));

    // Validate input arguments
    if (argc == 1)
    {
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
    struct node_s *initiativeOrder = NULL;
    struct node_s *initiativeQueue = NULL;
    struct node_s *temp = NULL;

    int numbersRead = load_monster_csv(&monsters_ptr, fp);
    fclose(fp);

    int input = 0;
    char buffer[MAX_LEN];
    int count = 0;
    int reroll = 0;
    int selectedMonster = 0;
    char *endptr;

    do
    {
        printf("1. Add Monsters\n2. Roll Initiative\n3. Next Turn\n4. View Current Order\n5. Quit\n> ");
        scanf(" %s", buffer);
        printf("\n");
        input = strtol(buffer, &endptr, 10);
        if (*endptr == '\0')
        {
            switch (input)
            {
            case 1:
                count = add_to_order(monsters_ptr, &initiativeOrder, numbersRead);
                break;

            case 2:
                if (!reroll)
                {
                    display_rolls(&initiativeOrder, count);
                    qsort(initiativeOrder, count, sizeof(struct node_s), compare_rolls);

                    for (int i = 0; i < count; i++)
                    {
                        if (initiativeQueue == NULL)
                        {
                            initiativeQueue = enqueue(NULL, initiativeOrder[i].data, initiativeOrder[i].position, initiativeOrder[i].roll);
                        }
                        else
                        {
                            initiativeQueue = enqueue(initiativeQueue, initiativeOrder[i].data, initiativeOrder[i].position, initiativeOrder[i].roll);
                        }
                    }
                    reroll = 1;
                }
                else
                {
                    char roll_input = 0;
                    do
                    {
                        printf("Would you like to reroll (Yes or No)?\n> ");
                        scanf(" %s", buffer);
                        printf("\n");
                        if (strcmp(buffer, "Yes") && strcmp(buffer, "No"))
                        {
                            printf("Invalid Input\n");
                        }
                        else if (!strcmp(buffer, "Yes"))
                        {
                            struct node_s *current = initiativeQueue;
                            while (current != NULL)
                            {
                                struct node_s *temp = current;
                                current = current->next;
                                temp = NULL;
                            }
                            initiativeQueue = NULL;
                            display_rolls(&initiativeOrder, count);
                            qsort(initiativeOrder, count, sizeof(struct node_s), compare_rolls);

                            for (int i = 0; i < count; i++)
                            {
                                if (initiativeQueue == NULL)
                                {
                                    initiativeQueue = enqueue(NULL, initiativeOrder[i].data, initiativeOrder[i].position, initiativeOrder[i].roll);
                                }
                                else
                                {
                                    initiativeQueue = enqueue(initiativeQueue, initiativeOrder[i].data, initiativeOrder[i].position, initiativeOrder[i].roll);
                                }
                            }
                            reroll = 1;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    } while (roll_input != 'y' && roll_input != 'n');
                }
                break;

            case 3:
                if (!reroll)
                {
                    printf("Roll first\n");
                }
                else
                {
                    temp = dequeue(&initiativeQueue, initiativeQueue[0].data, initiativeQueue[0].position, initiativeQueue[0].roll);
                    initiativeQueue = enqueue_to_end(initiativeQueue, temp);
                    peak(&initiativeQueue, count);
                }
                break;

            case 4:
                if (!reroll)
                {
                    printf("Roll first\n");
                }
                else
                {
                    display_order(&initiativeQueue, count);
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input\n");
                input = 0;
                break;
            }
        }
        else
        {
            printf("Invalid Input\n");
            input = 0;
        }
    } while (input != 5);

    free(monsters_ptr);
    // Free initaitveOrder
    struct node_s *current = initiativeQueue;
    while (current != NULL)
    {
        struct node_s *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}