/*  BOUNDARY TRAVERSAL=> ADD LEFT PART + ADD BOTTOM PART + ADD RIGHT PART
Step 1: Initialise an empty array to store the boundary traversal nodes.

Step 2: Create a helper function to check if a node is a leaf. This is to avoid cases where there will be an overlap in the traversal of nodes. We exclude leaf nodes when adding left and right boundaries as they will already be added when in the bottom boundary.

Step 3: Initialise a recursive function `addLeftBoundary` and a vector to store the left traversal.
     a) Start from the root of the tree.
     b) Traverse down the left side of the tree until we reach a leaf node. For each non-leaf node, add its value to the result list.
     c) Traverse to its left child. If unavailable, call the recursion function to its right child.

Step 4: Implement a recursive function `addLeafNodes` and a vector to store the bottom traversal.
     a) If the current node is a leaf, add its value to the result list.
     b) Recursively travel to the current nodes left and right subtrees in a preorder fashion.

Step 5: Implement a recursive function `addRightBoundary` and a vector to store the right traversal.
     a) Start from the root of the tree.
     b) Traverse to the right most side of the tree until we reach a leaf node.
         For each non-leaf node, call the recursive function to its right child; if unavailable, call to its left child.
     c) While the recursion backtracks, add the current node’s value to the result list.
*/

#include <iostream>
#include <vector>
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

class Solution
{
public:
    // Function to check if a node is a leaf
    bool isLeaf(Node *root)
    {
        return root->left == NULL && root->right == NULL;
    }

    // Function to add the left boundary of the tree
    void addLeftBoundary(Node *root, vector<int> &ans)
    {
        Node *curr = root->left;
        while (curr)
        {
            // If the current node is not a leaf and it is left subpart of tree, add its value to the ans
            if (!isLeaf(curr))
            {
                ans.push_back(curr->data);
            }
            // Move to the left child if it exists, otherwise move to the right child if left subpart not exist and add its value to the ans if it is not leaf
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
    }

    // Function to add the right boundary of the tree
    void addRightBoundary(Node *root, vector<int> &ans)
    {
        Node *curr = root->right;
        vector<int> temp; // becz u have to reverse the right part
        while (curr)
        {
            // If the current node is not a leaf, add its value to a temporary vector
            if (!isLeaf(curr))
            {
                temp.push_back(curr->data);
            }
            // Move to the right child if it exists, otherwise move to the left child if right subpart not exist and add its value to the ans if it is not leaf
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        // Reverse and add the values from the temporary vector to the result
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            ans.push_back(temp[i]);
        }
    }

    // Function to add the leaves of the tree in preorder tree traversal fashion
    void addLeaves(Node *root, vector<int> &ans)
    { // preorder fashion
        // If the current node is a leaf, add its value to the result
        if (isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        // Recursively add leaves of the left and right subtrees
        if (root->left != NULL)
        {
            addLeaves(root->left, ans);
        }
        if (root->right != NULL)
        {
            addLeaves(root->right, ans);
        }
    }

    // Main function to perform the boundary traversal of the binary tree
    vector<int> printBoundary(Node *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        // If the root is not a leaf, add its value to the result
        if (!isLeaf(root))
        {
            ans.push_back(root->data);
        }
        // Add the left boundary, leaves, and right boundary in order
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};

// Helper function to
// print the result
void printResult(const vector<int> &result)
{
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
}
int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);
    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}

// The overall time complexity is dominated by the most expensive operation, which is O(N).