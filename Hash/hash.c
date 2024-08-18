/* hash.c
 * This file contains implementations of a direct address hash table, a chained hash table,
 * and an open address hash table. A variety of hashing functions and probing functions are
 * implemented in order to give the user some flexibility in how they want to structure
 * their hash table. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash_linked_list.h"
#include "hash.h"

#define DIRECT_HASH_TABLE_SIZE 100
#define CHAINED_HASH_TABLE_SIZE 10
#define OPEN_HASH_TABLE_SIZE 100

/* MulHash(int k, int m, double A)
 * Uses the multiplication hash method to hash the key k into one of m slots
 * in the hash table. m is generally chosen as a power of 2 and A is chosen to
 * be a fraction in the range 0 < s < 2^w, where w is the the number of bits in
 * k.
*/
int MulHash(int k, int m, double A) {
  double frac = fmod(k * A, 1.0);
  return (int)floor(m * frac);
}

/* DivHash(int k, int m)
 * Uses the division hashing method to store a key k into one of the into one
 * of the m slots in the hash table. m should be chosen such that it is a prime
 * number that is not too close to a power of 2.
*/
int DivHash(int k, int m) {
  return k % m;
}

/* UniversalHash(int k, int m, int p, int a, int b)
 * Uses a universal hashing method that prevents an adversary from choosing
 * a set of keys that hash into the same slot. Has better average worst-case
 * behaviour than the other hash functions.
*/
int UniversalHash(int k, int m, int p, int a, int b) {
  if (p < m || p <= a || p <= b) return -1;
  return ((a * k + b) % p) % m;
}

/* LinearProbe(int k, int m, int i)
 * Probes hash slots in linear order (wrt to hashing function) to search for
 * empty slot to store key in open address hash table.
*/
int LinearProbe(int k, int m, int i) {
    return (k + i) % m;
}

/* QuadraticProbe(int k, int m, int i)
 * Probes hash slots in a quadratic manner to search for empty slot to store
 * key in an open address hash table.
*/
int QuadraticProbe(int k, int m, int i) {
    return (k + i * i) % m;
}

/* DoubleHash(int k, int m, int i)
 * Uses double hashing in order to probe the sequences of the open hash table
 * to store the key. h2(k) should be relatively prime to a hash-table of size
 * m. It is also good to make m prime or a power of 2 for better performance.
 * m for h2 can also be modified to be m_prime which is slightly less than m.
*/
int DoubleHash(int k, int m, int i) {
    int h1 = k % m;
    int h2 = 1 + (k % (m - 1));
    return (h1 + i * h2) % m;
}

/* DirectHashTableCreate(int size)
 * Creates a direct hash table of size n. The keys of each element are stored
 * in their respective slot in an array. -1 means the slot is invalid. 
*/
DirectHashTable* DirectHashTableCreate(int size) {
  DirectHashTable *hashTable = (DirectHashTable*)malloc(sizeof(DirectHashTable));
  hashTable->size = size;
  hashTable->table = (int*)malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    hashTable->table[i] = -1;
  }

  return hashTable;
}

/* DirectHashInsert(DirectHashTable* hashTable, int key, int val)
 * Stores a key in the hash table into its respective slot. Does bounds
 * checking to ensure that the key is in a valid index.
*/
void DirectHashInsert(DirectHashTable* hashTable, int key, int val) {
  if (key >= 0 && key < hashTable->size) {
    hashTable->table[key] = val;
  }
  else {
    printf("Key %d is not a valid key\n", key);
  }
}

/* DirectHashSearch(DirectHashTable* hashTable, int key)
 * Searches for the key in the direct hash table and returns its value if it
 * is contained and in a valid index of the table.
*/
int DirectHashSearch(DirectHashTable* hashTable, int key) {
  if (key >= 0 && key < hashTable->size) {
    return hashTable->table[key];
  }
  else {
    printf("Key %d is not a valid key\n", key);
  }
  return 0;
}

/* DirectHashDelete(DirectHashTable* hashTable, int key)
 * Deletes a key from the table and resets its value to invalid.
*/
void DirectHashDelete(DirectHashTable* hashTable, int key) {
  if (key >= 0 && key < hashTable->size) {
    hashTable->table[key] = -1;
  }
  else {
    printf("Key %d is not a valid key\n", key);
  }
}

/* DirectHashTableDelete(DirectHashTable* hashTable)
 * Cleans up all of the memory associated with the hash table.
*/
void DirectHashTableDelete(DirectHashTable* hashTable) {
  free(hashTable->table);
  free(hashTable);
}

/* ChainedHashTableCreate(int size)
 * Creates a chained hash table with size slots. Each of the slots contains
 * a linked list which can hold multiple keys.
*/
ChainedHashTable* ChainedHashTableCreate(int size) {
    ChainedHashTable* hashTable = (ChainedHashTable*)malloc(sizeof(ChainedHashTable));
    hashTable->size = size;
    hashTable->table = (LinkedList**)malloc(size * sizeof(LinkedList*));

    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }

    return hashTable;
}

/* ChainedHashInsert(ChainedHashTable* hashTable, int key, int val)
 * Inserts a key into the linked list pointed to by the proper key in the
 * array. 
*/
void ChainedHashInsert(ChainedHashTable* hashTable, int key, int val) {
    int index = DivHash(key, hashTable->size); 
    
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = (LinkedList*)malloc(sizeof(LinkedList));
        if (hashTable->table[index] == NULL) {
            printf("Memory allocation failed for linked list\n");
            return;
        }
        hashTable->table[index]->head = NULL;
        hashTable->table[index]->tail = NULL;
        hashTable->table[index]->len = 0;
    }
    
    InsertFirst(hashTable->table[index], key, val);
}

/* ChainedHashSearch(ChainedHashTable* hashTable, int key)
 * Returns the value associated with the key in the chained hash table, or
 * -1 if the key is not contained in the hash table.
*/
int ChainedHashSearch(ChainedHashTable* hashTable, int key) {
    int index = DivHash(key, hashTable->size);
    LinkedList* chain = hashTable->table[index];
    
    if (chain != NULL) {
        Node* current = chain->head;
        while (current != NULL) {
            if (current->key == key) {
                return current->val;
            }
            current = current->next;
        }
    }

    return -1;
}

/* ChainedHashDelete(ChainedHashTable* hashTable, int key)
 * Deletes key from the hash table if it is contained in the hash table. 
*/
void ChainedHashDelete(ChainedHashTable* hashTable, int key) {
    int index = DivHash(key, hashTable->size);
    LinkedList* chain = hashTable->table[index];

    if (chain != NULL) {
        Node* current = chain->head;
        while (current != NULL) {
            if (current->key == key) {
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                } else {
                    chain->head = current->next;
                }

                if (current->next != NULL) {
                    current->next->prev = current->prev;
                } else {
                    chain->tail = current->prev;
                }

                free(current);
                chain->len--;
                return;
            }
            current = current->next;
        }
    }
}

/* ChainedHashTableDelete(ChainedHashTable* hashTable)
 * Deletes all of the memory associated with the hash table.
*/
void ChainedHashTableDelete(ChainedHashTable* hashTable) {
  int size = hashTable->size;

  for (int i = 0; i < size; i++) {
    if (hashTable->table[i] != NULL) {
      while (hashTable->table[i]->len != 0) {
	DeleteFirst(hashTable->table[i]);
      }
      free(hashTable->table[i]);
    }
  }
  
  free(hashTable->table);
  free(hashTable);
}

/* OpenHashTableCreate(int size, ProbeFunction probe)
 * Creates an open hash table with size entries and uses the probing function
 * passed in to search for keys.
*/
OpenHashTable* OpenHashTableCreate(int size, ProbeFunction probe) {
  OpenHashTable *hashTable = (OpenHashTable*)malloc(sizeof(OpenHashTable));
  hashTable->size = size;
  hashTable->count = 0;
  hashTable->keys = (int*)malloc(size * sizeof(int*));
  hashTable->vals = (int*)malloc(size * sizeof(int*));
  hashTable->status = (int*)malloc(size * sizeof(int*));
  hashTable->probe = probe;
  
  for (int i = 0; i < size; i++) {
    hashTable->status[i] = 0;
  }

  return hashTable;
}

/* OpenHashInsert(OpenHashTable* hashTable, int key, int val)
 * Inserts a key and value pair into the open hash table.
*/
void OpenHashInsert(OpenHashTable* hashTable, int key, int val) {
    int index = key % hashTable->size;
    int i = 0;
    while (hashTable->status[index] == 1 && hashTable->keys[index] != key) {
        index = hashTable->probe(key, hashTable->size, i);
        if (++i >= hashTable->size) {
            return;
        }
    }
    hashTable->keys[index] = key;
    hashTable->vals[index] = val;
    hashTable->status[index] = 1;
    hashTable->count++;
}

/* OpenHashSearch(OpenHashTable* hashTable, int key)
 * Searches for key in the open hash table and returns the value associated
 * with it.
*/
int OpenHashSearch(OpenHashTable* hashTable, int key) {
  for (int i = 0; i < hashTable->size; i++) {
    int j = hashTable->probe(key, hashTable->size, i);
    if (hashTable->status[j] == 0) return -1;
    if (hashTable->keys[j] == key && hashTable->status[j] == 1) return hashTable->vals[j];
  }
  
  return -1;
}

/* OpenHashDelete(OpenHashTable* hashTable, int key)
 * Deletes the key and value associated with key in the hash table.
*/
void OpenHashDelete(OpenHashTable* hashTable, int key) {
  for (int i = 0; i < hashTable->size; i++) {
    int j = hashTable->probe(key, hashTable->size, i);
    if (hashTable->status[j] == 0) return;
    if (hashTable->keys[j] == key && hashTable->status[j] == 1) {
      hashTable->status[j] = 2;
      hashTable->count--;
      return;
    }
  }
}

/* OpenHashTableDelete(OpenHashTable* hashTable)
 * Deletes all of the memory associated with the open hash table.
*/
void OpenHashTableDelete(OpenHashTable* hashTable) {
  free(hashTable->keys);
  free(hashTable->vals);
  free(hashTable->status);
  free(hashTable);
}
