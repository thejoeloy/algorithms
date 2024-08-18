#ifndef RB_TREE_H
#define RB_TREE_H

typedef enum { RED, BLACK } NodeColor;

typedef struct RBNode {
    void* data;
    NodeColor color;
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
} RBNode;

typedef struct RBTree {
    RBNode* root;
    RBNode* nil;
    int (*compare)(const void*, const void*);
    void (*print)(const void*);
} RBTree;

// Function declarations
RBTree* CreateRBTree(int (*compare)(const void*, const void*), void (*print)(const void*));
void DeleteRBTree(RBTree* tree);
void RBTreeInsert(RBTree* tree, void* z);
void RBTreeDelete(RBTree* tree, RBNode* z);
RBNode* RBTreeMinimum(RBTree* tree, RBNode* x);
RBNode* RBTreeMaximum(RBTree* tree, RBNode* x);
void RBTreeInOrderTraversal(RBTree* tree, RBNode* x);
void RBTreePreOrderTraversal(RBTree* tree, RBNode* x);
void RBTreePostOrderTraversal(RBTree* tree, RBNode* x);
void* RBSearch(RBTree* tree, RBNode* x, void* key);

// Helper Functions
void RBRotateLeft(RBTree* tree, RBNode* x);
void RBRotateRight(RBTree* tree, RBNode* y);
void RBFixInsert(RBTree* tree, RBNode* z);
void RBFixDelete(RBTree* tree, RBNode* x);
void RBTransplant(RBTree* tree, RBNode* u, RBNode* v);
RBNode* NewRBNode(void* data);
void FreeNodes(RBTree* tree, RBNode* node);

#endif // RB_TREE_H
