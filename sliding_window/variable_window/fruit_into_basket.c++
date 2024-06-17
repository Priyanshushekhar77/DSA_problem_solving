/* You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits of size N, where fruits[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.

Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.

Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.


Example 1:

Input:
N = 3
fruits [ ] = { 2, 1, 2 }
Output: 3
Explanation: We can pick from all three trees.


Example 2:

Input:
N = 6
fruits [ ] = { 0, 1, 2, 2, 2, 2 }
Output: 5
Explanation: It's optimal to pick from trees(0-indexed) [1,2,3,4,5].
*/

 int totalFruits(int n, vector<int> &arr) {
        int len=0;
        int i=0,j=0;
        //similar qns length of longest substring have unique 'k' char replace here k=2
        unordered_map<int,int>mp;
        while(j<n){
            mp[arr[j]]++;
            if(mp.size()==2) len=max(len,j-i+1);
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0) mp.erase(arr[i]);
                    i++;
                }
            }
            j++;
        }
        return len;
    }