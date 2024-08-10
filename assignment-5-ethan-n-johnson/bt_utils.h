#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTNode BTNode;
struct BTNode
{
    void *data;
    BTNode *left;
    BTNode *right;
    BTNode *parent;
};

typedef struct car_s car_s;
struct car_s
{
    char make[128];
    char model[128];
    int price;
};

BTNode *add_btnode(void *, size_t);

int compareInt(const void *, const void *);

void insert(BTNode **, void *, size_t, int (*compare)(const void *, const void *));

BTNode *search(BTNode *, int);

BTNode *tree_max(BTNode *);

BTNode *tree_min(BTNode *);

void print_tree(BTNode *);

BTNode *tree_successor(BTNode *);

BTNode *tree_predecessor(BTNode *);

void *tree_delete(BTNode **, BTNode *);

void release_tree(BTNode *);

int load_car_csv(car_s **, FILE *);

void print_car_tree(BTNode *);

int compareCar(const void *, const void *);
