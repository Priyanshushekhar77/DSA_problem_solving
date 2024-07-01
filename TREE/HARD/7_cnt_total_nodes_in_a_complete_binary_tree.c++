/*  222. Count Complete Tree Nodes - https://leetcode.com/problems/count-complete-tree-nodes/description/
   Given the root of a complete binary tree, return the number of the nodes in the tree.

   According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

   Design an algorithm that runs in less than O(n) time complexity.

   Example 1:
   Input: root = [1,2,3,4,5,6]
   Output: 6

Approach->
 Step 1: Base Case If the given node is null, we return 0 as there are no nodes to count.
Step 2: Recursive Calls: Recursively find the left height and right height of the Binary Tree.
Step 3: Comparison: If the left height is equal to the right height implies that the tree’s last level is completely filled. Return the count of nodes using the formula: return (1 << lh) - 1, where << represents the left shift operator and represents the power of 2.
Step 4: If the left height is not equal to the right height implies that the tree’s last level is not completely filled. Recursively call the function to the left and right subtree and return the final number of nodes as 1 + countNodes(root->left) + countNodes(root->right)
*/

int findleftht(TreeNode *node)
{
    if (node == NULL)
        return 0;
    int ht = 0;
    while (node)
    {
        ht++;
        node = node->left;
    }
    return ht;
}
int findrightht(TreeNode *node)
{
    if (node == NULL)
        return 0;
    int ht = 0;
    while (node)
    {
        ht++;
        node = node->right;
    }
    return ht;
}
int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = findleftht(root);
    int rh = findrightht(root);

    if (lh == rh)
        return (1 << lh) - 1; // 2(pow(h))-1;
    // if lh and rh are not equal than
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* Time Complexity: O(log N * log N) where N is the number of nodes in the Binary Tree.

-> The calculation of leftHeight and rightHeight takes O(log N) time.
-> In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree).
-> Therefore, the total time complexity is O(log N * log N).

Space Complexity : O(H) ~ O(N) where N is the number of nodes in the Binary Tree.
->The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the binary tree.
->Since the given tree is a complete binary tree, the height will always be log N.
->Therefore, the space complexity is O(log N).
*/