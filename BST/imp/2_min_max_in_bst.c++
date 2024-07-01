/*
Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

Example 1:

Input:
           5
         /    \
        4      6
       /        \
      3          7
     /
    1
Output: 1
*/

int minValue(Node *root)
{
    // since minimum value lies on the leftmost bottom side so get it
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
}