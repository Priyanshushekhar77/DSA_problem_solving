/*
   230. Kth Smallest Element in a BST - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
   Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

   Example 1:
   Input: root = [3,1,4,null,2], k = 1
   Output: 1

   Example 2:
   Input: root = [5,3,6,2,4,null,null,1], k = 3
   Output: 3
*/

void inorder(TreeNode *root, int &k, int &ans)
{
    if (root == NULL)
        return;
    int cnt = 0;
    inorder(root->left, k, ans);
    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }
    inorder(root->right, k, ans);
}
int kthSmallest(TreeNode *root, int k)
{
    int ans;
    inorder(root, k, ans);
    return ans;
}

// for kth largest put k= n-k;
