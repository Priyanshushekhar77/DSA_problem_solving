/* Q. CHECK COMPLETENESS OF A BINARY TREE
https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
*/

bool isCompleteTree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    bool complte = true;
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == NULL)
                complte = false;
            // if any node is present after the null node than it violates the compllete tree and return the false
            else
            {
                if (complte == false)
                {
                    return false;
                }

                // push the left and cright child in q irrespective of node
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
    return true;
}