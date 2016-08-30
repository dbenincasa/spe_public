# Bash Exercise
Two arguments:
```
echo Hello World
```
One Argument:
```
echo "Hello World"
```
Stress on the fact that `-someting` are options.
```
echo "Hello \n World"
echo -e "Hello \n World"
```
List files, concatenation of options, one line, time, reverse:
```
ls -ltr
```
```
cd
mkdir
```
## File Operations
```
echo "Hello Wolrd" > out_file
echo "Ciao Mondo" >> out_file
```
```
echo "ciao" > f1
echo "riciao ciao" > f2
cat f1 f2
```
## Live Exercise:
The purpose of this tutorial is to get acquaintance with the following items:
    - create and running a bash script
    - the usage of `find`

In order to exploit the capabilities of `find`, we first create (step by step) two scripts that generate a lot of garbage files.

Cerate a simple script:
```
mkdir files_bucket
cd files_bucket
touch write_garbage_files.sh
```
Edit the file:
```
#!/bin/bash
for i in `seq 1 10`;
do
    echo $i
done
```
Check `Permissions`:
```
ls -l the_file_i_want_to_find.sh
-rw-r--r--  1 nicola  staff  55 Jun  8 10:07 write_garbage_files.sh
chmod +x the_file_i_want_to_find.sh 
```
Edit the file:
```
#!/bin/bash
for i in `seq 1 10`;
do
    VAR=$(date +%s | shasum | base64 | head -c 32) # watch out no spaces in the =
    # on linux sha256sum
    echo $VAR > $VAR
    echo "sleeping a while..."
    sleep 1
done
```
git for the first time, just a practical flavour...
```
git init
git status
git add the_file_i_want_to_find.sh
git status
git commit -m "bla"
git status
```
Side note: what if I delete the *committed* file by mistake?
```
rm the_file_i_want_to_find.sh
git status
git checkout -- the_file_i_want_to_find.sh
```
That's git's magic!


Ah, i was about to forget:
```
find files_bucket/ -name the_file_i_want_to_find.sh
```
Edit the file:
```
#!/bin/bash
KEY=$(( $RANDOM % 10 ))
for i in `seq 1 10`;
do
    VAR=$(date +%s | shasum | base64 | head -c 32) # watch out no spaces in the =
    # on linux sha256sum
    mkdir $VAR
    if [ "$i" = "$KEY" ]; then
       echo candy > "$VAR/candy"
    fi
    echo "sleeping a while..."
    sleep 1
done
```
```
find . -maxdepth 2 -name candy
```

