/* Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.

https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1?page=1&sprint=a028c5530f22782a9978ce8eebc1c4df&sortBy=submissions
*/

void solve(Node *root, int &last, int &ans)
{
    if (root == NULL)
        return;
    solve(root->left, last, ans);
    if (last != -1)
    {
        ans = min(ans, root->data - last);
    }
    // in each rec call we will get last=root.data;
    last = root->data;
    solve(root->right, last, ans);
}
int absolute_diff(Node *root)
{
    // method1) get inorder of BST which is already sorted than find min ele=min(abs(arr[i+1]-arr[i]));
    // method 2) in each recursive inorder call step we will store ans in min
    int last = -1;
    int ans = INT_MAX;
    solve(root, last, ans);
    return ans;
}