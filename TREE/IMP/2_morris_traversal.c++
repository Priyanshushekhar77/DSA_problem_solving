// Morris Preorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) also called threaded binary tree
// (A) inorder

/*
Case 1: The current node has no left subtree.
   a) Print the value of the current node.
   b)Then to the right child of the current node.
Case 2: There is a left subtree, and the right-most child of this left subtree is pointing to null.
   a)Set the right-most child of the left subtree to point to the current node.
   b)Move to the left child of the current node.
Case 3: There is a left subtree, and the right-most child of this left subtree is already pointing to the current node.
   a)Print the value of the current node.
   b)Revert the temporary link (set it back to null).
   c)Move to the right child of the current node.
*/

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            // Add the value of the current node to the inorder vector if curr.left is null
            inorder.push_back(curr->val);
            // Move to the right child
            curr = curr->right;
        }
        else
        {
            // if left child is not NULL than move to the rightmost node in the left subtree
            TreeNode *prev = curr->left;
            // jab tak right node null na aaye ya phr wo curr ko point na ka rha ho
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            // if the right child points to null than make a link with curr pointer and move the curr pointer to the left
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                // if the right child pointing to curr than break the linkage becz it already has been traversed and print the curr value and move the curr pointer to right
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

/*
Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.
The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
In each step, we perform constant-time operations, such as moving to the left or right child and updating pointers.

Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.*/

// (B) preorder

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            // Add the value of the current node to the inorder vector if curr.left is null
            preorder.push_back(curr->val);
            // Move to the right child
            curr = curr->right;
        }
        else
        {
            // if left child is not NULL than move to the rightmost node in the left subtree
            TreeNode *prev = curr->left;
            // jab tak right node null na aaye ya phr wo curr ko point na ka rha ho
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            // if the right child points to null than make a link with curr pointer and move the curr pointer to the left
            if (prev->right == NULL)
            {
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            }
            else
            {
                // if the right child pointing to curr than break the linkage becz it already has been traversed and print the curr value and move the curr pointer to right
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}
