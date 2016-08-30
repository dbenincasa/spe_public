# Sed
```
$ man sed
sed - stream editor for filtering and transforming text
```

Stream EDditor. It is simple to use for simple applications and
features a rich set of commands for complex applications. We will see
few of them

## Substitution *s* `sed s/pattern_to_find/replacement/`
```
$ echo day > old
$ sed 's/day/night/' old > new
$ cat new
```
```
$ echo day | sed s/day/night/ 
```


Try yourself to modify the file `haiku.txt`

Sed replace only **the first** pattern per line. To replace **all** occurrencies add a `g`. To replace the **n**-th matched one, add the number
```
$ sed 's/s/SSS/' haiku.txt
$ sed 's/s/SSS/g' haiku.txt
$ sed 's/s/SSS/2' haiku.txt
```


`&` corresponds to the pattern matched. This is useful when combined
  with regular expressions

```
sed 's/[Aa-Zz]*day/--- & ---/' haiku.txt
```


Delete the first line or the last one.
```
$ sed '1 d'
$ sed '$ d'
```

Delete a line matching a given pattern

```
$ sed '/day/d'
```

Much more...

	      
