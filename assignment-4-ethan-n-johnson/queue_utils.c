#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "queue_utils.h"

void trim(char *str)
{
    int l = strlen(str);
    if (str[l - 1] == '\n')
    {
        str[l - 1] = 0;
    }
}

struct node_s *enqueue(struct node_s *head, monster_s *data, int pos, int roll)
{
    struct node_s *temp_node = calloc(1, sizeof(struct node_s));
    temp_node->data = data;
    temp_node->next = NULL;
    temp_node->position = pos;
    temp_node->roll = roll;

    if (head == NULL)
    {
        head = temp_node;
    }
    else
    {
        struct node_s *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp_node;
    }
    return head;
}

struct node_s *enqueue_to_end(struct node_s *head, struct node_s *new_node)
{
    struct node_s *temp = head;
    monster_s *temp_monster = temp->data;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;

    return head;
}


int add_to_order(monster_s *monsters_ptr, struct node_s **initiativeOrder, int numbersRead)
{
    int count = 0;
    char input[MAX_LEN];
    int selected_monster = 0;
    char *endptr;
    *initiativeOrder = (struct node_s *)malloc(MAX_MONSTERS * sizeof(struct node_s));

    for (int i = 0; i < MAX_MONSTERS; i++)
    {
        (*initiativeOrder)[i].data = NULL;
        (*initiativeOrder)[i].next = NULL;
        (*initiativeOrder)[i].position = 0;
        (*initiativeOrder)[i].roll = 0;
    }

    if (numbersRead > 10)
    {
        int current_page = 0;
        do
        {
            int start = current_page * 10;
            int end = 0;

            if ((start + 10) < numbersRead)
            {
                end = start + 10;
            }
            else
            {
                end = numbersRead;
            }
            if (start > 10)
            {
                for (int i = start; i < end; i++)
                {
                    printf("(%d) %s\n", i, monsters_ptr[i].name);
                }
            }
            else
            {
                for (int i = start; i < end; i++)
                {
                    if (i < 9)
                    {
                        printf("(%d) %s\n", i + 1, monsters_ptr[i].name);
                    }
                    else
                    {
                        printf("(%d) %s\n", i - 9, monsters_ptr[i].name);
                    }
                }
            }
            printf("(N) Next\n(P) Previous\n(C) Continue\n");
            scanf(" %s", input);

            if (input[0] == 'C')
            {
                break;
            }
            else if (input[0] == 'N')
            {
                current_page++;
            }
            else if (input[0] == 'P')
            {
                if (current_page > 0)
                {
                    current_page--;
                }
            }
            else
            {

                selected_monster = strtol(input, &endptr, 10);
                if (*endptr != '\0' || selected_monster < 0 || selected_monster > numbersRead)
                {
                    printf("Invalid Input\n");
                }
                else
                {
                    if (selected_monster == 0)
                    {
                        selected_monster = 10;
                    }
                    if (start != 0)
                    {
                        selected_monster = start + selected_monster;
                    }
                    int added = 0;
                    for (int i = 0; i < count; i++)
                    {
                        if ((*initiativeOrder)[i].data == &monsters_ptr[selected_monster - 1])
                        {
                            added = 1;
                            break;
                        }
                    }
                    if (added)
                    {
                        printf("%s has already been added.\n", monsters_ptr[selected_monster - 1].name);
                    }
                    else
                    {
                        (*initiativeOrder)[count].data = &monsters_ptr[selected_monster - 1];
                        (*initiativeOrder)[count].position = count + 1;
                        printf("%s added to order.\n", monsters_ptr[selected_monster - 1].name);
                        count++;
                    }
                }
            }
        } while (1);
    }
    else
    {
        do
        {
            for (int i = 0; i < numbersRead; i++)
            {
                printf("(%d) %s\n", i + 1, monsters_ptr[i].name);
            }

            printf("(C) Continue\n");
            scanf(" %s", input);

            if (input[0] == 'C')
            {
                break;
            }

            selected_monster = strtol(input, &endptr, 10);

            if (*endptr != '\0' || selected_monster <= 0 || selected_monster > numbersRead)
            {
                printf("Invalid Input\n");
            }
            else
            {
                int added = 0;
                for (int i = 0; i < count; i++)
                {
                    if ((*initiativeOrder)[i].data == &monsters_ptr[selected_monster - 1])
                    {
                        added = 1;
                        break;
                    }
                }
                if (added)
                {
                    printf("%s has already been added.\n", monsters_ptr[selected_monster - 1].name);
                }
                else
                {
                    (*initiativeOrder)[count].data = &monsters_ptr[selected_monster - 1];
                    printf("%s added to order.\n", monsters_ptr[selected_monster - 1].name);
                    count++;
                }
            }
        } while (1);
    }
    printf("\n");
    return count;
}

void display_order(struct node_s **initiativeOrder, int count)
{
    struct node_s *current = *initiativeOrder;

    while (current != NULL)
    {
        monster_s *temp_monster = (monster_s *)(current->data);
        printf("(%d) %s\n", current->position, temp_monster->name);
        current = current->next;
    }
    
    printf("\n");
}

void display_rolls(struct node_s **initiativeOrder, int count)
{
    for (int i = 0; i < count; i++)
    {
        if ((*initiativeOrder)[i].data != NULL)
        {
            monster_s *temp_monster = (monster_s *)(*initiativeOrder)[i].data;
            (*initiativeOrder)[i].roll = roll_dice();
            (*initiativeOrder)[i].position = i + 1;
            printf("%s rolled a %d.\n", (*temp_monster).name, (*initiativeOrder)[i].roll);
        }
        else
        {
            printf("(%d) (Invalid Data)\n", i + 1);
        }
    }
    printf("\n");
}

void peak(struct node_s **initiativeQueue, int count)
{
    if (*initiativeQueue == NULL)
    {
        printf("Initiative queue is empty.\n");
    }
    else
    {
        monster_s *temp_monster = (*initiativeQueue)->data;
        printf("%s is next.\n", temp_monster->name);
    }
}

struct node_s *dequeue(struct node_s **initiativeQueue, monster_s *data, int pos, int roll)
{
    struct node_s *temp_node = calloc(1, sizeof(struct node_s));
    temp_node->data = data;
    temp_node->next = NULL;
    temp_node->position = pos;
    temp_node->roll = roll;
    printf("%s's Turn!\n", (*data).name);
    *initiativeQueue = (*initiativeQueue)->next;
    return temp_node;
}

void parse_monster(monster_s *monster, char *csv_line)
{
    char *token = strtok(csv_line, ",");

    int attr = 0;

    while (token)
    {
        switch (attr)
        {
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

int load_monster_csv(monster_s **monsters_ptr, FILE *fp)
{
    char buffer[MAX_LEN] = {0};
    int num_read = 0;

    while (fgets(buffer, MAX_LEN, fp))
    {
        trim(buffer);
        monster_s *temp_monster = (monster_s *)malloc(sizeof(monster_s));
        parse_monster(temp_monster, buffer);

        *monsters_ptr = (monster_s *)realloc(*monsters_ptr, sizeof(monster_s) * (num_read + 1));
        // Reminder not to forget the parentheses for (*monster_ptr)
        // If forgotten you will get the error Segmentation fault
        (*monsters_ptr)[num_read] = *temp_monster;
        free(temp_monster);

        num_read++;
    }

    return num_read;
}