// BFS USING QUEUE D.S

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode *> q;
    // Push the root node to the queue
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        // Create a vector to store nodes at the current level
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            // Get the front node in the queue
            TreeNode *node = q.front();
            q.pop();
            // Enqueue the child nodes if they exist
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            // Store the node value in the current level vector
            level.push_back(node->val);
        }
        // Store the current level in the answer vector
        ans.push_back(level);
    }
    return ans;
}

/*  Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.
Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N).
*/