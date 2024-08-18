#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash_linked_list.h"
#include "hash.h"

#define DIRECT_HASH_TABLE_SIZE 100
#define CHAINED_HASH_TABLE_SIZE 10
#define OPEN_HASH_TABLE_SIZE 100

void DirectHashTableTest();
void ChainedHashTableTest();
void OpenHashTableTest();

int main() {
  //DirectHashTableTest();
  //LinkedListTest();
  //ChainedHashTableTest();
  OpenHashTableTest();
  return 0;
}

void DirectHashTableTest() {
  DirectHashTable *hashTable = DirectHashTableCreate(DIRECT_HASH_TABLE_SIZE);

  DirectHashInsert(hashTable, 10, 100);
  DirectHashInsert(hashTable, 20, 200);
  DirectHashInsert(hashTable, 30, 300);

  printf("Value at key 10: %d\n", DirectHashSearch(hashTable, 10));
  printf("Value at key 20: %d\n", DirectHashSearch(hashTable, 20));
  printf("Value at key 30: %d\n", DirectHashSearch(hashTable, 30));

  DirectHashDelete(hashTable, 20);
  printf("Value at key 20: %d\n", DirectHashSearch(hashTable, 20));

  DirectHashTableDelete(hashTable);
}

void ChainedHashTableTest() {
    ChainedHashTable* hashTable = ChainedHashTableCreate(CHAINED_HASH_TABLE_SIZE);

    // Insert 15 different key-value pairs
    for (int i = 0; i < 15; i++) {
        ChainedHashInsert(hashTable, i, i * 10);
    }

    // Print values at each key to check if insertions were successful
    for (int i = 0; i < 15; i++) {
        printf("Value at key %d: %d\n", i, ChainedHashSearch(hashTable, i));
    }

    // Delete a few keys and check their values again
    for (int i = 0; i < 5; i++) {
        ChainedHashDelete(hashTable, i);
        printf("Value at key %d after deletion: %d\n", i, ChainedHashSearch(hashTable, i));
    }

    // Print values at remaining keys to ensure they are still correct
    for (int i = 5; i < 15; i++) {
        printf("Value at key %d: %d\n", i, ChainedHashSearch(hashTable, i));
    }

    ChainedHashTableDelete(hashTable);
}

void OpenHashTableTest() {
    // Create a hash table with linear probing
    OpenHashTable* hashTableLinear = OpenHashTableCreate(10, LinearProbe);
    OpenHashInsert(hashTableLinear, 1, 10);
    OpenHashInsert(hashTableLinear, 2, 20);
    OpenHashInsert(hashTableLinear, 11, 110); // Collision with key 1

    printf("Linear Probe: Search 1: %d\n", OpenHashSearch(hashTableLinear, 1)); // Should print 10
    printf("Linear Probe: Search 2: %d\n", OpenHashSearch(hashTableLinear, 2)); // Should print 20
    printf("Linear Probe: Search 11: %d\n", OpenHashSearch(hashTableLinear, 11)); // Should print 110

    // Create a hash table with quadratic probing
    OpenHashTable* hashTableQuadratic = OpenHashTableCreate(10, QuadraticProbe);
    OpenHashInsert(hashTableQuadratic, 1, 10);
    OpenHashInsert(hashTableQuadratic, 2, 20);
    OpenHashInsert(hashTableQuadratic, 11, 110); // Collision with key 1

    printf("Quadratic Probe: Search 1: %d\n", OpenHashSearch(hashTableQuadratic, 1)); // Should print 10
    printf("Quadratic Probe: Search 2: %d\n", OpenHashSearch(hashTableQuadratic, 2)); // Should print 20
    printf("Quadratic Probe: Search 11: %d\n", OpenHashSearch(hashTableQuadratic, 11)); // Should print 110

    // Create a hash table with double hashing
    OpenHashTable* hashTableDouble = OpenHashTableCreate(10, DoubleHash);
    OpenHashInsert(hashTableDouble, 1, 10);
    OpenHashInsert(hashTableDouble, 2, 20);
    OpenHashInsert(hashTableDouble, 11, 110); // Collision with key 1

    printf("Double Hash: Search 1: %d\n", OpenHashSearch(hashTableDouble, 1)); // Should print 10
    printf("Double Hash: Search 2: %d\n", OpenHashSearch(hashTableDouble, 2)); // Should print 20
    printf("Double Hash: Search 11: %d\n", OpenHashSearch(hashTableDouble, 11)); // Should print 110

    OpenHashTableDelete(hashTableLinear);
    OpenHashTableDelete(hashTableQuadratic);
    OpenHashTableDelete(hashTableDouble);
}
