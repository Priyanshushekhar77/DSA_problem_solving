/* PREORDER ITERATIVE TRAVERSAL=>
  1.Push the root of the binary tree into the stack.
  2.While the stack is not empty:
Get the current node from the top of the stack.
Remove the node from the stack.
Add the node’s value to the preorder traversal result.
First, push the right child onto the track if it exists.
Secondly, push the left child onto the stack if it exists.
 3. Return the ‘preorder’ traversal result.=>in stack we push in order NRL=> after pop from stack we get  NODE,LEFT,RIGHT
*/

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    if (root == nullptr)
    {
        return preorder;
    }
    // Create a stack to store nodes during traversal
    stack<TreeNode *> st;
    // Push the root node onto the stack
    st.push(root);
    // Perform iterative preorder traversal
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        // Add the node's value to the preorder traversal result
        preorder.push_back(root->val);
        // Push the right child onto the stack if exists
        if (root->right != nullptr)
        {
            st.push(root->right);
        }
        // Push the left child onto the stack if exists
        if (root->left != nullptr)
        {
            st.push(root->left);
        }
    }
    return preorder;
}

// Time Complexity: O(N) where N is the number of nodes in the binary tree. Every node of the binary tree is visited exactly once, and for each node, , the operations performed (pushing and popping from the stack, accessing node values, etc.) are constant time operations.
// Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because the stack can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.

/*POSTORDER ITERATIVE TRAVERSAL USING 1 STACK =>in stack we push in order NLR=> after pop from stack(NRL) and reversing we get  LEFT,RIGHT,NODE */

vector<int> postOrder(Node *node)
{
    // code here
    vector<int> ans;
    if (node == NULL)
    {
        return ans;
    }
    stack<Node *> st;
    st.push(node);
    while (!st.empty())
    {
        node = st.top();
        st.pop();
        ans.push_back(node->data);
        if (node->left != NULL)
        {
            st.push(node->left);
        }

        if (node->right != NULL)
        {
            st.push(node->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

/* POSTODER TRAVERSAL OF BINARY TREE USING 2 STACK
1. Step 1: Create two stacks: one for holding nodes and another for storing the final postorder traversal sequence. Initialise an array `postorder` to store the traversal sequence.
Step 2: Push the root node to the first stack.
Step 3: Process the nodes until the first stack is empty:
    Pop a node from the top of the first stack.
    Push this node onto the second stack.
    Push its left child (if it exists) onto the first stack.
    Push its right child (if it exists) onto the first stack.
4.Step 4:Once the first stack is empty, retrieve the nodes in the postorder sequence by popping nodes from the second stack one by one and store them in the postorder array.
*/

vector<int> postOrder(Node *root)
{
    vector<int> postorder;
    if (root == NULL)
    {
        return postorder;
    }
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        // Get the top node from st1
        root = st1.top();
        st1.pop();
        // Push the node onto st2
        st2.push(root);
        // Push left child onto st1 if exists
        if (root->left != NULL)
        {
            st1.push(root->left);
        }
        // Push right child onto st1 if exists
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }
    // retrieve the nodes in the postorder sequence by popping nodes from the second stack one by one and store them in the postorder array
    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}
// T.C=O(2N) AND S.C=O(2N)

// INORDER ITERATIVE TRAVERSAL
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != nullptr || !st.empty())
    {
        // Reach the left most TreeNode of the current TreeNode and push all the left node into stack
        while (curr != nullptr)
        {
            st.push(current);
            curr = curr->left;
        }

        // Current must be nullptr at this point so push as node
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);

        // We have visited the node and its left subtree, now it's right subtree's turn
        curr = curr->right;
        // and push all the left part of this right portion into stack using while loop above;
    }
    return result;
}
