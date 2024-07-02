/*
   Q. Find Inorder Successor of Binary Search Tree.

                     10
                   /  \
                 7     30
                / \   / \
               4   9 20  35
                  /     / \
                 8    31    400

    Example 1:
    Input: 20
    Output: 30

    Example 2:
    Input: 8
    Output: 9

    Example 3:
    Input: 400
    Output: null
*/

Node *inOrderSuccessor(Node *root, Node *x)
{
    // similar to ceil of bst
    // can be directly solved using inorder of bst and find ele which is ele>x;
    Node *ans = NULL;
    while (root != NULL)
    {
        if (root->data > x->data)
        {
            ans = root;
            root = root->left;
        }
        else
        {
            // root->val<x->val
            root = root->right;
        }
    }
    return ans;
}