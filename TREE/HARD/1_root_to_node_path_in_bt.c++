/*
   Path to Given Node
   Given a Binary Tree A containing N nodes.

   You need to find the path from Root to a given node B.

   NOTE:

   No two nodes in the tree have same data values.
   You can assume that B is present in the tree A and a path always exists.

   Example Input
   Input 1:

    A =

              1
            /   \
           2     3
          / \   / \
         4   5 6   7


   B = 5

   Input 2:

    A =
               1
             /   \
            2     3
           / \ .   \
          4   5 .   6


   B = 1


   Example Output
   Output 1:

    [1, 2, 5]
   Output 2:

    [1]


   Example Explanation
   Explanation 1:

    We need to find the path from root node to node with data value 5.
    So the path is 1 -> 2 -> 5 so we will return [1, 2, 5]
   Explanation 2:

    We need to find the path from root node to node with data value 1.
    As node with data value 1 is the root so there is only one node in the path.
   So we will return [1]
*/

// root to leaf path is present or not if any value of leaf node has been given
vector<int> ans;
getpath(root, ans, leaf);
return ans;

bool getpath(Treenode *root, vector<int> &ans, int x)
{
    if (root == null)
        return false;
    ans.push_back(root->val);
    if (root->val == x)
        return true;

    if (getpath(root->left, ans, x) || getpath(root->right, ans, x))
        return true;
    ans.pop_back();
    return false;
}

// print every root to leaf path -> https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

vector<vector<int>> ans;
void solve(Node *root, vector<int> &temp)
{
    if (!root)
        return;
    temp.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
    solve(root->left, temp);
    solve(root->right, temp);
    temp.pop_back();
}
vector<vector<int>> Paths(Node *root)
{
    vector<int> temp;
    if (root == NULL)
        return {};
    solve(root, temp);
    return ans;
}