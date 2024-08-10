# CSE 1320 Assignment 5

Covers Binary Search Trees

## Problem 1

For the first problem, develop a binary search tree library that implements the following functions:
- Minimum: returns the minimum value in the tree
- Maximum: returns the maximum value in the tree
- Insert: inserts a new value into the tree
- Search: searches for a value in the tree
- Print: prints the tree in order
- Free: frees the memory used by the tree

All of these function should be declared in a header file and defined in a corresponding C file. The tree should be able to hold any type of data. This will also require that the tree node has a member for a key so that it can be compared to other nodes. A pointer to a comparison function is required to compare the data for the required operations.

To verify that all operations work as required, create a BST using integer data and perform each operation on the tree. The tree should be created using the following data: 5, 3, 7, 2, 4, 6, 8, 1, 9, 0. The tree should be printed after each operation is performed. Be sure to print a clear message of each operation before printing the tree. An example of the output is shown below.

**Example Run**
```
Insert 5
5
Insert 3
3 5
Insert 7
3 5 7
Insert 2
2 3 5 7
Insert 4
2 3 4 5 7
Insert 6
2 3 4 5 6 7
Insert 8
2 3 4 5 6 7 8
Insert 1
1 2 3 4 5 6 7 8
Insert 9
1 2 3 4 5 6 7 8 9
Insert 0
0 1 2 3 4 5 6 7 8 9
Minimum: 0
Maximum: 9
Search for 5: 5
Search for 10: Not found
Freeing tree
```

**Tasks**
1. Create a node structure for a binary search tree that can store any type of data.
2. Create functions that support the following BST operations:
    - Minimum
    - Maximum
    - Insert
    - Search
    - Print
    - Free
3. Test each of the operations by creating a BST and performing each operation on it.

## Problem 2

Implement the functions required to delete a node from a binary search tree. A reference to the code and notes discussed in class is available (here)[https://ajdillhoff.github.io/notes/binary_search_trees/]. The functions that need to be implemented are:
- transplant: replaces one subtree as a child of its parent with another subtree
- delete: deletes a node from the tree

Add these functions and their declarations in the BST library created in problem 1. To test the functions, create a BST using the following data: 5, 3, 7, 2, 4, 6, 8, 1, 9, 0. Print the tree before deleting any nodes. Be sure to print a clear message of each operation before printing the tree. Delete nodes 3, 5, and 7 from the tree. Print the tree after each deletion. An example of the output is shown below.

**Example Run**
```
Delete 3
0 1 2 4 5 6 7 8 9
Delete 5
0 1 2 4 6 7 8 9
Delete 7
0 1 2 4 6 8 9
```

**Tasks**
1. Create the `transplant` function.
2. Create the `delete` function.
3. Test the `delete` function.

## Problem 3

This assignment includes a CSV file of vehicle data that contains the following fields:
- make
- model
- price

The data in the file is not sorted in any way. The goal of this problem is to read the data from the file and organize it into a binary search tree. The tree should be organized by price. You will need to implement a `struct` for the vehicles as well as a comparison function to compare each object by price. Verify that this works by printing the tree after all of the data has been read from the file.

**Tasks**
1. Organize the given file of cars so that the tree is balanced after all are inserted.
3. What observations can you make about the way the values were organized? Put your answer in a text file named `observations.txt`.