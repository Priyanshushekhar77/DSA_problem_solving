/*
   236. Lowest Common Ancestor of a Binary Tree
   Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

   According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

   Example 1:
   Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
   Output: 3
   Explanation: The LCA of nodes 5 and 1 is 3.

   Example 2:
   Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
   Output: 5
   Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

   Example 3:
   Input: root = [1,2], p = 1, q = 2
   Output: 1

link-. https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
Approach->
1. If root is null or if root is x or if root is y then return root
2. If the left subtree recursive call gives a null value that means we haven’t found LCA in the left subtree, which means we found LCA on the right subtree. So we will return right.
3. If the right subtree recursive call gives null value, that means we haven’t found LCA on the right subtree, which means we found LCA on the left subtree. So we will return left .
4. If both left & right calls give values (not null)  that means the root is the LCA.
*/

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // base case
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    // recursive traversal
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    // result by backtrack
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    // if both left and right ardee not NULL,we found our ans
    else
        return root;
}

/*  Time complexity: O(N) where n is the number of nodes.
Space complexity: O(N), auxiliary space.
*/