/* PREORDER,INORDER,POSTORDER TRAVERSAL IN ONE GO TRAVERSAL

1.Step 1: Initialise a stack that holds a tree node and an integer value representing its state corresponding to pre order, inorder and postorder. Initialise empty arrays to store the three traversals as well.Check if the tree is empty. If so, return empty traversals.
2.Step 2: Push the root node onto the stack along with its state ‘1’ (preorder) to start the traversal.
3.Step 3: While the stack isn’t empty, pop the top node of the stack and for each node:
   A) If the state is ‘1’ ie. preorder: store the node’s data in the preorder array and move its state to 2 (inorder) for this node. Push this updated state back onto the stack and push its left child as well.
   B) If the state is ‘2’ ie. inorder: store the node’s data is the inorder array and update its state to 3 (postorder) for this node. Push the updated state back onto the stack and push the right child onto the stack as well.
   C) If the state is ‘3’ ie. postorder: store the node’s data in the postorder array and do nothing.
Step 4: Return the preorder, inorder and postorder array.
*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to get the Preorder,Inorder and Postorder traversal Of Binary Tree in One traversal
vector<vector<int>> preInPostTraversal(Node *root)
{
    vector<int> pre, in, post;

    // If the tree is empty,return empty traversals
    if (root == NULL)
    {
        return {};
    }

    // Stack to maintain nodes and their traversal state
    stack<pair<Node *, int>> st;
    // Start with the root node and state 1 (preorder)
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        // this is part of pre
        if (it.second == 1)
        {
            // Store the node's data in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2 (inorder) for this node
            it.second = 2;
            // Push the updated state back onto the stack
            st.push(it);

            // Push left child onto the stack for processing
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of inorder
        else if (it.second == 2)
        {
            // Store the node's data in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3 (postorder) for this node
            it.second = 3;
            // Push the updated state back onto the stack
            st.push(it);
            // Push right child onto the stack for processing
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }

        // this is part of postorder
        else
        {
            // Store the node's data in the postorder traversal and do nothing
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}

// Function to print the elements of a vector
void printVector(const vector<int> &vec)
{
    // Iterate through the vector
    // and print each element
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}
// Main function
int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);
    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];
    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "Inorder traversal: ";
    for (int val : in)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "Postorder traversal: ";
    for (int val : post)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

// Output Preorder traversal: 1 2 4 5 3 Inorder traversal: 4 2 5 1 3 Postorder traversal: 4 5 2 3 1

/* Time Complexity: O(3N) where N is the number of nodes in the Binary Tree. Each node is processed once for each traversal type (pre-order, in-order, and post-order). Hence, the algorithm effectively visits each node three times in total across the three traversal types.
Space Complexity: O(4N) where N is the number of nodes in the Binary Tree. The following additional data structures are used:A stack to maintain traversal states, requiring additional space proportional to the maximum number of nodes in the stack at any point during traversal.Three vectors to store the preorder, inorder and postorder traversal. These arrays collectively occupy space proportional to the total number of nodes in the tree. Hence, 3N is added to the space complexity.
*/