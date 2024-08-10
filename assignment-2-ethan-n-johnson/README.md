# CSE 1320 Assignment 2

This assignment covers pointers, `struct`s, and advanced file I/O.

## (25%) Problem 1

Create a `monster` `struct` that contains the following fields:
- `name` (a `char` array of size 32)
- `type` (a `char` array of size 16)
- `hp` (an `int`)
- `level` (an `int`)

This `struct` should be defined in a header file called `monster.h`. Make sure you include a header guard.

In `monster.c`, implement a function named `create_monster` that prompts the user to enter the values for each field of the `struct monster`. The function should return a `struct monster` object.

Additionally, create a function called `print_monster` that takes a `struct monster` as a parameter and prints the data in the following format:

```
    Name: name
    Type: type
    HP: hp
    Level: level
```

Include the declarations for these functions in `monster.h`.

Create a third file named `test_add_monster.c` that includes `monster.h` and tests your `create_monster` and `print_monster` function.

### Grading Criteria

- (5 points) Create a `struct monster` with the given fields.
- (5 points) Create `create_monster` to prompt the user for the values of the `struct monster` fields.
- (5 points) Create `print_monster` to display the data. The data should be formatted similar to the example above.
- (5 points) Include the declaration for `create_monster` and `print_monster` in `monster.h`.
- (5 points) Create `test_add_monster.c` to test your `create_monster` and `print_monster` functions.

## (25%) Problem 2

Now that the `monster` is defined and we can add new entries in memory, we need to be able to save the data to a file. Create a function named `save_monster` that takes a `struct monster` and a `FILE` pointer as parameters. The function should write the `monster` as binary data.

You can assume that the given `FILE` pointer is already open for writing.

Define this function in `monster.c` and include the declaration in `monster.h`.

Create a third file named `test_save_monster.c` that includes `monster.h` and tests your `save_monster` function by creating a `monster` with `create_monster` and saving it to a file. Make sure to open the file in append mode so that new entries will save to the end of the file.

### Grading Criteria

- (15 points) Create `save_monster` to write the `monster` as binary data.
- (5 points) Include the declaration for `save_monster` in `monster.h`.
- (5 points) Create `test_save_monster.c` to test your `save_monster` function.

## (25%) Problem 3

The next step is to load the data from the file into memory. Create a function named `load_monster` that takes a `FILE` pointer as a parameter. The function should read the next line from the file and return a `struct monster` object. You can assume that the given `FILE` pointer is already open for reading.

Since this data is stored in a binary file, you will need to use the `fread` function to load the data. Since the data was written in the same order that it was read, you can use the same `fread` calls to load the data into a `struct monster` array. You can assume that the file contains less than 128 `monster` objects.

We will also need a way to display the data after loading. Create a function named `print_monsters` that takes an array of `struct monster` objects and the number of elements in the array as parameters. It should print a table of the data in the following format:

```
    Name    Type    HP  Level
    -------------------------
    name1   type1   hp1 level1
    name2   type2   hp2 level2
    ...
```

Create a file named `test_load_monsters.c` that includes `monster.h` and tests your `load_monster` and `print_monsters` functions by loading the data from the file and printing it to the screen.

### Grading Criteria

- (10 points) `load_monster` should return a `struct monster` object.
- (5 points) Create `print_monsters` to display the data. The table should be formatted similar to the example above.
- (5 points) Include the declaration for `load_monster` and `print_monsters` in `monster.h`.
- (5 points) Create `test_load_monsters.c` to test your `load_monster` and `print_monsters` functions.

## (15%) Problem 4

The included code examples use standard array indexing notation. Convert the indexing notation to an equivalent program using pointer arithmetic. Array initializations do not need to be converted since they define the array memory.
- `matrix_average.c`
- `array_utils.c`
- `array_tests.c`
- `selection_sort.c`

For `array_utils.c` and `array_tests.c`, you can verify that it is working by compiling both of the files together. For example, you can compile `array_utils.c` and `array_tests.c` with the following command:

    gcc -o array_tests array_utils.c array_tests.c

### Grading Criteria

- (5 points) Convert `matrix_average.c` to use pointer arithmetic
- (5 points) Convert `array_utils.c` to use pointer arithmetic
- (5 points) Convert `selection_sort.c` to use pointer arithmetic

## (10%) Problem 5

Add code in `matrix_average.c` to iterate through the matrix using pointer arithmetic. You only need a single pointer to do this. First, assign the address of the very first element of the matrix to a `double *` variable. Then, loop through with a single `for` loop to print the contents out.

### Grading Criteria

- (5 points) Create a pointer to the first element of the matrix
- (5 points) Loop through the matrix using pointer arithmetic