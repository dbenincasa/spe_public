# One-liners

One-liners are combination of some (many) bash commands written on one
line to achieve a specific task in a very efficient way. In the
following, we report some useful examples. We invite you to try them
and understan how and why they work. Then, you could challenge
yourself in finding a one-liner to achieve the same result.

- Find how many processors a computer (node) has:
```
$ cat /proc/cpuinfo | grep 'processor' | wc -l
$ cat /proc/cpuinfo | grep 'processor' | cut -d : -f 2 | sort | tail -n1 | xargs sh -c 'c=$1; let "c+=1"; echo $c' sh
```

- Print the model name of the processors:
```
$ cat /proc/cpuinfo | grep 'model name' | uniq | cut -d : -f 2
```

- Count the physical processors
```
$ cat /proc/cpuinfo | grep 'core id' | sort | uniq | wc -l
$ cat /proc/cpuinfo | grep 'core id' | sort | uniq -c
```

- Change the numbering
```
$ cat /proc/cpuinfo |  sed -r 's/(processor)(.*)([0-9]+)/echo "\1\2$((\3+1))"/ge'
```

# Exercises

1. Find the 5 largest file inside one directory (and subdirectories of course)

2. Find the 10 most used commands on ~/.bash_history


