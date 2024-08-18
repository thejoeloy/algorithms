#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "rb_tree.h"

#define NUM_VALUES 100
#define MAX_VALUE 100000000
#define NUM_TO_DELETE 1000
#define NUM_INSERT 300000
#define NUM_DELETE 100000

// Comparison and Print function declarations
int IntCompare(const void* a, const void* b);
int FloatCompare(const void* a, const void* b);
int CharCompare(const void* a, const void* b);
int StringCompare(const void* a, const void* b);
void PrintInt(const void* data);
void PrintFloat(const void* data);
void PrintChar(const void* data);
void PrintString(const void* data);

// Function declarations for testing
void RBTreeTestInt();
void RBTreeTestLargeInt();
void RBTreeTestFloat();
void RBTreeTestChar();
void RBTreeTestString();
void GenerateUniqueRandomValues(int* values, size_t num_values, int max_value);

// Main function
int main() {
	RBTreeTestLargeInt();
	//RBTreeTestInt();
	//RBTreeTestFloat();
	//RBTreeTestChar();
	//RBTreeTestString();
    return 0;
}

// Integer comparison function
int IntCompare(const void* a, const void* b) {
    int intA = *(const int*)a;
    int intB = *(const int*)b;
    return (intA > intB) - (intA < intB);
}

int FloatCompare(const void* a, const void* b) {
    float floatA = *(const float*)a;
    float floatB = *(const float*)b;
    return (floatA > floatB) - (floatA < floatB); 
}

int CharCompare(const void* a, const void* b) {
    char charA = *(const char*)a;
    char charB = *(const char*)b;
    return (charA > charB) - (charA < charB); 
}

int StringCompare(const void* a, const void* b) {
    const char* strA = *(const char**)a;
    const char* strB = *(const char**)b;
    return strcmp(strA, strB); 
}

void PrintInt(const void* data) {
    printf("%d\n", *(int*)data);
}

void PrintFloat(const void* p) {
    printf("%.2f\n", *(float*)p);
}

void PrintChar(const void* p) {
    printf("%c\n", *(char*)p);
}

void PrintString(const void* p) {
    printf("%s\n", *(char**)p);
}

// Function to generate unique random values
void GenerateUniqueRandomValues(int* values, size_t num_values, int max_value) {
    int* flags = (int*)calloc(max_value, sizeof(int));
    if (flags == NULL) {
        perror("Failed to allocate memory for flags");
        exit(EXIT_FAILURE);
    }

    size_t count = 0;
    srand((unsigned int)time(NULL));

    while (count < num_values) {
        int value = rand() % max_value;
        if (!flags[value]) {
            values[count] = value;
            flags[value] = 1;
            ++count;
        }
    }

    free(flags);
}

void RBTreeTestLargeInt() {
    printf("RBTreeTestLargeInt function is called.\n");

    int (*intCompare)(const void*, const void*) = &IntCompare;
    void (*printInt)(const void*) = &PrintInt;

    RBTree* tree = CreateRBTree(intCompare, printInt);

    // Generate 500 unique random nodes
    int insertData[NUM_INSERT];
    GenerateUniqueRandomValues(insertData, NUM_INSERT, MAX_VALUE); // Assuming max value 1000

    // Insert nodes
    for (int i = 0; i < NUM_INSERT; i++) {
        RBTreeInsert(tree, &insertData[i]);
    }

    // In-order traversal to print the tree nodes
    //printf("In-order traversal of the tree:\n");
    //RBTreeInOrderTraversal(tree, tree->root);

    // Check minimum and maximum
    RBNode* minNode = RBTreeMinimum(tree, tree->root);
    RBNode* maxNode = RBTreeMaximum(tree, tree->root);

    if (minNode != tree->nil) {
        printf("Minimum: ");
        tree->print(minNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    if (maxNode != tree->nil) {
        printf("Maximum: ");
        tree->print(maxNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    // Generate 200 random nodes to delete
    int deleteData[NUM_DELETE];
    GenerateUniqueRandomValues(deleteData, NUM_DELETE, MAX_VALUE); // Assuming max value 1000
    // Delete the selected nodes
    for (int i = 0; i < NUM_DELETE; i++) {
        //printf("Attempting to delete node with data %d.\n", deleteData[i]);
        RBNode* nodeToDelete = RBSearch(tree, tree->root, &deleteData[i]);
        if (nodeToDelete != tree->nil) {
            RBTreeDelete(tree, nodeToDelete);
        }
    }

    // In-order traversal after deletions
    //printf("In-order traversal after deletions:\n");
    //RBTreeInOrderTraversal(tree, tree->root);
    
    // Free the tree
    DeleteRBTree(tree);
}

void RBTreeTestInt() {
    printf("RBTreeTest function is called.\n");

    int (*intCompare)(const void*, const void*) = &IntCompare;
    void (*printInt)(const void*) = &PrintInt;

    RBTree* tree = CreateRBTree(intCompare, printInt);

    // Insert 50 different nodes
    int data[] = {15, 5, 20, 1, 7, 17, 25, 3, 9, 8, 12, 6, 11, 14, 4, 13, 18, 19, 2, 16,
                  10, 22, 30, 24, 27, 23, 26, 21, 28, 29, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
                  41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    
    for (int i = 0; i < 50; i++) {
        RBTreeInsert(tree, &data[i]);
    }

    // In-order traversal to print the tree nodes
    printf("In-order traversal of the tree:\n");
    RBTreeInOrderTraversal(tree, tree->root);

    // Check minimum and maximum
    RBNode* minNode = RBTreeMinimum(tree, tree->root);
    RBNode* maxNode = RBTreeMaximum(tree, tree->root);

    if (minNode != tree->nil) {
        printf("Minimum: ");
        tree->print(minNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    if (maxNode != tree->nil) {
        printf("Maximum: ");
        tree->print(maxNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    // Delete 20 nodes and print the tree again
    int deleteData[] = {15, 5, 20, 1, 7, 17, 25, 3, 9, 8, 12, 6, 11, 14, 4, 13, 18, 19, 2, 16};

    for (int i = 0; i < 20; i++) {
        printf("Deleting node with data %d.\n", deleteData[i]);
        RBNode* nodeToDelete = RBSearch(tree, tree->root, &deleteData[i]);
        if (nodeToDelete != tree->nil) {
            RBTreeDelete(tree, nodeToDelete);
        }
    }

    // In-order traversal after deletions
    printf("In-order traversal after deletions:\n");
    RBTreeInOrderTraversal(tree, tree->root);
    
    // Free the tree
    DeleteRBTree(tree);
}

void RBTreeTestFloat() {
    printf("RBTreeTestFloat function is called.\n");

    int (*floatCompare)(const void*, const void*) = &FloatCompare;
    void (*printFloat)(const void*) = &PrintFloat;

    RBTree* tree = CreateRBTree(floatCompare, printFloat);

    // Insert 10 different nodes
    float data[] = {1.5f, 3.2f, 7.8f, 2.4f, 5.5f, 8.9f, 0.3f, 4.6f, 6.7f, 9.1f};
    
    for (int i = 0; i < 10; i++) {
        RBTreeInsert(tree, &data[i]);
    }

    // In-order traversal to print the tree nodes
    printf("In-order traversal of the tree:\n");
    RBTreeInOrderTraversal(tree, tree->root);

    // Check minimum and maximum
    RBNode* minNode = RBTreeMinimum(tree, tree->root);
    RBNode* maxNode = RBTreeMaximum(tree, tree->root);

    if (minNode != tree->nil) {
        printf("Minimum: ");
        tree->print(minNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    if (maxNode != tree->nil) {
        printf("Maximum: ");
        tree->print(maxNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    // Delete 5 nodes and print the tree again
    float deleteData[] = {1.5f, 3.2f, 7.8f, 2.4f, 5.5f};

    for (int i = 0; i < 5; i++) {
        printf("Deleting node with data %.2f.\n", deleteData[i]);
        RBNode* nodeToDelete = RBSearch(tree, tree->root, &deleteData[i]);
        if (nodeToDelete != tree->nil) {
            RBTreeDelete(tree, nodeToDelete);
        }
    }

    // In-order traversal after deletions
    printf("In-order traversal after deletions:\n");
    RBTreeInOrderTraversal(tree, tree->root);
    
    // Free the tree
    DeleteRBTree(tree);
}

void RBTreeTestChar() {
    printf("RBTreeTestChar function is called.\n");

    int (*charCompare)(const void*, const void*) = &CharCompare;
    void (*printChar)(const void*) = &PrintChar;

    RBTree* tree = CreateRBTree(charCompare, printChar);

    // Insert 10 different nodes
    char data[] = {'a', 'e', 'i', 'o', 'u', 'b', 'c', 'd', 'f', 'g'};
    
    for (int i = 0; i < 10; i++) {
        RBTreeInsert(tree, &data[i]);
    }

    // In-order traversal to print the tree nodes
    printf("In-order traversal of the tree:\n");
    RBTreeInOrderTraversal(tree, tree->root);

    // Check minimum and maximum
    RBNode* minNode = RBTreeMinimum(tree, tree->root);
    RBNode* maxNode = RBTreeMaximum(tree, tree->root);

    if (minNode != tree->nil) {
        printf("Minimum: ");
        tree->print(minNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    if (maxNode != tree->nil) {
        printf("Maximum: ");
        tree->print(maxNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    // Delete 5 nodes and print the tree again
    char deleteData[] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++) {
        printf("Deleting node with data '%c'.\n", deleteData[i]);
        RBNode* nodeToDelete = RBSearch(tree, tree->root, &deleteData[i]);
        if (nodeToDelete != tree->nil) {
            RBTreeDelete(tree, nodeToDelete);
        }
    }

    // In-order traversal after deletions
    printf("In-order traversal after deletions:\n");
    RBTreeInOrderTraversal(tree, tree->root);
    
    // Free the tree
    DeleteRBTree(tree);
}

void RBTreeTestString() {
    printf("RBTreeTestString function is called.\n");

    int (*stringCompare)(const void*, const void*) = &StringCompare;
    void (*printString)(const void*) = &PrintString;

    RBTree* tree = CreateRBTree(stringCompare, printString);

    // Insert 5 different nodes
    const char* data[] = {"apple", "banana", "cherry", "date", "fig"};
    
    for (int i = 0; i < 5; i++) {
        RBTreeInsert(tree, &data[i]);
    }

    // In-order traversal to print the tree nodes
    printf("In-order traversal of the tree:\n");
    RBTreeInOrderTraversal(tree, tree->root);

    // Check minimum and maximum
    RBNode* minNode = RBTreeMinimum(tree, tree->root);
    RBNode* maxNode = RBTreeMaximum(tree, tree->root);

    if (minNode != tree->nil) {
        printf("Minimum: ");
        tree->print(minNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    if (maxNode != tree->nil) {
        printf("Maximum: ");
        tree->print(maxNode->data);
    } else {
        printf("Tree is empty.\n");
    }

    // Delete 3 nodes and print the tree again
    const char* deleteData[] = {"apple", "banana", "cherry"};

    for (int i = 0; i < 3; i++) {
        printf("Deleting node with data \"%s\".\n", deleteData[i]);
        RBNode* nodeToDelete = RBSearch(tree, tree->root, &deleteData[i]);
        if (nodeToDelete != tree->nil) {
            RBTreeDelete(tree, nodeToDelete);
        }
    }

    // In-order traversal after deletions
    printf("In-order traversal after deletions:\n");
    RBTreeInOrderTraversal(tree, tree->root);
    
    // Free the tree
    DeleteRBTree(tree);
}
