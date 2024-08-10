# CSE1320 Assignment 1
This assignment reviews concepts from CSE 1310 or equivalent.

## (10%) Problem 1
The code in `problem1.c` compiles correctly but includes some common mistakes. Fix ALL possible issues so that it runs properly.
*Hint: there are 3 mistakes and it should be possible to get to each case depending on input.*

After fixing it, create a new text file called `problem1.txt` and include output of running the program so that all 3 cases are shown. Add this file to your repository and commit it.

## (20%) Problem 2

Create a program that reads two strings of length 5 from the user. The user *must* enter a 5 letter word for both or your program should warn them and exit. Assuming the user enters valid input, your program will compare the two strings based on the following conditions:
1. If the character is the same in both strings, print a `*`.
2. If the character is present in the first string, but not in the matching position in the second string, print a `^`.
3. If the character in the first string is not present in the second string, print nothing.

Your program should include a function which accepts the following parameters:
- `char[]` - The string to compare against (this will be the second string as input earlier).
- `char` - The character to compare.
- `int` - The position of the character in the first string.

The function should return a `char` dependent on the conditions above.

**Save your code as `problem2.c`.

**Requirements**
- (5 points) Create a function that accepts the parameters listed above.
- (2.5 points) Read in two strings of length 5 from the user using `fgets`.
- (2.5 points) Remove the newline character captured by the input.
- (10 points) Compare the two strings and print the output as described above.

Your output should look similar to the example run below.

### Example Runs
**Run 1**
```
Enter the first string: hello
Enter the second string: world
hello
  ^*^
```

**Run 2**
```
Enter the first string: class
Enter the second string: blank
class
 ** 
```

## (20%) Problem 3

In this problem, you will use nested loops to control a sub-menu within a main menu.
Start by presenting the user with a main menu of the following options:

```
1. Attack
2. Defend
3. Use Item
4. Exit
```

If the user selects `1. Attack`, they will be presented with the following sub-menu:

```
1. Weapon Attack
2. Magic Attack
3. Back
```

Selecting `1` or `2` in this menu should print "Success!" and return the user to the main menu.
Selecting `3` will simply return them to the main menu.

If the user selects `3. Use Item`, they will be presented with the following sub-menu:

```
1. Potion
2. Elixir
3. Back
```

As with the other sub-menu, selecting `1` or `2` should print "Success!" and return the user to the main menu.
Selecting `3` will simply return them to the main menu.

**Requirements**
- Implement the program as described above.
- Save your code as `combat_menu.c`.

### Example Runs

**Run 1**

```
1. Attack
2. Defend
3. Use Item
4. Exit
> 1
1. Weapon Attack
2. Magic Attack
3. Back
> 1
Success!
1. Attack
2. Defend
3. Use Item
4. Exit
> 4
```

**Run 2**

```
1. Attack
2. Defend
3. Use Item
4. Exit
> 2
Success!
1. Attack
2. Defend
3. Use Item
4. Exit
> 4
```

**Run 3**

```
1. Attack
2. Defend
3. Use Item
4. Exit
> 3
1. Potion
2. Elixir
3. Back
> 3
1. Attack
2. Defend
3. Use Item
4. Exit
> 4
```

## (20%) Problem 4

Write a program that reads in 4 strings and sorts them based on their length.
You can use the code from selection sort to help solve this problem.

**Requirements**

- (5 points) The strings should be read into a 2D array of `char` with size $4 \times 32$ using `fgets`.
- (5 points) Remove the newline character captured by the input.
- (10 points) Print the sorted strings.
- Save your code as `read_strings.c`.

**Example Run**

```
String 1: Naomi
String 2: Alex
String 3: Holden
String 4: Bo
1. Holden
2. Naomi
3. Alex
4. Bo
```

## (30%) Problem 5

Create a program that validates a CSV file based on a header line at the top of the file. The header line will represent the attribute names and the number of attributes. For example, if the header line is `ID,NAME,PRICE,QUANTITY`, you know that there are 4 attributes. All subsequent lines of data must include 4 attributes to be considered valid.

**Requirements**

- (2.5 points) Prompt the user to enter a file name.
- (2.5 points) Check your file pointer to make sure the file exists.
- (5 points) If the file passes validation, print the name of the file and a message indicating that it is valid.
- (10 points) If the file does not pass validation, print each line that is not valid.
- (10 points) The validation code should be implemented as a separate function.
- Include a corresponding header file that contains any `#include` statements, `#define` statements, and function **declarations**.
- Save your code as `csv_check.c` and `csv_check.h`.