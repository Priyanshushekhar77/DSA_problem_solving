/* Q1. MAXIMUM PATH SUM(STRIVER) https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 */
int solve(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int left = solve(root->left, maxi);
    int right = solve(root->right, maxi);
    maxi = max(maxi, root->val + left + right);
    return max(left, right) + root->val;
}

int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    solve(root, maxi);
    return maxi;
}

/* Q2. CHILD SUM PROPERTY(STRIVER)  https://www.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent
  refer hard repo
*/
int isSumProperty(Node *root)
{
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    // if childsum is not equal to root than return false
    if (child != root->data)
    {
        return false;
    }
    // if it equals than check left and right subtree
    return (child == root->data && isSumProperty(root->left) && isSumProperty(root->right));
}

/* Q3. SUM OF LEFT LEAVES
https://leetcode.com/problems/sum-of-left-leaves/description/
*/
int sumOfLeftLeaves(TreeNode *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            if (root->left->left == NULL && root->left->right == NULL)
            {
                sum += root->left->val;
            }
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
    }

    return sum;
}

/* Q4. PATH SUM-1
https://leetcode.com/problems/path-sum-ii/
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
*/
vector<vector<int>> ans;
void solve(vector<int> &temp, TreeNode *root, int sum, int target)
{
    if (root == NULL)
        return;
    sum += root->val;
    temp.push_back(root->val);
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == target)
        {
            ans.push_back(temp);
        }
        // if tosum till root node not equals to target
        temp.pop_back();
        return;
    }
    solve(temp, root->left, sum, target);
    solve(temp, root->right, sum, target);
    temp.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int target)
{
    vector<int> temp;
    solve(temp, root, 0, target);
    return ans;
}

/* Q5. PATH SUM-2
https://leetcode.com/problems/path-sum/
*/
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return targetSum == root->val;
    }
    bool left = hasPathSum(root->left, targetSum - root->val);
    bool right = hasPathSum(root->right, targetSum - root->val);
    return left || right; // koi ek agar true value return kar de toh answer true hoga
}

/* Q6. MAX LEVEL SUM OF BINARY TREE
  https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
*/
int maxLevelSum(TreeNode *root)
{
    int maxsum = INT_MIN;
    int levl = 1;
    queue<TreeNode *> q;
    q.push(root);
    int curr_lev = 1;
    while (!q.empty())
    {
        int n = q.size();
        int sum = 0;
        while (n--)
        {
            TreeNode *node = q.front();
            q.pop();
            sum += node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        if (maxsum < sum)
        {
            maxsum = sum;
            levl = curr_lev;
        }
        curr_lev++;
    }
}
return levl;

/* Q7. PRUNE TREE
https://leetcode.com/problems/binary-tree-pruning/description/
*/
TreeNode *pruneTree(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left == NULL && root->right == NULL && root->val == 0)
        return NULL;
    return root;
}