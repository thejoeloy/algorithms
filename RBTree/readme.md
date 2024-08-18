# Red Black Tree
Contains a generic C implementation of a red black tree. A red black tree 
is a self balancing binary tree that supports a variety of search, insert, 
and delete operations in lgn time. The implementation uses dynamically 
allocated memory. 

## Operations Supported
- CreateRBTree : Creates an empty RBTree
- DeleteRBTree : Deletes all of the memory associated with the RBTree
- RBTreeInsert : Inserts the element z into its proper location in the 
RBTree and restores the RB properties
- RBTreeDelete : Deletes the element z from the RBTree and restores the RB 
properties
- RBTreeMinimum : Returns the minimum element stored in the RBTree
- RBTreeMaximum : Returns the maximum element stored in the RBTree
- RBTreeInOrderTraversal : Prints out the RBTree in order
- RBSearch : Searches for key in the RBTree and returns a pointer to the 
the value contained in the node.
- RBRotateLeft : Performs a left rotation on a node in the binary tree. 
Used to restore the RB properties
- RBRotateRight : Performs a right rotation on a node in the binary tree.
- RBFixInsert : Restores the RB properties in the RBTree after an 
insertion
- RBFixDelete : Restores the RB properties in the RBTree after a deletion
- RBTransplant : Performs a transplant on the nodes u and v to restore the 
RB properties in a tree after a deletion
- NewRBNode : Creates a new RBNode containing data as its value.
- FreeNodes : Deletes all of the memory associated with the nodes in the 
RBTree
