/*
   701. Insert into a Binary Search Tree - https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
   You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

   Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

   Example 1:
   Input: root = [4,2,7,1,3], val = 5
   Output: [4,2,7,1,3,5]
   Explanation: Another accepted tree is:

   Example 2:
   Input: root = [40,20,60,10,30,50,70], val = 25
   Output: [40,20,60,10,30,50,70,null,null,25]

   Example 3:
   Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
   Output: [4,2,7,1,3,5]
*/

TreeNode *insertIntoBST(TreeNode *root, int insertval)
{
    if (root == NULL)
        return new TreeNode(insertval);
    // always do insertion at bottom of leafnode
    TreeNode *temp = root;
    while (root != NULL)
    {
        if (temp->val >= insertval)
        {
            // goto bottom leftmost
            if (temp->left != NULL)
                temp = temp->left;
            else
            {
                // insert at bottom
                temp->left = new TreeNode(insertval);
                break;
            }
        }
        else
        { // temp->val<insval
            // goto bottom rightmost
            if (temp->right != NULL)
                temp = temp->right;
            else
            {
                // insert at bottom
                temp->right = new TreeNode(insertval);
                break;
            }
        }
    }
    return root;
}