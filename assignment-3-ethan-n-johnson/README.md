# CSE 1320 Assignment 3

Covers dynamic memory allocation.

## Problem 1

**Part 1**

Create a file named `problem1.c` with a comparison function `int compare_int(const void *elem1, const void *elem2);`
The comparison function, when used with `qsort`, should sort integers in ascending order with a slight twist: all even numbers must come before any odd number.

**Part 2**

In `main`, prompt the user to enter an integer representing the size of an array of integers. Allocate memory for the array and have the user enter the values for the array. Once the values are read, use `qsort` to sort the data using the comparison function you defined in part 1.

Print the values of the array before AND after the call to `qsort` in the format shown in the example run.

```
Enter the size of the array: 10
Enter 10 values: 10 2 3 8 5 9 1 4 7 6
10 2 3 8 5 9 1 4 7 6
2 4 6 8 10 1 3 5 7 9
```

## Problem 2

Create a new `monster_s` `struct` which contains the attributes of a monster.

```
typedef struct {
    char name[MAX_STR];
    char type[MAX_STR];
    int hp;
    int ac;
    int str;
    int dex;
    int con;
} monster_s;
```

Add this to `utils.h`.

**Part 1**

Modify the parameter list for `main` in `problem2.c` so that it accepts command line arguments. The program should accept a single argument: a file name for a CSV file. Your program should verify that the user entered the required number of command line arguments. Load the file with the given file name and verify that the file is open.

**Part 2**

Complete `load_monster_csv` in `utils.c` which accepts the following arguments:
- `monster_s **monsters` - a pointer-to-`monster_s`, this will be your array.
- `FILE *fp` - a file pointer referencing an open file of CSV data.

The function returns an `int` representing the number of monsters read from the file. The code in this function is only partially complete. Follow the comments to complete the function.

**Part 3**

Verify that your function works by printing out the monsters in the format used from assignment 1.

`"%s (%s), %d HP, %d AC, %d STR, %d DEX, %d CON\n"`

## Problem 3

Create a function `print_monsters` in `utils.c` which takes as input a pointer-to-`monster_s` and an `int` representing the number of monsters. Print the monster's data to `stdout` following the example run below. Don't forget to declare the function in `utils.h`. The function should display the data as seen below.

```
| NAME                 | TYPE     | HP  | AC | STR | DEX | CON |
| -------------------- | -------- | --- | -- | --- | --- | --- |
| Acolyte              | HUMANOID | 9   | 10 | 5   | 5   | 5   |
| Adult Black Dragon   | DRAGON   | 195 | 19 | 11  | 7   | 10  |
| Goblin               | HUMANOID | 7   | 15 | 4   | 7   | 5   |
| Gold Dragon Wyrmling | DRAGON   | 60  | 17 | 9   | 7   | 8   |
| Bearded Devil        | FIEND    | 52  | 13 | 8   | 7   | 7   |
| Rakshasa             | FIEND    | 110 | 16 | 7   | 8   | 9   |
```

The formatting is important here. The hyphens between the name and stats should be the same length as the string above it.

Write a program in a file named `problem4.c` that accepts a file name from the command line and attempts to open it. If it is successful, display the contents of each monster using `print_monster`.

**HINT:** You will need to loop through your data first and get the maximum length for each attribute. This will be simple for strings by using `strlen`. The `int` data will require a different approach. Math functions like `log10` will be useful here. Use sub-specifiers to control the length.

## Problem 4

Write a program that sorts monsters based on each of their properties, depending on the user's choice.

**Part 1**

Use `problem4.c` as a starting point to implement your program. Follow the `TODO`s so that the program accepts a file name from the command line and attempts to open it. If opened, parse the CSV data using `load_monster_csv`. You can assume that the user will give a valid CSV file (if the file exists). Your program should exit if the file does not exist.

**Part 2**

Implement 4 comparison functions that will sort the data that is loaded. For each one, call the sort and print the sorted data using `print_monsters`. These are organized in the `switch` statement in `problem5.c`. The comparisons should be implemented as follows:
1. Sort by name alphabetically.
2. Sort by HP from greatest to lowest (at the bottom).
3. Sort by AC from greatest to lowest (at the bottom).
4. Sort by stats from greatest to lowest (at the bottom). This is done by summing up `str`, `dex`, and `con` and using that value in your comparisons.

**When exiting the program, make sure you free all memory that was allocated!**