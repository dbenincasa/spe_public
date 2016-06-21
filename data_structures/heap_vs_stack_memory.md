# Heap vs Stack

Human translation of what you can find on [stackoverflow](http://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap#79936).

## Stack

In a stack of items, items sit one on top of the other in the order they were placed there, and you can only remove the top one (without toppling the whole thing over).

![alt text](stack.jpg)

*The stack is the memory set aside as scratch space for a thread of execution.* When a function is called, a block is reserved on the top of the stack for local variables and some bookkeeping data. When that function returns, the block becomes unused and can be used the next time a function is called. *The stack is always reserved in a LIFO (last in first out) order*; the most recently reserved block is always the next block to be freed. This makes it really simple to keep track of the stack; freeing a block from the stack is nothing more than adjusting one pointer.

 - Stored in computer RAM just like the heap.
 - Variables created on the stack will go out of scope and automatically deallocate.
 - Much faster to allocate in comparison to variables on the heap.
 - Implemented with an actual stack data structure.
 - Stores local data, return addresses, used for parameter passing
 - Can have a stack overflow when too much of the stack is used. (mostly from infinite (or too much) recursion, very large allocations)
 - Data created on the stack can be used without pointers.
 - You would use the stack if you know exactly how much data you need to allocate before compile time and it is not too big.
 - Usually has a maximum size already determined when your program starts

## Heap

In a heap, there is no particular order to the way items are placed. You can reach in and remove items in any order because there is no clear 'top' item.

![alt text](heap.jpg)

The heap is memory set aside for dynamic allocation. Unlike the stack, there's no enforced pattern to the allocation and deallocation of blocks from the heap; you can allocate a block at any time and free it at any time. This makes it much more complex to keep track of which parts of the heap are allocated or free at any given time; there are many custom heap allocators available to tune heap performance for different usage patterns.

 - Stored in computer RAM just like the stack.
 - Variables on the heap must be destroyed manually and never fall out of scope. The data is freed with delete, delete[], or free
 - Slower to allocate in comparison to variables on the stack.
 - Used on demand to allocate a block of data for use by the program.
 - Can have fragmentation when there are a lot of allocations and deallocations
 - In C++ data created on the heap will be pointed to by pointers and allocated with new or malloc
 - Can have allocation failures if too big of a buffer is requested to be allocated.
 - You would use the heap if you don't know exactly how much data you will need at runtime or if you need to allocate a lot of data.
 - Responsible for memory leaks

## How they are controlled by the OS

The OS allocates the stack for each system-level thread when the thread is created. Typically the OS is called by the language runtime to allocate the heap for the application.

## What is Their Scope

The stack is attached to a thread, so when the thread exits the stack is reclaimed. The heap is typically allocated at application startup by the runtime, and is reclaimed when the application (technically process) exits.

## What is the fastest

The stack is faster because the access pattern makes it trivial to allocate and deallocate memory from it (a pointer/integer is simply incremented or decremented), while the heap has much more complex bookkeeping involved in an allocation or deallocation. Also, each byte in the stack tends to be reused very frequently which means it tends to be mapped to the processor's cache, making it very fast. Another performance hit for the heap is that the heap, being mostly a global resource, typically has to be multi-threading safe, i.e. each allocation and deallocation needs to be - typically - synchronized with "all" other heap accesses in the program.

## Example

```
int foo()
{
  char *pBuffer; //<--nothing allocated yet (excluding the pointer itself, which is allocated here on the stack).
  bool b = true; // Allocated on the stack.
  if(b)
  {
    //Create 500 bytes on the stack
    char buffer[500];

    //Create 500 bytes on the heap
    pBuffer = new char[500];

   }//<-- buffer is deallocated here, pBuffer is not
}//<--- oops there's a memory leak, I should have called delete[] pBuffer;
```



