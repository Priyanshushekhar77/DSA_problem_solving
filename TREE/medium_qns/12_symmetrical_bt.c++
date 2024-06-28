/*
   101. Symmetric Tree--  https://leetcode.com/problems/symmetric-tree/description/
   Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

   Example 1:
   Input: root = [1,2,2,3,4,4,3]
   Output: true

   Example 2:
   Input: root = [1,2,2,null,3,null,3]
   Output: false
*/

bool dfs(TreeNode *p, TreeNode *q)
{
   if (p == NULL && q == NULL)
      return true;
   if (p == NULL && q != NULL)
      return false;
   if (p != NULL && q == NULL)
      return false;
   if (p->val != q->val)
      return false;
   return (p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left));
}
bool isSymmetric(TreeNode *root)
{
   return dfs(root->left, root->right);
}