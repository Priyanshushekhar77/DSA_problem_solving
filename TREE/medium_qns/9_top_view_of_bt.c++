/*
   Q. Top View of Binary Tree  --  https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
   Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

          1
       /     \
      2       3
     /  \    /   \
   4    5  6   7

   Top view will be: 4 2 1 3 7
   Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the extreme ones only(i.e. leftmost and rightmost).
   For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.
*/

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0}); // root,x
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            Node *node = it.first; // root
            int level = it.second; // x
            // poping out
            q.pop();
            // if this level is traversed for the first time
            if (mp.find(level) == mp.end())
            {
                mp[level] = node->data;
            }
            if (node->left != NULL)
                q.push({node->left, level - 1});
            if (node->right != NULL)
                q.push({node->right, level + 1});
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}