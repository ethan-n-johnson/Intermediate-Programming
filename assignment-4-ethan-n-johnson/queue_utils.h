#ifndef UTILS_H_
#define UTILS_H_

#define MAX_MONSTERS 32
#define MAX_LEN 128

#define FILTER_NAME 1
#define FILTER_HP 2
#define FILTER_AC 3
#define FILTER_STATS 4
#define EXIT_CHOICE 5

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

struct node_s {
    void *data;   // Pointer to the monster_s struct
    int roll;     // The roll value
    int position; // The original position in the array (after sorting)
    struct node_s *next;
};

int load_monster_csv(monster_s **, FILE *);

int add_to_order(monster_s *, struct node_s **,  int);

void display_order(struct node_s **, int);

void display_rolls(struct node_s **, int);

void peak(struct node_s **, int);

void parse_monster(monster_s *, char *);

struct node_s *enqueue(struct node_s *, monster_s *, int, int);

// int dequeue(struct node_s **, int);
struct node_s *dequeue(struct node_s **, monster_s *, int, int);

struct node_s *enqueue_to_end(struct node_s *, struct node_s *);

int roll_dice();

#endif
