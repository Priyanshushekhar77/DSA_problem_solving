/*
   Bottom View of Binary Tree --  https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
   Given a binary tree, print the bottom view from left to right.
   A node is included in bottom view if it can be seen when we look at the tree from bottom.

                         20
                       /    \
                     8       22
                   /   \        \
                 5      3       25
                       /   \
                     10    14

   For the above tree, the bottom view is 5 10 3 14 25.
   If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                         20
                       /    \
                     8       22
                   /   \     /   \
                 5      3 4     25
                        /    \
                    10       14

   For the above tree the output should be 5 10 4 14 25.
   */

vector<int> bottomView(Node *root)
{
    // Your Code Here
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
            // if this level is traversed for the first time or any time(i.e last time for bottom view then replace on mp[level])

            mp[level] = node->data;

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