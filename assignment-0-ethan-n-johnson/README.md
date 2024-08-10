# CSE 1320 Assignment 0

To acclimate you to how assignments will be completed and submitted, we will walk through a tutorial on writing code and tracking it with GitHub.

First, it is highly recommended that you at least have a high level understanding of `git`. If you are unfamiliar with `git`, please read the [Git Tutorial](https://git-scm.com/docs/gittutorial) and [Git Book](https://git-scm.com/book/en/v2). At a bare minimum, read the first 3 chapters of the Git Book.

We will start with some data and a goal: we want to convert address data stored as CSV into a readable format and print it to `stdout`.
The data that we will be using is already part of this repository.

# Reading CSV data

Our first task is to write a program that can read the CSV data from the file.
Create a file named `read_csv.c` and write code which prompts the user to open a file and prints each line of the text file.
It should output something similar to what is seen below.

```
Enter a filename: data.csv
Engineering Research Building,500 UTA Blvd,Arlington,TX,76010
UTA Bookstore,400 Spaniolo Dr,Arlington,TX,76010
Nedderman Hall,416 Yates St,Arlington,TX,76010
E.H. Hereford University Center,300 W 1st St,Arlington,TX,76010
Science and Engineering Innovation and Research Building,655 W Mitchell St,Arlington,TX,76010
College Park Center,600 S Center St,Arlington,TX,76019
Kalpana Chawla Hall,901 S Oak St,Arlington,TX,76010
Clay Gould Ballpark,1301 S Fielder Rd,Arlington,TX,76013
```

Once you finish and your output looks similar to example above, it is time to add the file to the repository.
To see the current status of the local repository, type `git status` in the terminal window.
You should see output similar to the following.

```
On branch main
Your branch is up to date with 'origin/main'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)
	read_csv.c

nothing added to commit but untracked files present (use "git add" to track)
```

Your local repository tracks that a new file exists that is not part of the local repo.
To add this file, use the command `git add read_csv.c`.

Running `git status` again shows that the file has been added and is staged to be committed to the repository.

```
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	new file:   read_csv.c
```

To commit this file to the local repository, use command `git commit`.
By default, this will open up a local version of `vi`.
If you have never used `vi` before, don't panic.
Press `i` to enter `INSERT` mode. This will allow you to enter a message describing your commit.
Since this is our first code file, add the message "first code file."
To save and exit the editor, use command `SHIFT+ZZ`.

Using `git status` again shows that the local repository is one commit ahead of the remote repository.

```
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)
```

As mentioned in the output, we can push our local repository changes to the remote repository by using `git push`.
This is the last step required to make sure our code is up-to-date on the remote repository.
