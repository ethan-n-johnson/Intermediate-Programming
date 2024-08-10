#include "bt_utils.h"

int main()
{
    int data[] = {5, 3, 7, 2, 4, 6, 8, 1, 9, 0};
    int data_size = sizeof(data) / sizeof(data[0]);

    BTNode *tree = NULL;

    for (int i = 0; i < data_size; i++)
    {
        insert(&tree, &data[i], data_size, compareInt);
        printf("Insert %d\n", data[i]);
        print_tree(tree);
        printf("\n");
    }
    printf("Minimum: %d\nMaximum: %d\n", *(int *)tree_min(tree)->data, *(int *)tree_max(tree)->data);

    printf("Search for 5: ");
    BTNode *s1 = search(tree, 5);
    if (s1)
    {
        printf("Found 5\n");
    }
    else
    {
        printf("Not found\n");
    }

    printf("Search for 10: ");
    BTNode *s2 = search(tree, 10);
    if (s2)
    {
        printf("Found 10\n");
    }
    else
    {
        printf("Not found\n");
    }
    
    for (int i = 0; i < 3; i++)
    {
        int deleteValue[] = {3, 5, 7};
        BTNode *node_to_delete = search(tree, deleteValue[i]);
        if (node_to_delete)
        {
            tree_delete(&tree, node_to_delete);
            printf("Delete %d\n", deleteValue[i]);
            print_tree(tree);
            printf("\n");
        }
    }
    release_tree(tree);
    return 0;
}
