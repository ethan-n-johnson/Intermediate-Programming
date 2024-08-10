#include "bt_utils.h"

BTNode *add_btnode(void *data, size_t data_size)
{
    int data_type = 0;
    BTNode *node = malloc(sizeof(BTNode));
    node->data = malloc(data_size);
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    if (data_size == sizeof(car_s))
    {
        data_type = 1;
    }

    if (data_type == 0)
    {
        // Integer data
        *(int *)(node->data) = *(int *)data;
    }
    else if (data_type == 1)
    {
        // Car data
        memcpy(node->data, data, data_size);
    }

    return node;
}

int compareCar(const void *a, const void *b)
{
    int price_a = ((car_s *)a)->price;
    int price_b = ((car_s *)b)->price;

    return price_a - price_b;
}

int compareInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void insert(BTNode **root, void *data, size_t data_size, int (*compare)(const void *, const void *))
{
    BTNode *newNode = add_btnode(data, data_size);
    BTNode *current = *root;
    BTNode *parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (compare(data, current->data) >= 0)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    newNode->parent = parent;

    if (parent == NULL)
    {
        *root = newNode;
    }
    else if (compare(data, parent->data) >= 0)
    {
        parent->right = newNode;
    }
    else
    {
        parent->left = newNode;
    }
}

BTNode *search(BTNode *node, int val)
{
    if (node == NULL || val == *(int *)(node->data))
    {
        return node;
    }
    else if (val > *(int *)(node->data))
    {
        return search(node->right, val);
    }
    else
    {
        return search(node->left, val);
    }
}

BTNode *tree_max(BTNode *node)
{
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

BTNode *tree_min(BTNode *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

void print_tree(BTNode *node)
{
    if (node != NULL)
    {
        print_tree(node->left);
        printf("%d ", *(int *)node->data);
        print_tree(node->right);
    }
}

void print_car_tree(BTNode *node)
{
    if (node != NULL)
    {
        car_s *car = node->data;

        print_car_tree(node->left);
        printf("Make: %s Model: %s Price: %d\n", car->make, car->model, car->price);
        print_car_tree(node->right);
    }
}

void transplant(BTNode **root, BTNode *node1, BTNode *node2)
{
    if (node1->parent == NULL)
    {
        *root = node2;
    }
    else if (node1 == node1->parent->left)
    {
        node1->parent->left = node2;
    }
    else
    {
        node1->parent->right = node2;
    }

    if (node2 != NULL)
    {
        node2->parent = node1->parent;
    }
}

void *tree_delete(BTNode **root, BTNode *node_to_delete)
{
    if (node_to_delete->left == NULL)
    {
        transplant(root, node_to_delete, node_to_delete->right);
    }
    else if (node_to_delete->right == NULL)
    {
        transplant(root, node_to_delete, node_to_delete->left);
    }
    else
    {
        BTNode *temp_node = tree_min(node_to_delete->right);
        if (temp_node->parent != node_to_delete)
        {
            transplant(root, temp_node, temp_node->right);
            temp_node->right = node_to_delete->right;
            temp_node->right->parent = temp_node;
        }
        transplant(root, node_to_delete, temp_node);
        temp_node->left = node_to_delete->left;
        temp_node->left->parent = temp_node;
    }
    free(node_to_delete->data);
    free(node_to_delete);
}

void release_tree(BTNode *node)
{
    if (node != NULL)
    {
        release_tree(node->left);
        release_tree(node->right);
        free(node->data);
        free(node);
    }
}

void trim(char *str)
{
    int l = strlen(str);
    if (str[l - 1] == '\n')
    {
        str[l - 1] = 0;
    }
}

void parse_car(car_s *car, char *csv_line)
{
    char *token = strtok(csv_line, ",");

    int attr = 0;

    while (token)
    {
        switch (attr)
        {
        case 0:
            strcpy(car->make, token);
            break;
        case 1:
            strcpy(car->model, token);
            break;
        case 2:
            car->price = atoi(token);
            break;
        }
        attr++;
        token = strtok(NULL, ",");
    }
}

int load_car_csv(car_s **cars_ptr, FILE *fp)
{
    char buffer[128] = {0};
    int num_read = 0;

    while (fgets(buffer, 128, fp))
    {
        trim(buffer);
        car_s *temp_car = (car_s *)malloc(sizeof(car_s));
        parse_car(temp_car, buffer);

        *cars_ptr = (car_s *)realloc(*cars_ptr, sizeof(car_s) * (num_read + 1));
        (*cars_ptr)[num_read] = *temp_car;
        free(temp_car);

        num_read++;
    }

    return num_read;
}