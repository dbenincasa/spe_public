# In a single phrase

A pointer has its own memory address and size on the stack (4 bytes on x86), whereas a reference shares the same memory address (with the original variable) but also takes up some space on the stack. Since a reference has the same address as the original variable itself, it is safe to think of a reference as another name for the same variable. Note: What a pointer points to can be on the stack or heap.

# Pointers vs References in `C`

Manupulation of [stackoverflow](http://stackoverflow.com/questions/4995899/difference-between-pointer-and-reference-in-c):

Here is a memory map; a representation of memory as a sequence of blocks:

```
    address    01   02   03
             +----+----+----+...
data within  | 23 | 6f | 4a |
             +----+----+----+...
```
Now suppose we create a character:
```
char c = 'z';  // 'z' is 7a in hex
```
Further suppose `c` is stored at address `01`, so our memory looks like so:
```
    address    01   02   03
             +----+----+----+...
data within  | 7a | 6f | 4a |
             +----+----+----+...
```
Now, let's create a pointer:
```c
char* p = &c;  // point at c
```
`p` may be stored at address `02`:
```
    address    01   02   03
             +----+----+----+...
data within  | 7a | 01 | 4a |
             +----+----+----+...
```
Here the pointer `p` is at address `02` and it points at address `01`. That's the meaning of `p = &c`. When we dereference the pointer `p` (at address `02`) we look at what's in the address pointed at by `p`. That is, `p` points at address `01`, and so dereferencing `p` means looking inside address `01`.
```c
printf("%c", *p);
```


# Pointers vs References in `C++`

No actual differenc between `C` and `C++`

An educated organisation of [stackoverflow](http://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in).

1. A pointer can be re-assigned:
```c++
int x = 5;
int y = 6;
int *p;
p =  &x;
p = &y;
*p = 10;
assert(x == 5);
assert(y == 10);
```
A reference cannot, and must be assigned at initialization:
```c++
int x = 5;
int y = 6;
int &r = x;
```

2. A pointer has its own memory address and size on the stack (4 bytes on x86), whereas a reference shares the same memory address (with the original variable) but also takes up some space on the stack. Since a reference has the same address as the original variable itself, it is safe to think of a reference as another name for the same variable. Note: What a pointer points to can be on the stack or heap

3. You can have pointers to pointers to pointers offering extra levels of indirection. Whereas references only offer one level of indirection.
```c++
int x = 0;
int y = 0;
int *p = &x;
int *q = &y;
int **pp = &p;
pp = &q;//*pp = q
**pp = 4;
assert(y == 4);
assert(x == 0);
```

4. Pointer can be assigned NULL directly, whereas reference cannot. If you try hard enough, and you know how, you can make the address of a reference NULL. Likewise, if you try hard enough you can have a reference to a pointer, and then that reference can contain NULL.
```c++
int *p = NULL;
int &r = NULL; <--- compiling error
```