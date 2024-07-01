/* https://leetcode.com/problems/even-odd-tree/description/
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.


*/

bool isEvenOddTree(TreeNode *root)
{
    bool iseven = true;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        int prevele;
        if (iseven)
            prevele = INT_MIN;
        else
            prevele = INT_MAX;
        while (n--)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (iseven && (curr->val % 2 == 0 || prevele >= curr->val))
                return false;
            if (!iseven && (curr->val % 2 != 0 || prevele <= curr->val))
                return false;
            prevele = curr->val;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        // change the condn
        iseven = !iseven;
    }
    return true;
}