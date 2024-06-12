/*
    Q. 0/1 Knapsack (DP – 19)
    Practice : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

    You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
    In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).
    
    Example 1:
    
    Input:
    N = 3
    W = 4
    values[] = {1,2,3}
    weight[] = {4,5,1}
    Output: 3
    Example 2:
    
    Input:
    N = 3
    W = 3
    values[] = {1,2,3}
    weight[] = {4,5,6}
    Output: 0
*/

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& wt, vector<int>& val, int ind, int cap, vector<vector<int>>& dp){
 // Base case: If there are no items left or the knapsack has no capacity, return 0
    if (ind == 0 || cap == 0) {
        return 0;
}
if(dp[ind][cap]!=-1) return dp[ind][cap];
//nottake
int nottake=solve(wt,val,ind-1,cap,dp);
//take
int take=0;
if(wt[ind]<=cap){
    take=val[ind] + solve(wt,val,ind-1,cap-wt[ind],dp);
}
return dp[ind][cap] = max(take,nottake);
}
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve(wt, val, n - 1, W, dp);
}
int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();
    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);
    return 0;
}

// Time Complexity: O(N*W)
// Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

// Space Complexity: O(N*W) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).

//TABULATION

int knapsack(vector<int>& wt, vector<int>& val, int n, int cap){
    vector<vector<int>>dp(n,vector<int>(cap+1,0));
     // Base condition: Fill in the first row for the weight of the first item from the wt of first item to cap (cap>=wt[0])
     for(int i=wt[0];i<=cap;i++){
        dp[0][i] = val[0];//cap>=wt[0]
     }
     //fill the dp table
  for(int ind=1;ind<n;ind++){
    for(int w=0;w<=cap;w++){
        int nottake=dp[ind-1][w];
        int take=INT_MIN;
         // Check if the current item can be included without exceeding the knapsack's capacity
            if (wt[ind] <= w) {
                take = val[ind] + dp[ind - 1][w - wt[ind]];
            }
            //update dp table
            dp[ind][w]=max(take,nottake);
    }
  }
  return dp[n-1][cap];

}
int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();
    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);
    return 0;
}