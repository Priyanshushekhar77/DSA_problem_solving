// (A) construct binary tree from inorder and preorder

/* Step 1:Create an empty map to store the indices of elements in the inorder traversal. Iterate through each element in the inorder traversal and store its index in the map
Step 2: Create a recursive helper function `buildTree` with the following parameters:
 a) Preorder vector
 b) Start index of preorder (preStart), initially set to 0
 c) End index of preorder (preEnd), initially set to preorder.size() - 1.
 d) Inorder vector
 e) Start index of inorder (inStart), initially set to 0.
 f) End index of inorder (inEnd), initially set to inorder.size() - 1.
 g) Map for efficient root index lookup in the inorder traversal.
Step 3: Base Case: Check if preStart is greater than preEnd or inStart is greater than inEnd. If true, return NULL, indicating an empty subtree/node.
Step 4: The root node for the current subtree  (preorder[preStart]). Find the index of this root node in the inorder traversal using the map (inMap[rootValue]). This is the rootIndex.
Step 5: FOR LEFT SUBTREE
Update preStart to preStart + 1 (moving to the next element in preorder)
Update preEnd to preStart + leftSubtreeSize (end of left subtree in preorder)
Update inEnd to rootIndex - 1 (end of left subtree in inorder)

For the right subtree:

Update preStart to preStart + leftSubtreeSize + 1 (moving to the next element after the left subtree)
Update preEnd to the original preEnd (end of right subtree in preorder)
Update inStart to rootIndex + 1 (start of right subtree in inorder)
Step 7: Return the root node constructed for the current subtree.
*/
// for better understanding make dry run

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> inmap; // val and ind
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]] = i;
    }
    // Call the private helper function to recursively build the tree
    TreeNode *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, int prest, int preend,
                    vector<int> &inorder, int inst, int inend, map<int, int> &inmap)
{
    // base case
    if (prest > preend || inst > inend)
        return NULL;
    // create new tree from start of preorder array and find its index in inorder array
    TreeNode *root = new TreeNode(preorder[prest]);
    int inroot = inmap[preorder[prest]];
    int numleft = inroot - inst;
    // recursively build left and right subtree
    root->left = buildTree(preorder, prest + 1, prest + numleft, inorder, inst, inroot - 1, inmap);
    root->right = buildTree(preorder, prest + numleft + 1, preend, inorder, inroot + 1, inend, inmap);
    return root;
}


//(B) construct the binary tree from postorder and inorder tree traversal

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> inormap; // val and index
    for (int i = 0; i < inorder.size(); i++)
    {
        inormap[inorder[i]] = i;
    }
    TreeNode *root = buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
                                     postorder.size() - 1, inormap);
    return root;
}

TreeNode *buildTreePostIn(vector<int> &inorder, int is, int ie,
                          vector<int> &postorder, int ps, int pe, map<int, int> &inormap)
{

    // Base case: If the subtree
    // is empty, return NULL
    if (ps > pe || is > ie)
    {
        return NULL;
    }
    // create newtreenode from end of postorder vector
    TreeNode *root = new TreeNode(postorder[pe]);
    // find the ind of this root in inorder vector
    int inroot = inormap[postorder[pe]];
    int numleft = inroot - is;
    // recursively  build left and right
    root->left = buildTreePostIn(inorder, is, inroot - 1, postorder, ps, ps + numleft - 1, inormap);
    root->right = buildTreePostIn(inorder, inroot + 1, ie, postorder, ps + numleft, pe - 1, inormap);
    return root;
}
