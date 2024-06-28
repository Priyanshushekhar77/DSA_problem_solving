/// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
/*
   103. Binary Tree Zigzag Level Order Traversal
   Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

   Example 1:
   Input: root = [3,9,20,null,null,15,7]
   Output: [[3],[20,9],[15,7]]

   Example 2:
   Input: root = [1]
   Output: [[1]]

   Example 3:
   Input: root = []
   Output: []
*/

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    // using level order traversal
    vector<vector<int>> ans;
    // base case for avoiding runtime error
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool lefttoright = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            // positioning for placing
            int ind = (lefttoright) ? i : (size - 1 - i);
            level[ind] = node->val;
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        lefttoright = !lefttoright;
        ans.push_back(level);
    }
    return ans;
}