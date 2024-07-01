/*
   863. All Nodes Distance K in Binary Tree - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

   Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

   You can return the answer in any order.



   Example 1:


   Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
   Output: [7,4,1]
   Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
   Example 2:

   Input: root = [1], target = 1, k = 3
   Output: []


                     3
                   /  \
                 5     1
                / \   / \         -------> [7, 4, 1] are the elements at distance K = 2 from Node [5]
               6   2 0   8
                  / \
                 7   4
*/

unordered_map<TreeNode *, TreeNode *> parent;
void inorder(TreeNode *root)
{
  if (root == NULL)
    return;
  if (root->left != NULL)
    parent[root->left] = root;
  inorder(root->left);
  if (root->right != NULL)
    parent[root->right] = root;
  inorder(root->right);
}

void bfs(TreeNode *target, int k, vector<int> &ans)
{
  queue<TreeNode *> q;
  unordered_map<TreeNode *, int> visited;
  q.push(target);
  visited[target] = 1;
  while (!q.empty())
  {
    int n = q.size();
    if (k == 0)
      break;
    while (n--)
    {
      auto node = q.front();
      q.pop();
      if (node->left != NULL && !visited[node->left])
      {
        q.push(node->left);
        visited[node->left] = 1;
      }
      if (node->right != NULL && !visited[node->right])
      {
        q.push(node->right);
        visited[node->right] = 1;
      }
      if (parent[node] != NULL && !visited[parent[node]])
      {
        q.push(parent[node]);
        visited[parent[node]] = 1;
      }
    }
    k--;
  }
  while (!q.empty())
  {
    auto currnode = q.front();
    q.pop();
    ans.push_back(currnode->val);
  }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
  vector<int> ans;
  inorder(root);
  bfs(target, k, ans);
  return ans;
}

/* The minTime function calls bfstomapparent and findtotaltime, both of which have a time complexity of O(N).
Thus, the overall time complexity of the minTime function is O(N).
The overall space complexity of the minTime function is dominated by the space used for the parent map and visited map, both of which are O(N).
*/