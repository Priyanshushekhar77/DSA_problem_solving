/*
   Ceil in a Binary Search Tree
   Given a BST and a number X, find Ceil of X.
   Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

   Example 1:

   Input:
         5
       /   \
      1     7
       \
        2
         \
          3
   X = 3
   Output: 3
   Explanation: We find 3 in BST, so ceil
   of 3 is 3.
   Example 2:

   Input:
        10
       /  \
      5    11
     / \
    4   7
         \
          8
   X = 6
   Output: 7
   Explanation: We find 7 in BST, so ceil
   of 6 is 7.
*/

int findCeil(Node *root, int x)
{
    if (root == NULL)
        return -1;

    // Your code here
    int ceil = -1;
    while (root != NULL)
    {
        if (root->data == x)
        {
            ceil = root->data;
            return ceil;
        }
        if (root->data > x)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            // root->val<x->val
            root = root->right;
        }
    }
    return ceil;
}