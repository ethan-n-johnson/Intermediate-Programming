#include "monster.h"


monster_t LoadMonster(FILE *monsterData)
{
    monster_t monster = { 0 };
    fread(&monster, sizeof(monster_t), 1, monsterData);
    return monster;
}


void SaveMonster(monster_t *monster, FILE *monsterData)
{
    fwrite(monster, sizeof(monster_t), 1, monsterData);
}

void PrintMonster(monster_t *monster)
{
    printf("Monster Name: %s\n", monster->name);
    printf("Monster Type: %s\n", monster->type);
    printf("Monster HP: %d\n", monster->hp);
    printf("Monster Level: %d\n", monster->level);
}

void PrintMonsters(monster_t *monster, int monsterNumber)
{
    printf("    Name    Type    HP  Level\n");
    printf("    -------------------------\n");
    for (int i = 0; i < monsterNumber; i++)
    {
        printf("    %-8s%-8s%-4d%-6d\n", monster[i].name, monster[i].type, monster[i].hp, monster[i].level);

    }    
}

monster_t CreateMonster()
{
    monster_t monster = { 0 };

    printf("Enter Monster Name: ");
    fgets(monster.name, 32, stdin);
    monster.name[strlen(monster.name) - 1] = '\0';

    printf("Enter Monster Type: ");
    fgets(monster.type, 16, stdin);
    monster.type[strlen(monster.type) - 1] = '\0';

    printf("Enter Monster HP: ");
    scanf("%d", &monster.hp);

    printf("Enter Monster Level: ");
    scanf("%d", &monster.level);

    return monster;
}