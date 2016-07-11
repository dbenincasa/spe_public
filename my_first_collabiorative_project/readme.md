# My First Collaborative Project

## The Template Text

```
This is an extremely interesting text.
This is the result to he work of AStudent 
and BStudent.

Meanwhile BStudent calls up AStudent. BStudent 
tells him he will improve this part of the text, 
he will do this on a different branch so that he 
will not interfere with AStudent’s work.
*PLACE HOLDER*

AStudent suddenly realises that there is a 
very nice text, that copes very nicely with 
what BStudent is about to write. This is why 
he is creating a new branch and writing 
his text here. 
*PLACE HOLDER*

Before merging the two branches, AStudent
writes a very nice conclusion for the document
and commits it.
*PLACE HOLDER*
```

## Collaborative Development


This is meant to be a simple collaborative project between `AStudent` and `BStudent`.

In this example case `AStudent=nicolacavallini`, `BStudent=`

`AStudent` creates a directory:

```
$ mkdir my_first_collabiorative_project
```

Stats a new file called `very_interesting_text.txt` and edits the template text above.

Now `AStudent` starts version controlling this repository using git:

```
$ git init
Initialized empty Git repository in /Users/nicola/mhpc/my_first_collaborative_project/.git/
```

`AStudent` asks git what's the status of the repository he created:

```
$ git status
On branch master

Initial commit

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	very_interesting_text.txt

nothing added to commit but untracked files present (use "git add" to track)
```

Now `AStudent` tells git he wants to control `very_interesting_text.txt`:

```
$ git add very_interesting_text.txt
```

Check the status again to make sure git understood correctly:

```
$ git status
On branch master

Initial commit

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

	new file:   very_interesting_text.txt

```

Now git is suggesting us that the file is ready to be committed, and we agree with git in this case:

```
$ git commit -m "first commit"
[master (root-commit) 15ec2cc] first commit
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 very_interesting_text.txt
```
