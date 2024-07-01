/*
https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1?page=1&sprint=a028c5530f22782a9978ce8eebc1c4df&sortBy=submissions

*/

void solve(Node *root, int &ans, int &n)
{
    if (root == NULL)
        return;
    if (root->key <= n)
    {
        ans = max(ans, root->key);
        solve(root->right, ans, n);
    }
    else
    {
        solve(root->left, ans, n);
    }
    return;
}
int findMaxForN(Node *root, int n)
{
    // method 1 -> inorder of bst is always in sorted order,so store in vector and than find the element which is greater than n in vector array;
    // method 2-> recursion-> explore towards right becz of inc value towards right;
    int ans = -1;
    solve(root, ans, n);
    return ans;
}