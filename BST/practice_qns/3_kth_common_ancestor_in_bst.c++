/*
https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1?page=1&sprint=a028c5530f22782a9978ce8eebc1c4df&sortBy=submissions

*/

Node *getlca(Node *root, int x, int y)
{
    if (root == NULL)
        return NULL;
    if (root->data == x || root->data == y)
        return root;
    if (root->data > x && root->data > y)
        getlca(root->left, x, y); // case 1
    else if (root->data < x && root->data < y)
        getlca(root->right, x, y); // case 2
    else
    {
        // root->data>x && root->data<y or root->data<x && root->data>y
        return root;
    }
}
void solve(Node *root, Node *lca, vector<int> &path)
{
    // st0ring ele from root to lca in path vector arr;
    path.push_back(root->data);
    if (root->data == lca->data)
        return;
    else if (root->data < lca->data)
        solve(root->right, lca, path);
    else
    {
        // root->data>lca->data
        solve(root->left, lca, path);
    }
    return;
}
int kthCommonAncestor(Node *root, int k, int x, int y)
// steps 1.find lca of x and y
// 2.now traverse from root node to lca node
// 3.kth node is path[n-k];
{
    Node *lca = getlca(root, x, y);
    vector<int> path;
    solve(root, lca, path);
    int n = path.size();
    if (path.size() < k)
        return -1;
    return path[n - k];
}