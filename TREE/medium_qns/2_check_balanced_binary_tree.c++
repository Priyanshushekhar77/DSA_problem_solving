/*
   110. Balanced Binary Tree  -->  https://leetcode.com/problems/balanced-binary-tree/description/
   Given a binary tree, determine if it is
   height-balanced

   Example 1:
   Input: root = [3,9,20,null,null,15,7]
   Output: true

   Example 2:
   Input: root = [1,2,2,3,3,null,null,4,4]
   Output: false
   Example 3:

   Input: root = []
   Output: true
*/

int solveht(TreeNode *root)
{
    // base case
    if (root == NULL)
        return 0;
    // Height of left subtree...
    int left = solveht(root->left);
    // Height of right subtree...
    int right = solveht(root->right);
    // In case of left subtree or right subtree unbalanced or their heights differ by more than ‘1’, return -1..
    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;
    // Otherwise, return the height of this subtree as max(leftHeight, rightHight) + 1...
    return 1 + max(left, right);
}


bool isBalanced(TreeNode *root)
{
    // If the tree is empty, we can say it’s balanced...
    if (root == NULL)
        return true;
    // Height Function will return -1, when it’s an unbalanced tree...
    if (solveht(root) == -1)
        return false;
    else
        return true;
}