/*
   199. Binary Tree Right Side View--  https://leetcode.com/problems/binary-tree-right-side-view/description/
   Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

   Example 1:
   Input: root = [1,2,3,null,5,null,4]
   Output: [1,3,4]

   Example 2:
   Input: root = [1,null,3]
   Output: [1,3]

   Example 3:
   Input: root = []
   Output: []
*/

vector<int> rightSideView(TreeNode *root)
{
    // level order traversal method
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (i == 0)
                ans.push_back(node->val); // pushing first right element of each level
            // we goes towards right first becz in queue first ele stored from right side
            if (node->right != NULL)
                q.push(node->right);
            if (node->left != NULL)
                q.push(node->left);
        }
    }
    return ans;
}

// method 2

void solve(TreeNode *root, int lev, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (ans.size() == lev)
        ans.push_back(root->val);
    // first goes to right than left
    solve(root->right, lev + 1, ans);
    solve(root->left, lev + 1, ans);
}
vector<int> rightSideView(TreeNode *root)
{
    // recursive method
    vector<int> ans;
    if (root == NULL)
        return ans;
    solve(root, 0, ans);
    return ans;
}