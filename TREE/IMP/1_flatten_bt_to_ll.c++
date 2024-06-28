/*  Given the root of a binary tree, flatten the tree into a "linked list":

   The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
   The "linked list" should be in the same order as a pre-order traversal of the binary tree.


   Example 1:
   Input: root = [1,2,5,3,4,null,6]
   Output: [1,null,2,null,3,null,4,null,5,null,6]
*/

// method1 T.C->O(N) AND S.C->O(N)  -> The intuition behind this approach is to perform a reverse pre-order traversal where, instead of simply visiting nodes, we flatten the tree into a linked list as we traverse it.

/* Step 1:Initialise a global variable `prev` to keep track of the previously processed node. Initially set it to null.
Step 2: Base Case: If the current node is null, return null.
Step 3: Flatten the Right and Left Subtree: Recursively flatten the right and left subtree of the current node by calling the flatten function on the current node's right and left child.
Step 4: Attach the Right Subtree to the Flattened Left Subtree: Set the right child of the current node to the value of `prev` since `prev` points to the rightmost node in the flattened left subtree. This effectively attaches the right subtree to the right of the rightmost node of the left subtree.
Step 5:Attach the Left Subtree as Right Child: Set the right child of the current node to the left subtree.
Set the left child of the current node to null since we are flattening the binary tree to a linked list and there should be no left child.
Step 6:Update `prev` to the current node for the next iteration and recursion step.
*/

TreeNode *prev = NULL;
void flatten(TreeNode *root)
{
    // reverse preorder method

    if (root == NULL)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

// METHOD2 T.C->O(N) AND S.C->O(1)  ->  Morris Traversal is an algorithm that allows preorder/inorder tree traversal without using any extra space for stack or recursion. It utilises threaded binary trees to traverse the tree without requiring a stack for saving the path.

/* Step 1: Start with the current node as the root of the tree.
Step 2: While the current node is not null we traverse the tree in a while loop:
   a) If the current node has a left child:
   b) Find the rightmost node in the left subtree by while loop.
   c)Connect the rightmost node of the left subtree to the current node’s right child.
   d)Update the current node’s right child to be its left child.
   e)Set the current node’s left child to null.
   f)Move to the current node’s right child.
Step 3: Repeat until all nodes are processed.
*/

void flatten(TreeNode *root)
{
    // morris traversal threaded binary tree
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            TreeNode *pre = curr->left;
            while (pre->right != NULL)
            {
                pre = pre->right;
            }
            // Connect the rightmost node in the left subtree to the current node's right child
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        // Move to the next node on the right side
        curr = curr->right;
    }
}
