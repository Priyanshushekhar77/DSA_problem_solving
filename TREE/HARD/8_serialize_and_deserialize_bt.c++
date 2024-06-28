/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * link->https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/1303276822/
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {

        if (root == nullptr)
            return "$";

        string serialized_string = "";
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node)
            {
                serialized_string.append(to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                serialized_string += "$,";
            }
        }
        return serialized_string;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        if (data == "$")
            return nullptr;

        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode *root = new TreeNode(stoi(item));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (getline(ss, item, ','))
            {
                if (item != "$")
                {
                    TreeNode *leftNode = new TreeNode(stoi(item));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            if (getline(ss, item, ','))
            {
                if (item != "$")
                {
                    TreeNode *rightNode = new TreeNode(stoi(item));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));