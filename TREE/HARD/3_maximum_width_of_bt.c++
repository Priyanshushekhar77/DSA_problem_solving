/*  662. Maximum Width of Binary Tree -- https://leetcode.com/problems/maximum-width-of-binary-tree/description/
   Given the root of a binary tree, return the maximum width of the given tree.

   The maximum width of a tree is the maximum width among all levels.

   The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

   It is guaranteed that the answer will in the range of a 32-bit signed integer.

   Example 1:
   Input: root = [1,3,2,5,3,null,9]
   Output: 4
   Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
*/

typedef unsigned long long ll;
int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, ll>> q;
    q.push({root, 0});
    ll maxwidth = 0;
    while (!q.empty())
    {
        // processing
        ll lft = q.front().second;
        ll rght = q.back().second;
        maxwidth = max(maxwidth, rght - lft + 1);
        int n = q.size();
        while (n--)
        {
            TreeNode *curr = q.front().first;
            ll ind = q.front().second;
            q.pop();
            if (curr->left != NULL)
                q.push({curr->left, 2 * ind + 1});
            if (curr->right != NULL)
                q.push({curr->right, 2 * ind + 2});
        }
    }
    return maxwidth;
}