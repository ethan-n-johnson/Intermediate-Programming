#ifndef UTILS_H_
#define UTILS_H_

#define MAX_MONSTERS 32
#define MAX_LEN 128

#define FILTER_NAME 1
#define FILTER_HP 2
#define FILTER_AC 3
#define FILTER_STATS 4
#define EXIT_CHOICE 5

void swap_int(int, int);
void trim(char *);

typedef struct {
    char name[MAX_LEN];
    char type[MAX_LEN];
    int hp;
    int ac;
    int str;
    int dex;
    int con;
} monster_s;

int load_monster_csv(monster_s **, FILE *);

void print_monsters(monster_s *, int);

void print_header(int, int, int, int, int, int, int);


#endif
