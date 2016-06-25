# Exercise 2

## Sed

```
echo day | sed s/day/night/ 
```

```
s/programmer/donkey/ input > output
```
```
echo Sunday | sed 's/day/night/'
```
Line oriented, input file:
```
one two three, one two three
four three two one
one hundred
```

```
ONE two three, one two three
four three two ONE
ONE hundred
```