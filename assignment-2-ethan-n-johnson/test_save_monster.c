#include "monster.h"


int main()
{
    FILE *monsterData = fopen("monsterData.dat", "a+");

    if (monsterData == NULL)
    {
        printf("File did not open.");
    }   
    
    monster_t testMonster = CreateMonster();
    SaveMonster(&testMonster, monsterData);

    fclose(monsterData);

    return 0;
}
