/*
   99. Recover Binary Search Tree  - https://leetcode.com/problems/recover-binary-search-tree/description/
   You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

   Example 1:
   Input: root = [1,3,null,null,2]
   Output: [3,1,null,null,2]
   Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

   Example 2:
   Input: root = [3,1,4,null,null,2]
   Output: [2,1,4,null,null,3]
   Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
*/

/* METHOD 1-> a) make inorder of bst which is in sorted order
              b) compare original bst with inorder array and if it is not similar than swap them
   METHOD 2-> a) if bst violated and if swapped nodes are not adjacent than swap first and last
            b) if swaped nodes are adjacent than swap first and middle
*/

class Solution
{
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

public:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        if (prev != NULL && (root->val < prev->val))
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                // agar first mil chuka hao
                last = root;
            }
        }
        // initialise prev with current root
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        // initialsies to class
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        // do operations in middle of inorder traversal
        inorder(root);
        // if swap ele is not adjacent
        if (first && last)
            swap(first->val, last->val);
        // if swap ele is adjacent
        else if (first && middle)
            swap(first->val, middle->val);
    }