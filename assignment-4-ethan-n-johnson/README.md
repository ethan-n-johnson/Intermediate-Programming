# CSE 1320 Assignment 4
Covers queues and linked lists.

For our turn-based RPG, combat order is managed by having all combatants roll to consider their position in the initiative order. Those with a higher roll will go before those with a lower roll. In this assignment, you will implement this functionality using a linked list-based queue.

Create a program with the following features.

## Add Monster

Using the `monster_s` struct from assignment 3, load the monsters from the CSV file into an array. Create a second dynamic array of pointers to `monster_s` that will be used to manage the initiative order.

Present the user with a list of monsters and allow them to select one to add to the initiative order. They should be able to add as many monsters as they want. If they select a monster that is already in the initiative order, print an error message and ask them to select another monster. Include an option to continue when they are done adding monsters.

**Example**
```
(1) Goblin
(2) Acolyte
(3) Adult Black Dragon
(4) Gold Dragon Wyrmling
(5) Bearded Devil
(6) Rakshasa
(C) Continue
```

**BONUS**

If there are more than 10 monsters, print the monsters in groups of 10. Include two prompts to allow the user to select between groups of monsters.

**Example**
```
(1) Goblin
(2) Acolyte
(3) Adult Black Dragon
(4) Gold Dragon Wyrmling
(5) Bearded Devil
(6) Rakshasa
(7) Adult Green Dragon
(8) Beholder
(9) Lich
(0) Cult Fanatic
(N) Next
(P) Previous
(C) Continue
```

Once the user has selected all of the monsters they want to add, print the current list.

## Roll Initiative

Use the list of monsters added from the first option to roll initiative for each monster. This will involve using the `rand` function to generate a random number between 1 and 20 for each monster. Once every selected creature in the array has rolled, you can use `qsort` to sort the array based on the roll. To simplify this with the next step of adding them to a linked-list based queue, you could create a `struct` for your linked list node that includes a `roll` value and a `position` value:

```c
struct node_s {
    void *data;   // Pointer to the monster_s struct
    int roll;     // The roll value
    int position; // The original position in the array (after sorting)
    struct node_s *next;
};
```

Create a linked-list queue based on the rolls of each monster. The ordering is based on their roll. If two or more creatures roll the same value, you can choose the relative ordering. If you have used the `struct` above, your sorted array is actually an array of the linked list nodes. Building the queue at this point will be as simple as iterating through the array and adding each node to the queue.

If the user runs this command after already calculating initiative, warn the user that they are about to re-roll. If they confirm, roll initiative as normal. If they decline, go back to the main menu.

**Example**
```
1. Add Monsters
2. Roll Initiative
3. Next Turn
4. View Current Order
> 2
Goblin rolled a 20.
Adult Black Dragon rolled an 18.
Cult Fanatic rolled an 18.
Lich rolled a 17.
Beholder rolled a 12.
Rakshasa rolled a 9.
Bearded Devil rolled a 2.
```

## Next Turn

Option 3 will process a turn in the current ordering. This involves dequeuing the front of the queue and printing a message indicating who is going. **Since the monsters will go again in the next round, you should immediately add them back to the queue after printing their turn.** Additionally, write a function named `peek` that looks at the next monster in the queue, **but does not remove them**. Use that to notify who is up next.

**Example**
```
1. Add Monsters
2. Roll Initiative
3. Next Turn
4. View Current Order
> 3
Goblin's Turn!
Cult Fanatic is next.
```

## View Current Order

Print the current ordering with the current monster at the top of the output. The original ordering number should be printed next to the monster's name.

**Example**
```
1. Add Monsters
2. Roll Initiative
3. Next Turn
4. View Current Order
> 4
3. Adult Black Dragon
4. Lich
5. Beholder
6. Rakshasa
7. Bearded Devil
1. Goblin
2. Cult Fanatic
```

## Requirements
- Each monster should be represented by a `struct` that is dynamically allocated.
- All logic for the main program should be in `monster_initiative.c`.
- Implement the menu as requested. It does not have to look exactly like the example run.
- Implement the 4 sub-items as defined above.
- All queue functions should be declared and defined in separate files. For example, they will be in `queue_utils.(c|h)`.
- Free all memory before exiting the program.