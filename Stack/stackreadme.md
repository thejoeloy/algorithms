# Stack 
This file contains a C implementation of a Stack which implements a FIFO 
interface. The implementation is generic and supports arbitrary data 
types, although the test code only contains code for the built in C data 
types. Alas, the implementation can readily be modified to support user 
made data types. The implementation allocates memory dynamically. 

## Operations Supported
- BuildStack : Builds a stack containing size elements, each of size 
elemSize. The stack size is static and must be declared at instantiation.
- DeleteStack : This function deletes all of the memory associated with 
the stack
- IsEmpty : This function checks whether or not the stack currently has 
any elements inside of it. 
- Push : Pushes an element to the top of the stack. 
- Pop : Removes the top element from the stack.
- Peek : Returns the top element of the stack but does not remove it from 
the stack. 
