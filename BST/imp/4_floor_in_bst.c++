/*
   Floor in BST
   You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
   Note: when x is smaller than the smallest node of BST then returns -1.

   Example:

   Input:
   n = 7               2
                        \
                         81
                       /     \
                    42       87
                      \       \
                       66      90
                      /
                    45
   x = 87
   Output:
   87
   Explanation:
   87 is present in tree so floor will be 87.
   Example 2:

   Input:
   n = 4                     6
                              \
                               8
                             /   \
                           7       9
   x = 11
   Output:
   9
*/

int floor(Node *root, int x)
{
    // Code here
    if (root == NULL)
        return -1;

    // Your code here
    int flr = -1;
    while (root != NULL)
    {
        if (root->data == x)
        {
            flr = root->data;
            return flr;
        }
        if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            // root->val<x->val
            flr = root->data;
            root = root->right;
        }
    }
    return flr;
}