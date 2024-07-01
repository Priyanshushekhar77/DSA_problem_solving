
TreeNode *searchBST(TreeNode *root, int val)
{

    while (root != NULL && root->val != val)
    {
        if (root->val > val)
            root = root->left;
        else // root->val <val
            root = root->right;
    }
    // if val founded
    return root;
}

/*
Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.

Space Complexity: O(1) since the algorithm does not use any additional space or data structures. The algorithm does use auxiliary stack space from recursion. In the average and worst-case scenarios, the space complexity for recursive stack space is O(h), where 'h' represents the height of the tree.*/