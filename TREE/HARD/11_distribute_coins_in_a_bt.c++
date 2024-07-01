/*  https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
Input :      3
           /   \
          0     0
Output : 2
Explanation:
From the root of the tree, we move one
candy to its left child, and one candy to
its right child.
Example 2:

Input :      0
           /   \
          3     0
Output : 3
Explanation :
From the left child of the root, we move
two candies to the root [taking two moves].
Then, we move one candy from the root of the
tree to the right child.
*/

int solve(Node *root, int &moves)
{
    if (root == NULL)
        return 0;
    int l = solve(root->left, moves);
    int r = solve(root->right, moves);
    moves += abs(l) + abs(r);
    return (l + r + root->key) - 1;
}
int distributeCandy(Node *root)
{
    // we will follow the approach bottom to top,if any candies extra in child than give it to parents through backtracking and cnt the moves
    int moves = 0;
    solve(root, moves);
    return moves;
}