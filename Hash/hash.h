#ifndef HASH_H
#define HASH_H

// Probe Function Pointers
typedef int (*ProbeFunction)(int k, int m, int i);

// Hash Table struct declarations
typedef struct {
  int* table;
  int size;
} DirectHashTable;

typedef struct {
  LinkedList** table;
  int size;
} ChainedHashTable;

typedef struct {
  int* keys;
  int* vals;
  int size;
  int count;
  int* status;
  ProbeFunction probe;
} OpenHashTable;

// Hashing Functions
int MulHash(int k, int m, double A);
int DivHash(int k, int m);
int UniversalHash(int k, int m, int p, int a, int b);
int LinearProbe(int k, int m, int i);
int QuadraticProbe(int k, int m, int i);
int DoubleHash(int k, int m, int i);

// Direct Hash Table Functions
DirectHashTable* DirectHashTableCreate(int size);
void DirectHashInsert(DirectHashTable* hashTable, int key, int val);
int DirectHashSearch(DirectHashTable* hashTable, int key);
void DirectHashDelete(DirectHashTable* hashTable, int key);
void DirectHashTableDelete(DirectHashTable* hashTable);

// Chained Hash Table Functions
ChainedHashTable* ChainedHashTableCreate(int size);
void ChainedHashInsert(ChainedHashTable* hashTable, int key, int val);
int ChainedHashSearch(ChainedHashTable* hashTable, int key);
void ChainedHashDelete(ChainedHashTable* hashTable, int key);
void ChainedHashTableDelete(ChainedHashTable* hashTable);

// Open Address Hash Table Functions
OpenHashTable* OpenHashTableCreate(int size, ProbeFunction probe);
void OpenHashInsert(OpenHashTable* hashTable, int key, int val);
int OpenHashSearch(OpenHashTable* hashTable, int key);
void OpenHashDelete(OpenHashTable* hashTable, int key);
void OpenHashTableDelete(OpenHashTable* hashTable);

#endif // HASH_H
