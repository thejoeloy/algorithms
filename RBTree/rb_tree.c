/* rb_binary_tree.c
 * Contains an implementation of a red black tree. A red black tree supports dynamic inserts
 * and deletes, searches, and max and min functions. This implementation uses a sentinel called
 * nil, which trades off a small amount of memory for code simplicity.
*/

#include <stdio.h>
#include <stdlib.h>
#include "rb_tree.h"

/* CreateRBTree(int (*compare)(const void*, const void*), void (*print)(void*))
 *
*/
RBTree* CreateRBTree(int (*compare)(const void*, const void*), void (*print)(const void*)) {
	RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
  	if (tree == NULL) exit(1);

  	tree->nil = (RBNode*)malloc(sizeof(RBNode));
  	if (tree->nil == NULL) exit(1);

  	tree->nil->color = BLACK;
  	tree->root = tree->nil;
  	tree->compare = compare;
  	tree->print = print;
  	return tree;
}

/* NewRBNode(void* data)
 * Creates a new rb node containing data and sets its other fields to be ready for insertion
*/
RBNode* NewRBNode(void* data) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    if (node == NULL) {
        exit(1);
    }
    node->data = data;
    node->color = RED; 
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

/* DeleteRBTree(RBTree* tree)
 * Deletes all of the memory associated with the RB Tree
*/
void DeleteRBTree(RBTree* tree) {
    if (tree != NULL) {
        FreeNodes(tree, tree->root);
        free(tree->nil);
        free(tree);
    }
}

/* FreeNodes(RBTree* tree, RBNode* node)
 * Frees the memory of all of the nodes in the RB Tree.
*/
void FreeNodes(RBTree* tree, RBNode* node) {
    if (node != tree->nil && node != NULL) {
        FreeNodes(tree, node->left);
        FreeNodes(tree, node->right);
        free(node);
    }
}

/* RBTreeMinimum(RBTree* tree, RBNode* x)
 * Returns a pointer to the smallest node contained in the tree.
*/
RBNode* RBTreeMinimum(RBTree* tree, RBNode* x) {
  while (x->left != tree->nil) {
    x = x->left;
  }
  return x;
}

/* RBTreeMaximum(RBTree* tree, RBNode* x)
 * Returns a pointer to the largest node contained in the tree.
*/
RBNode* RBTreeMaximum(RBTree* tree, RBNode* x) {
  while (x->right != tree->nil) {
    x = x->right;
  }
  return x;
}

/* RBSearch(RBTree* tree, RBNode* x, void* key)
 * Returns a pointer to the data contained in the node containing key if it is in the RB Tree 
*/
void* RBSearch(RBTree* tree, RBNode* x, void* key) {
  if (x == tree->nil || tree->compare(key, x->data) == 0) {
    return x;
  }

  if (tree->compare(key, x->data) < 0) {
    return RBSearch(tree, x->left, key);
  }
  else {
    return RBSearch(tree, x->right, key);
  }
}

/* RBTreeInOrderTraversal(RBTree* tree, RBNode* x)
 * Prints out the data and color associated with each node in the tree in traversal order.
*/
void RBTreeInOrderTraversal(RBTree* tree, RBNode* x) {
	if (x != tree->nil) {
		RBTreeInOrderTraversal(tree, x->left);
		tree->print(x->data);
		RBTreeInOrderTraversal(tree, x->right);
	}
}

void RBTreePreOrderTraversal(RBTree* tree, RBNode* x) {
	if (x != tree->nil) {
		tree->print(x->data);              
		RBTreePreOrderTraversal(tree, x->left);  
		RBTreePreOrderTraversal(tree, x->right); 
	}
}

void RBTreePostOrderTraversal(RBTree* tree, RBNode* x) {
	if (x != tree->nil) {
		RBTreePostOrderTraversal(tree, x->left);  
    	RBTreePostOrderTraversal(tree, x->right); 
  		tree->print(x->data);
	}
}

/* RBRotateLeft(RBTree* tree, RBNode* x)
 * Performs a left rotation on a node.
*/
void RBRotateLeft(RBTree* tree, RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;

    if (y->left != tree->nil) y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == tree->nil) tree->root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    y->left = x;
    x->parent = y;
}

/* RBRotateRight(RBTree* tree, RBNode* y)
 * Performs a right rotation on a node.
*/
void RBRotateRight(RBTree* tree, RBNode* y) {
    RBNode* x = y->left;
    y->left = x->right;

    if (x->right != tree->nil) x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == tree->nil) tree->root = x;
    else if (y == y->parent->right) y->parent->right = x;
    else y->parent->left = x;

    x->right = y;
    y->parent = x;
}

/* RBTransplant(RBTree* tree, RBNode* u, RBNode* v)
 *
*/
void RBTransplant(RBTree* tree, RBNode* u, RBNode* v) {
    if (u->parent == tree->nil) 
        tree->root = v;
    else if (u == u->parent->left) 
        u->parent->left = v;
    else 
        u->parent->right = v;

    v->parent = u->parent;
}

/* RBTreeInsert(RBTree* tree, void* data)
 * Inserts a node into the tree containing data.
*/
void RBTreeInsert(RBTree* tree, void* data) {
    RBNode* z = NewRBNode(data);
    RBNode* y = tree->nil;
    RBNode* x = tree->root;
    
    while (x != tree->nil) {
        y = x;
        if (tree->compare(z->data, x->data) < 0) x = x->left;
        else x = x->right;
    }
    
    z->parent = y;

    if (y == tree->nil) tree->root = z;
    else if (tree->compare(z->data, y->data) < 0) y->left = z;
    else y->right = z;
    
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;
    
    RBFixInsert(tree, z);
}

/* RBFixInsert(RBTree* tree, RBNode* z)
 * Restores the max tree property if the inserted node violates the RB properties.
*/
void RBFixInsert(RBTree* tree, RBNode* z) {
    RBNode* y;
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } 
            else {
            	if (z == z->parent->right) {
            	    z = z->parent;
                	RBRotateLeft(tree, z);
            	}
            	z->parent->color = BLACK;
            	z->parent->parent->color = RED;
            	RBRotateRight(tree, z->parent->parent);
            }
        } 
        else {
            y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } 
            else {
            	if (z == z->parent->left) {
            		z = z->parent;
                	RBRotateRight(tree, z);
            	}
            	z->parent->color = BLACK;
            	z->parent->parent->color = RED;
            	RBRotateLeft(tree, z->parent->parent);
        	}
        }
    }
    tree->root->color = BLACK;
}

/* RBTreeDelete(RBTree* tree, RBNode* z)
 * Deletes the node z from the tree and restores the RB properties
*/
void RBTreeDelete(RBTree* tree, RBNode* z) {
    RBNode* y = z;
    NodeColor y_original_color = y->color;
    RBNode* x;

    if (z->left == tree->nil) {
        x = z->right;
        RBTransplant(tree, z, z->right);
    }
    else if (z->right == tree->nil) {
        x = z->left;
        RBTransplant(tree, z, z->left);
    }
    else {
        y = RBTreeMinimum(tree, z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z) 
            x->parent = y;
        else {
            RBTransplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        RBTransplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK) {
        RBFixDelete(tree, x);
    }
    free(z);
}

/* RBFixDelete(RBTree* tree, RBNode* x)
 * Restores the RB properties after deleting the node
*/
void RBFixDelete(RBTree* tree, RBNode* x) {
    RBNode* w;
    while (x != tree->root && x->color == BLACK) {
        if (x == x->parent->left) {
            w = x->parent->right;
            
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                RBRotateLeft(tree, x->parent);
                w = x->parent->right;
            }
 
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
            	if (w->right->color == BLACK) {
                	w->left->color = BLACK;
                	w->color = RED;
                	RBRotateRight(tree, w);
                	w = x->parent->right;
            	}
            	w->color = x->parent->color;
            	x->parent->color = BLACK;
            	w->right->color = BLACK;
            	RBRotateLeft(tree, x->parent);
            	x = tree->root;
			}
        }
        else {
            w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                RBRotateRight(tree, x->parent);
                w = x->parent->left;
            }

            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else  {
            	if (w->left->color == BLACK) {
                	w->right->color = BLACK;
                	w->color = RED;
                	RBRotateLeft(tree, w);
                	w = x->parent->left;
            	}
            	w->color = x->parent->color;
            	x->parent->color = BLACK;
            	w->left->color = BLACK;
            	RBRotateRight(tree, x->parent);
            	x = tree->root;
            }
        }
    }
    x->color = BLACK;
}
