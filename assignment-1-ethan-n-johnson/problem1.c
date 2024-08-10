#include <stdio.h>

int main() {
    int input = 0;

    scanf("%d", &input);

    if (input > 5 && input < 15) {
        printf("Case 1\n");
    } else if (input == 20) {
        printf("Case 2\n");
    } else {
        printf("Case 3\n");
    }

    return 0;
}