/* Q. MAXIMUM DIFFERENCE BETWEEN NODE AND ANCESTOR
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
*/

int solve(TreeNode *root, int mini, int maxi)
{
    // base case at leaf node for max diff btw ancestor and child
    if (root == NULL)
    {
        return abs(maxi - mini);
    }
    mini = min(mini, root->val);
    maxi = max(maxi, root->val);
    int lft = solve(root->left, mini, maxi);
    int rght = solve(root->right, mini, maxi);
    // return the max of left and right traversal
    return max(lft, rght);
}
int maxAncestorDiff(TreeNode *root)
{
    return solve(root, root->val, root->val);
}