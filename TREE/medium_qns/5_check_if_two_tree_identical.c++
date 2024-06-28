/*
   100. Same Tree  ---  https://leetcode.com/problems/same-tree/description/
   Given the roots of two binary trees p and q, write a function to check if they are the same or not.
   
   Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
   
   Example 1:   
   Input: p = [1,2,3], q = [1,2,3]
   Output: true
   Example 2:
   
   
   Input: p = [1,2], q = [1,null,2]
   Output: false

   Example 3:   
   Input: p = [1,2,1], q = [1,1,2]
   Output: false
*/


 bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if(p==NULL && q==NULL) return true;
        //if not equals  note: if(p->val!=q->val) return false gives runtime error
        if(p!=NULL && q==NULL) return false;
        if(p==NULL && q!=NULL) return false;
        if(p->val != q->val) return false;
       // if val equals than move forward for matching
        return (p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }