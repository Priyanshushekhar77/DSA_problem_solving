/* https://www.geeksforgeeks.org/problems/largest-bst/1
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2
Output: 2
Explanation: The following sub-tree is a
BST of size 2:
       2
    /    \
   N      8
   Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).
*/

// making classs and constructor
class treenode
{
public:
    int size;
    int minval;
    int maxval;
    bool isbst;

    treenode(int size, int minval, int maxval, bool isbst) : size(size), minval(minval), maxval(maxval), isbst(isbst)
    {
    }
};

class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    treenode *solve(Node *root, int &ans)
    {
        if (root == nullptr)
            return new treenode(0, INT_MAX, INT_MIN, true);
        // we do postorder traversal becz we have to dela with left and right elements
        treenode *left = solve(root->left, ans);
        treenode *right = solve(root->right, ans);
        // checking the current node for valid BST
        treenode *curr;
        bool isbst;
        int size = left->size + right->size + 1;
        int maxval = max(root->data, right->maxval);
        int minval = min(root->data, left->minval);
        if (left->isbst && right->isbst && (left->maxval < root->data && root->data < right->minval))
        {
            isbst = true;
        }
        else
        {
            isbst = false;
        }
        if (isbst)
        {
            ans = max(ans, size);
        }
        curr = new treenode(size, minval, maxval, isbst);
        return curr;
    }

    int largestBst(Node *root)
    {
        // maximum of all left nodes < root node < minimum of all right nodes
        int ans = 0;
        solve(root, ans);
        return ans;
    }