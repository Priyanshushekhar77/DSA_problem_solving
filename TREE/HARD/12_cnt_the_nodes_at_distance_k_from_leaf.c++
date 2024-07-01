/*
https://www.geeksforgeeks.org/problems/node-at-distance/1
Binary tree
        1
      /   \
     2     3
   /  \   /  \
  4   5  6    7
          \ 
           8
k = 2
Output: 
2
Explanation: 
There are only two unique nodes that are at a distance of 2 units from the leaf node. (node 3 for leaf with value 8 and node 1 for leaves with values 4, 5 and 7) Note that node 2 isn't considered for leaf with value 8 because it isn't a direct ancestor of node 8.
*/

 public:
    vector<vector<Node*>>paths;
    void allpath(Node* root,vector<Node*>&temp){
        if(root==NULL) return;
        temp.push_back(root);
        if(root->left==NULL && root->right==NULL) paths.push_back(temp);
        allpath(root->left,temp);
        allpath(root->right,temp);
        temp.pop_back();
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	vector<Node*>temp;
    	allpath(root,temp);
    	unordered_set<Node*>ans;
    	for(auto it:paths){
    	    int n=it.size();
    	    if(n>k){
    	        ans.insert(it[n-k-1]);
    	    }
    	}
    	return ans.size();
    }