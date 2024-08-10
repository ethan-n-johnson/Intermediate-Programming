#include "monster.h"

int main()
{
    int monsterAmount = 0;
    FILE *monsterData = fopen("monsterData.dat", "a+");

    monster_t monsters[128];

    while (monsterAmount < MaxMonsterNumber)
    {    
        monster_t monster = LoadMonster(monsterData);       
        if (feof(monsterData))
        {
            break;
        }
        if (monster.name != "")
        {
            monsters[monsterAmount++] = monster;
        }
        
    }
    
    fclose(monsterData);

    PrintMonsters(monsters, monsterAmount);

    return 0;
}
