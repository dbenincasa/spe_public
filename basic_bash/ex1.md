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
Cerate a simple script:
```
mkdir files_bucket
cd files_bucket
touch the_file_i_want_to_find.sh
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
-rw-r--r--  1 nicola  staff  55 Jun  8 10:07 the_file_i_want_to_find.sh
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
git commit "bla"
git status
rm the_file_i_want_to_find.sh
git status
```
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

