## BINARY TREE TYPES

1.  Binary Tree: Binary tree is a fundamental hierarchical data structure in computer science that comprises nodes arranged in a tree-like structure. It consists of nodes, where each node can have at most two children nodes, known as the left child and the right child.e.g--folder and subfolder of your app files

2.  Nodes: Each node in a binary tree contains a piece of data, often referred to as the node’s value or key. This node also contains references and pointers to its left and right children so that we can traverse from one node to another in a hierarchical order.

3.  Ancestors in a Binary Tree are those nodes that lie on the path from a particular node to the root node.

4.Full Binary Tree: where every node has either zero or two children.contributes significantly to the tree’s balance, making traversal, searching and insertion options more predictable and efficient.

5. Complete Binary Tree:
   A Complete Binary Tree is a specialised form of Binary Tree where all levels are filled completely except possibly the last level, which is filled from left to right.
   All levels of the tree, except possibly the last one, are fully filled. If the last level is not completely filled, it is filled from left to right, ensuring that nodes are positioned as far left as possible.

6. Perfect Binary Tree: Every node in a perfect binary tree has either zero or two children. This means that every internal node (non-leaf node) has exactly two children and all leaf nodes are at the same level.

7. Balanced Binary Tree: A Balanced Binary tree is a type of Binary Tree where the heights of the two subtrees of any node differ by at most one.

8. Degenerate Tree:
   A Degenerate Tree is a Binary Tree where the nodes are arranged in a single path leaning to the right or left.


## Binary Tree Representation in C++

#include <iostream>

// Structure definition for
// a node in a binary tree
struct Node {
int data;  
 // Reference pointer to the left child node
Node* left;  
 // Reference pointer to the right child node
Node* right;  
 // Method to initialize the node with a value
Node(int val) {
data = val;  
 // Initialize left and right pointers as NULL
left = right = NULL;  
 }
};

int main() {
// Creating a new node for the root of the
// binary tree using dynamic allocation
Node\* root = new Node(1);
// Creating left and right child nodes for the root node
root->left = new Node(2);
root->right = new Node(3);
// Creating a right child node for the left child node of the root
root->left->right = new Node(5);
}


## Binary Tree Traversal

1. Depth-First Search (DFS) explores a binary tree by going as deeply as possible along each branch before backtracking.
   The order in which we visit a node determines if that traversal would be preorder, inorder and postorder.
   DFS uses recursion or a stack to traverse deeper levels of the tree before visiting nodes at the same level.

I.PREORDER -> Root,Left, Right.
CODE-> void preorder(Node\* root, vector<int> &arr){
if(root == nullptr){
return;
}
// Push the current node's value into the vector
arr.push_back(root->data);
// Recursively traverse the left subtree
preorder(root->left, arr);
// Recursively traverse the right subtree
preorder(root->right, arr);
}

II.INORDER -> Left,Root, Right.
CODE-> void inorder(TreeNode\* root,vector<int>&ans){
if(root==NULL){
return;
}
inorder(root->left,ans);
ans.push_back(root->val);

    inorder(root->right,ans);

}

III.Postorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Left, Right then Root.
CODE-> void postorder(TreeNode\* root,vector<int>&ans){
if(root==NULL){
return;
}
postorder(root->left,ans);
postorder(root->right,ans);
ans.push_back(root->val);
}

Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.
Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because the recursive stack uses an auxiliary space which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).


2. Breadth-First Search (BFS) explores a binary tree level by level, visiting all nodes at a given level before processing to the next level.
   It starts from the root and visits all nodes at level 0, then proceeds to level 1, level 2, and so on. Nodes at a level are visited from left to right.
   BFS uses a queue data structure to maintain nodes at each level, ensuring that nodes at higher levels are visited moving to lower levels.
