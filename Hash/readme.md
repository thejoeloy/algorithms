# Hash
Contains C implementations of a direct address hash table, chained hash 
table, and open address hash table. The chained hash table uses a modified 
double linked list data structure which stores a key value pair. 

## Hash Functions
- MulHash : Implements a multiplicative hash function of the form 
- DivHash : Implements a division hash function of the form 
- UniversalHash : Implements a universal hash function of the form

## Probing Functions
- LinearProbe : Implements a linear probing hash function of the form
- QuadraticProbe : Implements a quadratic probing hash function of the 
form 
- Double Hash : Implement a double hash probe function of the form 

## Direct Address Table Operations
- DirectHashTableCreate : Creates a direct hash table that can contain 
size elements
- DirectHashInsert : Inserts val into the proper location for key in the 
hash table
- DirectHashSearch : Searches for key in the hash table and returns the 
value associated with it.
- DirectHashDelete : Deletes the key value pair for key in the hash table.
- DirectHashTableDelete : Deletes all of the memory associated with the 
direct address hash table.

## Chained Hash Table Operations
- ChainedHashTableCreate : Creates a chained hash table of size size.
- ChainedHashInsert : Inserts the key value pair into the chained hash 
table at the end of the linked list structure containing the vals
- ChainedHashSearch : Searches for the key in the chained hash table and 
returns the value associated with it.
- ChainedHashDelete : Deletes the key value entry in the chained hash 
table
- ChainedHashTableDelete : Deletes all memory associated with the chained 
hash table.

## Open Address Hash Table Operations
- OpenHashTableCreate : Creates an open hash table that can contain size 
elements. Uses the probing function passed in to search for keys.
- OpenHashInsert : Inserts the key value pair into the hash table
- OpenHashSearch : Searches for the value associated with key in the hash 
table
- OpenHashDelete : Deletes the key value pair associated with key in the 
hash table.
- OpenHashTableDelete : Deletes all memory associated with the hash table.
