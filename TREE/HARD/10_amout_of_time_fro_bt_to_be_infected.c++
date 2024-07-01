// link->https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/   similar to burnig tree

TreeNode *bfstomapparent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, int start)
{
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *res;
    while (!q.empty())
    {
        auto node = q.front();
        if (node->val == start)
            res = node;
        q.pop();
        if (node->left != NULL)
        {
            parent[node->left] = node;
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int findtotaltime(unordered_map<TreeNode *, TreeNode *> &parent, TreeNode *target)
{
    queue<TreeNode *> q;
    // for visited tracking -> if particula node not visited than inc the cnt and mark its visited
    unordered_map<TreeNode *, int> visited;
    q.push(target);
    visited[target] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            auto node = q.front();
            q.pop();
            // left part not null and not visited than mark flag true and if flag is true than increment the cnt
            if (node->left != NULL && !visited[node->left])
            {
                flag = 1;
                visited[node->left] = 1;
                q.push(node->left);
            }
            // right part not null and not visited than mark flag true and if flag is true than increment the cnt
            if (node->right != NULL && !visited[node->right])
            {
                flag = 1;
                visited[node->right] = 1;
                q.push(node->right);
            }
            // parent of node is not null and parent is not visited than mark flag true and if flag is true than increment the cnt
            if (parent[node] && !visited[parent[node]])
            {
                flag = 1;
                visited[parent[node]] = 1;
                q.push(parent[node]);
            }
        }
        if (flag)
            cnt++;
    }
    return cnt;
}

int amountOfTime(TreeNode *root, int start)
{
    unordered_map<TreeNode *, TreeNode *> parent;
    TreeNode *target = bfstomapparent(root, parent, start);
    int ans = findtotaltime(parent, target);
    return ans;
}