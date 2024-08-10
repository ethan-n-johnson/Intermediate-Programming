#include <stdio.h>
#include <string.h>

#define MaxMonsterNumber 128

typedef struct {
    char name[32];
    char type[16];
    int hp;
    int level;
} monster_t;

monster_t LoadMonster(FILE *);

void SaveMonster(monster_t *, FILE *);

void PrintMonster(monster_t *);

void PrintMonsters(monster_t *monst, int monsterAmount);

monster_t CreateMonster();

