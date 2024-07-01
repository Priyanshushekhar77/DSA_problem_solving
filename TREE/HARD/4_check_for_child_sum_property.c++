/*
   Check for Children Sum Property in a Binary Tree -> https://www.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent

   Problem Statement: Children Sum Property in a Binary Tree. Write a program that converts any binary tree to one that follows the children sum property.

   The children sum property is defined as, For every node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).

   Note:

   The node values can be increased by 1 any number of times but decrement of any node value is not allowed.
   A value for a NULL node can be assumed as 0.
   You are not allowed to change the structure of the given binary tree.


                     1                                     37
                   /  \                                   /  \
                 2     3                                12    25
                / \   / \         -------->            / \   / \
               4   5 6   7                            4   8 6   19
                  /     / \                              /     / \
                 8    9    10                           8    9    10

Step 1: Comparison and Value Update: Compare the sum of the children (child) with the current node's value.
If the sum of children is greater than or equal to the current node's value, we update the value of the parent to the sum of the children.
If the sum of children is smaller than the current node's value,than update the children with node(root) value

Step 2: Update Current Node's Value: Once both children have been processed, we recalculate the total sum of the values of the left and right children and update the current node’s value to match the total sum of its children.
*/

// this is a code of making a tree to child-sum property

int isSumProperty(Node *root)
{
    if (root == NULL)
        return NULL;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    // if childsum is greater than root update root with childsum
    if (child >= root->data)
    {
        root->data = child;
    }
    // otherewise update the child with root value
    else
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }
    // recursive
    isSumProperty(root->left);
    isSumProperty(root->right);
    // backtrack and verify the parent sum with child sum
    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;
    if (root->left != NULL || root->right != NULL)
        root->data = total;
}

// this is a code of checking a tree to validation of child-sum property

int isSumProperty(Node *root)
{
    if (root == NULL) // ultimate base case
        return 1;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    // if childsum is not equal to root than return false
    if (child != root->data)
    {
        return false;
    }
    // if it equals than check left and right subtree
    return (child == root->data && isSumProperty(root->left) && isSumProperty(root->right));
}