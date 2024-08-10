#include "bt_utils.h"

int main()
{
    FILE *fp = fopen("data/cars.csv", "r");
    if (fp == NULL)
    {
        printf("Invalid Filename or path\n");
        return 0;
    }

    car_s *car_ptr = NULL;
    int numRead = load_car_csv(&car_ptr, fp);

    BTNode *car_tree = NULL;

    for (int i = 0; i < numRead; i++)
    {
        // Insert the car into the tree
        insert(&car_tree, &car_ptr[i], sizeof(car_s), compareCar);
        printf("Insert %s %s\n", car_ptr[i].make, car_ptr[i].model);
        printf("\n");
    }

    print_car_tree(car_tree);

    fclose(fp);
    free(car_ptr);
    release_tree(car_tree);

    return 0;
}
