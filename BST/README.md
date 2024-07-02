# BST ->

## 1. Inorder of BST is always in sorted order so maximum questions will be solve by it.(e.g- 2 sum in bst)

## 2.For every given node in a Binary Search Tree if a left or a right child exists then:(Left Child < Node < Right Child)

### 3.As we can visualize from the above Tree, the right subtree has all the elements greater than the root element and the left subtree has all the elements lesser than the root element. A point to note here is that every subtree is itself a Binary Search Tree as it contains a subtree whose root node is lesser than the value of the current node and another subtree whose root node is greater than the value of the current node. AND for the general implementation of Binary Search Trees, duplicate node values are not allowed.

## 4.is particularly makes the time of searching for a given node in a Binary Search Tree a lot less than searching in a simple Binary Tree.log(N)2

/_ IS bst traversal
e.g-Input: arr[] = [8, 14, 45, 64, 100]
Output: True
Input: arr[] = [5, 6, 1, 8, 7]
Output: False
bool isBSTTraversal(vector<int>& arr) {
// your code here
bool ans = true;
for(int i=0;i<arr.size()-1;i++){
if(arr[i]>=arr[i+1]){
ans = false;
break;
}
}
return ans;
}
_/
