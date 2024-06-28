/*
   987. Vertical Order Traversal of a Binary Tree--   https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
   Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

   For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

   The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

   Return the vertical order traversal of the binary tree.
   */

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // use multiset and for left child(x-1,y+1) and right child have(x+1,y+1);
    map<int, map<int, multiset<int>>> mp;      // x,y,node
    queue<pair<TreeNode *, pair<int, int>>> q; // node,x,y
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first; // node
        int x = it.second.first;   // x
        int y = it.second.second;  // y
        // storing each vertical level in mp
        mp[x][y].insert(node->val);
        if (node->left != NULL)
            q.push({node->left, {x - 1, y + 1}});
        if (node->right != NULL)
            q.push({node->right, {x + 1, y + 1}});
    }

    //storing ans
    vector<vector<int>> ans;
    for (auto it1 : mp)
    {
        vector<int> col;
        for (auto it2 : it1.second)
        {
            col.insert(col.end(), it2.second.begin(), it2.second.end()); // pushing each vertical level parts a/c level x;col.end() becz we are fetching fromm end
        }
        ans.push_back(col);
    }
    return ans;
}