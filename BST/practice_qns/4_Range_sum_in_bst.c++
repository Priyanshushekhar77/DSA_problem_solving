//https://leetcode.com/problems/range-sum-of-bst/description/


void solve(TreeNode* root, int low, int high){
    if(root==NULL){
        return;
    }
    if(root->val>=low && root->val<=high){
        ans+=root->val;
    }
    solve(root->left,low,high);
    solve(root->right,low,high);
 }
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans=0;
        solve(root,low,high);
        return ans;
    }