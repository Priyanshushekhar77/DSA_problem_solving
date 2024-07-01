/*
 Q. Minimum time taken to BURN the Binary Tree from a Node-- https://www.geeksforgeeks.org/problems/burning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=burning-tree

   Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


   Example 1:

   Input:
             1
           /   \
         2      3
       /  \      \
      4    5      6
          / \      \
         7   8      9
                      \
                      10
   Target Node = 8
   Output: 7
   Explanation: If leaf with the value
   8 is set on fire.
   After 1 sec: 5 is set on fire.
   After 2 sec: 2, 7 are set to fire.
   After 3 sec: 4, 1 are set to fire.
   After 4 sec: 3 is set to fire.
   After 5 sec: 6 is set to fire.
   After 6 sec: 9 is set to fire.
   After 7 sec: 10 is set to fire.
   It takes 7s to burn the complete tree.
*/

int findtotaltime(unordered_map<Node *, Node *> &parent, Node *target)
{
    queue<Node *> q;
    // for visited tracking -> if particula node not visited than inc the cnt and mark its visited
    unordered_map<Node *, int> visited;
    q.push(target);
    visited[target] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            auto node = q.front();
            q.pop();
            // left part not null and not visited than mark flag true and if flag is true than increment the cnt
            if (node->left != NULL && !visited[node->left])
            {
                flag = 1;
                visited[node->left] = 1;
                q.push(node->left);
            }
            // right part not null and not visited than mark flag true and if flag is true than increment the cnt
            if (node->right != NULL && !visited[node->right])
            {
                flag = 1;
                visited[node->right] = 1;
                q.push(node->right);
            }
            // parent of node is not null and parent is not visited than mark flag true and if flag is true than increment the cnt
            if (parent[node] && !visited[parent[node]])
            {
                flag = 1;
                visited[parent[node]] = 1;
                q.push(parent[node]);
            }
        }
        if (flag)
            cnt++;
    }
    return cnt;
}

Node *bfstomapparent(Node *root, unordered_map<Node *, Node *> &parent, int start)
{
    queue<Node *> q;
    q.push(root);
    Node *res;
    while (!q.empty())
    {
        Node *node = q.front();
        if (node->data == start)
            res = node;
        q.pop();
        if (node->left != NULL)
        {
            parent[node->left] = node;
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int minTime(Node *root, int start)
{
    unordered_map<Node *, Node *> parent;
    Node *target = bfstomapparent(root, parent, start);
    int ans = findtotaltime(parent, target);
    return ans;
}

/* The minTime function calls bfstomapparent and findtotaltime, both of which have a time complexity of O(N).
Thus, the overall time complexity of the minTime function is O(N).
The overall space complexity of the minTime function is dominated by the space used for the parent map and visited map, both of which are O(N).
*/