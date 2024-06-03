// Method 1: Using Auxiliary Space
// Inorder Traversal Function:
// The Inorder function performs an inorder traversal of the BST and stores the elements in a vector ans.
// flattenBST Function:
// It uses the Inorder function to get the sorted elements.
// Creates a new linked list from the sorted elements stored in the vector ans.

// Method 2: Without Using Auxiliary Space
// flattenBST Function:
// Recursively flattens the left subtree.
// Disconnects the left child of the root to avoid cycles.
// Finds the last node of the flattened left subtree and connects it to the root.
// Recursively flattens the right subtree and connects it to the root's right.

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST
{
public:
    void Inorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        Inorder(root->left, ans);
        ans.push_back(root->data);
        Inorder(root->right, ans);
    }

    Node *flattenBSTUsingAux(Node *root)
    {
        vector<int> ans;
        Inorder(root, ans);
        if (ans.empty())
            return NULL;
        Node *head = new Node(ans[0]);
        Node *curr = head;
        for (int i = 1; i < ans.size(); i++)
        {
            curr->right = new Node(ans[i]);
            curr = curr->right;
        }
        return head;
    }
    // using recusive
    Node *flattenBST(Node *root)
    {
        if (root == NULL)
            return NULL;
        Node *head = flattenBST(root->left); // till lastmost left ele that is smallest ele of BST
                                             // since left part is flattened than disconnect the root componenet
        root->left = NULL;
        Node *temp = head; // lastmost ele
        // now connect the last node of flatting list to root node
        // agar left paart me nodes ho

        if (temp != NULL)
        {
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = root;
        }
        else
        {
            head = root; // //if head is null than root becomes the head of the flattening list
        }
        // Now go for right part
        root->right = flattenBST(root->right);
        return head;
    }

    void printLinkedList(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->right;
        }
        cout << endl;
    }
};

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    BST bst;
    Node *flattenedRoot = bst.flattenBST(root);
    cout << "Flattened BST: ";
    bst.printLinkedList(flattenedRoot);

    return 0;
}
