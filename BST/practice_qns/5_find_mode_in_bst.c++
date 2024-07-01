/*
https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

*/
vector<int> ans;
int currval = 0, currfreq = 0, maxfreq = 0;
void solve(TreeNode *root)
{
    if (root == NULL)
        return;
    solve(root->left);
    if (root->val == currval)
    {
        currfreq++;
    }
    else
    {
        currval = root->val;
        currfreq = 1;
    }
    if (currfreq > maxfreq)
    {
        maxfreq = currfreq;
        ans = {};
    }
    if (currfreq == maxfreq)
    {
        ans.push_back(root->val);
    }
    solve(root->right);
}
vector<int> findMode(TreeNode *root)
{
    // method 1 find inorder of bst in vector and than find the element which occurs maximum times or store im map cnt of each element during inorder traversal
    // method 2//keep track of cnt and store maxi ele in each rec step
    solve(root);
    return ans;
}